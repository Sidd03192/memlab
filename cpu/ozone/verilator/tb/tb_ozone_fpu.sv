/* verilator lint_off UNUSEDSIGNAL */
`timescale 1ns/1ps

module tb_ozone_fpu;
    import ozone_pkg::*;

    localparam int DEPTH = 4;

    // FP64 bit patterns for common values
    // These are IEEE 754 double-precision encodings
    localparam logic [63:0] FP64_1_0  = 64'h3FF0000000000000; // 1.0
    localparam logic [63:0] FP64_2_0  = 64'h4000000000000000; // 2.0
    localparam logic [63:0] FP64_3_0  = 64'h4008000000000000; // 3.0
    localparam logic [63:0] FP64_4_0  = 64'h4010000000000000; // 4.0
    localparam logic [63:0] FP64_6_0  = 64'h4018000000000000; // 6.0
    localparam logic [63:0] FP64_0_5  = 64'h3FE0000000000000; // 0.5
    localparam logic [63:0] FP64_NEG1 = 64'hBFF0000000000000; // -1.0
    localparam logic [63:0] FP64_NEG2 = 64'hC000000000000000; // -2.0
    localparam logic [63:0] FP64_INF  = 64'h7FF0000000000000; // +inf
    localparam logic [63:0] FP64_NAN  = 64'h7FF8000000000000; // canonical qNaN

    logic clk;
    logic rst_n;

    // regstate
    logic                      reg_flush;
    logic [4:0]                src1_addr;
    logic [4:0]                src2_addr;
    logic [4:0]                fp_src1_addr;
    logic [4:0]                fp_src2_addr;
    reg_entry_t                src1_status;
    reg_entry_t                src2_status;
    reg_entry_t                fp_src1_status;
    reg_entry_t                fp_src2_status;
    reg_entry_t                nzcv_status;
    logic                      disp_wr_en;
    logic [4:0]                disp_wr_addr;
    logic [ROB_IDX_WIDTH-1:0]  disp_rob_idx;
    logic                      disp_fp_wr_en;
    logic [4:0]                disp_fp_wr_addr;
    logic [ROB_IDX_WIDTH-1:0]  disp_fp_rob_idx;
    logic                      disp_nzcv_wr_en;
    logic [ROB_IDX_WIDTH-1:0]  disp_nzcv_rob_idx;

    // rob
    logic [ROB_IDX_WIDTH-1:0]  src1_rob_idx;
    logic [ROB_IDX_WIDTH-1:0]  src2_rob_idx;
    logic                      src1_ready;
    logic [63:0]               src1_value;
    logic                      src2_ready;
    logic [63:0]               src2_value;
    logic                      rob_alloc_valid;
    logic                      alloc_has_dest;
    rob_entry_t                alloc_data;
    logic [ROB_IDX_WIDTH-1:0]  alloc_rob_idx;
    logic                      rob_full;
    logic [ROB_IDX_WIDTH-1:0]  rob_head;
    logic                      commit_valid;
    rob_entry_t                commit_data;
    logic                      commit_reg_en;
    logic [4:0]                commit_reg_addr;
    logic [63:0]               commit_reg_value;
    logic [ROB_IDX_WIDTH-1:0]  commit_reg_rob_idx;
    logic                      commit_fp_en;
    logic [4:0]                commit_fp_addr;
    logic [63:0]               commit_fp_value;
    logic [ROB_IDX_WIDTH-1:0]  commit_fp_rob_idx;
    logic                      commit_nzcv_en;
    logic [3:0]                commit_nzcv_value;
    logic [ROB_IDX_WIDTH-1:0]  commit_nzcv_rob_idx;
    logic                      lsq_store_commit;
    logic [63:0]               lsq_store_addr;
    logic [63:0]               lsq_store_data;
    logic                      bp_update_valid;
    logic [63:0]               bp_update_pc;
    logic                      bp_update_taken;
    logic [63:0]               bp_update_target;
    logic                      pipe_flush;
    logic [63:0]               flush_target_pc;
    logic                      exception_valid;
    logic [63:0]               exception_pc;
    logic [3:0]                exception_code;

    // fpu
    logic                      fpu_alloc_valid;
    rs_entry_fp_t              fpu_alloc_entry;
    logic                      fpu_full;
    cdb_broadcast_t            fpu_req;
    logic                      fpu_granted;

    // cdb
    cdb_broadcast_t            cdb_broadcast;
    cdb_broadcast_t            zero_req;
    cdb_broadcast_t            blocker_req;
    logic                      unused_adder_granted;
    logic                      unused_logic_granted;
    logic                      unused_mem_granted;

    int failures;

    assign zero_req  = '0;
    assign reg_flush = pipe_flush;

    ozone_regstate regstate (
        .clk(clk),
        .rst_n(rst_n),
        .flush(reg_flush),
        .src1_addr(src1_addr),
        .src2_addr(src2_addr),
        .fp_src1_addr(fp_src1_addr),
        .fp_src2_addr(fp_src2_addr),
        .src1_status(src1_status),
        .src2_status(src2_status),
        .fp_src1_status(fp_src1_status),
        .fp_src2_status(fp_src2_status),
        .nzcv_status(nzcv_status),
        .disp_wr_en(disp_wr_en),
        .disp_wr_addr(disp_wr_addr),
        .disp_rob_idx(disp_rob_idx),
        .disp_fp_wr_en(disp_fp_wr_en),
        .disp_fp_wr_addr(disp_fp_wr_addr),
        .disp_fp_rob_idx(disp_fp_rob_idx),
        .disp_nzcv_wr_en(disp_nzcv_wr_en),
        .disp_nzcv_rob_idx(disp_nzcv_rob_idx),
        .commit_en(commit_reg_en),
        .commit_addr(commit_reg_addr),
        .commit_value(commit_reg_value),
        .commit_rob_idx(commit_reg_rob_idx),
        .commit_fp_en(commit_fp_en),
        .commit_fp_addr(commit_fp_addr),
        .commit_fp_value(commit_fp_value),
        .commit_fp_rob_idx(commit_fp_rob_idx),
        .commit_nzcv_en(commit_nzcv_en),
        .commit_nzcv_value(commit_nzcv_value),
        .commit_nzcv_rob_idx(commit_nzcv_rob_idx)
    );

    ozone_rob rob (
        .clk(clk),
        .rst_n(rst_n),
        .src1_rob_idx(src1_rob_idx),
        .src2_rob_idx(src2_rob_idx),
        .src1_ready(src1_ready),
        .src1_value(src1_value),
        .src2_ready(src2_ready),
        .src2_value(src2_value),
        .alloc_valid(rob_alloc_valid),
        .alloc_has_dest(alloc_has_dest),
        .alloc_data(alloc_data),
        .alloc_rob_idx(alloc_rob_idx),
        .rob_full(rob_full),
        .rob_head(rob_head),
        .cdb_in(cdb_broadcast),
        .commit_valid(commit_valid),
        .commit_data(commit_data),
        .commit_reg_en(commit_reg_en),
        .commit_reg_addr(commit_reg_addr),
        .commit_reg_value(commit_reg_value),
        .commit_reg_rob_idx(commit_reg_rob_idx),
        .commit_fp_en(commit_fp_en),
        .commit_fp_addr(commit_fp_addr),
        .commit_fp_value(commit_fp_value),
        .commit_fp_rob_idx(commit_fp_rob_idx),
        .commit_nzcv_en(commit_nzcv_en),
        .commit_nzcv_value(commit_nzcv_value),
        .commit_nzcv_rob_idx(commit_nzcv_rob_idx),
        .lsq_store_commit(lsq_store_commit),
        .lsq_store_addr(lsq_store_addr),
        .lsq_store_data(lsq_store_data),
        .bp_update_valid(bp_update_valid),
        .bp_update_pc(bp_update_pc),
        .bp_update_taken(bp_update_taken),
        .bp_update_target(bp_update_target),
        .flush(pipe_flush),
        .flush_target_pc(flush_target_pc),
        .exception_valid(exception_valid),
        .exception_pc(exception_pc),
        .exception_code(exception_code)
    );

    fpnew_top #(.DEPTH(DEPTH)) fpu (
        .clk(clk),
        .rst_n(rst_n),
        .flush(reg_flush),
        .alloc_valid(fpu_alloc_valid),
        .alloc_entry(fpu_alloc_entry),
        .full(fpu_full),
        .cdb_in(cdb_broadcast),
        .cdb_out(fpu_req),
        .cdb_granted(fpu_granted)
    );

    ozone_cdb cdb (
        .adder_req(blocker_req),
        .logic_req(zero_req),
        .fpu_req(fpu_req),
        .mem_req(zero_req),
        .rob_head(rob_head),
        .cdb_broadcast(cdb_broadcast),
        .adder_granted(unused_adder_granted),
        .logic_granted(unused_logic_granted),
        .fpu_granted(fpu_granted),
        .mem_granted(unused_mem_granted)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    // -------------------------------------------------------
    // Utility functions
    // -------------------------------------------------------
    function automatic cdb_broadcast_t make_blocker_req(
        input logic [ROB_IDX_WIDTH-1:0] tag
    );
        cdb_broadcast_t req;
        req              = '0;
        req.valid        = 1'b1;
        req.rob_tag      = tag;
        req.cdb_value_en = 1'b0;
        req.rob_wb_en    = 1'b0;
        make_blocker_req = req;
    endfunction

    task automatic clear_inputs();
        begin
            src1_addr          = '0;
            src2_addr          = '0;
            fp_src1_addr       = '0;
            fp_src2_addr       = '0;
            src1_rob_idx       = '0;
            src2_rob_idx       = '0;
            disp_wr_en         = 1'b0;
            disp_wr_addr       = '0;
            disp_rob_idx       = '0;
            disp_fp_wr_en      = 1'b0;
            disp_fp_wr_addr    = '0;
            disp_fp_rob_idx    = '0;
            disp_nzcv_wr_en    = 1'b0;
            disp_nzcv_rob_idx  = '0;
            rob_alloc_valid    = 1'b0;
            alloc_has_dest     = 1'b0;
            alloc_data         = '0;
            fpu_alloc_valid    = 1'b0;
            fpu_alloc_entry    = '0;
            blocker_req        = '0;
        end
    endtask

    task automatic reset_dut();
        begin
            clear_inputs();
            rst_n = 1'b0;
            repeat (3) @(posedge clk);
            rst_n = 1'b1;
            @(posedge clk);
            #1;
            clear_inputs();
        end
    endtask

    // Preload an FP register directly into regstate
    task automatic preload_fpr(input int idx, input logic [63:0] value);
        begin
            regstate.fp_reg[idx].value   = value;
            regstate.fp_reg[idx].busy    = 1'b0;
            regstate.fp_reg[idx].rob_idx = '0;
        end
    endtask

    task automatic check_true(input bit cond, input string label);
        begin
            if (!cond) begin
                failures++;
                $display("[FAIL] %s", label);
            end
        end
    endtask

    task automatic check_u64(
        input logic [63:0] got,
        input logic [63:0] expected,
        input string label
    );
        begin
            if (got !== expected) begin
                failures++;
                $display("[FAIL] %s expected=0x%016h got=0x%016h", label, expected, got);
            end
        end
    endtask

    // Resolve FP register sources through regstate + ROB, mirroring dispatch logic
    task automatic resolve_fpr_sources(
        input  logic [4:0] reg_a,
        input  logic [4:0] reg_b,
        output logic [63:0] vj,
        output logic [ROB_IDX_WIDTH-1:0] qj,
        output logic [63:0] vk,
        output logic [ROB_IDX_WIDTH-1:0] qk
    );
        begin
            fp_src1_addr = reg_a;
            fp_src2_addr = reg_b;
            src1_rob_idx = '0;
            src2_rob_idx = '0;
            #1;

            src1_rob_idx = fp_src1_status.rob_idx;
            src2_rob_idx = fp_src2_status.rob_idx;
            #1;

            if (!fp_src1_status.busy) begin
                vj = fp_src1_status.value;
                qj = '0;
            end else if (src1_ready) begin
                vj = src1_value;
                qj = '0;
            end else begin
                vj = '0;
                qj = fp_src1_status.rob_idx;
            end

            if (!fp_src2_status.busy) begin
                vk = fp_src2_status.value;
                qk = '0;
            end else if (src2_ready) begin
                vk = src2_value;
                qk = '0;
            end else begin
                vk = '0;
                qk = fp_src2_status.rob_idx;
            end
        end
    endtask

    // Dispatch an FP register-register operation
    task automatic dispatch_fpu_rr(
        input  fpnew_pkg::operation_e op,
        input  logic [4:0] src1_reg,
        input  logic [4:0] src2_reg,
        input  logic [4:0] dest_reg,
        output logic [ROB_IDX_WIDTH-1:0] tag_out
    );
        logic [63:0] vj, vk;
        logic [ROB_IDX_WIDTH-1:0] qj, qk;
        rs_entry_fp_t entry;
        rob_entry_t   rob_entry;
        begin
            while (rob_full || fpu_full) @(negedge clk);
            resolve_fpr_sources(src1_reg, src2_reg, vj, qj, vk, qk);
            tag_out = alloc_rob_idx;

            entry             = '0;
            entry.Vj          = vj;
            entry.Vk          = vk;
            entry.Qj          = qj;
            entry.Qk          = qk;
            entry.rob_tag     = tag_out;
            entry.op          = op;
            entry.op_mod      = 1'b0;
            entry.src_fmt     = fpnew_pkg::FP64;
            entry.dst_fmt     = fpnew_pkg::FP64;
            entry.int_fmt     = fpnew_pkg::INT64;
            entry.rnd_mode    = fpnew_pkg::RNE;
            entry.vectorial_op = 1'b0;

            rob_entry                = '0;
            rob_entry.inst_type      = ROB_TYPE_ALU;
            rob_entry.dest_reg       = dest_reg;
            rob_entry.dest_type      = DEST_FPR;
            rob_entry.alloc_has_dest = 1'b1;

            @(negedge clk);
            alloc_data         = rob_entry;
            alloc_has_dest     = 1'b1;
            rob_alloc_valid    = 1'b1;
            fpu_alloc_entry    = entry;
            fpu_alloc_valid    = 1'b1;
            disp_fp_wr_en      = 1'b1;
            disp_fp_wr_addr    = dest_reg;
            disp_fp_rob_idx    = tag_out;
            @(posedge clk);
            #1;
            clear_inputs();
        end
    endtask

    // Wait for a specific FP register to reach an expected bit-exact value
    task automatic wait_for_fpr_value(
        input int reg_idx,
        input logic [63:0] expected,
        input string label
    );
        int cycles;
        begin
            cycles = 0;
            while (((regstate.fp_reg[reg_idx].value !== expected) ||
                     regstate.fp_reg[reg_idx].busy) &&
                   (cycles < 60)) begin
                @(posedge clk);
                #1;
                cycles++;
            end
            check_u64(regstate.fp_reg[reg_idx].value, expected, label);
            check_true(!regstate.fp_reg[reg_idx].busy, {label, " busy clear"});
        end
    endtask

    // -------------------------------------------------------
    // Tests
    // -------------------------------------------------------

    // 1.0 + 2.0 = 3.0
    task automatic test_basic_fadd();
        logic [ROB_IDX_WIDTH-1:0] tag;
        begin
            $display("Running basic FADD commit");
            reset_dut();
            preload_fpr(1, FP64_1_0);
            preload_fpr(2, FP64_2_0);
            dispatch_fpu_rr(fpnew_pkg::ADD, 5'd1, 5'd2, 5'd3, tag);
            wait_for_fpr_value(3, FP64_3_0, "fadd f3 = 1.0+2.0");
            check_true(rob.rob_entries[tag].ready, "fadd rob entry became ready");
        end
    endtask

    // 3.0 - 1.0 = 2.0  (SUB is ADD with op_mod=1 in fpnew)
    task automatic test_basic_fsub();
        logic [ROB_IDX_WIDTH-1:0] tag;
        rs_entry_fp_t entry;
        rob_entry_t   rob_entry;
        logic [63:0] vj, vk;
        logic [ROB_IDX_WIDTH-1:0] qj, qk;
        begin
            $display("Running basic FSUB commit");
            reset_dut();
            preload_fpr(1, FP64_3_0);
            preload_fpr(2, FP64_1_0);

            // FSUB = ADD with op_mod asserted — dispatch manually so we can set op_mod
            while (rob_full || fpu_full) @(negedge clk);
            resolve_fpr_sources(5'd1, 5'd2, vj, qj, vk, qk);
            tag = alloc_rob_idx;

            entry              = '0;
            entry.Vj           = vj;
            entry.Vk           = vk;
            entry.Qj           = qj;
            entry.Qk           = qk;
            entry.rob_tag      = tag;
            entry.op           = fpnew_pkg::ADD;
            entry.op_mod       = 1'b1;       // negate second operand → SUB
            entry.src_fmt      = fpnew_pkg::FP64;
            entry.dst_fmt      = fpnew_pkg::FP64;
            entry.int_fmt      = fpnew_pkg::INT64;
            entry.rnd_mode     = fpnew_pkg::RNE;
            entry.vectorial_op = 1'b0;

            rob_entry                = '0;
            rob_entry.inst_type      = ROB_TYPE_ALU;
            rob_entry.dest_reg       = 5'd4;
            rob_entry.dest_type      = DEST_FPR;
            rob_entry.alloc_has_dest = 1'b1;

            @(negedge clk);
            alloc_data      = rob_entry;
            alloc_has_dest  = 1'b1;
            rob_alloc_valid = 1'b1;
            fpu_alloc_entry = entry;
            fpu_alloc_valid = 1'b1;
            disp_fp_wr_en   = 1'b1;
            disp_fp_wr_addr = 5'd4;
            disp_fp_rob_idx = tag;
            @(posedge clk);
            #1;
            clear_inputs();

            wait_for_fpr_value(4, FP64_2_0, "fsub f4 = 3.0-1.0");
            check_true(rob.rob_entries[tag].ready, "fsub rob entry became ready");
        end
    endtask

    // 2.0 * 3.0 = 6.0
    task automatic test_basic_fmul();
        logic [ROB_IDX_WIDTH-1:0] tag;
        begin
            $display("Running basic FMUL commit");
            reset_dut();
            preload_fpr(1, FP64_2_0);
            preload_fpr(2, FP64_3_0);
            dispatch_fpu_rr(fpnew_pkg::MUL, 5'd1, 5'd2, 5'd5, tag);
            wait_for_fpr_value(5, FP64_6_0, "fmul f5 = 2.0*3.0");
            check_true(rob.rob_entries[tag].ready, "fmul rob entry became ready");
        end
    endtask

    // 1.0 + (-1.0) = 0.0 — checks zero result path
    task automatic test_fadd_zero_result();
        logic [ROB_IDX_WIDTH-1:0] tag;
        begin
            $display("Running FADD zero result");
            reset_dut();
            preload_fpr(1, FP64_1_0);
            preload_fpr(2, FP64_NEG1);
            dispatch_fpu_rr(fpnew_pkg::ADD, 5'd1, 5'd2, 5'd6, tag);
            // +0.0 in FP64
            wait_for_fpr_value(6, 64'h0000000000000000, "fadd zero f6 = 1.0+(-1.0)");
        end
    endtask

    // inf + 1.0 = inf — checks NV status flag
    task automatic test_fadd_infinity();
        logic [ROB_IDX_WIDTH-1:0] tag;
        begin
            $display("Running FADD infinity propagation");
            reset_dut();
            preload_fpr(1, FP64_INF);
            preload_fpr(2, FP64_1_0);
            dispatch_fpu_rr(fpnew_pkg::ADD, 5'd1, 5'd2, 5'd7, tag);
            wait_for_fpr_value(7, FP64_INF, "fadd inf f7 = inf+1.0");
            // fp_status.OF should be set
            while (!fpu.result.valid && fpu.result.rob_tag != tag)
                @(posedge clk);
            check_true(fpu.result.fp_status.OF, "fadd inf sets OF flag");
        end
    endtask

    // CDB wakeup: dispatch two adds where the second depends on the first
    task automatic test_cdb_wakeup_chain();
        logic [ROB_IDX_WIDTH-1:0] tag1, tag2;
        begin
            $display("Running FPU CDB wakeup chain");
            reset_dut();
            preload_fpr(1, FP64_1_0);
            preload_fpr(2, FP64_2_0);

            // f3 = f1 + f2 = 3.0
            dispatch_fpu_rr(fpnew_pkg::ADD, 5'd1, 5'd2, 5'd3, tag1);

            // f4 = f3 + f2 = 5.0  — f3 not ready yet, Qj should be set to tag1
            dispatch_fpu_rr(fpnew_pkg::ADD, 5'd3, 5'd2, 5'd4, tag2);

            wait_for_fpr_value(3, FP64_3_0, "chain fadd f3");
            wait_for_fpr_value(4, 64'h4014000000000000 /* 5.0 */, "chain fadd f4");
        end
    endtask

    // Hold result when CDB is blocked, then release
    task automatic test_hold_until_grant();
        logic [ROB_IDX_WIDTH-1:0] tag;
        begin
            $display("Running FPU hold until grant");
            reset_dut();
            preload_fpr(1, FP64_1_0);
            preload_fpr(2, FP64_2_0);
            dispatch_fpu_rr(fpnew_pkg::ADD, 5'd1, 5'd2, 5'd8, tag);

            // Wait for result to land in the holding register
            while (!(fpu.result.valid && fpu.result.rob_tag == tag)) begin
                @(posedge clk);
                #1;
            end

            // Block the CDB for one cycle
            blocker_req = make_blocker_req(tag);
            check_true(cdb_broadcast.rob_tag == blocker_req.rob_tag, "blocker wins CDB first");
            check_true(fpu.result.valid, "fpu result held without grant");

            blocker_req = '0;
            @(posedge clk);
            #1;
            check_true(cdb_broadcast.rob_tag == tag, "fpu wins after blocker cleared");
            wait_for_fpr_value(8, FP64_3_0, "held fadd commit f8");
            clear_inputs();
        end
    endtask

    // Fill the RS, check full signal, drain and check it clears
    task automatic test_rs_full();
        logic [ROB_IDX_WIDTH-1:0] tags [0:DEPTH-1];
        begin
            $display("Running FPU RS full");
            reset_dut();
            // Use a value that keeps all operands ready so entries issue immediately —
            // we want to observe full while they queue up then drain
            preload_fpr(1, FP64_1_0);
            preload_fpr(2, FP64_1_0);

            // Block CDB so results pile up in holding register and back-pressure the RS
            // after the first result so subsequent ops can't issue
            dispatch_fpu_rr(fpnew_pkg::ADD, 5'd1, 5'd2, 5'd10, tags[0]);
            while (!(fpu.result.valid && fpu.result.rob_tag == tags[0])) begin
                @(posedge clk); #1;
            end
            blocker_req = make_blocker_req(tags[0]);

            dispatch_fpu_rr(fpnew_pkg::ADD, 5'd1, 5'd2, 5'd11, tags[1]);
            dispatch_fpu_rr(fpnew_pkg::ADD, 5'd1, 5'd2, 5'd12, tags[2]);
            dispatch_fpu_rr(fpnew_pkg::ADD, 5'd1, 5'd2, 5'd13, tags[3]);

            @(posedge clk); #1;
            check_true(fpu_full, "fpu RS reports full");

            blocker_req = '0;

            // All four should eventually commit
            wait_for_fpr_value(10, FP64_2_0, "rs_full f10");
            wait_for_fpr_value(11, FP64_2_0, "rs_full f11");
            wait_for_fpr_value(12, FP64_2_0, "rs_full f12");
            wait_for_fpr_value(13, FP64_2_0, "rs_full f13");
            check_true(!fpu_full, "fpu RS no longer full after drain");
        end
    endtask

    // -------------------------------------------------------
    // Top-level
    // -------------------------------------------------------
    initial begin
        failures = 0;
        clear_inputs();

        test_basic_fadd();
        test_basic_fsub();
        test_basic_fmul();
        test_fadd_zero_result();
        test_fadd_infinity();
        test_cdb_wakeup_chain();
        test_hold_until_grant();
        test_rs_full();

        if (failures != 0) begin
            $fatal(1, "tb_ozone_fpu failed with %0d failures", failures);
        end

        $display("tb_ozone_fpu passed");
        $finish;
    end

endmodule
/* verilator lint_on UNUSEDSIGNAL */