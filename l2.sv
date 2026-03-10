`timescale 1ns/1ps

module l2_cache #(
    parameter L2_CAPACITY   = 4096,
    parameter L2_WAYS       = 4,
    parameter BLOCK_SIZE    = 64,
    parameter L1_MSHRS      = 2,
    parameter L2_MSHRS      = 4,
    parameter PA_WIDTH      = 30,
    parameter DATA_WIDTH    = 64,
    parameter TAG_SIZE      = 20
)(
    input   logic                                   clk,
    input   logic                                   rst_n,

    // eviction buffer from L1 to L2
    input   logic                                   evict_in,
    input   logic [PA_WIDTH-1:0]                    e_paddr_in,
    input   logic                                   e_dirty_in,
    input   logic [BLOCK_SIZE*8-1:0]                e_data_in,

    // input from L1 MSHRs — unpacked so always_ff variable indexing works
    input   logic                                   miss_in     [L1_MSHRS],
    input   logic [PA_WIDTH-1:0]                    paddr_in    [L1_MSHRS],
    input   logic                                   w_in        [L1_MSHRS],
    input   logic [BLOCK_SIZE*8-1:0]                data_in     [L1_MSHRS],

    // output to L1 MSHRs — unpacked
    output  logic                                   empty_out       [L1_MSHRS],
    output  logic                                   resolve_out     [L1_MSHRS],
    output  logic [BLOCK_SIZE*8-1:0]                superior_data_out [L1_MSHRS]
);


    localparam int L2_SETS = L2_CAPACITY / (BLOCK_SIZE * L2_WAYS);
    localparam int OFFSET_BITS = $clog2(BLOCK_SIZE);
    localparam int INDEX_BITS = $clog2(L2_SETS);
    localparam int TAG_BITS = PA_WIDTH - INDEX_BITS - OFFSET_BITS;
    localparam int WAY_BITS = $clog2(L2_WAYS);
    localparam int L2_MSHR_BITS = $clog2(L2_MSHRS);
    localparam int L1_MSHR_BITS = $clog2(L1_MSHRS);


    // cache state — all unpacked for variable indexing
    logic [BLOCK_SIZE * 8 - 1:0]    contents    [L2_SETS][L2_WAYS];
    logic [TAG_BITS - 1:0]          tags        [L2_SETS][L2_WAYS];
    logic                           lru_mat     [L2_SETS][L2_WAYS][L2_WAYS];
    logic [WAY_BITS-1:0]            lru         [L2_SETS];
    logic                           valid       [L2_SETS][L2_WAYS];
    logic                           dirty       [L2_SETS][L2_WAYS];

    // lru[i] = way with all-zero row in lru_mat[i] (least recently used)
    logic row_empty;
    always_comb begin
        for (int i = 0; i < L2_SETS; i++) begin
            lru[i] = '0;
            for (int j = 0; j < L2_WAYS; j++) begin
                row_empty = 1'b1;
                for (int k = 0; k < L2_WAYS; k++)
                    row_empty = row_empty & ~lru_mat[i][j][k];
                if (row_empty)
                    lru[i] = j[WAY_BITS-1:0];
            end
        end
    end

    // L1 miss input parsing
    logic                   miss;
    logic [L1_MSHR_BITS-1:0] miss_mshr_index;
    logic [PA_WIDTH-1:0]    miss_paddr;
    logic                   miss_w;
    logic [BLOCK_SIZE*8-1:0] miss_data;
    logic [INDEX_BITS-1:0]  miss_index;
    logic [TAG_BITS-1:0]    miss_tag;

    always_comb begin
        miss            = 1'b0;
        miss_mshr_index = '0;
        miss_paddr      = '0;
        miss_w          = 1'b0;
        miss_data       = '0;
        for (int i = 0; i < L1_MSHRS; i++) begin
            if (miss_in[i]) begin
                miss            = 1'b1;
                miss_mshr_index = i[L1_MSHR_BITS-1:0];
                miss_paddr      = paddr_in[i];
                miss_w          = w_in[i];
                miss_data       = data_in[i];
            end
        end
        miss_index = miss_paddr[OFFSET_BITS+INDEX_BITS-1:OFFSET_BITS];
        miss_tag   = miss_paddr[PA_WIDTH-1:PA_WIDTH-TAG_BITS];
    end

    logic [TAG_BITS-1:0]    e_tag;
    logic [INDEX_BITS-1:0]  e_index;
    assign e_tag   = e_paddr_in[PA_WIDTH-1:PA_WIDTH-TAG_BITS];
    assign e_index = e_paddr_in[OFFSET_BITS+INDEX_BITS-1:OFFSET_BITS];

    logic               hit;
    logic [WAY_BITS-1:0] hit_way;
    logic               e_hit;
    logic [WAY_BITS-1:0] e_hit_way;
    always_comb begin
        hit       = 1'b0;
        hit_way   = '0;
        e_hit     = 1'b0;
        e_hit_way = '0;
        for (int w = 0; w < L2_WAYS; w++) begin
            if (valid[miss_index][w] && tags[miss_index][w] == miss_tag) begin
                hit     = 1'b1;
                hit_way = w[WAY_BITS-1:0];
            end
            if (valid[e_index][w] && tags[e_index][w] == e_tag) begin
                e_hit     = 1'b1;
                e_hit_way = w[WAY_BITS-1:0];
            end
        end
    end


    // L2 -> memory eviction buffer
    logic                    n_evict_in;
    logic [PA_WIDTH-1:0]     n_e_paddr_in;
    logic                    n_e_dirty_in;
    logic [BLOCK_SIZE*8-1:0] n_e_data_in;

    // mainmem input/output — already unpacked
    logic                    mm_miss_in          [L2_MSHRS];
    logic [PA_WIDTH-1:0]     mm_paddr_in         [L2_MSHRS];
    logic                    mm_w_in             [L2_MSHRS];
    logic [BLOCK_SIZE*8-1:0] mm_data_in          [L2_MSHRS];
    logic                    mm_empty_out        [L2_MSHRS];
    logic                    mm_resolve_out      [L2_MSHRS];
    logic [BLOCK_SIZE*8-1:0] mm_superior_data_out[L2_MSHRS];
    logic                    mm_stall_out;
    logic                    free_mshr_valid;
    logic [L2_MSHR_BITS-1:0] free_mshr_idx;

    always_comb begin
        mm_stall_out    = 1'b1;
        free_mshr_valid = 1'b0;
        free_mshr_idx   = '0;
        for (int i = L2_MSHRS-1; i >= 0; i--) begin
            if (mm_empty_out[i]) begin
                mm_stall_out    = 1'b0;
                free_mshr_valid = 1'b1;
                free_mshr_idx   = i[L2_MSHR_BITS-1:0];
            end
        end
    end

    mainmem mm(
        .clk(clk),
        .rst_n(rst_n),

        .evict_in(n_evict_in),
        .e_paddr_in(n_e_paddr_in),
        .e_dirty_in(n_e_dirty_in),
        .e_data_in(n_e_data_in),

        .miss_in(mm_miss_in),
        .paddr_in(mm_paddr_in),
        .w_in(mm_w_in),
        .data_in(mm_data_in),

        .empty_out(mm_empty_out),
        .resolve_out(mm_resolve_out),
        .superior_data_out(mm_superior_data_out),
        .stall_out()
    );

    // resolution logic
    logic                    res;
    logic [L2_MSHR_BITS-1:0] res_mshr_index;
    logic [INDEX_BITS-1:0]   res_index;
    logic [TAG_BITS-1:0]     res_tag;
    logic [WAY_BITS-1:0]     res_way;

    always_comb begin
        res            = 1'b0;
        res_mshr_index = '0;
        res_index      = '0;
        res_tag        = '0;
        res_way        = '0;
        for (int i = 0; i < L2_MSHRS; i++) begin
            if (mm_resolve_out[i]) begin
                res            = 1'b1;
                res_mshr_index = i[L2_MSHR_BITS-1:0];
                res_index      = mm_paddr_in[i][INDEX_BITS+OFFSET_BITS-1:OFFSET_BITS];
                res_tag        = mm_paddr_in[i][PA_WIDTH-1:PA_WIDTH-TAG_BITS];
            end
        end
        // find which way holds res_tag at res_index (if any; else use LRU)
        res_way = lru[res_index];
        for (int w = 0; w < L2_WAYS; w++) begin
            if (tags[res_index][w] == res_tag && valid[res_index][w])
                res_way = w[WAY_BITS-1:0];
        end
    end


    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            n_evict_in <= 1'b0;
            for (int i = 0; i < L1_MSHRS; i++) begin
                empty_out[i]          <= 1'b1;
                resolve_out[i]        <= 1'b0;
                superior_data_out[i]  <= '0;
            end
            for (int i = 0; i < L2_MSHRS; i++) begin
                mm_miss_in[i]  <= 1'b0;
                mm_paddr_in[i] <= '0;
                mm_w_in[i]     <= 1'b0;
                mm_data_in[i]  <= '0;
            end
            for (int s = 0; s < L2_SETS; s++)
                for (int w = 0; w < L2_WAYS; w++) begin
                    valid[s][w] <= 1'b0;
                    dirty[s][w] <= 1'b0;
                    for (int k = 0; k < L2_WAYS; k++)
                        lru_mat[s][w][k] <= 1'b0;
                end
        end else begin
            // default: clear resolve strobes and miss signals
            for (int i = 0; i < L1_MSHRS; i++)
                resolve_out[i] <= 1'b0;
            for (int i = 0; i < L2_MSHRS; i++)
                mm_miss_in[i] <= 1'b0;
            n_evict_in <= 1'b0;

            if (evict_in && e_hit && e_dirty_in) begin
                contents[e_index][e_hit_way] <= e_data_in;
                for (int k = 0; k < L2_WAYS; k++) begin
                    lru_mat[e_index][e_hit_way][k] <= 1'b1;
                    lru_mat[e_index][k][e_hit_way] <= 1'b0;
                end
            end

            if (res) begin
                n_evict_in   <= 1'b1;
                n_e_paddr_in <= {tags[res_index][res_way], res_index[INDEX_BITS-1:0], {OFFSET_BITS{1'b0}}};
                n_e_dirty_in <= dirty[res_index][res_way];
                n_e_data_in  <= contents[res_index][res_way];

                dirty[res_index][res_way]    <= 1'b0;
                valid[res_index][res_way]    <= 1'b1;
                contents[res_index][res_way] <= mm_superior_data_out[res_mshr_index];
                tags[res_index][res_way]     <= res_tag;

                // forward resolution to L1 MSHR — find which L1 MSHR owns this address
                for (int i = 0; i < L1_MSHRS; i++) begin
                    if (!empty_out[i] &&
                        paddr_in[i][PA_WIDTH-1:PA_WIDTH-TAG_BITS] == res_tag &&
                        paddr_in[i][OFFSET_BITS+INDEX_BITS-1:OFFSET_BITS] == res_index)
                    begin
                        resolve_out[i]       <= 1'b1;
                        superior_data_out[i] <= mm_superior_data_out[res_mshr_index];
                        empty_out[i]         <= 1'b1;
                    end
                end
            end

            if (miss) begin
                empty_out[miss_mshr_index] <= 1'b0;
                if (hit) begin
                    if (miss_w) begin
                        contents[miss_index][hit_way] <= miss_data;
                        superior_data_out[miss_mshr_index] <= miss_data;
                    end else begin
                        superior_data_out[miss_mshr_index] <= contents[miss_index][hit_way];
                    end
                    resolve_out[miss_mshr_index] <= 1'b1;
                    empty_out[miss_mshr_index]   <= 1'b1;
                    for (int k = 0; k < L2_WAYS; k++) begin
                        lru_mat[miss_index][hit_way][k] <= 1'b1;
                        lru_mat[miss_index][k][hit_way] <= 1'b0;
                    end
                end else begin
                    if (free_mshr_valid) begin
                        mm_miss_in[free_mshr_idx]  <= 1'b1;
                        mm_paddr_in[free_mshr_idx] <= miss_paddr;
                        mm_w_in[free_mshr_idx]     <= miss_w;
                        mm_data_in[free_mshr_idx]  <= miss_data;
                    end
                end
            end

        end
    end


endmodule
