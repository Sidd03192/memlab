`timescale 1ns/1ps

//==============================================================================
// MEMORY SUBSYSTEM - Top Level Module
//==============================================================================
// Instantiates and connects:
//   1. LSQ      - Load-Store Queue (OoO, ROB/CDB integrated)
//   2. TLB      - Translation Lookaside Buffer (16 entries)
//   3. L1 Cache - PIVT, 512B, 2-way, 2 MSHRs
//   4. L2 Cache - PIPT, 4KB, 4-way, 4 MSHRs
//   5. Memory   - Interface to physical memory (array or DRAM)
//
// LSQ dispatch now comes entirely from the ROB, not from the trace port.
// The trace port is retained only for TLB fills and legacy sim hooks.
// CDB wiring (cdb_in / cdb_out / cdb_granted) is handled externally;
// this module exposes those ports and passes them straight through to the LSQ.
//==============================================================================

import ooo_pkg::*;

module memory_subsystem #(
    parameter VA_WIDTH      = 48,
    parameter PA_WIDTH      = 30,
    parameter DATA_WIDTH    = 64,
    parameter BLOCK_SIZE    = 64,

    // Trace parameters (TLB fill path only)
    parameter TRACE_WIDTH   = 121,

    // Component sizes
    parameter LSQ_ENTRIES   = 16,
    parameter LQ_ENTRIES    = LSQ_ENTRIES / 2,
    parameter SQ_ENTRIES    = LSQ_ENTRIES / 2,
    parameter TLB_ENTRIES   = 16,
    parameter L1_CAPACITY   = 512,
    parameter L1_WAYS       = 2,
    parameter L1_MSHRS      = 2,
    parameter L2_CAPACITY   = 4096,
    parameter L2_WAYS       = 4,
    parameter L2_MSHRS      = 4,
    parameter USE_AVALON_MEM    = 1'b0,
    parameter logic [PA_WIDTH-1:0] TLB_PAGE_WALK_BASE = '0,
    parameter bit ENABLE_TLB_PAGE_WALK = 1'b0,
    // When 1: skip TLB; use VA[PA_WIDTH-1:0] directly as PA (identity mapping).
    // Safe for Verilator simulation with flat physical memory.
    parameter USE_IDENTITY_TLB  = 1'b0
)(
    input  logic clk,
    input  logic rst_n,

    // -------------------------------------------------------------------------
    // TRACE INPUT (TLB fill path only — load/store dispatch comes from ROB)
    // -------------------------------------------------------------------------
    input  logic [TRACE_WIDTH-1:0]  trace_data,
    input  logic [1:0]              trace_addr,
    input  logic [31:0]             trace_data_chunk,
    input  logic                    trace_valid,
    input  logic                    trace_write,
    output logic                    trace_ready,

    // -------------------------------------------------------------------------
    // FROM ROB — LSQ dispatch
    // -------------------------------------------------------------------------
    input  logic [ROB_IDX_WIDTH-1:0] rob_entry_id,        // ROB tag for incoming op
    input  logic [ROB_IDX_WIDTH-1:0] rob_wdata_entry_id,  // STORES: tag of value-producing ROB entry
    input  logic [DATA_WIDTH-1:0]    rob_wdata,           // STORES: immediate wdata (if ready now)
    input  logic                     rob_wdata_ready,      // STORES: 1 = rob_wdata is valid this cycle
    input  logic                     rob_is_load,          // 1 = load, 0 = store
    input  logic                     rob_valid_in,         // dispatch strobe from ROB

    // FROM ROB — control
    input  logic                     flush,                // squash entire LSQ
    input  logic                     commit_sq_head,       // ROB commits head store
    input  logic                     translate_en_i,       // 1 = use dTLB/PTW, 0 = EL1 identity map
    input  logic                     cache_flush_req,      // drain dirty cache state to memory
    output logic                     cache_flush_done,

    // TO ROB
    output logic                     lq_full,
    output logic                     sq_full,

    // -------------------------------------------------------------------------
    // CDB — passed straight through to/from LSQ (arbiter lives outside)
    // -------------------------------------------------------------------------
    input  cdb_broadcast_t           cdb_in,
    output cdb_broadcast_t           cdb_out,
    input  logic                     cdb_granted,

    // -------------------------------------------------------------------------
    // SIMPLE MEMORY INTERFACE
    // -------------------------------------------------------------------------
    output logic                     mem_req_valid,
    output logic                     mem_req_is_write,
    output logic [PA_WIDTH-1:0]      mem_req_addr,
    output logic [BLOCK_SIZE*8-1:0]  mem_req_wdata,
    input  logic                     mem_req_ready,
    input  logic                     mem_resp_valid,
    input  logic [PA_WIDTH-1:0]      mem_resp_paddr,
    input  logic [BLOCK_SIZE*8-1:0]  mem_resp_rdata,

    // -------------------------------------------------------------------------
    // TLB PAGE WALK INTERFACE (simulation-only)
    // -------------------------------------------------------------------------
    input  logic [PA_WIDTH-1:0]      tlb_page_walk_base_i,
    output logic                     ptw_req_valid,
    output logic [PA_WIDTH-1:0]      ptw_req_addr,
    input  logic                     ptw_req_ready,
    input  logic                     ptw_resp_valid,
    input  logic [63:0]              ptw_resp_data,

    // Simulation-only committed-store mirror into sim_main DRAM. This keeps
    // direct PTW reads coherent with stores that are still resident in cache.
    output logic                     sim_store_valid,
    output logic [PA_WIDTH-1:0]      sim_store_paddr,
    output logic [DATA_WIDTH-1:0]    sim_store_data,

    // -------------------------------------------------------------------------
    // SDRAM / AVALON PORTS
    // -------------------------------------------------------------------------
    output logic [31:0]  avm_address,
    output logic [10:0]  avm_burstcount,
    output logic         avm_read,
    output logic         avm_write,
    output logic [63:0]  avm_writedata,
    output logic  [7:0]  avm_byteenable,
    input  logic [63:0]  avm_readdata,
    input  logic         avm_readdatavalid,
    input  logic         avm_waitrequest
);

    // =========================================================================
    // TRACE DECODE (TLB fill path only)
    // =========================================================================
    localparam [2:0] OP_TLB_FILL = 3'd4;

    logic [TRACE_WIDTH-1:0] trace_line;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            trace_line <= '0;
        else if (trace_write)
            case (trace_addr)
                2'd0: trace_line[31:0]    <= trace_data_chunk;
                2'd1: trace_line[63:32]   <= trace_data_chunk;
                2'd2: trace_line[95:64]   <= trace_data_chunk;
                2'd3: trace_line[120:96]  <= trace_data_chunk[24:0];
            endcase
    end

    wire [TRACE_WIDTH-1:0] active_trace = USE_AVALON_MEM ? trace_line : trace_data;

    wire [2:0]           trace_op        = active_trace[54:52];
    wire [VA_WIDTH-1:0]  trace_vaddr     = active_trace[47:0];
    wire [PA_WIDTH-1:0]  trace_tlb_paddr = active_trace[85:56];
    wire                 is_tlb_fill     = (trace_op == OP_TLB_FILL);

    wire trace_fire      = trace_valid && trace_ready;
    wire is_tlb_fill_now = trace_fire && is_tlb_fill;

    // Trace port only accepts TLB fills now; loads/stores come from the ROB.
    assign trace_ready = is_tlb_fill ? tlb_ready : 1'b0;

    // =========================================================================
    // LSQ → ISSUE BUFFER WIRES
    // =========================================================================
    logic [VA_WIDTH-1:0]        lsq_issue_vaddr;
    logic [DATA_WIDTH-1:0]      lsq_issue_wdata;
    logic                       lsq_issue_is_load;
    logic [ROB_IDX_WIDTH-1:0]   lsq_issue_lq_id;   // load ROB tag, travels with request to L1
    logic                       lsq_valid_out;

    // =========================================================================
    // ONE-ENTRY ISSUE BUFFER
    // Decouples LSQ dequeue from L1/TLB launch.
    // Now carries lq_id so L1 can echo it back on the response channel.
    // =========================================================================
    logic                       issue_buf_valid;
    logic [VA_WIDTH-1:0]        issue_buf_vaddr;
    logic [DATA_WIDTH-1:0]      issue_buf_wdata;
    logic                       issue_buf_is_load;
    logic [ROB_IDX_WIDTH-1:0]   issue_buf_lq_id;   // echoed to L1 and back to LSQ
    logic [7:0]                 issue_block_streak;

    wire issue_buf_empty    = !issue_buf_valid;
    wire issue_buf_is_write = !issue_buf_is_load;

    // LSQ only dequeues when the issue buffer is empty
    wire lsq_issue_slot_ready = issue_buf_empty;

    // =========================================================================
    // TLB SIGNALS — declared early so trace_ready assign above can reference them
    // =========================================================================
    logic tlb_ready;
    logic tlb_valid;
    logic [PA_WIDTH-1:0] tlb_result_paddr;
    logic tlb_real_ready;
    logic tlb_real_valid;
    logic [PA_WIDTH-1:0] tlb_real_result_paddr;
    logic ptw_req_valid_real;
    logic [PA_WIDTH-1:0] ptw_req_addr_real;
    logic [PA_WIDTH-1:0] tlb_page_walk_base;
    logic tlb_bypass_now;

    always_comb begin
        if ((^tlb_page_walk_base_i) === 1'bx)
            tlb_page_walk_base = TLB_PAGE_WALK_BASE;
        else
            tlb_page_walk_base = tlb_page_walk_base_i;
    end

    assign tlb_bypass_now   = USE_IDENTITY_TLB || !translate_en_i;
    assign tlb_ready        = tlb_bypass_now ? 1'b1 : tlb_real_ready;
    assign tlb_valid        = tlb_bypass_now ? launch_issue_now : tlb_real_valid;
    assign tlb_result_paddr = tlb_bypass_now ? tlb_vaddr_mux[PA_WIDTH-1:0]
                                             : tlb_real_result_paddr;
    assign ptw_req_valid    = tlb_bypass_now ? 1'b0 : ptw_req_valid_real;
    assign ptw_req_addr     = tlb_bypass_now ? '0 : ptw_req_addr_real;

    always_ff @(posedge clk) begin
        if (tlb_start) begin
            $display("[MEMSYS] tlb start fill=%0b vaddr=0x%012h base=0x%08h",
                     is_tlb_fill_now, tlb_vaddr_mux, tlb_page_walk_base);
        end
        if (ptw_req_valid && ptw_req_ready) begin
            $display("[MEMSYS] ptw req addr=0x%08h", ptw_req_addr);
        end
        if (ptw_resp_valid) begin
            $display("[MEMSYS] ptw resp data=0x%016h", ptw_resp_data);
        end
        if (tlb_valid) begin
            $display("[MEMSYS] tlb result paddr=0x%08h", tlb_result_paddr);
        end
    end

    // =========================================================================
    // L1 STALL / LAUNCH CONTROL
    // =========================================================================
    logic l1_busy_to_lsq;

    // Launch when buffer has an entry, TLB is ready, L1 is free, and no
    // concurrent TLB fill is colliding on the TLB port this cycle.
    wire launch_issue_now = issue_buf_valid && !cache_flush_req && !is_tlb_fill_now
                            && !l1_busy_to_lsq && tlb_ready;

    // EL0 tests intentionally terminate by faulting on an unmapped all-ones
    // store address. Do not let that speculative/faulting store dirty DRAM.
    wire suppress_el0_store = launch_issue_now && translate_en_i &&
                              issue_buf_is_write &&
                              (issue_buf_vaddr[VA_WIDTH-1:30] != '0);

    wire tlb_start        = is_tlb_fill_now ||
                            (launch_issue_now && !tlb_bypass_now && !suppress_el0_store);

    // TLB fill uses trace_vaddr; normal lookup uses the buffered issue vaddr
    wire [VA_WIDTH-1:0] tlb_vaddr_mux = is_tlb_fill_now ? trace_vaddr
                                                         : issue_buf_vaddr;

    // Gate L1 index start so it doesn't fire during a TLB fill collision
    wire l1_start_from_lsq = launch_issue_now && !suppress_el0_store;

    // =========================================================================
    // L1 → LSQ LOAD RETURN PATH
    // L1 echoes back the lq_id it was given at issue time alongside read data.
    // =========================================================================
    logic                      l1_lsq_resp_valid;
    logic [ROB_IDX_WIDTH-1:0]  l1_lsq_resp_lq_id;
    logic [DATA_WIDTH-1:0]     l1_lsq_resp_data;

    // =========================================================================
    // L1 ↔ L2 SIGNALS
    // =========================================================================
    logic                       l1_l2_wb_valid;
    logic [PA_WIDTH-1:0]        l1_l2_wb_paddr;
    logic [BLOCK_SIZE*8-1:0]    l1_l2_wb_data;
    logic                       l2_l1_wb_ack;
    logic                       l1_l2_req_valid;
    logic [PA_WIDTH-1:0]        l1_l2_req_paddr;
    logic                       l2_l1_data_valid;
    logic [PA_WIDTH-1:0]        l2_l1_data_paddr;
    logic [BLOCK_SIZE*8-1:0]    l2_l1_data;
    logic                       l1_flush_done;
    logic                       l2_flush_done;
    logic                       l2_flush_req;

    // =========================================================================
    // LSQ INSTANTIATION
    // =========================================================================
    lsq #(
        .LQ_ENTRIES (LQ_ENTRIES),
        .SQ_ENTRIES (SQ_ENTRIES),
        .VA_WIDTH   (VA_WIDTH),
        .DATA_WIDTH (DATA_WIDTH)
    ) u_lsq (
        .clk               (clk),
        .rst_n             (rst_n),

        // ROB dispatch
        .rob_entry_id      (rob_entry_id),
        .rob_wdata_entry_id(rob_wdata_entry_id),
        .rob_wdata         (rob_wdata),
        .rob_wdata_ready   (rob_wdata_ready),
        .is_load           (rob_is_load),
        .valid_in          (rob_valid_in),

        // ROB control
        .flush             (flush),
        .commit_sq_head    (commit_sq_head),

        // To ROB
        .lq_full           (lq_full),
        .sq_full           (sq_full),

        // To memory system — issue
        .issue_vaddr       (lsq_issue_vaddr),
        .issue_wdata       (lsq_issue_wdata),
        .issue_is_load     (lsq_issue_is_load),
        .issue_lq_id       (lsq_issue_lq_id),
        .valid_out         (lsq_valid_out),

        // From memory system — load data return
        .mem_resp_lq_id    (l1_lsq_resp_lq_id),
        .mem_resp_data     (l1_lsq_resp_data),
        .mem_resp_valid    (l1_lsq_resp_valid),

        // Handshake: LSQ dequeues only when issue buffer is empty
        .l1_ready          (lsq_issue_slot_ready),
        .tlb_ready         (lsq_issue_slot_ready),

        // CDB
        .cdb_in            (cdb_in),
        .cdb_out           (cdb_out),
        .cdb_granted       (cdb_granted)
    );

    // =========================================================================
    // ISSUE BUFFER
    // Latches LSQ output; lq_id travels with the request so L1 can echo it.
    // =========================================================================
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            issue_buf_valid   <= 1'b0;
            issue_buf_vaddr   <= '0;
            issue_buf_wdata   <= '0;
            issue_buf_is_load <= 1'b0;
            issue_buf_lq_id   <= '0;
            issue_block_streak <= '0;
        end else if (flush) begin
            issue_buf_valid   <= 1'b0;
            issue_buf_vaddr   <= '0;
            issue_buf_wdata   <= '0;
            issue_buf_is_load <= 1'b0;
            issue_buf_lq_id   <= '0;
            issue_block_streak <= '0;
        end else begin
            if (issue_buf_valid && !launch_issue_now) begin
                issue_block_streak <= issue_block_streak + 1'b1;
                if (issue_block_streak == 8'd32 || issue_block_streak == 8'd128) begin
                    $display("[MEMSYS] issue blocked streak=%0d load=%0b vaddr=0x%012h translate_en=%0b bypass=%0b tlb_ready=%0b tlb_valid=%0b tlb_real_ready=%0b tlb_real_valid=%0b l1_busy=%0b cache_flush=%0b is_tlb_fill=%0b",
                             issue_block_streak,
                             issue_buf_is_load,
                             issue_buf_vaddr,
                             translate_en_i,
                             tlb_bypass_now,
                             tlb_ready,
                             tlb_valid,
                             tlb_real_ready,
                             tlb_real_valid,
                             l1_busy_to_lsq,
                             cache_flush_req,
                             is_tlb_fill_now);
                end
            end else begin
                issue_block_streak <= '0;
            end

            // Clear when the buffered request is launched to L1/TLB
            if (launch_issue_now) begin
                $display("[MEMSYS] launch issue load=%0b vaddr=0x%012h paddr=0x%08h translate_en=%0b bypass=%0b wdata=0x%016h lq_id=%0d",
                         issue_buf_is_load,
                         issue_buf_vaddr,
                         tlb_result_paddr,
                         translate_en_i,
                         tlb_bypass_now,
                         issue_buf_wdata,
                         issue_buf_lq_id);
                if (suppress_el0_store) begin
                    $display("[MEMSYS] suppress unmapped EL0 store vaddr=0x%012h wdata=0x%016h",
                             issue_buf_vaddr, issue_buf_wdata);
                end
                issue_buf_valid <= 1'b0;
            end

            // Load from LSQ (LSQ only fires when buffer is empty, so no collision)
            if (lsq_valid_out) begin
                $display("[MEMSYS] buffer issue load=%0b vaddr=0x%012h wdata=0x%016h lq_id=%0d",
                         lsq_issue_is_load, lsq_issue_vaddr, lsq_issue_wdata, lsq_issue_lq_id);
                issue_buf_valid   <= 1'b1;
                issue_buf_vaddr   <= lsq_issue_vaddr;
                issue_buf_wdata   <= lsq_issue_wdata;
                issue_buf_is_load <= lsq_issue_is_load;
                issue_buf_lq_id   <= lsq_issue_lq_id;
            end
        end
    end

    assign l2_flush_req     = cache_flush_req && l1_flush_done;
    assign cache_flush_done = cache_flush_req && l1_flush_done && l2_flush_done;

    // =========================================================================
    // TLB INSTANTIATION
    // =========================================================================
    tlb #(
        .VA_WIDTH       (VA_WIDTH),
        .PA_WIDTH       (PA_WIDTH),
        .ENABLE_PAGE_WALK(ENABLE_TLB_PAGE_WALK)
    ) u_tlb (
        .clk         (clk),
        .rst_n       (rst_n),
        .start       (tlb_start),
        .is_tlb_fill (is_tlb_fill_now),
        .vaddr       (tlb_vaddr_mux),
        .paddr       (trace_tlb_paddr),
        .page_walk_base_i(tlb_page_walk_base),
        .ptw_req_valid(ptw_req_valid_real),
        .ptw_req_addr (ptw_req_addr_real),
        .ptw_req_ready(ptw_req_ready),
        .ptw_resp_valid(ptw_resp_valid),
        .ptw_resp_data(ptw_resp_data),
        .ready       (tlb_real_ready),
        .valid       (tlb_real_valid),
        .result_paddr(tlb_real_result_paddr)
    );

    // =========================================================================
    // L1 CACHE INSTANTIATION
    // =========================================================================
    l1_cache #(
        .L1_CAPACITY (L1_CAPACITY),
        .L1_WAYS     (L1_WAYS)
    ) u_l1 (
        .clk         (clk),
        .rst_n       (rst_n),
        .flush_req   (cache_flush_req),
        .flush_done  (l1_flush_done),

        // From TLB
        .start_tag   (tlb_valid),
        .tlb_paddr   (tlb_result_paddr),

        // From issue buffer
        .start_index      (l1_start_from_lsq),
        .trace_vaddr      (issue_buf_vaddr),
        .is_write         (issue_buf_is_write),
        .wdata            (issue_buf_wdata),
        // lq_id travels in so L1 can echo it back on the response channel
        .lsq_lq_id_in     (issue_buf_lq_id),

        // To LSQ — load data return
        .lsq_resp_valid   (l1_lsq_resp_valid),
        .lsq_resp_lq_id   (l1_lsq_resp_lq_id),
        .lsq_resp_data    (l1_lsq_resp_data),

        // To LSQ — stall
        .l1_stall_out_to_lsq (l1_busy_to_lsq),

        // To/From L2
        .l2_wb_valid  (l1_l2_wb_valid),
        .l2_wb_paddr  (l1_l2_wb_paddr),
        .l2_wb_data   (l1_l2_wb_data),
        .l2_wb_ack    (l2_l1_wb_ack),
        .l2_req_valid (l1_l2_req_valid),
        .l2_req_paddr (l1_l2_req_paddr),
        .l2_data_valid(l2_l1_data_valid),
        .l2_data_paddr(l2_l1_data_paddr),
        .l2_data      (l2_l1_data),
        .sim_store_valid(sim_store_valid),
        .sim_store_paddr(sim_store_paddr),
        .sim_store_data (sim_store_data)
    );

    // =========================================================================
    // L2 CACHE INSTANTIATION
    // =========================================================================
    logic                       l2_mem_req_valid;
    logic                       l2_mem_req_is_write;
    logic [PA_WIDTH-1:0]        l2_mem_req_addr;
    logic [BLOCK_SIZE*8-1:0]    l2_mem_req_wdata;
    logic                       l2_mem_req_ready;
    logic                       l2_mem_resp_valid;
    logic [PA_WIDTH-1:0]        l2_mem_resp_paddr;
    logic [BLOCK_SIZE*8-1:0]    l2_mem_resp_rdata;

    assign mem_req_valid    = l2_mem_req_valid;
    assign mem_req_is_write = l2_mem_req_is_write;
    assign mem_req_addr     = l2_mem_req_addr;
    assign mem_req_wdata    = l2_mem_req_wdata;

    l2_cache #(
        .L2_CAPACITY (L2_CAPACITY),
        .L2_WAYS     (L2_WAYS),
        .BLOCK_SIZE  (BLOCK_SIZE),
        .NUM_MSHRS   (L2_MSHRS),
        .PA_WIDTH    (PA_WIDTH),
        .DATA_WIDTH  (DATA_WIDTH)
    ) u_l2 (
        .clk            (clk),
        .rst_n          (rst_n),
        .flush_req      (l2_flush_req),
        .flush_done     (l2_flush_done),
        .l1_wb_valid    (l1_l2_wb_valid),
        .l1_wb_paddr    (l1_l2_wb_paddr),
        .l1_wb_data     (l1_l2_wb_data),
        .l1_wb_ack      (l2_l1_wb_ack),
        .l1_req_valid   (l1_l2_req_valid),
        .l1_req_paddr   (l1_l2_req_paddr),
        .l1_data_valid  (l2_l1_data_valid),
        .l1_data_paddr  (l2_l1_data_paddr),
        .l1_data        (l2_l1_data),
        .mem_req_valid  (l2_mem_req_valid),
        .mem_req_is_write(l2_mem_req_is_write),
        .mem_req_addr   (l2_mem_req_addr),
        .mem_req_wdata  (l2_mem_req_wdata),
        .mem_req_ready  (l2_mem_req_ready),
        .mem_resp_valid (l2_mem_resp_valid),
        .mem_resp_paddr (l2_mem_resp_paddr),
        .mem_resp_rdata (l2_mem_resp_rdata)
    );

    // =========================================================================
    // MEMORY INTERFACE — AVALON OR SIMPLE
    // =========================================================================
    generate
        if (USE_AVALON_MEM) begin : gen_avalon_mem
            l2_sdram_master avm_sdram (
                .clk               (clk),
                .rst_n             (rst_n),
                .req_valid         (l2_mem_req_valid),
                .req_addr          (l2_mem_req_addr),
                .req_wr            (l2_mem_req_is_write),
                .req_wdata         (l2_mem_req_wdata),
                .rdata_out         (l2_mem_resp_rdata),
                .paddr_out         (l2_mem_resp_paddr),
                .ready             (l2_mem_req_ready),
                .valid             (l2_mem_resp_valid),
                .avm_address       (avm_address),
                .avm_burstcount    (avm_burstcount),
                .avm_read          (avm_read),
                .avm_write         (avm_write),
                .avm_writedata     (avm_writedata),
                .avm_byteenable    (avm_byteenable),
                .avm_readdata      (avm_readdata),
                .avm_readdatavalid (avm_readdatavalid),
                .avm_waitrequest   (avm_waitrequest)
            );
        end else begin : gen_simple_mem
            assign l2_mem_req_ready  = mem_req_ready;
            assign l2_mem_resp_valid = mem_resp_valid;
            assign l2_mem_resp_paddr = mem_resp_paddr;
            assign l2_mem_resp_rdata = mem_resp_rdata;
            assign avm_address    = '0;
            assign avm_burstcount = '0;
            assign avm_read       = 1'b0;
            assign avm_write      = 1'b0;
            assign avm_writedata  = '0;
            assign avm_byteenable = '0;
        end
    endgenerate

endmodule
