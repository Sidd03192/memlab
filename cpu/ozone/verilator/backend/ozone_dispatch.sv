// In-order dispatch/rename-control stage: read ARF or ROB tags via RST,
// allocate ROB entries, and enqueue uops into each FU reservation station.
//
// One uop is dispatched per cycle. Two-uop instructions stall decode for a
// second cycle (Option B from the design discussion). ready_for_uop is
// asserted on the cycle the LAST uop of an instruction is dispatched.
//
// UOP[1] validity: uop_out[1].uop_type == UOP_AGU (4'd0) means "no second
// uop", because the decoder never places UOP_AGU in slot 1 — slot 1 is only
// populated by UOP_RD, UOP_WR, UOP_ADD, UOP_OR, UOP_FADD, UOP_FMUL.

module ozone_dispatch
  import ozone_pkg::*;
(
    input  logic        clk,
    input  logic        rst_n,
    input  logic        flush,

    // ─── decode handshake ─────────────────────────────────────────────────
    input  uop_t        uop_in [2],
    input  logic        uop_valid,
    output logic        ready_for_uop,

    // ─── regstate read (combinational, every cycle) ───────────────────────
    output logic [4:0]  rst_src1_addr,
    output logic [4:0]  rst_src2_addr,
    output logic [4:0]  rst_fp_src1_addr,
    output logic [4:0]  rst_fp_src2_addr,
    input  reg_entry_t  rst_src1_status,
    input  reg_entry_t  rst_src2_status,
    input  reg_entry_t  rst_fp_src1_status,
    input  reg_entry_t  rst_fp_src2_status,
    input  reg_entry_t  rst_nzcv_status,

    // ─── regstate write (mark dest busy, takes effect next posedge) ───────
    output logic        rst_wr_en,
    output logic [4:0]  rst_wr_addr,
    output logic [5:0]  rst_rob_idx,
    output logic        rst_fp_wr_en,
    output logic [4:0]  rst_fp_wr_addr,
    output logic [5:0]  rst_fp_rob_idx,
    output logic        rst_nzcv_wr_en,
    output logic [5:0]  rst_nzcv_rob_idx,

    // ─── ROB source readiness (combinational with CDB forward inside ROB) ─
    output logic [5:0]  rob_src1_idx,
    output logic [5:0]  rob_src2_idx,
    input  logic        rob_src1_ready,
    input  logic [63:0] rob_src1_val,
    input  logic        rob_src2_ready,
    input  logic [63:0] rob_src2_val,

    // ─── ROB alloc ────────────────────────────────────────────────────────
    output logic        rob_alloc_valid,
    output logic        rob_alloc_has_dest,
    output rob_entry_t  rob_alloc_data,
    input  logic [5:0]  rob_alloc_idx,   // = ROB tail, combinational
    input  logic        rob_full,

    // ─── Adder RS ─────────────────────────────────────────────────────────
    output logic          adder_alloc_valid,
    output rs_entry_add_t adder_alloc_entry,
    input  logic          adder_full,

    // ─── Logic RS ─────────────────────────────────────────────────────────
    output logic          logic_alloc_valid,
    output rs_entry_t     logic_alloc_entry,
    input  logic          logic_full,

    // ─── FPU RS ───────────────────────────────────────────────────────────
    output logic          fpu_alloc_valid,
    output rs_entry_fp_t  fpu_alloc_entry,
    input  logic          fpu_full,

    // ─── AGU RS ───────────────────────────────────────────────────────────
    output logic          agu_alloc_valid,
    output rs_entry_add_t agu_alloc_entry,
    input  logic          agu_full,

    // ─── LSQ dispatch ─────────────────────────────────────────────────────
    output logic        lsq_alloc_valid,
    output logic [5:0]  lsq_rob_entry_id,
    output logic [5:0]  lsq_rob_wdata_entry_id,
    output logic [63:0] lsq_rob_wdata,
    output logic        lsq_rob_wdata_ready,
    output logic        lsq_is_load,
    input  logic        lq_full,
    input  logic        sq_full
);

// ─── FSM ───────────────────────────────────────────────────────────────────
typedef enum logic { DS_IDLE = 1'b0, DS_DISP1 = 1'b1 } disp_state_e;
disp_state_e state;
uop_t        pending_uop1;

// ─── current uop being dispatched ──────────────────────────────────────────
uop_t cur;
always_comb cur = (state == DS_DISP1) ? pending_uop1 : uop_in[0];

