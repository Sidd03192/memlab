/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNDRIVEN */
// Dispatch testbench.
//
// Instantiates ozone_dispatch wired to real ozone_rob, ozone_regstate, and
// all four FU RS modules.  cdb_bus is normally all-zero (no execution) but
// T3 injects a one-cycle CDB broadcast to test the ROB forward path.
//
// Tests:
//   T1  single ADD, all sources ready
//   T2  ADD with src1 in-flight (Qj = pending ROB tag)
//   T3  ADD with src1 ready via ROB forward (Qj = 0, Vj = forwarded value)
//   T4  2-uop FADD (NAN_CHECK + FADD) — stalls decode for second cycle
//   T5  adder RS full stall — ready_for_uop held low, clears after flush
//   T6  ORR routes to logic RS not adder

module tb_ozone_dispatch
  import ozone_pkg::*; ();

// ─── clock / reset ────────────────────────────────────────────────────────
logic clk = 0, rst_n = 0, flush = 0;
always #5 clk = ~clk;

// ─── decode → dispatch ────────────────────────────────────────────────────
uop_t  uop_in [2];
logic  uop_valid = 0;
logic  ready_for_uop;

// ─── dispatch ↔ regstate (read) ───────────────────────────────────────────
logic [4:0] rst_src1_addr,    rst_src2_addr;
logic [4:0] rst_fp_src1_addr, rst_fp_src2_addr;
reg_entry_t rst_src1_status,    rst_src2_status;
reg_entry_t rst_fp_src1_status, rst_fp_src2_status;
reg_entry_t rst_nzcv_status;

// ─── dispatch ↔ regstate (write) ──────────────────────────────────────────
logic       rst_wr_en, rst_fp_wr_en, rst_nzcv_wr_en;
logic [4:0] rst_wr_addr, rst_fp_wr_addr;
logic [5:0] rst_rob_idx, rst_fp_rob_idx, rst_nzcv_rob_idx;

// ─── dispatch ↔ ROB ───────────────────────────────────────────────────────
logic [5:0]  rob_src1_idx, rob_src2_idx;
logic        rob_src1_ready, rob_src2_ready;
logic [63:0] rob_src1_val,  rob_src2_val;
logic        rob_alloc_valid, rob_alloc_has_dest;
rob_entry_t  rob_alloc_data;
logic [5:0]  rob_alloc_idx;
logic        rob_full;
logic [5:0]  rob_head;

// ─── ROB commit → regstate ────────────────────────────────────────────────
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

// ─── CDB bus (driven by testbench; normally idle) ─────────────────────────
cdb_broadcast_t cdb_bus;
initial cdb_bus = '0;

// ─── FU RS ports ──────────────────────────────────────────────────────────
logic           adder_alloc_valid; rs_entry_add_t   adder_alloc_entry; logic adder_full;
logic           logic_alloc_valid; rs_entry_t       logic_alloc_entry; logic logic_full;
logic           fpu_alloc_valid;   rs_entry_fpmul_t fpu_alloc_entry;   logic fpu_full;
logic           agu_alloc_valid;   rs_entry_add_t   agu_alloc_entry;   logic agu_full;
cdb_broadcast_t adder_cdb_out, logic_cdb_out, fpu_cdb_out, agu_cdb_out;

// ─── DUT instances ────────────────────────────────────────────────────────
ozone_dispatch dut (
    .clk, .rst_n, .flush,
    .uop_in, .uop_valid, .ready_for_uop,
    .rst_src1_addr, .rst_src2_addr,
    .rst_fp_src1_addr, .rst_fp_src2_addr,
    .rst_src1_status, .rst_src2_status,
    .rst_fp_src1_status, .rst_fp_src2_status,
    .rst_nzcv_status,
    .rst_wr_en,  .rst_wr_addr,  .rst_rob_idx,
    .rst_fp_wr_en, .rst_fp_wr_addr, .rst_fp_rob_idx,
    .rst_nzcv_wr_en, .rst_nzcv_rob_idx,
    .rob_src1_idx, .rob_src2_idx,
    .rob_src1_ready, .rob_src2_ready,
    .rob_src1_val,   .rob_src2_val,
    .rob_alloc_valid, .rob_alloc_has_dest,
    .rob_alloc_data, .rob_alloc_idx, .rob_full,
    .adder_alloc_valid, .adder_alloc_entry, .adder_full,
    .logic_alloc_valid, .logic_alloc_entry, .logic_full,
    .fpu_alloc_valid,   .fpu_alloc_entry,   .fpu_full,
    .agu_alloc_valid,   .agu_alloc_entry,   .agu_full
);

