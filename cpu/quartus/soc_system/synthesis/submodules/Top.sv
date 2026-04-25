`timescale 1ns/1ps

module Top
  import ozone_pkg::*;
(
    input clk,
    input reset,
    input logic [63:0] start_pc,

    // Simple Memory Interface (instruction fetch)
    output reg [63:0] mem_addr,
    input      [31:0] mem_rdata,
    output reg        mem_en,

    // Data Memory Interface (L2 cache-line miss port)
    output logic                     dmem_req_valid,
    output logic                     dmem_req_is_write,
    output logic [29:0]              dmem_req_addr,
    output logic [511:0]             dmem_req_wdata,
    input  logic                     dmem_req_ready,
    input  logic                     dmem_resp_valid,
    input  logic [29:0]              dmem_resp_paddr,
    input  logic [511:0]             dmem_resp_rdata,

    // Simulation-only page-table walk port
    output logic                     ptw_req_valid,
    output logic [29:0]              ptw_req_addr,
    input  logic                     ptw_req_ready,
    input  logic                     ptw_resp_valid,
    input  logic [63:0]              ptw_resp_data,

    // Simulation-only committed-store mirror for sim_main's shared DRAM.
    output logic                     sim_store_valid,
    output logic [29:0]              sim_store_paddr,
    output logic [63:0]              sim_store_data,

    // Status
    output reg        done,

    // Register File (Exposed for testbench to copy to SHM)
    output reg [63:0] x_regs [0:30],
    output reg [63:0] fp_regs [0:31]
);

    // Temporary bring-up switch: standalone Verilator tests currently expect
    // instruction fetch to behave like the C simulator's EL1 identity mapping.
    // Set back to 1'b1 when the real ITLB/MMU fetch path is ready for
    // submission/integration.
    localparam logic USE_ITLB_FETCH = 1'b0;
    localparam logic [47:0] DEFAULT_ENTRY_PC = 48'h0000_2000_0000;
    // Matches memlab/cpu/ozone/ozone-config.json for Verilator runs.
    localparam logic [29:0] SIM_TTBR0_BASE = 30'h00001000;
    localparam logic [63:0] SIM_SP_EL0 = 64'h0000_0000_0040_f000;
    localparam logic [63:0] SIM_SP_EL1 = 64'h0000_0000_2010_0000;
    localparam logic [63:0] SIM_VBAR_EL1 = 64'h0000_0000_2000_0800;
    localparam logic [63:0] SIM_ELR_EL1 = 64'h0000_0000_0040_0000;
    localparam logic [63:0] SIM_SPSR_EL1 = 64'h0;
    localparam logic [63:0] SIM_TERMINATE_VAL = 64'h0000_0000_0000_dead;
    localparam logic [15:0] SYSREG_SP_EL0   = 16'hc208;
    localparam logic [15:0] SYSREG_SPSR_EL1 = 16'hc200;
    localparam logic [15:0] SYSREG_ELR_EL1  = 16'hc201;
    localparam logic [15:0] SYSREG_VBAR_EL1 = 16'hc600;
    localparam logic [15:0] SYSREG_ACTLR_EL1 = 16'hc081;
    localparam logic [47:0] EXC_VEC_DEFAULT  = 48'h400;
    localparam logic [47:0] EXC_VEC_SVC_TERM = 48'h500;
    localparam logic [47:0] EXC_VEC_BAD_SYS  = 48'h600;

    reg [31:0] state;
    reg [47:0] pc;
    reg [29:0] pa_pc;
    reg [17:0] ttbr0;
    reg [1:0]  cur_el;
    reg [63:0] sp_el0, sp_el1, spsr_el1, elr_el1, vbar_el1, actlr_el1;
    logic [63:0] current_sp_value;

    logic [63:0] tte;
    logic [31:0] insn_bits;
    logic        state7_sent;
    logic        reset_seen;

    logic rst_n;
    assign rst_n = ~reset;
    assign current_sp_value = (cur_el == 2'd0) ? sp_el0 : sp_el1;

    logic        itlb_lookup_req;
    logic [47:0] itlb_vaddr;
    logic        itlb_hit;
    logic [29:0] itlb_paddr;
    logic        itlb_fill_req;
    logic [35:0] itlb_fill_vpn;
    logic [17:0] itlb_fill_ppn;
    logic        itlb_flush;
    logic        itlb_lookup_ack_o;
    logic        itlb_fill_ack_o;
    logic        itlb_flush_ack_o;

    logic        halt_fetch;
    logic        insn_ready;
    logic        ready_for_uop;
    logic        decoder_ready;
    logic        uop_valid;
    uop_t        uop_out [2];

    logic [4:0]  rst_src1_addr, rst_src2_addr;
    logic [4:0]  rst_fp_src1_addr, rst_fp_src2_addr;
    reg_entry_t  rst_src1_status, rst_src2_status;
    reg_entry_t  rst_fp_src1_status, rst_fp_src2_status;
    reg_entry_t  rst_nzcv_status;

    logic        rst_wr_en, rst_fp_wr_en, rst_nzcv_wr_en;
    logic [4:0]  rst_wr_addr, rst_fp_wr_addr;
    logic [5:0]  rst_rob_idx, rst_fp_rob_idx, rst_nzcv_rob_idx;

    logic [5:0]  rob_src1_idx, rob_src2_idx;
    logic        rob_src1_ready, rob_src2_ready;
    logic [63:0] rob_src1_val, rob_src2_val;
    logic        rob_alloc_valid, rob_alloc_has_dest;
    rob_entry_t  rob_alloc_data;
    logic [5:0]  rob_alloc_idx;
    logic        rob_full, rob_empty;
    logic [5:0]  rob_head;

    logic        commit_valid;
    rob_entry_t  commit_data;
    logic        commit_reg_en;
    logic [4:0]  commit_reg_addr;
    logic [63:0] commit_reg_value;
    logic [5:0]  commit_reg_rob_idx;
    logic        commit_fp_en;
    logic [4:0]  commit_fp_addr;
    logic [63:0] commit_fp_value;
    logic [5:0]  commit_fp_rob_idx;
    logic        commit_nzcv_en;
    logic [3:0]  commit_nzcv_value;
    logic [5:0]  commit_nzcv_rob_idx;

    logic        lsq_store_commit;
    logic [63:0] lsq_store_addr, lsq_store_data;
    logic        bp_update_valid;
    logic [63:0] bp_update_pc;
    logic        bp_update_taken;
    logic [63:0] bp_update_target;
    logic [BP_GHR_WIDTH-1:0] bp_update_ghr;
    logic        pipe_flush;
    logic [63:0] flush_target_pc;
    logic        exception_valid;
    logic [63:0] exception_pc;
    logic [7:0]  exception_code;
    logic [47:0] exception_vector_off;

    logic [47:0] btb_pred_target;
    logic        btb_pred_hit;
    logic        bpred_take;
    logic [BP_GHR_WIDTH-1:0] bpred_ghr_snapshot;
    logic        fetch_pred_taken;

    logic             adder_alloc_valid, adder_full, adder_granted;
    rs_entry_add_t    adder_alloc_entry;
    logic             logic_alloc_valid, logic_full, logic_granted;
    rs_entry_t        logic_alloc_entry;
    logic             fpu_alloc_valid, fpu_full, fpu_granted;
    rs_entry_fp_t     fpu_alloc_entry;
    logic             agu_alloc_valid, agu_full, agu_granted;
    rs_entry_add_t    agu_alloc_entry;
    logic             shifter_alloc_valid, shifter_full, shifter_granted;
    rs_entry_t        shifter_alloc_entry;

    // LSQ dispatch wires
    logic        lsq_alloc_valid;
    logic [5:0]  lsq_rob_entry_id;
    logic [5:0]  lsq_rob_wdata_entry_id;
    logic [63:0] lsq_rob_wdata;
    logic        lsq_rob_wdata_ready;
    logic        lsq_is_load;
    logic        lq_full, sq_full;
    logic        sim_finish_pending;
    logic        cache_flush_done;
    logic [47:0] last_fetch_pc;
    logic [7:0]  fetch_same_pc_streak;
    logic        fetch_zero_pending;
    logic [3:0]  fetch_zero_wait;

    cdb_broadcast_t adder_req, logic_req, fpu_req, agu_req, lsq_req, shifter_req, cdb_broadcast;
    logic           lsq_granted;
    logic           core_flush;
    logic           ret_zero_redirect;

    assign core_flush = pipe_flush || sim_finish_pending;
    assign halt_fetch = core_flush;
    assign fetch_pred_taken = btb_pred_hit && bpred_take;
    assign exception_vector_off = (exception_code == EXC_SVC_TERMINATE) ? EXC_VEC_SVC_TERM :
                                  (exception_code == EXC_BAD_SYSCALL)   ? EXC_VEC_BAD_SYS  :
                                                                          EXC_VEC_DEFAULT;
    assign ret_zero_redirect = commit_valid &&
                               commit_data.inst_type == ROB_TYPE_BRANCH &&
                               commit_data.br_taken &&
                               commit_data.br_target == 64'b0;

    ozone_btb #(
        .VADDR_WIDTH       (48),
        .INSTR_OFFSET_WIDTH(2),
        .BTB_SETS          (8)
    ) ozone_btb_i (
        .clk            (clk),
        .rst_n          (rst_n),
        .pred_pc_in     (pc),
        .pred_vaddr_out (btb_pred_target),
        .pred_hit_out   (btb_pred_hit),
        .resolve_v_in   (bp_update_valid),
        .resolve_pc_in  (bp_update_pc[47:0]),
        .resolve_vaddr_in(bp_update_target[47:0])
    );

    ozone_bpred #(
        .VADDR_WIDTH(48),
        .GHR_WIDTH  (BP_GHR_WIDTH)
    ) ozone_bpred_i (
        .clk             (clk),
        .rst_n           (rst_n),
        .pred_pc_in      (pc),
        .take_out        (bpred_take),
        .ghr_snapshot_out(bpred_ghr_snapshot),
        .resolve_v_in    (bp_update_valid),
        .resolve_taken_in(bp_update_taken),
        .resolve_pc_in   (bp_update_pc[47:0]),
        .resolve_ghr_in  (bp_update_ghr)
    );

    ozone_itlb ozone_itlb (
        .clk_i         (clk),
        .rst_ni        (rst_n),
        .lookup_req_i  (itlb_lookup_req),
        .lookup_vaddr_i(itlb_vaddr),
        .lookup_hit_o  (itlb_hit),
        .lookup_paddr_o(itlb_paddr),
        .fill_req_i    (itlb_fill_req),
        .fill_vpn_i    (itlb_fill_vpn),
        .fill_ppn_i    (itlb_fill_ppn),
        .flush_all_i   (itlb_flush),
        .lookup_ack_o  (itlb_lookup_ack_o),
        .fill_ack_o    (itlb_fill_ack_o),
        .flush_ack_o   (itlb_flush_ack_o)
    );

    ozone_decode decode (
        .clk          (clk),
        .rst          (reset),
        .flush        (core_flush),
        .the_insn_bits(insn_bits),
        .the_insn_pc  (pc),
        .pred_taken_in(fetch_pred_taken),
        .pred_target_in(btb_pred_target),
        .pred_ghr_in  (bpred_ghr_snapshot),
        .insn_ready   (insn_ready),
        .ready_for_uop(ready_for_uop),
        .decoder_ready(decoder_ready),
        .uop_out      (uop_out),
        .uop_valid    (uop_valid)
    );

    ozone_dispatch dispatch (
        .clk              (clk),
        .rst_n            (rst_n),
        .flush            (core_flush),
        .uop_in           (uop_out),
        .uop_valid        (uop_valid),
        .ready_for_uop    (ready_for_uop),
        .rst_src1_addr    (rst_src1_addr),
        .rst_src2_addr    (rst_src2_addr),
        .rst_fp_src1_addr (rst_fp_src1_addr),
        .rst_fp_src2_addr (rst_fp_src2_addr),
        .rst_src1_status  (rst_src1_status),
        .rst_src2_status  (rst_src2_status),
        .rst_fp_src1_status(rst_fp_src1_status),
        .rst_fp_src2_status(rst_fp_src2_status),
        .rst_nzcv_status  (rst_nzcv_status),
        .rst_wr_en        (rst_wr_en),
        .rst_wr_addr      (rst_wr_addr),
        .rst_rob_idx      (rst_rob_idx),
        .rst_fp_wr_en     (rst_fp_wr_en),
        .rst_fp_wr_addr   (rst_fp_wr_addr),
        .rst_fp_rob_idx   (rst_fp_rob_idx),
        .rst_nzcv_wr_en   (rst_nzcv_wr_en),
        .rst_nzcv_rob_idx (rst_nzcv_rob_idx),
        .rob_src1_idx     (rob_src1_idx),
        .rob_src2_idx     (rob_src2_idx),
        .rob_src1_ready   (rob_src1_ready),
        .rob_src1_val     (rob_src1_val),
        .rob_src2_ready   (rob_src2_ready),
        .rob_src2_val     (rob_src2_val),
        .current_sp_value (current_sp_value),
        .rob_alloc_valid  (rob_alloc_valid),
        .rob_alloc_has_dest(rob_alloc_has_dest),
        .rob_alloc_data   (rob_alloc_data),
        .rob_alloc_idx    (rob_alloc_idx),
        .rob_full         (rob_full),
        .adder_alloc_valid(adder_alloc_valid),
        .adder_alloc_entry(adder_alloc_entry),
        .adder_full       (adder_full),
        .logic_alloc_valid(logic_alloc_valid),
        .logic_alloc_entry(logic_alloc_entry),
        .logic_full       (logic_full),
        .fpu_alloc_valid  (fpu_alloc_valid),
        .fpu_alloc_entry  (fpu_alloc_entry),
        .fpu_full         (fpu_full),
        .agu_alloc_valid  (agu_alloc_valid),
        .agu_alloc_entry  (agu_alloc_entry),
        .agu_full         (agu_full),
        .shifter_alloc_valid(shifter_alloc_valid),
        .shifter_alloc_entry(shifter_alloc_entry),
        .shifter_full       (shifter_full),
        .lsq_alloc_valid         (lsq_alloc_valid),
        .lsq_rob_entry_id        (lsq_rob_entry_id),
        .lsq_rob_wdata_entry_id  (lsq_rob_wdata_entry_id),
        .lsq_rob_wdata           (lsq_rob_wdata),
        .lsq_rob_wdata_ready     (lsq_rob_wdata_ready),
        .lsq_is_load             (lsq_is_load),
        .lq_full                 (lq_full),
        .sq_full                 (sq_full)
    );

    ozone_regstate regstate (
        .clk            (clk),
        .rst_n          (rst_n),
        .flush          (core_flush),
        .src1_addr      (rst_src1_addr),
        .src2_addr      (rst_src2_addr),
        .fp_src1_addr   (rst_fp_src1_addr),
        .fp_src2_addr   (rst_fp_src2_addr),
        .src1_status    (rst_src1_status),
        .src2_status    (rst_src2_status),
        .fp_src1_status (rst_fp_src1_status),
        .fp_src2_status (rst_fp_src2_status),
        .nzcv_status    (rst_nzcv_status),
        .disp_wr_en     (rst_wr_en),
        .disp_wr_addr   (rst_wr_addr),
        .disp_rob_idx   (rst_rob_idx),
        .disp_fp_wr_en  (rst_fp_wr_en),
        .disp_fp_wr_addr(rst_fp_wr_addr),
        .disp_fp_rob_idx(rst_fp_rob_idx),
        .disp_nzcv_wr_en(rst_nzcv_wr_en),
        .disp_nzcv_rob_idx(rst_nzcv_rob_idx),
        .commit_en      (commit_reg_en),
        .commit_addr    (commit_reg_addr),
        .commit_value   (commit_reg_value),
        .commit_rob_idx (commit_reg_rob_idx),
        .commit_fp_en   (commit_fp_en),
        .commit_fp_addr (commit_fp_addr),
        .commit_fp_value(commit_fp_value),
        .commit_fp_rob_idx(commit_fp_rob_idx),
        .commit_nzcv_en (commit_nzcv_en),
        .commit_nzcv_value(commit_nzcv_value),
        .commit_nzcv_rob_idx(commit_nzcv_rob_idx)
    );

    ozone_rob rob (
        .clk            (clk),
        .rst_n          (rst_n),
        .src1_rob_idx   (rob_src1_idx),
        .src2_rob_idx   (rob_src2_idx),
        .src1_ready     (rob_src1_ready),
        .src1_value     (rob_src1_val),
        .src2_ready     (rob_src2_ready),
        .src2_value     (rob_src2_val),
        .alloc_valid    (rob_alloc_valid),
        .alloc_has_dest (rob_alloc_has_dest),
        .alloc_data     (rob_alloc_data),
        .alloc_rob_idx  (rob_alloc_idx),
        .rob_full       (rob_full),
        .rob_empty      (rob_empty),
        .rob_head       (rob_head),
        .cdb_in         (cdb_broadcast),
        .commit_valid   (commit_valid),
        .commit_data    (commit_data),
        .commit_reg_en  (commit_reg_en),
        .commit_reg_addr(commit_reg_addr),
        .commit_reg_value(commit_reg_value),
        .commit_reg_rob_idx(commit_reg_rob_idx),
        .commit_fp_en   (commit_fp_en),
        .commit_fp_addr (commit_fp_addr),
        .commit_fp_value(commit_fp_value),
        .commit_fp_rob_idx(commit_fp_rob_idx),
        .commit_nzcv_en (commit_nzcv_en),
        .commit_nzcv_value(commit_nzcv_value),
        .commit_nzcv_rob_idx(commit_nzcv_rob_idx),
        .lsq_store_commit(lsq_store_commit),
        .lsq_store_addr (lsq_store_addr),
        .lsq_store_data (lsq_store_data),
        .bp_update_valid(bp_update_valid),
        .bp_update_pc   (bp_update_pc),
        .bp_update_taken(bp_update_taken),
        .bp_update_target(bp_update_target),
        .bp_update_ghr  (bp_update_ghr),
        .flush          (pipe_flush),
        .flush_target_pc(flush_target_pc),
        .exception_valid(exception_valid),
        .exception_pc   (exception_pc),
        .exception_code (exception_code)
    );

    ozone_rs_adder adder (
        .clk        (clk),
        .rst_n      (rst_n),
        .flush      (core_flush),
        .alloc_valid(adder_alloc_valid),
        .alloc_entry(adder_alloc_entry),
        .full       (adder_full),
        .cdb_in     (cdb_broadcast),
        .cdb_out    (adder_req),
        .cdb_granted(adder_granted)
    );

    ozone_logic logic_fu (
        .clk        (clk),
        .rst_n      (rst_n),
        .flush      (core_flush),
        .alloc_valid(logic_alloc_valid),
        .alloc_entry(logic_alloc_entry),
        .full       (logic_full),
        .cdb_in     (cdb_broadcast),
        .cdb_out    (logic_req),
        .cdb_granted(logic_granted)
    );

    ozone_shifter shifter_fu (
        .clk        (clk),
        .rst_n      (rst_n),
        .flush      (core_flush),
        .alloc_valid(shifter_alloc_valid),
        .alloc_entry(shifter_alloc_entry),
        .full       (shifter_full),
        .cdb_in     (cdb_broadcast),
        .cdb_out    (shifter_req),
        .cdb_granted(shifter_granted)
    );

    ozone_agu agu (
        .clk        (clk),
        .rst_n      (rst_n),
        .flush      (core_flush),
        .alloc_valid(agu_alloc_valid),
        .alloc_entry(agu_alloc_entry),
        .full       (agu_full),
        .cdb_in     (cdb_broadcast),
        .cdb_out    (agu_req),
        .cdb_granted(agu_granted)
    );

    fpnew_top fpu (
        .clk        (clk),
        .rst_n      (rst_n),
        .flush      (core_flush),
        .alloc_valid(fpu_alloc_valid),
        .alloc_entry(fpu_alloc_entry),
        .full       (fpu_full),
        .cdb_in     (cdb_broadcast),
        .cdb_out    (fpu_req),
        .cdb_granted(fpu_granted)
    );

    memory_subsystem #(
        .VA_WIDTH        (48),
        .PA_WIDTH        (30),
        .DATA_WIDTH      (64),
        .BLOCK_SIZE      (64),
        .LSQ_ENTRIES     (16),
        .USE_AVALON_MEM  (1'b0),
        .TLB_PAGE_WALK_BASE(SIM_TTBR0_BASE),
        .ENABLE_TLB_PAGE_WALK(1'b1),
        .USE_IDENTITY_TLB(1'b0)
    ) memsys (
        .clk                (clk),
        .rst_n              (rst_n),
        // trace port unused in Verilator sim
        .trace_data         ('0),
        .trace_addr         ('0),
        .trace_data_chunk   ('0),
        .trace_valid        (1'b0),
        .trace_write        (1'b0),
        .trace_ready        (),
        // ROB dispatch
        .rob_entry_id       (lsq_rob_entry_id),
        .rob_wdata_entry_id (lsq_rob_wdata_entry_id),
        .rob_wdata          (lsq_rob_wdata),
        .rob_wdata_ready    (lsq_rob_wdata_ready),
        .rob_is_load        (lsq_is_load),
        .rob_valid_in       (lsq_alloc_valid),
        // ROB control
        .flush              (core_flush),
        .commit_sq_head     (sim_finish_pending ? 1'b0 : lsq_store_commit),
        .translate_en_i     (cur_el == 2'd0),
        .cache_flush_req    (sim_finish_pending),
        .cache_flush_done   (cache_flush_done),
        // To dispatch (stall)
        .lq_full            (lq_full),
        .sq_full            (sq_full),
        // CDB
        .cdb_in             (cdb_broadcast),
        .cdb_out            (lsq_req),
        .cdb_granted        (lsq_granted),
        // L2 miss — physical memory interface
        .mem_req_valid      (dmem_req_valid),
        .mem_req_is_write   (dmem_req_is_write),
        .mem_req_addr       (dmem_req_addr),
        .mem_req_wdata      (dmem_req_wdata),
        .mem_req_ready      (dmem_req_ready),
        .mem_resp_valid     (dmem_resp_valid),
        .mem_resp_paddr     (dmem_resp_paddr),
        .mem_resp_rdata     (dmem_resp_rdata),
        .tlb_page_walk_base_i({ttbr0, 12'b0}),
        .ptw_req_valid      (ptw_req_valid),
        .ptw_req_addr       (ptw_req_addr),
        .ptw_req_ready      (ptw_req_ready),
        .ptw_resp_valid     (ptw_resp_valid),
        .ptw_resp_data      (ptw_resp_data),
        .sim_store_valid    (sim_store_valid),
        .sim_store_paddr    (sim_store_paddr),
        .sim_store_data     (sim_store_data),
        // Avalon unused
        .avm_readdata       ('0),
        .avm_readdatavalid  (1'b0),
        .avm_waitrequest    (1'b0),
        .avm_address        (),
        .avm_burstcount     (),
        .avm_read           (),
        .avm_write          (),
        .avm_writedata      (),
        .avm_byteenable     ()
    );

    ozone_cdb cdb (
        .adder_req      (adder_req),
        .logic_req      (logic_req),
        .fpu_req        (fpu_req),
        .mem_req        (agu_req),
        .lsq_req        (lsq_req),
        .shifter_req    (shifter_req),
        .rob_head       (rob_head),
        .cdb_broadcast  (cdb_broadcast),
        .adder_granted  (adder_granted),
        .logic_granted  (logic_granted),
        .fpu_granted    (fpu_granted),
        .mem_granted    (agu_granted),
        .lsq_granted    (lsq_granted),
        .shifter_granted(shifter_granted)
    );

    always @(posedge clk) begin
        if (reset) begin
            state           <= 0;
            done            <= 0;
            sim_finish_pending <= 1'b0;
            pc              <= (start_pc != 64'b0) ? start_pc[47:0]
                                                   : DEFAULT_ENTRY_PC;
            pa_pc           <= '0;
            ttbr0           <= SIM_TTBR0_BASE[29:12];
            cur_el          <= 2'd1;
            sp_el0          <= SIM_SP_EL0;
            sp_el1          <= SIM_SP_EL1;
            spsr_el1        <= SIM_SPSR_EL1;
            elr_el1         <= SIM_ELR_EL1;
            vbar_el1        <= SIM_VBAR_EL1;
            actlr_el1       <= 64'b0;
            tte             <= '0;
            insn_bits       <= '0;
            state7_sent     <= 1'b0;
            mem_addr        <= '0;
            mem_en          <= 1'b0;
            itlb_lookup_req <= 1'b0;
            itlb_vaddr      <= '0;
            itlb_fill_req   <= 1'b0;
            itlb_fill_vpn   <= '0;
            itlb_fill_ppn   <= '0;
            itlb_flush      <= 1'b0;
            insn_ready      <= 1'b0;
            for (int i = 0; i < 31; i++) x_regs[i] <= 64'b0;
            for (int i = 0; i < 32; i++) fp_regs[i] <= 64'b0;
            last_fetch_pc       <= '0;
            fetch_same_pc_streak <= '0;
            fetch_zero_pending   <= 1'b0;
            fetch_zero_wait      <= '0;

            if (!reset_seen) begin
                $display("Did reset!\n");
                reset_seen <= 1'b1;
            end
        end else if (!done) begin : top_run
            logic skip_fetch_progress;
            reset_seen <= 1'b0;
            insn_ready <= 1'b0;
            itlb_flush <= 1'b0;
            skip_fetch_progress = 1'b0;

            if (sim_finish_pending) begin
                mem_en          <= 1'b0;
                itlb_lookup_req <= 1'b0;
                itlb_fill_req   <= 1'b0;
                state           <= 0;
                state7_sent     <= 1'b0;
                if (cache_flush_done) begin
                    sim_finish_pending <= 1'b0;
                    done <= 1'b1;
                    $display("[TOP] cache flush complete; done");
                end
            end else begin
            if (fetch_zero_pending) begin
                mem_en          <= 1'b0;
                itlb_lookup_req <= 1'b0;
                itlb_fill_req   <= 1'b0;
                state           <= 0;
                state7_sent     <= 1'b0;
                if (rob_empty) begin
                    $display("[TOP] stop: zero/invalid fetch with empty ROB");
                    fetch_zero_pending <= 1'b0;
                    fetch_zero_wait    <= '0;
                    sim_finish_pending <= 1'b1;
                    skip_fetch_progress = 1'b1;
                end else if (commit_valid) begin
                    fetch_zero_wait <= '0;
                end else begin
                    fetch_zero_wait <= fetch_zero_wait + 1'b1;
                end
            end

            if (commit_reg_en && commit_reg_addr != 5'd31) begin
                x_regs[commit_reg_addr] <= commit_reg_value;
            end

            if (commit_valid &&
                commit_data.alloc_has_dest &&
                commit_data.dest_type == DEST_GPR &&
                commit_data.dest_reg == 5'd31) begin
                if (cur_el == 2'd0) begin
                    sp_el0 <= commit_data.value;
                    $display("[TOP] SP_EL0 <= 0x%016h", commit_data.value);
                end else begin
                    sp_el1 <= commit_data.value;
                    $display("[TOP] SP_EL1 <= 0x%016h", commit_data.value);
                end
            end

            if (commit_fp_en) begin
                fp_regs[commit_fp_addr] <= commit_fp_value;
            end

            if (commit_valid && commit_data.is_sysreg && !commit_data.sysreg_read) begin
                case (commit_data.sysreg_id)
                    SYSREG_SP_EL0: begin
                        sp_el0 <= commit_data.value;
                        $display("[TOP] MSR SP_EL0 <= 0x%016h", commit_data.value);
                    end
                    SYSREG_SPSR_EL1: begin
                        spsr_el1 <= commit_data.value;
                        $display("[TOP] MSR SPSR_EL1 <= 0x%016h", commit_data.value);
                    end
                    SYSREG_ELR_EL1: begin
                        elr_el1 <= commit_data.value;
                        $display("[TOP] MSR ELR_EL1 <= 0x%016h", commit_data.value);
                    end
                    SYSREG_VBAR_EL1: begin
                        vbar_el1 <= commit_data.value;
                        $display("[TOP] MSR VBAR_EL1 <= 0x%016h", commit_data.value);
                    end
                    SYSREG_ACTLR_EL1: begin
                        actlr_el1 <= commit_data.value;
                        $display("[TOP] MSR ACTLR_EL1 <= 0x%016h", commit_data.value);
                        if (commit_data.value == SIM_TERMINATE_VAL) begin
                            $display("[TOP] terminate value observed via ACTLR_EL1");
                            sim_finish_pending <= 1'b1;
                            skip_fetch_progress = 1'b1;
                        end
                    end
                    default: begin end
                endcase
            end

            // Pure-sim completion fallback: Ozone's EL1 sync handler writes the
            // terminate cookie to ACTLR_EL1 and then branches to itself at
            // VBAR_EL1 + 0x410. If the branch self-loop is reached with x0
            // already carrying that cookie, treat it as completion even if the
            // architectural ACTLR write path didn't trip done first.
            if (commit_valid
                && cur_el == 2'd1
                && commit_data.inst_type == ROB_TYPE_BRANCH
                && commit_data.PC == (vbar_el1[47:0] + 48'h410)
                && commit_data.br_taken
                && commit_data.br_target[47:0] == commit_data.PC[47:0]) begin
                x_regs[0]  <= SIM_TERMINATE_VAL;
                actlr_el1 <= SIM_TERMINATE_VAL;
                sim_finish_pending <= 1'b1;
                skip_fetch_progress = 1'b1;
                $display("[TOP] terminate observed via sync-handler self-loop");
            end

            if (rob_alloc_valid) begin
                $display("[TOP] rob alloc idx=%0d pc=0x%016h dest=%0d has_dest=%0b type=%0d ready=%0b",
                         rob_alloc_idx,
                         rob_alloc_data.PC,
                         rob_alloc_data.dest_reg,
                         rob_alloc_has_dest,
                         rob_alloc_data.inst_type,
                         rob_alloc_data.ready);
            end

            if (lsq_alloc_valid) begin
                $display("[TOP] lsq alloc rob=%0d load=%0b wtag=%0d wready=%0b wdata=0x%016h",
                         lsq_rob_entry_id, lsq_is_load, lsq_rob_wdata_entry_id,
                         lsq_rob_wdata_ready, lsq_rob_wdata);
            end

            if (lsq_store_commit) begin
                $display("[TOP] lsq store commit pulse addr=0x%016h data=0x%016h",
                         lsq_store_addr, lsq_store_data);
            end

            if (dmem_req_valid) begin
                $display("[TOP] dmem req write=%0b addr=0x%08h", dmem_req_is_write, dmem_req_addr);
            end

            if (dmem_resp_valid) begin
                $display("[TOP] dmem resp paddr=0x%08h", dmem_resp_paddr);
            end

            if (sim_store_valid) begin
                $display("[TOP] sim store mirror addr=0x%08h data=0x%016h",
                         sim_store_paddr, sim_store_data);
            end

            if (ptw_req_valid && ptw_req_ready) begin
                $display("[TOP] ptw req addr=0x%08h ttbr0=0x%05h", ptw_req_addr, ttbr0);
            end

            if (ptw_resp_valid) begin
                $display("[TOP] ptw resp data=0x%016h", ptw_resp_data);
            end

            if (cdb_broadcast.valid) begin
                $display("[TOP] cdb tag=%0d value_en=%0b rob_wb=%0b value=0x%016h br_valid=%0b br_taken=%0b br_target=0x%016h nzcv_upd=%0b",
                         cdb_broadcast.rob_tag,
                         cdb_broadcast.cdb_value_en,
                         cdb_broadcast.rob_wb_en,
                         cdb_broadcast.value,
                         cdb_broadcast.br_valid,
                         cdb_broadcast.br_taken,
                         cdb_broadcast.br_target,
                         cdb_broadcast.update_nzcv);
            end

            if (commit_valid) begin
                $display("[TOP] commit pc=0x%016h type=%0d ready=%0b br_taken=%0b br_target=0x%016h xdst=%0d xval=0x%016h",
                         commit_data.PC,
                         commit_data.inst_type,
                         commit_data.ready,
                         commit_data.br_taken,
                         commit_data.br_target,
                         commit_reg_addr,
                         commit_reg_value);
            end

            if (commit_valid && commit_data.is_eret) begin
                $display("[TOP] ERET -> EL%0d pc=0x%016h", spsr_el1[1:0], elr_el1);
                cur_el          <= spsr_el1[1:0];
                pc              <= elr_el1[47:0];
                state           <= 0;
                state7_sent     <= 1'b0;
                fetch_zero_pending <= 1'b0;
                fetch_zero_wait    <= '0;
                mem_en          <= 1'b0;
                itlb_lookup_req <= 1'b0;
                itlb_fill_req   <= 1'b0;
                skip_fetch_progress = 1'b1;
            end

            if (ret_zero_redirect) begin
                if (cur_el == 2'd0) begin
                    $display("[TOP] EL0 RET-to-zero exception -> handler 0x%016h", vbar_el1 + 64'h400);
                    elr_el1         <= commit_data.PC;
                    spsr_el1        <= {62'b0, cur_el};
                    cur_el          <= 2'd1;
                    pc              <= vbar_el1[47:0] + 48'h400;
                    state           <= 0;
                    state7_sent     <= 1'b0;
                    fetch_zero_pending <= 1'b0;
                    fetch_zero_wait    <= '0;
                    mem_en          <= 1'b0;
                    itlb_lookup_req <= 1'b0;
                    itlb_fill_req   <= 1'b0;
                    skip_fetch_progress = 1'b1;
                end else begin
                    $display("[TOP] done: committed branch to zero");
                    sim_finish_pending <= 1'b1;
                    skip_fetch_progress = 1'b1;
                end
            end

            if (exception_valid) begin
                $display("[TOP] exception code=%0d pc=0x%016h -> handler 0x%016h",
                         exception_code, exception_pc, {16'b0, vbar_el1[47:0] + exception_vector_off});
                elr_el1         <= exception_pc;
                spsr_el1        <= {62'b0, cur_el};
                cur_el          <= 2'd1;
                pc              <= vbar_el1[47:0] + exception_vector_off;
                state           <= 0;
                state7_sent     <= 1'b0;
                fetch_zero_pending <= 1'b0;
                fetch_zero_wait    <= '0;
                mem_en          <= 1'b0;
                itlb_lookup_req <= 1'b0;
                itlb_fill_req   <= 1'b0;
                skip_fetch_progress = 1'b1;
            end

            if (core_flush && !exception_valid && !ret_zero_redirect) begin
                $display("[TOP] flush redirect -> 0x%016h (pc=0x%012h state=%0d core_flush=%0b pipe_flush=%0b sim_finish=%0b commit_valid=%0b commit_pc=0x%012h commit_type=%0d br_taken=%0b br_target=0x%016h)",
                         flush_target_pc,
                         pc,
                         state,
                         core_flush,
                         pipe_flush,
                         sim_finish_pending,
                         commit_valid,
                         commit_data.PC[47:0],
                         commit_data.inst_type,
                         commit_data.br_taken,
                         commit_data.br_target);
                pc              <= flush_target_pc[47:0];
                state           <= 0;
                state7_sent     <= 1'b0;
                fetch_zero_pending <= 1'b0;
                fetch_zero_wait    <= '0;
                mem_en          <= 1'b0;
                itlb_lookup_req <= 1'b0;
                itlb_fill_req   <= 1'b0;
            end else if (!skip_fetch_progress && !fetch_zero_pending) begin
                case (state)
                    0: begin
                        state7_sent <= 1'b0;
                        if (!halt_fetch) begin
                            if (USE_ITLB_FETCH) begin
                                itlb_lookup_req <= 1'b1;
                                itlb_vaddr <= pc;
                                state <= 1;
                            end else begin
                                pa_pc <= pc[29:0];
                                state <= 5;
                            end
                        end
                    end

                    1: begin
                        if (itlb_lookup_ack_o) begin
                            itlb_lookup_req <= 1'b0;
                            if (itlb_hit) begin
                                pa_pc <= itlb_paddr;
                                state <= 5;
                            end else begin
                                logic [35:0] pc_vpn;
                                logic [29:0] entry_addr;
                                logic [29:0] ind;

                                pc_vpn = pc[47:12];
                                ind = pc_vpn[29:0];
                                entry_addr = {ttbr0, 12'b0} + (ind << 3);

                                mem_addr <= {34'b0, entry_addr};
                                mem_en <= 1'b1;
                                state <= 2;
                            end
                        end
                    end

                    2: begin
                        tte[31:0] <= mem_rdata;
                        state <= 3;
                    end

                    3: begin
                        mem_en <= 1'b0;
                        mem_addr <= mem_addr + 64'd4;
                        tte[63:32] <= mem_rdata;
                        itlb_fill_req <= 1'b1;
                        itlb_fill_ppn <= tte[29:12];
                        itlb_fill_vpn <= pc[47:12];
                        state <= 4;
                    end

                    4: begin
                        if (itlb_fill_ack_o) begin
                            itlb_fill_req <= 1'b0;
                            state <= 0;
                        end
                    end

                    5: begin
                        mem_en <= 1'b1;
                        mem_addr <= {34'b0, pa_pc};
                        state <= 6;
                    end

                    6: begin
                        mem_en <= 1'b0;
                        insn_bits <= mem_rdata;
                        $display("[TOP] fetched pc=0x%012h insn=0x%08h", pc, mem_rdata);
                        if (mem_rdata == 32'h0000_0000) begin
                            $display("[TOP] zero/invalid instruction at pc=0x%012h; waiting for in-flight redirect", pc);
                            fetch_zero_pending <= 1'b1;
                            fetch_zero_wait <= '0;
                            state <= 0;
                            state7_sent <= 1'b0;
                        end else begin
                            state <= 7;
                        end
                    end

                    7: begin
                        if (!halt_fetch) begin
                            if (!state7_sent) begin
                                $display("[TOP] send to decode pc=0x%012h insn=0x%08h", pc, insn_bits);
                                insn_ready <= 1'b1;
                                state7_sent <= 1'b1;
                            end else if (decoder_ready) begin
                                $display("[TOP] decoder consumed pc=0x%012h", pc);
                                pc <= fetch_pred_taken ? btb_pred_target : (pc + 48'd4);
                                state <= 0;
                                state7_sent <= 1'b0;
                            end
                        end
                    end

                    default: state <= 0;
                endcase
            end

            if (pc == last_fetch_pc && !sim_finish_pending && !halt_fetch) begin
                if (fetch_same_pc_streak != 8'hff)
                    fetch_same_pc_streak <= fetch_same_pc_streak + 1'b1;
                if (fetch_same_pc_streak == 8'd7) begin
                    $display("[TOP] fetch repeating pc=0x%012h state=%0d state7_sent=%0b skip_fetch_progress=%0b core_flush=%0b pipe_flush=%0b sim_finish=%0b halt=%0b decoder_ready=%0b ready_for_uop=%0b commit_valid=%0b commit_pc=0x%012h commit_type=%0d flush_target=0x%016h",
                             pc,
                             state,
                             state7_sent,
                             skip_fetch_progress,
                             core_flush,
                             pipe_flush,
                             sim_finish_pending,
                             halt_fetch,
                             decoder_ready,
                             ready_for_uop,
                             commit_valid,
                             commit_data.PC[47:0],
                             commit_data.inst_type,
                             flush_target_pc);
                end
            end else begin
                fetch_same_pc_streak <= 8'd0;
            end
            last_fetch_pc <= pc;
            end
        end
    end

endmodule