// Slot 1 is valid when it holds something other than the cleared sentinel.
// The decoder sets uop_out[1] = '0 (uop_type=UOP_AGU=0, a/b/c=32) for
// single-uop instructions; it never places a real UOP_AGU in slot 1.
logic has_uop1;
assign has_uop1 = (uop_in[1].uop_type != 4'd0);

// We are trying to dispatch this cycle when:
//   • IDLE and decode has a valid uop, OR
//   • DISP1 (always trying to drain pending_uop1)
logic active;
assign active = (state == DS_DISP1) || (state == DS_IDLE && uop_valid);

// ─── regstate address outputs (always driven from cur) ────────────────────
// For stores (UOP_WR): src2 port reads the store-data register (a) instead
// of the c operand, since stores need 3 sources (base, offset, data) but
// offset is always immediate for M-format, freeing the src2 slot.
always_comb begin
    rst_src1_addr    = cur.b[4:0];
    rst_src2_addr    = (cur.uop_type == UOP_WR) ? cur.a[4:0] : cur.c[4:0];
    rst_fp_src1_addr = cur.b[4:0];
    rst_fp_src2_addr = (cur.uop_type == UOP_WR) ? cur.a[4:0] : cur.c[4:0];
end

// ─── source operand resolution: Vj/Qj (src1 = uop.b) ─────────────────────
logic [63:0] Vj;
logic [5:0]  Qj;
reg_entry_t  src1_st;

always_comb begin
    // Immediate branches use the instruction PC as their first operand so the
    // adder can form PC-relative targets.
    if (cur.uop_type == UOP_COND_CHECK) begin
        src1_st      = rst_nzcv_status;
    end else if (cur.check_target && cur.imm_opnd && cur.b == 6'd32) begin
        // Immediate branch with no register source (B/BL): Vj = PC
        src1_st      = '0;
    end else begin
        src1_st      = cur.fp_bit ? rst_fp_src1_status : rst_src1_status;
    end
    rob_src1_idx = src1_st.rob_idx;

    if (cur.uop_type == UOP_COND_CHECK) begin
        // NZCV source: value lives in low 4 bits of nzcv_reg.value
        if (!src1_st.busy) begin
            Vj = {60'b0, src1_st.value[3:0]};
            Qj = 6'b0;
        end else if (rob_src1_ready) begin
            Vj = rob_src1_val;
            Qj = 6'b0;
        end else begin
            Vj = 64'b0;
            Qj = src1_st.rob_idx;
        end
    end else if (cur.check_target && cur.imm_opnd && cur.b == 6'd32) begin
        // B/BL: Vj = PC so adder computes PC + offset
        Vj = {16'b0, cur.pc};
        Qj = 6'b0;
    end else if (cur.b == 6'd32) begin
        // XZR or no source — always zero, no dependency
        Vj = 64'b0;
        Qj = 6'b0;
    end else if (!src1_st.busy) begin
        Vj = src1_st.value;
        Qj = 6'b0;
    end else if (rob_src1_ready) begin
        Vj = rob_src1_val;
        Qj = 6'b0;
    end else begin
        Vj = 64'b0;
        Qj = src1_st.rob_idx;
    end
end

// ─── source operand resolution: Vk/Qk (src2 = uop.c or immediate) ─────────
// For UOP_WR (stores): src2_st was redirected above to hold store-data status.
// The address offset is always an immediate (imm_opnd=1 for M-format), so
// Vk=imm_bits and Qk=0 — the store-data register status in src2_st is only
// consumed by the Vdata/Qdata block below.
logic [63:0] Vk;
logic [5:0]  Qk;
reg_entry_t  src2_st;

always_comb begin
    src2_st      = cur.fp_bit ? rst_fp_src2_status : rst_src2_status;
    rob_src2_idx = src2_st.rob_idx;

    if (cur.imm_opnd) begin
        // Second operand is an immediate baked into uop.imm_bits
        Vk = cur.imm_bits;
        Qk = 6'b0;
    end else if (cur.c == 6'd32) begin
        Vk = 64'b0;
        Qk = 6'b0;
    end else if (!src2_st.busy) begin
        Vk = src2_st.value;
        Qk = 6'b0;
    end else if (rob_src2_ready) begin
        Vk = rob_src2_val;
        Qk = 6'b0;
    end else begin
        Vk = 64'b0;
        Qk = src2_st.rob_idx;
    end
end

// ─── store-data operand (Vdata/Qdata) — UOP_WR only ──────────────────────
// src2_st was redirected to read the store-data register (a) for stores.
// ROB forwarding reuses rob_src2_idx/rob_src2_val since imm_opnd=1 means
// Qk=0 and the src2 ROB read is otherwise unused for stores.
logic [63:0] Vdata;
logic [5:0]  Qdata;

always_comb begin
    if (cur.uop_type == UOP_WR) begin
        if (cur.a == 6'd32) begin
            Vdata = 64'b0;
            Qdata = 6'b0;
        end else if (!src2_st.busy) begin
            Vdata = src2_st.value;
            Qdata = 6'b0;
        end else if (rob_src2_ready) begin
            Vdata = rob_src2_val;
            Qdata = 6'b0;
        end else begin
            Vdata = 64'b0;
            Qdata = src2_st.rob_idx;
        end
    end else begin
        Vdata = 64'b0;
        Qdata = 6'b0;
    end
end

// ─── FU routing ───────────────────────────────────────────────────────────
logic goes_adder, goes_logic, goes_fpu, goes_agu;

always_comb begin
    goes_adder = (cur.uop_type == UOP_ADD)        ||
                 (cur.uop_type == UOP_COND_CHECK)  ||
                 (cur.uop_type == UOP_LSL)          ||
                 (cur.uop_type == UOP_LSR)          ||
                 (cur.uop_type == UOP_ASR);
    goes_logic = (cur.uop_type == UOP_AND) ||
                 (cur.uop_type == UOP_OR)  ||
                 (cur.uop_type == UOP_XOR);
    goes_fpu   = (cur.uop_type == UOP_FADD)      ||
                 (cur.uop_type == UOP_FMUL)      ||
                 (cur.uop_type == UOP_NAN_CHECK);
    goes_agu   = (cur.uop_type == UOP_AGU) ||
                 (cur.uop_type == UOP_RD)  ||
                 (cur.uop_type == UOP_WR);
    // UOP_ERET: no RS, just ROB (marked ready at alloc so it commits and
    // triggers the flush path in the ROB commit logic)
end

logic target_full, stall, do_dispatch;
assign target_full = (goes_adder && adder_full)                     ||
                     (goes_logic && logic_full)                      ||
                     (goes_fpu   && fpu_full)                        ||
                     (goes_agu   && agu_full)                        ||
                     (cur.uop_type == UOP_RD && lq_full)            ||
                     (cur.uop_type == UOP_WR && sq_full);
assign stall       = rob_full || target_full;
assign do_dispatch = active && !stall;

// ─── op code translation ──────────────────────────────────────────────────
adder_op_e adder_op;
always_comb begin
    unique case (cur.uop_type)
        UOP_ADD: begin
            if (cur.check_target) begin
                if (cur.imm_opnd && cur.b != 6'd32)
                    // CBZ/CBNZ: b=Rt (register to test), imm_opnd=1 for absolute target
                    adder_op = cur.neg_c_or_imm ? OP_CBNZ : OP_CBZ;
                else
                    // imm_opnd distinguishes BL (imm offset) from BLR (register target)
                    adder_op = (cur.a == 6'd30 && !cur.imm_opnd) ? OP_BLR :
                               (cur.a == 6'd30)                   ? OP_BL  : OP_B;
            // a==32 means no writeback (CMP / CMN)
            end else if (cur.a == 6'd32 && cur.set_flags)
                adder_op = cur.neg_c_or_imm ? OP_CMP : OP_CMN;
            else if (cur.neg_c_or_imm)
                adder_op = cur.set_flags ? OP_SUBS : OP_SUB;
            else
                adder_op = cur.set_flags ? OP_ADDS : OP_ADD;
        end
        UOP_COND_CHECK: adder_op = OP_BCOND;
        UOP_LSL:        adder_op = OP_LSL;
        UOP_LSR:        adder_op = OP_LSR;
        UOP_ASR:        adder_op = OP_ASR;
        default:        adder_op = OP_ADD;
    endcase
end

adder_op_e logic_op;
always_comb begin
    unique case (cur.uop_type)
        UOP_AND: logic_op = cur.set_flags ? OP_ANDS : OP_AND;
        UOP_OR:  logic_op = cur.neg_c_or_imm ? OP_ORN : OP_ORR;
        UOP_XOR: logic_op = OP_EOR;
        default: logic_op = OP_ORR;
    endcase
end

// ─── ROB alloc ────────────────────────────────────────────────────────────
always_comb begin
    rob_alloc_valid    = do_dispatch;
    // Stores (UOP_WR) write no architectural register — dest is NONE.
    rob_alloc_has_dest = (cur.a != 6'd32) && (cur.uop_type != UOP_WR);

    rob_alloc_data             = '0;
    rob_alloc_data.PC          = {16'b0, cur.pc};
    rob_alloc_data.dest_reg    = cur.a[4:0];
    rob_alloc_data.dest_type   = (cur.uop_type == UOP_WR) ? DEST_NONE :
                                  (cur.a == 6'd32)         ? DEST_NONE :
                                  (cur.fp_bit)             ? DEST_FPR  : DEST_GPR;
    rob_alloc_data.alloc_has_dest = (cur.a != 6'd32) && (cur.uop_type != UOP_WR);
    rob_alloc_data.update_nzcv = cur.set_flags;
    rob_alloc_data.inst_type   =
        (cur.uop_type == UOP_RD)   ? ROB_TYPE_LOAD  :
        (cur.uop_type == UOP_WR)   ? ROB_TYPE_STORE :
        cur.check_target            ? ROB_TYPE_BRANCH :
                                      ROB_TYPE_ALU;
    // ERET has no FU to mark it done; mark ready immediately so the ROB can
    // commit it and (eventually) trigger the flush path.
    rob_alloc_data.ready = (cur.uop_type == UOP_ERET);
end

// ─── Adder RS entry ───────────────────────────────────────────────────────
always_comb begin
    adder_alloc_valid           = do_dispatch && goes_adder;
    adder_alloc_entry           = '0;
    adder_alloc_entry.valid     = 1'b1;
    adder_alloc_entry.rob_tag   = rob_alloc_idx;
    adder_alloc_entry.Vj        = (adder_op == OP_BCOND) ? {16'b0, cur.pc} : Vj;
    // BLR: Vj=reg_n (branch target), Vk carries PC+4 (return address).
    // c=XZR so Vk/Qk were both 0; safe to override.
    adder_alloc_entry.Vk        = (adder_op == OP_BLR) ? ({16'b0, cur.pc} + 64'd4) : Vk;
    adder_alloc_entry.Qj        = Qj;
    adder_alloc_entry.Qk        = (adder_op == OP_BLR) ? 6'b0 : Qk;
    adder_alloc_entry.op        = adder_op;
    adder_alloc_entry.has_rd    = (cur.a != 6'd32);
    // B.cond: pass the condition code via branch_cond.
    // NOTE: uop_t has no cond_code field yet — imm_bits[3:0] is used as
    // a workaround until the decode is extended.
    adder_alloc_entry.branch_cond = (adder_op == OP_BCOND) ?
                                    cond_code_e'(cur.c[3:0]) :
                                    cond_code_e'(cur.imm_bits[3:0]);
    adder_alloc_entry.nzcv        = (adder_op == OP_BCOND) ? Vj[3:0] : 4'b0;
    adder_alloc_entry.shift_amt   = cur.shift_amt;
    adder_alloc_entry.shift_type  = cur.shift_type;
end

// ─── Logic RS entry ───────────────────────────────────────────────────────
always_comb begin
    logic_alloc_valid              = do_dispatch && goes_logic;
    logic_alloc_entry              = '0;
    logic_alloc_entry.valid        = 1'b1;
    logic_alloc_entry.rob_tag      = rob_alloc_idx;
    logic_alloc_entry.Vj           = Vj;
    logic_alloc_entry.Vk           = Vk;
    logic_alloc_entry.Qj           = Qj;
    logic_alloc_entry.Qk           = Qk;
    logic_alloc_entry.op           = 6'(logic_op);
    logic_alloc_entry.updates_nzcv = cur.set_flags;
    logic_alloc_entry.shift_amt    = cur.shift_amt;
    logic_alloc_entry.shift_type   = cur.shift_type;
end

// ─── FPU RS entry ─────────────────────────────────────────────────────────
always_comb begin
    fpu_alloc_valid              = do_dispatch && goes_fpu;
    fpu_alloc_entry              = '0;
    fpu_alloc_entry.valid        = 1'b1;
    fpu_alloc_entry.rob_tag      = rob_alloc_idx;
    fpu_alloc_entry.Vj           = Vj;
    fpu_alloc_entry.Vk           = Vk;
    fpu_alloc_entry.Qj           = Qj;
    fpu_alloc_entry.Qk           = Qk;
    fpu_alloc_entry.rnd_mode     = fpnew_pkg::RNE;
    fpu_alloc_entry.src_fmt      = fpnew_pkg::FP64;
    fpu_alloc_entry.dst_fmt      = fpnew_pkg::FP64;
    fpu_alloc_entry.int_fmt      = fpnew_pkg::INT64;
    fpu_alloc_entry.vectorial_op = 1'b0;
    // Map uop type to fpnew operation
    unique case (cur.uop_type)
        UOP_FADD: begin
            fpu_alloc_entry.op     = fpnew_pkg::ADD;
            fpu_alloc_entry.op_mod = cur.neg_c_or_imm; // 0=FADD, 1=FSUB
        end
        UOP_FMUL: begin
            fpu_alloc_entry.op     = fpnew_pkg::MUL;
            fpu_alloc_entry.op_mod = 1'b0;
        end
        default: begin  // UOP_NAN_CHECK (FCMP path)
            fpu_alloc_entry.op     = fpnew_pkg::CLASSIFY;
            fpu_alloc_entry.op_mod = 1'b0;
        end
    endcase
end

// ─── AGU RS entry ─────────────────────────────────────────────────────────
// For UOP_RD/WR: Vj=base, Vk=offset (always imm), rob_tag = this instruction's
// ROB entry.  The LSQ is dispatched simultaneously with the same rob_tag so it
// can match the AGU's EA broadcast on the CDB.
always_comb begin
    agu_alloc_valid           = do_dispatch && goes_agu;
    agu_alloc_entry           = '0;
    agu_alloc_entry.valid     = 1'b1;
    agu_alloc_entry.rob_tag   = rob_alloc_idx;
    agu_alloc_entry.Vj        = Vj;
    agu_alloc_entry.Vk        = Vk;
    agu_alloc_entry.Qj        = Qj;
    agu_alloc_entry.Qk        = Qk;
    agu_alloc_entry.has_rd    = (cur.a != 6'd32);
    agu_alloc_entry.op        = OP_ADD;
end

// ─── LSQ dispatch ─────────────────────────────────────────────────────────
always_comb begin
    lsq_alloc_valid        = do_dispatch &&
                             (cur.uop_type == UOP_RD || cur.uop_type == UOP_WR);
    lsq_is_load            = (cur.uop_type == UOP_RD);
    lsq_rob_entry_id       = rob_alloc_idx;
    // Store wdata: Vdata/Qdata resolved from the store-data register (a).
    lsq_rob_wdata_entry_id = Qdata;
    lsq_rob_wdata          = Vdata;
    lsq_rob_wdata_ready    = (cur.uop_type == UOP_WR) && (Qdata == 6'b0);
end

// ─── regstate writes ─────────────────────────────────────────────────────
always_comb begin
    // GPR: mark dest busy (skip XZR=32 and stores which write no reg)
    rst_wr_en    = do_dispatch && !cur.fp_bit &&
                   (cur.a != 6'd32) &&
                   (cur.uop_type != UOP_WR);
    rst_wr_addr  = cur.a[4:0];
    rst_rob_idx  = rob_alloc_idx;

    // FPR: mark dest busy
    rst_fp_wr_en    = do_dispatch && cur.fp_bit && (cur.a != 6'd32) &&
                      (cur.uop_type != UOP_WR);
    rst_fp_wr_addr  = cur.a[4:0];
    rst_fp_rob_idx  = rob_alloc_idx;

    // NZCV: mark busy when this instruction writes flags
    rst_nzcv_wr_en   = do_dispatch && cur.set_flags;
    rst_nzcv_rob_idx = rob_alloc_idx;
end

// ─── ready_for_uop ────────────────────────────────────────────────────────
// Asserted on the cycle the LAST uop is successfully dispatched so decode
// can release its hold and reset to state 0 on the next posedge.
always_comb begin
    ready_for_uop = 1'b0;
    if (state == DS_IDLE && uop_valid && !stall && !has_uop1)
        ready_for_uop = 1'b1;   // single-uop instruction, done this cycle
    else if (state == DS_DISP1 && !stall)
        ready_for_uop = 1'b1;   // second uop dispatched, done
end

// ─── FSM ──────────────────────────────────────────────────────────────────
always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n || flush) begin
        state        <= DS_IDLE;
        pending_uop1 <= '0;
    end else begin
        case (state)
            DS_IDLE: begin
                if (uop_valid && !stall && has_uop1) begin
                    // UOP0 dispatched this cycle; latch UOP1 for next cycle.
                    pending_uop1 <= uop_in[1];
                    state        <= DS_DISP1;
                end
            end
            DS_DISP1: begin
                if (!stall) begin
                    state <= DS_IDLE;
                end
                // While stalled, pending_uop1 stays stable.
            end
            default: state <= DS_IDLE;
        endcase
    end
end

endmodule
