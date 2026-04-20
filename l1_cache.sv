`timescale 1ns/1ps

module l1_cache #(
    parameter L1_CAPACITY   = 512,
    parameter L1_WAYS       = 2,
    parameter BLOCK_SIZE    = 64,
    parameter NUM_MSHRS     = 2,
    parameter VA_WIDTH      = 48,
    parameter PA_WIDTH      = 30,
    parameter DATA_WIDTH    = 64
)(
    input  logic                        clk,
    input  logic                        rst_n,

    // FROM TLB
    input  logic                        start_tag,
    input  logic [PA_WIDTH-1:0]         tlb_paddr,

    // FROM LSQ / ISSUE BUFFER
    input  logic                        start_index,
    input  logic [VA_WIDTH-1:0]         trace_vaddr,
    input  logic                        is_write,
    input  logic [DATA_WIDTH-1:0]       wdata,
    // ROB tag of the load — registered alongside the request and echoed back
    // on the response channel so the LSQ can match returning data.
    // Ignored for stores (is_write=1); tie to '0 in that case.
    input  logic [ROB_IDX_WIDTH-1:0]    lsq_lq_id_in,

    // TO LSQ — load data return
    // Driven for one cycle when a load completes (hit or MSHR install).
    output logic                        lsq_resp_valid,
    output logic [ROB_IDX_WIDTH-1:0]    lsq_resp_lq_id,
    output logic [DATA_WIDTH-1:0]       lsq_resp_data,

    // TO LSQ — back-pressure
    output logic                        l1_stall_out_to_lsq,

    // TO/FROM L2
    output logic                        l2_wb_valid,
    output logic [PA_WIDTH-1:0]         l2_wb_paddr,
    output logic [BLOCK_SIZE*8-1:0]     l2_wb_data,
    input  logic                        l2_wb_ack,
    output logic                        l2_req_valid,
    output logic [PA_WIDTH-1:0]         l2_req_paddr,
    input  logic                        l2_data_valid,
    input  logic [PA_WIDTH-1:0]         l2_data_paddr,
    input  logic [BLOCK_SIZE*8-1:0]     l2_data
);

    localparam int L1_SETS        = L1_CAPACITY / (BLOCK_SIZE * L1_WAYS);
    localparam int INDEX_BITS     = $clog2(L1_SETS);
    localparam int OFFSET_BITS    = $clog2(BLOCK_SIZE);
    localparam int WORD_BITS      = $clog2(BLOCK_SIZE * 8 / DATA_WIDTH);
    localparam int WORDS_PER_BLOCK = BLOCK_SIZE * 8 / DATA_WIDTH;
    localparam int TAG_SIZE       = PA_WIDTH - INDEX_BITS - OFFSET_BITS;

    // =========================================================================
    // CACHE ARRAYS
    // =========================================================================
    logic [BLOCK_SIZE*8-1:0]  set_contents [L1_SETS][L1_WAYS];
    logic [TAG_SIZE-1:0]      tags         [L1_SETS][L1_WAYS];
    logic [L1_SETS-1:0]       lru;
    logic [L1_WAYS-1:0]       set_valids   [L1_SETS];
    logic [L1_WAYS-1:0]       set_dirty    [L1_SETS];

    // =========================================================================
    // PIPELINE STATE
    // =========================================================================
    logic [2:0]              state;
    logic [INDEX_BITS-1:0]   curr_index;
    logic                    curr_is_write;
    logic [DATA_WIDTH-1:0]   curr_wdata;
    logic [WORD_BITS-1:0]    curr_word_offset;
    logic [ROB_IDX_WIDTH-1:0] curr_lq_id;   // registered lq_id for the in-flight request

    logic                    mshr_dup;
    logic [$clog2(NUM_MSHRS)-1:0] mshr_dup_idx;
    logic                    evict_way_l;
    logic [PA_WIDTH-1:0]     evict_pa;
    logic                    mshr_install_done;

    // =========================================================================
    // MSHR
    // =========================================================================
    logic [1:0]               mshr_state      [NUM_MSHRS];
    logic [PA_WIDTH-1:0]      mshr_paddr      [NUM_MSHRS];
    logic [INDEX_BITS-1:0]    mshr_index      [NUM_MSHRS];
    logic [BLOCK_SIZE*8-1:0]  mshr_block      [NUM_MSHRS];
    logic [WORDS_PER_BLOCK-1:0] mshr_store_mask [NUM_MSHRS];
    logic [BLOCK_SIZE*8-1:0]  mshr_store_data [NUM_MSHRS];
    // lq_id for the load that caused each miss — needed to send the response
    // back to the LSQ when the MSHR finally installs.
    logic [ROB_IDX_WIDTH-1:0] mshr_lq_id      [NUM_MSHRS];
    logic                     mshr_is_load     [NUM_MSHRS]; // 0 = store miss, no LSQ response

    logic                         mshr_full;
    logic [$clog2(NUM_MSHRS)-1:0] mshr_free_idx;

    localparam [1:0] MS_IDLE       = 2'b00;
    localparam [1:0] MS_UNRESOLVED = 2'b01;
    localparam [1:0] MS_RESOLVED   = 2'b10;

    // =========================================================================
    // WRITEBACK FIFO
    // =========================================================================
    localparam int WB_DEPTH = 2;
    localparam int WB_PTR_W = (WB_DEPTH > 1) ? $clog2(WB_DEPTH) : 1;

    logic [PA_WIDTH-1:0]     wb_paddr_q [WB_DEPTH];
    logic [BLOCK_SIZE*8-1:0] wb_data_q  [WB_DEPTH];
    logic [WB_PTR_W-1:0]     wb_head, wb_tail;
    logic [WB_PTR_W:0]       wb_count;
    logic                    wb_push, wb_pop;
    logic [PA_WIDTH-1:0]     wb_push_paddr;
    logic [BLOCK_SIZE*8-1:0] wb_push_data;
    logic                    victim_dirty;
    logic [PA_WIDTH-1:0]     victim_paddr;
    logic [BLOCK_SIZE*8-1:0] victim_data;

    wire wb_empty = (wb_count == '0);
    wire wb_full  = (wb_count == WB_DEPTH);

    assign l2_wb_valid = !wb_empty;
    assign l2_wb_paddr = wb_paddr_q[wb_head];
    assign l2_wb_data  = wb_data_q[wb_head];

    // =========================================================================
    // STALL TO LSQ
    // =========================================================================
    assign l1_stall_out_to_lsq = (state != 3'd0) || mshr_full;

    // =========================================================================
    // L2 REQUEST — combinational scan of unresolved MSHRs
    // =========================================================================
    always_comb begin
        l2_req_valid = 1'b0;
        l2_req_paddr = '0;
        for (int i = 0; i < NUM_MSHRS; i++)
            if (mshr_state[i] == MS_UNRESOLVED && !l2_req_valid) begin
                l2_req_valid = 1'b1;
                l2_req_paddr = mshr_paddr[i];
            end
    end

    // =========================================================================
    // MSHR FREE SLOT — combinational
    // =========================================================================
    always_comb begin
        mshr_full     = 1'b1;
        mshr_free_idx = '0;
        for (int i = 0; i < NUM_MSHRS; i++)
            if (mshr_state[i] == MS_IDLE && mshr_full) begin
                mshr_full     = 1'b0;
                mshr_free_idx = i[$clog2(NUM_MSHRS)-1:0];
            end
    end

    // =========================================================================
    // TAG CHECK — combinational
    // =========================================================================
    logic [TAG_SIZE-1:0]  incoming_tag;
    logic [PA_WIDTH-1:0]  incoming_line_paddr;
    logic                 hit;
    logic [$clog2(L1_WAYS)-1:0] hit_way;

    assign incoming_tag        = tlb_paddr[PA_WIDTH-1 -: TAG_SIZE];
    assign incoming_line_paddr = {tlb_paddr[PA_WIDTH-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};

    always_comb begin
        hit     = 1'b0;
        hit_way = '0;
        for (int w = 0; w < L1_WAYS; w++)
            if (set_valids[curr_index][w] && tags[curr_index][w] == incoming_tag) begin
                hit     = 1'b1;
                hit_way = w[$clog2(L1_WAYS)-1:0];
            end
    end

    // =========================================================================
    // SEQUENTIAL LOGIC
    // =========================================================================
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state            <= 3'd0;
            curr_index       <= '0;
            curr_is_write    <= 1'b0;
            curr_wdata       <= '0;
            curr_word_offset <= '0;
            curr_lq_id       <= '0;
            lsq_resp_valid   <= 1'b0;
            lsq_resp_lq_id   <= '0;
            lsq_resp_data    <= '0;
            for (int i = 0; i < L1_SETS; i++) begin
                set_valids[i] <= '0;
                set_dirty[i]  <= '0;
            end
            lru <= '0;
            for (int i = 0; i < NUM_MSHRS; i++) begin
                mshr_state[i]      <= MS_IDLE;
                mshr_paddr[i]      <= '0;
                mshr_index[i]      <= '0;
                mshr_block[i]      <= '0;
                mshr_store_mask[i] <= '0;
                mshr_store_data[i] <= '0;
                mshr_lq_id[i]      <= '0;
                mshr_is_load[i]    <= 1'b0;
            end
            wb_head  <= '0;
            wb_tail  <= '0;
            wb_count <= '0;
            for (int i = 0; i < WB_DEPTH; i++) begin
                wb_paddr_q[i] <= '0;
                wb_data_q[i]  <= '0;
            end

        end else begin

            // Default: de-assert response for one cycle pulse
            lsq_resp_valid <= 1'b0;
            lsq_resp_lq_id <= '0;
            lsq_resp_data  <= '0;

            wb_pop        = l2_wb_ack && !wb_empty;
            wb_push       = 1'b0;
            wb_push_paddr = '0;
            wb_push_data  = '0;

            // -----------------------------------------------------------------
            // STATE MACHINE
            // -----------------------------------------------------------------
            case (state)

                // -------------------------------------------------------------
                3'd0: begin  // IDLE
                // -------------------------------------------------------------

                    // --- MSHR INSTALL (resolved entries from L2) ---
                    mshr_install_done = 1'b0;
                    for (integer i = 0; i < NUM_MSHRS; i++) begin
                        if (!mshr_install_done && mshr_state[i] == MS_RESOLVED) begin

                            // Choose victim way
                            if (!set_valids[mshr_index[i]][0])
                                evict_way_l = 1'b0;
                            else if (!set_valids[mshr_index[i]][1])
                                evict_way_l = 1'b1;
                            else
                                evict_way_l = lru[mshr_index[i]];

                            victim_dirty = set_dirty[mshr_index[i]][evict_way_l] &&
                                           set_valids[mshr_index[i]][evict_way_l];
                            victim_paddr = {tags[mshr_index[i]][evict_way_l],
                                            mshr_index[i], {OFFSET_BITS{1'b0}}};
                            victim_data  = set_contents[mshr_index[i]][evict_way_l];

                            // Stall install if WB FIFO is full and victim is dirty
                            if (!(victim_dirty && wb_full && !wb_pop)) begin

                                if (victim_dirty) begin
                                    wb_push       = 1'b1;
                                    wb_push_paddr = victim_paddr;
                                    wb_push_data  = victim_data;
                                end

                                // Merge any pending store writes into the returning block
                                begin
                                    logic [BLOCK_SIZE*8-1:0] temp_install;
                                    temp_install = mshr_block[i];
                                    for (int w = 0; w < WORDS_PER_BLOCK; w++)
                                        if (mshr_store_mask[i][w])
                                            temp_install[w*DATA_WIDTH +: DATA_WIDTH] =
                                                mshr_store_data[i][w*DATA_WIDTH +: DATA_WIDTH];
                                    set_contents[mshr_index[i]][evict_way_l] <= temp_install;

                                    // --- LSQ RESPONSE: load miss fill ---
                                    // Only send a response for load misses.
                                    // The read word is extracted from the merged block.
                                    if (mshr_is_load[i]) begin
                                        lsq_resp_valid <= 1'b1;
                                        lsq_resp_lq_id <= mshr_lq_id[i];
                                        lsq_resp_data  <=
                                            temp_install[curr_word_offset*DATA_WIDTH +: DATA_WIDTH];
                                    end
                                end

                                tags[mshr_index[i]][evict_way_l]       <= mshr_paddr[i][PA_WIDTH-1 -: TAG_SIZE];
                                set_valids[mshr_index[i]][evict_way_l] <= 1'b1;
                                set_dirty[mshr_index[i]][evict_way_l]  <= (mshr_store_mask[i] != '0);
                                lru[mshr_index[i]]                     <= ~evict_way_l;
                                mshr_state[i]                          <= MS_IDLE;
                                mshr_store_mask[i]                     <= '0;
                                mshr_store_data[i]                     <= '0;
                                mshr_lq_id[i]                          <= '0;
                                mshr_is_load[i]                        <= 1'b0;
                                mshr_install_done                       = 1'b1;
                            end
                        end
                    end

                    // --- ACCEPT NEW REQUEST FROM LSQ ---
                    if (start_index) begin
                        curr_index       <= trace_vaddr[OFFSET_BITS +: INDEX_BITS];
                        curr_word_offset <= trace_vaddr[OFFSET_BITS-1 -: WORD_BITS];
                        curr_is_write    <= is_write;
                        curr_wdata       <= wdata;
                        curr_lq_id       <= lsq_lq_id_in;  // latch tag for response
                        state            <= 3'd1;
                    end
                end

                // -------------------------------------------------------------
                3'd1: begin  // TAG WAIT (TLB result pending)
                // -------------------------------------------------------------
                    if (start_tag) begin
                        if (hit) begin
                            // HIT
                            if (curr_is_write) begin
                                set_contents[curr_index][hit_way]
                                    [curr_word_offset*DATA_WIDTH +: DATA_WIDTH] <= curr_wdata;
                                set_dirty[curr_index][hit_way] <= 1'b1;
                            end else begin
                                // --- LSQ RESPONSE: load hit ---
                                lsq_resp_valid <= 1'b1;
                                lsq_resp_lq_id <= curr_lq_id;
                                lsq_resp_data  <=
                                    set_contents[curr_index][hit_way]
                                        [curr_word_offset*DATA_WIDTH +: DATA_WIDTH];
                            end
                            lru[curr_index] <= ~hit_way[0];
                            state <= 3'd0;

                        end else begin
                            // MISS — allocate MSHR
                            mshr_dup     = 1'b0;
                            mshr_dup_idx = '0;
                            for (int i = 0; i < NUM_MSHRS; i++)
                                if (!mshr_dup && mshr_state[i] != MS_IDLE
                                    && mshr_paddr[i] == incoming_line_paddr) begin
                                    mshr_dup     = 1'b1;
                                    mshr_dup_idx = i[$clog2(NUM_MSHRS)-1:0];
                                end

                            if (mshr_dup) begin
                                // Merge store data into existing MSHR slot
                                if (curr_is_write) begin
                                    mshr_store_data[mshr_dup_idx]
                                        [curr_word_offset*DATA_WIDTH +: DATA_WIDTH] <= curr_wdata;
                                    mshr_store_mask[mshr_dup_idx][curr_word_offset] <= 1'b1;
                                end
                                // For a duplicate load miss the lq_id of the
                                // first miss wins — the second load will be
                                // re-issued once the first broadcasts on CDB.
                            end else if (!mshr_full) begin
                                // Fresh MSHR allocation
                                mshr_paddr[mshr_free_idx]    <= incoming_line_paddr;
                                mshr_index[mshr_free_idx]    <= curr_index;
                                mshr_state[mshr_free_idx]    <= MS_UNRESOLVED;
                                mshr_lq_id[mshr_free_idx]    <= curr_lq_id;
                                mshr_is_load[mshr_free_idx]  <= !curr_is_write;
                                if (curr_is_write) begin
                                    mshr_store_data[mshr_free_idx]
                                        [curr_word_offset*DATA_WIDTH +: DATA_WIDTH] <= curr_wdata;
                                    mshr_store_mask[mshr_free_idx][curr_word_offset] <= 1'b1;
                                end
                            end
                            state <= 3'd0;
                        end
                    end
                end

            endcase

            // -----------------------------------------------------------------
            // L2 DATA RETURN — mark matching MSHR as resolved
            // -----------------------------------------------------------------
            for (integer i = 0; i < NUM_MSHRS; i++)
                if (mshr_state[i] == MS_UNRESOLVED
                    && l2_data_valid && l2_data_paddr == mshr_paddr[i]) begin
                    mshr_block[i] <= l2_data;
                    mshr_state[i] <= MS_RESOLVED;
                end

            // -----------------------------------------------------------------
            // WRITEBACK FIFO MANAGEMENT
            // -----------------------------------------------------------------
            if (wb_pop) begin
                wb_head  <= wb_head + 1'b1;
                wb_count <= wb_count - 1'b1;
            end

            if (wb_push) begin
                wb_paddr_q[wb_tail] <= wb_push_paddr;
                wb_data_q[wb_tail]  <= wb_push_data;
                wb_tail             <= wb_tail + 1'b1;
                wb_count            <= wb_count + (wb_pop ? '0 : 1'b1);
            end else if (wb_pop) begin
                wb_count <= wb_count - 1'b1;
            end

        end
    end

endmodule