ozone_rob rob (
    .clk, .rst_n,
    .src1_rob_idx(rob_src1_idx),
    .src2_rob_idx(rob_src2_idx),
    .src1_ready(rob_src1_ready), .src1_value(rob_src1_val),
    .src2_ready(rob_src2_ready), .src2_value(rob_src2_val),
    .alloc_valid(rob_alloc_valid),
    .alloc_has_dest(rob_alloc_has_dest),
    .alloc_data(rob_alloc_data),
    .alloc_rob_idx(rob_alloc_idx),
    .rob_full, .rob_head,
    .cdb_in(cdb_bus),
    .commit_valid(), .commit_data(),
    .commit_reg_en,   .commit_reg_addr,   .commit_reg_value, .commit_reg_rob_idx,
    .commit_fp_en,    .commit_fp_addr,    .commit_fp_value,  .commit_fp_rob_idx,
    .commit_nzcv_en,  .commit_nzcv_value, .commit_nzcv_rob_idx,
    .lsq_store_commit(), .lsq_store_addr(), .lsq_store_data(),
    .bp_update_valid(), .bp_update_pc(), .bp_update_taken(), .bp_update_target(),
    .flush(), .flush_target_pc(),
    .exception_valid(), .exception_pc(), .exception_code()
);

ozone_regstate regstate (
    .clk, .rst_n, .flush,
    .src1_addr(rst_src1_addr),   .src2_addr(rst_src2_addr),
    .fp_src1_addr(rst_fp_src1_addr), .fp_src2_addr(rst_fp_src2_addr),
    .src1_status(rst_src1_status),   .src2_status(rst_src2_status),
    .fp_src1_status(rst_fp_src1_status), .fp_src2_status(rst_fp_src2_status),
    .nzcv_status(rst_nzcv_status),
    .disp_wr_en(rst_wr_en),         .disp_wr_addr(rst_wr_addr),       .disp_rob_idx(rst_rob_idx),
    .disp_fp_wr_en(rst_fp_wr_en),   .disp_fp_wr_addr(rst_fp_wr_addr), .disp_fp_rob_idx(rst_fp_rob_idx),
    .disp_nzcv_wr_en(rst_nzcv_wr_en), .disp_nzcv_rob_idx(rst_nzcv_rob_idx),
    .commit_en(commit_reg_en),       .commit_addr(commit_reg_addr),
    .commit_value(commit_reg_value), .commit_rob_idx(commit_reg_rob_idx),
    .commit_fp_en,    .commit_fp_addr,    .commit_fp_value,    .commit_fp_rob_idx,
    .commit_nzcv_en,  .commit_nzcv_value, .commit_nzcv_rob_idx
);

