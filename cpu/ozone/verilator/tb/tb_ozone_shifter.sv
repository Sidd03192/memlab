/* verilator lint_off UNUSEDSIGNAL */
`timescale 1ns/1ps

module tb_ozone_shifter;
    import ozone_pkg::*;

    localparam int DEPTH = 4;

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
    logic [7:0]                exception_code;

    // shifter
    logic                      shifter_alloc_valid;
    rs_entry_t                 shifter_alloc_entry;
    logic                      shifter_full;
    cdb_broadcast_t            shifter_req;
    logic                      shifter_granted;

    // cdb
    cdb_broadcast_t            cdb_broadcast;
    cdb_broadcast_t            zero_req;
    cdb_broadcast_t            blocker_req;
    logic                      unused_adder_granted;
    logic                      unused_logic_granted;
    logic                      unused_fpu_granted;

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
        .bp_update_ghr(),
        .flush(pipe_flush),
        .flush_target_pc(flush_target_pc),
        .exception_valid(exception_valid),
        .exception_pc(exception_pc),
        .exception_code(exception_code)
    );

    ozone_shifter #(.DEPTH(DEPTH)) shifter (
        .clk(clk),
        .rst_n(rst_n),
        .flush(reg_flush),
        .alloc_valid(shifter_alloc_valid),
        .alloc_entry(shifter_alloc_entry),
        .full(shifter_full),
        .cdb_in(cdb_broadcast),
        .cdb_out(shifter_req),
        .cdb_granted(shifter_granted)
    );

    ozone_cdb cdb (
        .adder_req(blocker_req),
        .logic_req(zero_req),
        .fpu_req(zero_req),
        .mem_req(shifter_req),
        .rob_head(rob_head),
        .cdb_broadcast(cdb_broadcast),
        .adder_granted(unused_adder_granted),
        .logic_granted(unused_logic_granted),
        .fpu_granted(unused_fpu_granted),
        .mem_granted(shifter_granted)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    function automatic cdb_broadcast_t make_req(
        input logic [ROB_IDX_WIDTH-1:0] tag,
        input logic [63:0] value
    );
        cdb_broadcast_t req;
        req              = '0;
        req.valid        = 1'b1;
        req.rob_tag      = tag;
        req.cdb_value_en = 1'b1;
        req.rob_wb_en    = 1'b1;
        req.value        = value;
        make_req         = req;
    endfunction

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
            src1_addr           = '0;
            src2_addr           = '0;
            fp_src1_addr        = '0;
            fp_src2_addr        = '0;
            src1_rob_idx        = '0;
            src2_rob_idx        = '0;
            disp_wr_en          = 1'b0;
            disp_wr_addr        = '0;
            disp_rob_idx        = '0;
            disp_fp_wr_en       = 1'b0;
            disp_fp_wr_addr     = '0;
            disp_fp_rob_idx     = '0;
            disp_nzcv_wr_en     = 1'b0;
            disp_nzcv_rob_idx   = '0;
            rob_alloc_valid     = 1'b0;
            alloc_has_dest      = 1'b0;
            alloc_data          = '0;
            shifter_alloc_valid = 1'b0;
            shifter_alloc_entry = '0;
            blocker_req         = '0;
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

    task automatic preload_gpr(input int idx, input logic [63:0] value);
        begin
            regstate.gp_reg[idx].value   = value;
            regstate.gp_reg[idx].busy    = 1'b0;
            regstate.gp_reg[idx].rob_idx = '0;
        end
    endtask

    task automatic preload_nzcv(input logic [3:0] flags);
        begin
            regstate.nzcv_reg.value   = {60'b0, flags};
            regstate.nzcv_reg.busy    = 1'b0;
            regstate.nzcv_reg.rob_idx = '0;
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

    task automatic check_u4(
        input logic [3:0] got,
        input logic [3:0] expected,
        input string label
    );
        begin
            if (got !== expected) begin
                failures++;
                $display("[FAIL] %s expected=0x%0h got=0x%0h", label, expected, got);
            end
        end
    endtask

    task automatic resolve_gpr_sources(
        input  logic [4:0] reg_a,
        input  logic [4:0] reg_b,
        output logic [63:0] vj,
        output logic [ROB_IDX_WIDTH-1:0] qj,
        output logic [63:0] vk,
        output logic [ROB_IDX_WIDTH-1:0] qk
    );
        begin
            src1_addr    = reg_a;
            src2_addr    = reg_b;
            src1_rob_idx = '0;
            src2_rob_idx = '0;
            #1;

            src1_rob_idx = src1_status.rob_idx;
            src2_rob_idx = src2_status.rob_idx;
            #1;

            if (!src1_status.busy) begin
                vj = src1_status.value;
                qj = '0;
            end else if (src1_ready) begin
                vj = src1_value;
                qj = '0;
            end else begin
                vj = '0;
                qj = src1_status.rob_idx;
            end

            if (!src2_status.busy) begin
                vk = src2_status.value;
                qk = '0;
            end else if (src2_ready) begin
                vk = src2_value;
                qk = '0;
            end else begin
                vk = '0;
                qk = src2_status.rob_idx;
            end
        end
    endtask

    task automatic dispatch_shift_rr(
        input  adder_op_e op,
        input  logic [4:0] value_reg,
        input  logic [4:0] shamt_reg,
        input  logic [4:0] dest_reg,
        input  logic       writes_nzcv,
        output logic [ROB_IDX_WIDTH-1:0] tag_out
    );
        logic [63:0] vj;
        logic [63:0] vk;
        logic [ROB_IDX_WIDTH-1:0] qj;
        logic [ROB_IDX_WIDTH-1:0] qk;
        rs_entry_t entry;
        rob_entry_t rob_entry;
        begin
            while (rob_full || shifter_full) @(negedge clk);
            resolve_gpr_sources(value_reg, shamt_reg, vj, qj, vk, qk);
            tag_out = alloc_rob_idx;

            entry              = '0;
            entry.Vj           = vj;
            entry.Vk           = vk;
            entry.Qj           = qj;
            entry.Qk           = qk;
            entry.rob_tag      = tag_out;
            entry.op           = op;
            entry.updates_nzcv = writes_nzcv;

            rob_entry                = '0;
            rob_entry.inst_type      = ROB_TYPE_ALU;
            rob_entry.dest_reg       = dest_reg;
            rob_entry.dest_type      = DEST_GPR;
            rob_entry.alloc_has_dest = 1'b1;
            rob_entry.update_nzcv    = writes_nzcv;

            @(negedge clk);
            alloc_data          = rob_entry;
            alloc_has_dest      = 1'b1;
            rob_alloc_valid     = 1'b1;
            shifter_alloc_entry = entry;
            shifter_alloc_valid = 1'b1;
            disp_wr_en          = 1'b1;
            disp_wr_addr        = dest_reg;
            disp_rob_idx        = tag_out;
            disp_nzcv_wr_en     = writes_nzcv;
            disp_nzcv_rob_idx   = tag_out;
            @(posedge clk);
            #1;
            clear_inputs();
        end
    endtask

    function automatic int find_shifter_slot(input logic [ROB_IDX_WIDTH-1:0] tag);
        int idx;
        begin
            find_shifter_slot = -1;
            for (idx = 0; idx < DEPTH; idx++) begin
                if (shifter.entries[idx].valid && shifter.entries[idx].rob_tag == tag)
                    find_shifter_slot = idx;
            end
        end
    endfunction

    task automatic wait_for_gpr_value(
        input int reg_idx,
        input logic [63:0] expected,
        input string label
    );
        int cycles;
        begin
            cycles = 0;
            while (((regstate.gp_reg[reg_idx].value !== expected) ||
                    regstate.gp_reg[reg_idx].busy) &&
                   (cycles < 40)) begin
                @(posedge clk);
                #1;
                cycles++;
            end
            check_u64(regstate.gp_reg[reg_idx].value, expected, label);
            check_true(!regstate.gp_reg[reg_idx].busy, {label, " busy clear"});
        end
    endtask

    task automatic wait_for_nzcv_value(
        input logic [3:0] expected,
        input string label
    );
        int cycles;
        begin
            cycles = 0;
            while (((regstate.nzcv_reg.value[3:0] !== expected) ||
                    regstate.nzcv_reg.busy) &&
                   (cycles < 40)) begin
                @(posedge clk);
                #1;
                cycles++;
            end
            check_u4(regstate.nzcv_reg.value[3:0], expected, label);
            check_true(!regstate.nzcv_reg.busy, {label, " busy clear"});
        end
    endtask

    task automatic test_basic_lsl_commit();
        logic [ROB_IDX_WIDTH-1:0] tag;
        begin
            $display("Running basic LSL commit");
            reset_dut();
            preload_gpr(1, 64'd3);
            preload_gpr(2, 64'd2);
            dispatch_shift_rr(OP_LSL, 5'd1, 5'd2, 5'd3, 1'b0, tag);
            wait_for_gpr_value(3, 64'd12, "lsl commit x3");
            check_true(rob.rob_entries[tag].ready, "lsl rob entry became ready");
        end
    endtask

    task automatic test_basic_lsr_commit();
        logic [ROB_IDX_WIDTH-1:0] tag;
        begin
            $display("Running basic LSR commit");
            reset_dut();
            preload_gpr(1, 64'd40);
            preload_gpr(2, 64'd3);
            dispatch_shift_rr(OP_LSR, 5'd1, 5'd2, 5'd4, 1'b0, tag);
            wait_for_gpr_value(4, 64'd5, "lsr commit x4");
            check_true(rob.rob_entries[tag].ready, "lsr rob entry became ready");
        end
    endtask

    task automatic test_basic_asr_commit();
        logic [ROB_IDX_WIDTH-1:0] tag;
        begin
            $display("Running basic ASR commit");
            reset_dut();
            preload_gpr(1, 64'hFFFF_FFFF_FFFF_FFF0);
            preload_gpr(2, 64'd2);
            dispatch_shift_rr(OP_ASR, 5'd1, 5'd2, 5'd5, 1'b0, tag);
            wait_for_gpr_value(5, 64'hFFFF_FFFF_FFFF_FFFC, "asr commit x5");
            check_true(rob.rob_entries[tag].ready, "asr rob entry became ready");
        end
    endtask

    task automatic test_local_forwarding();
        logic [ROB_IDX_WIDTH-1:0] seed_tag;
        logic [ROB_IDX_WIDTH-1:0] prod_tag;
        logic [ROB_IDX_WIDTH-1:0] cons_tag;
        int cons_slot;
        begin
            $display("Running shifter local forwarding");
            reset_dut();
            preload_gpr(1, 64'd4);
            preload_gpr(2, 64'd1);
            preload_gpr(3, 64'd2);
            preload_gpr(11, 64'd9);
            preload_gpr(12, 64'd1);

            // Hold an older seed result on the CDB so the producer and consumer
            // can both sit in the RS before the producer is allowed to issue.
            dispatch_shift_rr(OP_LSL, 5'd11, 5'd12, 5'd30, 1'b0, seed_tag);
            while (!(shifter.result.valid && shifter.result.rob_tag == seed_tag)) begin
                @(posedge clk);
                #1;
            end
            blocker_req = make_blocker_req(seed_tag);

            dispatch_shift_rr(OP_LSL, 5'd1, 5'd2, 5'd4, 1'b0, prod_tag);
            dispatch_shift_rr(OP_LSR, 5'd4, 5'd3, 5'd5, 1'b0, cons_tag);

            blocker_req = '0;

            while (!(shifter.result.valid && shifter.result.rob_tag == prod_tag)) begin
                @(posedge clk);
                #1;
            end

            cons_slot = find_shifter_slot(cons_tag);
            check_true(cons_slot >= 0, "shifter consumer still in RS");
            if (cons_slot >= 0) begin
                check_true(shifter.entries[cons_slot].Qj == '0, "shifter consumer Qj cleared by local forward");
                check_u64(shifter.entries[cons_slot].Vj, 64'd8, "shifter consumer forwarded value");
            end

            wait_for_gpr_value(4, 64'd8, "shifter producer commit x4");
            wait_for_gpr_value(5, 64'd2, "shifter consumer commit x5");
        end
    endtask

    task automatic test_hold_until_grant();
        logic [ROB_IDX_WIDTH-1:0] tag;
        begin
            $display("Running shifter hold until grant");
            reset_dut();
            preload_gpr(1, 64'd5);
            preload_gpr(2, 64'd1);
            dispatch_shift_rr(OP_LSL, 5'd1, 5'd2, 5'd6, 1'b0, tag);

            while (!(shifter.result.valid && shifter.result.rob_tag == tag)) begin
                @(posedge clk);
                #1;
            end
            // Synthetic request blocks the CDB for a cycle without touching the ROB.
            blocker_req = make_blocker_req(tag);

            check_true(cdb_broadcast.rob_tag == blocker_req.rob_tag, "blocker wins cdb first");
            check_true(shifter.result.valid, "shifter result held without grant");

            blocker_req = '0;
            @(posedge clk);
            #1;
            check_true(cdb_broadcast.rob_tag == tag, "shifter wins after blocker cleared");
            wait_for_gpr_value(6, 64'd10, "held shifter commit x6");
            clear_inputs();
        end
    endtask

    task automatic test_carry_only_flags();
        logic [ROB_IDX_WIDTH-1:0] tag;
        begin
            $display("Running shifter carry-only flags");
            reset_dut();
            preload_nzcv(4'b1111);

            preload_gpr(1, 64'h8000_0000_0000_0001);
            preload_gpr(2, 64'd1);
            dispatch_shift_rr(OP_LSL, 5'd1, 5'd2, 5'd7, 1'b1, tag);
            while (!(shifter.result.valid && shifter.result.rob_tag == tag)) begin
                @(posedge clk);
                #1;
            end
            check_u4(shifter.result.nzcv, 4'b0010, "lsl carry-only flags");
            wait_for_nzcv_value(4'b0010, "lsl carry commit");
            wait_for_gpr_value(7, 64'h0000_0000_0000_0002, "lsl carry result");

            reset_dut();
            preload_nzcv(4'b1111);
            preload_gpr(1, 64'd3);
            preload_gpr(2, 64'd1);
            dispatch_shift_rr(OP_LSR, 5'd1, 5'd2, 5'd8, 1'b1, tag);
            while (!(shifter.result.valid && shifter.result.rob_tag == tag)) begin
                @(posedge clk);
                #1;
            end
            check_u4(shifter.result.nzcv, 4'b0010, "lsr carry-only flags");
            wait_for_nzcv_value(4'b0010, "lsr carry commit");

            reset_dut();
            preload_nzcv(4'b1111);
            preload_gpr(1, 64'h8000_0000_0000_0003);
            preload_gpr(2, 64'd1);
            dispatch_shift_rr(OP_ASR, 5'd1, 5'd2, 5'd9, 1'b1, tag);
            while (!(shifter.result.valid && shifter.result.rob_tag == tag)) begin
                @(posedge clk);
                #1;
            end
            check_u4(shifter.result.nzcv, 4'b0010, "asr carry-only flags");
            wait_for_nzcv_value(4'b0010, "asr carry commit");

            reset_dut();
            preload_nzcv(4'b1111);
            preload_gpr(1, 64'h8000_0000_0000_0001);
            preload_gpr(2, 64'd0);
            dispatch_shift_rr(OP_LSL, 5'd1, 5'd2, 5'd10, 1'b1, tag);
            while (!(shifter.result.valid && shifter.result.rob_tag == tag)) begin
                @(posedge clk);
                #1;
            end
            check_u4(shifter.result.nzcv, 4'b0000, "zero shift clears carry");
            wait_for_nzcv_value(4'b0000, "zero shift carry commit");
        end
    endtask

    initial begin
        failures = 0;
        clear_inputs();

        test_basic_lsl_commit();
        test_basic_lsr_commit();
        test_basic_asr_commit();
        test_local_forwarding();
        test_hold_until_grant();
        test_carry_only_flags();

        if (failures != 0) begin
            $fatal(1, "tb_ozone_shifter failed with %0d failures", failures);
        end

        $display("tb_ozone_shifter passed");
        $finish;
    end
endmodule
/* verilator lint_on UNUSEDSIGNAL */