ozone_rs_adder adder (
    .clk, .rst_n, .flush,
    .alloc_valid(adder_alloc_valid), .alloc_entry(adder_alloc_entry), .full(adder_full),
    .cdb_in(cdb_bus), .cdb_out(adder_cdb_out), .cdb_granted(1'b0)
);
ozone_logic logic_fu (
    .clk, .rst_n, .flush,
    .alloc_valid(logic_alloc_valid), .alloc_entry(logic_alloc_entry), .full(logic_full),
    .cdb_in(cdb_bus), .cdb_out(logic_cdb_out), .cdb_granted(1'b0)
);
ozone_rs_fpmult fpu (
    .clk, .rst_n, .flush,
    .alloc_valid(fpu_alloc_valid), .alloc_entry(fpu_alloc_entry), .full(fpu_full),
    .cdb_in(cdb_bus), .cdb_out(fpu_cdb_out), .cdb_granted(1'b0)
);
ozone_agu agu_fu (
    .clk, .rst_n, .flush,
    .alloc_valid(agu_alloc_valid), .alloc_entry(agu_alloc_entry), .full(agu_full),
    .cdb_in(cdb_bus), .cdb_out(agu_cdb_out), .cdb_granted(1'b0)
);

// ─── checker helpers ──────────────────────────────────────────────────────
int pass_count = 0, fail_count = 0;

task chk(input string name, input logic got, input logic expected);
    if (got !== expected) begin
        $display("  FAIL  %-45s  got=%0b expected=%0b", name, got, expected);
        fail_count++;
    end else begin
        $display("  pass  %s", name);
        pass_count++;
    end
endtask

task chk6(input string name, input logic [5:0] got, input logic [5:0] expected);
    if (got !== expected) begin
        $display("  FAIL  %-45s  got=%0d expected=%0d", name, got, expected);
        fail_count++;
    end else begin
        $display("  pass  %s", name);
        pass_count++;
    end
endtask

task chk64(input string name, input logic [63:0] got, input logic [63:0] expected);
    if (got !== expected) begin
        $display("  FAIL  %-45s  got=0x%016X expected=0x%016X", name, got, expected);
        fail_count++;
    end else begin
        $display("  pass  %s", name);
        pass_count++;
    end
endtask

// ─── uop builder ──────────────────────────────────────────────────────────
function automatic uop_t mk(
    input uop_type_e typ,
    input logic [5:0] a, b, c,
    input logic neg, imm_opnd, set_flags, fp,
    input logic [63:0] imm
);
    uop_t u = '0;
    u.uop_type     = typ;
    u.a            = a; u.b = b; u.c = c;
    u.neg_c_or_imm = neg;
    u.imm_opnd     = imm_opnd;
    u.set_flags    = set_flags;
    u.fp_bit       = fp;
    u.imm_bits     = imm;
    u.pc           = 48'h1000;
    return u;
endfunction

// ─── send_insn: drive uop_valid until dispatch asserts ready_for_uop ──────
task send_insn(input uop_t u0, input uop_t u1);
    @(negedge clk);
    uop_in[0] = u0;
    uop_in[1] = u1;
    uop_valid = 1'b1;
    do @(posedge clk); while (!ready_for_uop);
    #1;
    @(negedge clk);
    uop_valid = 1'b0;
    @(posedge clk); #1;
endtask

// ─── reset ────────────────────────────────────────────────────────────────
task do_reset();
    rst_n     = 0;
    uop_valid = 0;
    flush     = 0;
    cdb_bus   = '0;
    uop_in[0] = '0;
    uop_in[1] = '0;
    repeat(3) @(posedge clk);
    rst_n = 1;
    @(posedge clk); #1;
endtask

// Module-level temporaries used across test blocks
logic [5:0] saved_rob_tag;

// ─── stimulus ─────────────────────────────────────────────────────────────
initial begin

    do_reset();

    // ================================================================
    // T1: ADD X1, X2, X3  (all sources not busy)
    //   • adder RS allocated, logic/fpu/agu not
    //   • ROB tag = 1 (first tag after tag-0 is reserved)
    //   • Qj = 0, Qk = 0 (both ready), Vj = 0, Vk = 0 (reset values)
    //   • ready_for_uop asserts same cycle (1-uop instruction)
    // ================================================================
    $display("\n=== T1: ADD X1,X2,X3 (all sources ready) ===");

    @(negedge clk);
    uop_in[0] = mk(UOP_ADD, 6'd1, 6'd2, 6'd3, 0,0,0,0, 0);
    uop_in[1] = '0;
    uop_valid = 1'b1;
    #1; // let combinational outputs settle

    chk ("adder_alloc_valid=1",    adder_alloc_valid,         1'b1);
    chk ("logic_alloc_valid=0",    logic_alloc_valid,         1'b0);
    chk ("fpu_alloc_valid=0",      fpu_alloc_valid,           1'b0);
    chk ("agu_alloc_valid=0",      agu_alloc_valid,           1'b0);
    chk ("rob_alloc_valid=1",      rob_alloc_valid,           1'b1);
    chk ("rob_alloc_has_dest=1",   rob_alloc_has_dest,        1'b1);
    chk6("rob_alloc_idx=1",        rob_alloc_idx,             6'd1);
    chk6("adder.Qj=0",             adder_alloc_entry.Qj,      6'd0);
    chk6("adder.Qk=0",             adder_alloc_entry.Qk,      6'd0);
    chk6("adder.rob_tag=1",        adder_alloc_entry.rob_tag, 6'd1);
    chk ("adder.has_rd=1",         adder_alloc_entry.has_rd,  1'b1);
    chk ("ready_for_uop=1",        ready_for_uop,             1'b1);

    @(posedge clk); #1; // ROB + RS + regstate update on posedge
    uop_valid = 1'b0;
    @(posedge clk); #1;

    // ================================================================
    // T2: ADD X4, X1, X3  (X1 is now in-flight with rob_tag=1)
    //   • dispatch looks up X1 in regstate → busy, rob_idx=1
    //   • ROB entry 1 is not ready (no CDB) → Qj=1
    // ================================================================
    $display("\n=== T2: ADD X4,X1,X3 (X1 in-flight, Qj=1) ===");

    @(negedge clk);
    uop_in[0] = mk(UOP_ADD, 6'd4, 6'd1, 6'd3, 0,0,0,0, 0);
    uop_in[1] = '0;
    uop_valid = 1'b1;
    #1;

    chk ("adder_alloc_valid=1",    adder_alloc_valid,         1'b1);
    chk6("adder.Qj=1 (in-flight)", adder_alloc_entry.Qj,      6'd1);
    chk6("adder.Qk=0",             adder_alloc_entry.Qk,      6'd0);
    chk6("adder.rob_tag=2",        adder_alloc_entry.rob_tag, 6'd2);
    chk ("ready_for_uop=1",        ready_for_uop,             1'b1);

    @(posedge clk); #1;
    uop_valid = 1'b0;
    @(posedge clk); #1;

    // ================================================================
    // T3: CDB-forward path — mark ROB[1] ready (value=42), then dispatch
    //     ADD X5, X1, X3.  Dispatch should read ROB[1] as ready and
    //     produce Qj=0, Vj=42.
    // ================================================================
    $display("\n=== T3: ADD X5,X1,X3 after CDB forward (Vj=42) ===");

    // Inject one CDB cycle: mark ROB entry 1 ready with value=42
    @(negedge clk);
    cdb_bus.valid        = 1'b1;
    cdb_bus.cdb_value_en = 1'b1;
    cdb_bus.rob_wb_en    = 1'b1;
    cdb_bus.rob_tag      = 6'd1;
    cdb_bus.value        = 64'd42;
    @(posedge clk); #1; // ROB writes entry-1 ready=1, value=42
    cdb_bus = '0;       // CDB back to idle

    @(negedge clk);
    uop_in[0] = mk(UOP_ADD, 6'd5, 6'd1, 6'd3, 0,0,0,0, 0);
    uop_in[1] = '0;
    uop_valid = 1'b1;
    #1;

    // X1 is still busy in regstate (busy bit cleared only at commit),
    // but the ROB entry IS ready → dispatch forwards the value.
    chk ("adder_alloc_valid=1",      adder_alloc_valid,        1'b1);
    chk6("adder.Qj=0 (forwarded)",   adder_alloc_entry.Qj,     6'd0);
    chk64("adder.Vj=42",             adder_alloc_entry.Vj,     64'd42);
    chk6("adder.Qk=0",               adder_alloc_entry.Qk,     6'd0);
    chk ("ready_for_uop=1",          ready_for_uop,            1'b1);

    @(posedge clk); #1;
    uop_valid = 1'b0;
    @(posedge clk); #1;

    // ================================================================
    // T4: FADD Dd,Dn,Dm — 2 uops (NAN_CHECK then FADD).
    //   Cycle 1: NAN_CHECK → fpu, ready_for_uop=0
    //   Cycle 2: FADD      → fpu, ready_for_uop=1
    //   Both get consecutive ROB tags.
    // ================================================================
    $display("\n=== T4: FADD (NAN_CHECK + FADD) — 2-uop stall ===");

    @(negedge clk);
    uop_in[0] = mk(UOP_NAN_CHECK, 6'd32, 6'd10, 6'd11, 0,0,0,1, 0);
    uop_in[1] = mk(UOP_FADD,      6'd9,  6'd10, 6'd11, 0,0,0,1, 0);
    uop_valid = 1'b1;
    #1;

    // Cycle 1 checks (NAN_CHECK being dispatched)
    chk ("fpu_alloc_valid=1 (NAN_CHECK cycle)", fpu_alloc_valid, 1'b1);
    chk ("ready_for_uop=0 (2nd uop pending)",   ready_for_uop,   1'b0);
    saved_rob_tag = rob_alloc_idx;
    $display("  info  NAN_CHECK rob_tag=%0d", saved_rob_tag);

    @(posedge clk); #1; // DS_IDLE→DS_DISP1, pending_uop1 latched

    // Cycle 2 checks (FADD being dispatched from pending_uop1)
    chk ("fpu_alloc_valid=1 (FADD cycle)", fpu_alloc_valid, 1'b1);
    chk ("ready_for_uop=1 (done)",         ready_for_uop,   1'b1);
    chk ("FADD rob_tag = NAN+1",
         (rob_alloc_idx == saved_rob_tag + 1), 1'b1);
    $display("  info  FADD rob_tag=%0d", rob_alloc_idx);

    @(posedge clk); #1;
    uop_valid = 1'b0;
    @(posedge clk); #1;

    // ================================================================
    // T5: Adder RS full stall.  Reset first for a clean slate, then
    //     fill all 4 adder RS slots.  5th ADD must stall.
    //     After flush, adder RS clears and dispatch unblocks.
    // ================================================================
    $display("\n=== T5: adder RS full stall + flush ===");

    do_reset();

    // Seed one unresolved source dependency so the dispatched ADDs remain in
    // the RS instead of issuing into the FU result register.
    regstate.gp_reg[9].busy    = 1'b1;
    regstate.gp_reg[9].rob_idx = 6'd7;

    // Fill all 4 adder RS slots with entries waiting on ROB tag 7.
    begin
        uop_t tmp;
        for (int k = 0; k < 4; k++) begin
            tmp = mk(UOP_ADD, 6'(k+1), 6'd9, 6'd30, 0,0,0,0, 0);
            send_insn(tmp, '0);
        end
    end

    chk("adder_full=1 after 4 dispatches", adder_full, 1'b1);

    // 5th ADD — dispatch stalls
    @(negedge clk);
    uop_in[0] = mk(UOP_ADD, 6'd5, 6'd30, 6'd30, 0,0,0,0, 0);
    uop_in[1] = '0;
    uop_valid = 1'b1;
    @(posedge clk); #1;
    chk("ready_for_uop=0 while RS full", ready_for_uop, 1'b0);

    // Flush → RS clears
    @(negedge clk);
    flush = 1'b1;
    @(posedge clk); #1;
    flush = 1'b0;

    // After flush RS is empty, dispatch unblocks (uop_valid still 1)
    chk("adder_full=0 after flush",      adder_full,    1'b0);
    chk("ready_for_uop=1 after flush",   ready_for_uop, 1'b1);

    @(posedge clk); #1;
    uop_valid = 1'b0;
    @(posedge clk); #1;

    // ================================================================
    // T6: ORR X6, X7, X8 — routes to logic RS, not adder
    // ================================================================
    $display("\n=== T6: ORR X6,X7,X8 → logic RS ===");

    do_reset();

    @(negedge clk);
    uop_in[0] = mk(UOP_OR, 6'd6, 6'd7, 6'd8, 0,0,0,0, 0);
    uop_in[1] = '0;
    uop_valid = 1'b1;
    #1;

    chk ("logic_alloc_valid=1",  logic_alloc_valid,                    1'b1);
    chk ("adder_alloc_valid=0",  adder_alloc_valid,                    1'b0);
    chk ("fpu_alloc_valid=0",    fpu_alloc_valid,                      1'b0);
    chk ("logic.op == OP_ORR",   (logic_alloc_entry.op == 6'(OP_ORR)), 1'b1);

    @(posedge clk); #1;
    uop_valid = 1'b0;
    @(posedge clk); #1;

    // ─── summary ──────────────────────────────────────────────────────
    $display("\n=== Dispatch TB done: %0d passed, %0d failed ===",
             pass_count, fail_count);
    if (fail_count == 0) $display("ALL PASS");
    else                 $display("FAILURES DETECTED");
    $finish;
end

endmodule
