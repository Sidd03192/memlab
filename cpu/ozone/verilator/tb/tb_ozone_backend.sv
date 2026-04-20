/* verilator lint_off UNUSEDSIGNAL */
`timescale 1ns/1ps

module tb_ozone_cdb;
    import ozone_pkg::*;

    cdb_broadcast_t adder_req;
    cdb_broadcast_t logic_req;
    cdb_broadcast_t fpu_req;
    cdb_broadcast_t mem_req;
    logic [ROB_IDX_WIDTH-1:0] rob_head;

    cdb_broadcast_t cdb_broadcast;
    logic adder_granted;
    logic logic_granted;
    logic fpu_granted;
    logic mem_granted;

    int failures;

    ozone_cdb dut (
        .adder_req(adder_req),
        .logic_req(logic_req),
        .fpu_req(fpu_req),
        .mem_req(mem_req),
        .rob_head(rob_head),
        .cdb_broadcast(cdb_broadcast),
        .adder_granted(adder_granted),
        .logic_granted(logic_granted),
        .fpu_granted(fpu_granted),
        .mem_granted(mem_granted)
    );

    function automatic cdb_broadcast_t make_req(
        input logic [ROB_IDX_WIDTH-1:0] tag,
        input logic [63:0] value
    );
        cdb_broadcast_t req;
        req             = '0;
        req.valid       = 1'b1;
        req.rob_tag     = tag;
        req.cdb_value_en= 1'b1;
        req.rob_wb_en   = 1'b1;
        req.value       = value;
        make_req        = req;
    endfunction

    task automatic clear_reqs();
        begin
            adder_req = '0;
            logic_req = '0;
            fpu_req   = '0;
            mem_req   = '0;
            rob_head  = '0;
            #1;
        end
    endtask

    task automatic check_bit(
        input logic got,
        input logic expected,
        input string label
    );
        begin
            if (got !== expected) begin
                failures++;
                $display("[FAIL] %s expected=%0b got=%0b", label, expected, got);
            end
        end
    endtask

    task automatic check_tag(
        input logic [ROB_IDX_WIDTH-1:0] got,
        input logic [ROB_IDX_WIDTH-1:0] expected,
        input string label
    );
        begin
            if (got !== expected) begin
                failures++;
                $display("[FAIL] %s expected tag=%0d got=%0d", label, expected, got);
            end
        end
    endtask

    initial begin
        failures = 0;
        clear_reqs();

        // no valid requests
        check_bit(cdb_broadcast.valid, 1'b0, "idle cdb valid");
        check_bit(adder_granted, 1'b0, "idle adder grant");
        check_bit(logic_granted, 1'b0, "idle logic grant");

        // one valid request
        adder_req = make_req(6'd5, 64'h55);
        #1;
        check_bit(cdb_broadcast.valid, 1'b1, "single winner valid");
        check_tag(cdb_broadcast.rob_tag, 6'd5, "single winner tag");
        check_bit(adder_granted, 1'b1, "single adder grant");
        check_bit(logic_granted, 1'b0, "single logic grant");

        // smaller age wins without wrap
        clear_reqs();
        rob_head  = 6'd10;
        adder_req = make_req(6'd12, 64'h12); // age 2
        logic_req = make_req(6'd11, 64'h11); // age 1
        #1;
        check_tag(cdb_broadcast.rob_tag, 6'd11, "age compare winner");
        check_bit(logic_granted, 1'b1, "age compare logic grant");
        check_bit(adder_granted, 1'b0, "age compare adder loses");

        // wraparound age compare
        clear_reqs();
        rob_head  = 6'd62;
        adder_req = make_req(6'd63, 64'h63); // age 1
        logic_req = make_req(6'd1,  64'h01); // age 3
        #1;
        check_tag(cdb_broadcast.rob_tag, 6'd63, "wrap winner");
        check_bit(adder_granted, 1'b1, "wrap adder grant");
        check_bit(logic_granted, 1'b0, "wrap logic loses");

        // all four valid
        clear_reqs();
        rob_head  = 6'd20;
        adder_req = make_req(6'd24, 64'h24); // age 4
        logic_req = make_req(6'd22, 64'h22); // age 2
        fpu_req   = make_req(6'd25, 64'h25); // age 5
        mem_req   = make_req(6'd21, 64'h21); // age 1
        #1;
        check_tag(cdb_broadcast.rob_tag, 6'd21, "all valid winner");
        check_bit(mem_granted, 1'b1, "all valid mem grant");
        check_bit(adder_granted, 1'b0, "all valid adder loses");
        check_bit(logic_granted, 1'b0, "all valid logic loses");
        check_bit(fpu_granted, 1'b0, "all valid fpu loses");

        if (failures != 0) begin
            $fatal(1, "tb_ozone_cdb failed with %0d failures", failures);
        end

        $display("tb_ozone_cdb passed");
        $finish;
    end
endmodule

module tb_ozone_backend;
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
    logic [3:0]                exception_code;

    // adder
    logic                      adder_alloc_valid;
    rs_entry_add_t             adder_alloc_entry;
    logic                      adder_full;
    cdb_broadcast_t            adder_req;
    logic                      adder_granted;

    // logic fu
    logic                      logic_alloc_valid;
    rs_entry_t                 logic_alloc_entry;
    logic                      logic_full;
    cdb_broadcast_t            logic_req;
    logic                      logic_granted;

    // agu
    logic                      agu_alloc_valid;
    rs_entry_add_t             agu_alloc_entry;
    logic                      agu_full;
    cdb_broadcast_t            agu_req;
    logic                      agu_granted;

    // fpu
    logic                      fpu_alloc_valid;
    rs_entry_fpmul_t           fpu_alloc_entry;
    logic                      fpu_full;
    cdb_broadcast_t            fpu_req;
    logic                      fpu_granted;

    // cdb
    cdb_broadcast_t            cdb_broadcast;
    cdb_broadcast_t            zero_req;

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

    ozone_rs_adder #(.DEPTH(DEPTH)) adder (
        .clk(clk),
        .rst_n(rst_n),
        .flush(reg_flush),
        .alloc_valid(adder_alloc_valid),
        .alloc_entry(adder_alloc_entry),
        .full(adder_full),
        .cdb_in(cdb_broadcast),
        .cdb_out(adder_req),
        .cdb_granted(adder_granted)
    );

    ozone_logic #(.DEPTH(DEPTH)) logic_fu (
        .clk(clk),
        .rst_n(rst_n),
        .flush(reg_flush),
        .alloc_valid(logic_alloc_valid),
        .alloc_entry(logic_alloc_entry),
        .full(logic_full),
        .cdb_in(cdb_broadcast),
        .cdb_out(logic_req),
        .cdb_granted(logic_granted)
    );

    ozone_agu #(.DEPTH(DEPTH)) agu (
        .clk(clk),
        .rst_n(rst_n),
        .flush(reg_flush),
        .alloc_valid(agu_alloc_valid),
        .alloc_entry(agu_alloc_entry),
        .full(agu_full),
        .cdb_in(cdb_broadcast),
        .cdb_out(agu_req),
        .cdb_granted(agu_granted)
    );

    ozone_rs_fpmult #(.DEPTH(DEPTH), .P(8), .Q(8)) fpu (
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
        .adder_req(adder_req),
        .logic_req(logic_req),
        .fpu_req(fpu_req),
        .mem_req(agu_req),
        .rob_head(rob_head),
        .cdb_broadcast(cdb_broadcast),
        .adder_granted(adder_granted),
        .logic_granted(logic_granted),
        .fpu_granted(fpu_granted),
        .mem_granted(agu_granted)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    task automatic clear_inputs();
        begin
            src1_addr         = '0;
            src2_addr         = '0;
            fp_src1_addr      = '0;
            fp_src2_addr      = '0;
            src1_rob_idx      = '0;
            src2_rob_idx      = '0;
            disp_wr_en        = 1'b0;
            disp_wr_addr      = '0;
            disp_rob_idx      = '0;
            disp_fp_wr_en     = 1'b0;
            disp_fp_wr_addr   = '0;
            disp_fp_rob_idx   = '0;
            disp_nzcv_wr_en   = 1'b0;
            disp_nzcv_rob_idx = '0;
            rob_alloc_valid   = 1'b0;
            alloc_has_dest    = 1'b0;
            alloc_data        = '0;
            adder_alloc_valid = 1'b0;
            adder_alloc_entry = '0;
            logic_alloc_valid = 1'b0;
            logic_alloc_entry = '0;
            agu_alloc_valid   = 1'b0;
            agu_alloc_entry   = '0;
            fpu_alloc_valid   = 1'b0;
            fpu_alloc_entry   = '0;
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

    task automatic resolve_nzcv_source(
        output logic [3:0] flags,
        output logic [ROB_IDX_WIDTH-1:0] q
    );
        begin
            #1;
            if (!nzcv_status.busy) begin
                flags = nzcv_status.value[3:0];
                q     = '0;
            end else if (cdb_broadcast.valid &&
                         cdb_broadcast.rob_tag == nzcv_status.rob_idx &&
                         cdb_broadcast.update_nzcv) begin
                flags = cdb_broadcast.nzcv;
                q     = '0;
            end else if (rob.rob_entries[nzcv_status.rob_idx].ready) begin
                flags = rob.rob_entries[nzcv_status.rob_idx].nzcv;
                q     = '0;
            end else begin
                flags = '0;
                q     = nzcv_status.rob_idx;
            end
        end
    endtask

    task automatic resolve_fp_sources(
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

    task automatic dispatch_adder_rr(
        input  adder_op_e op,
        input  logic [4:0] reg_a,
        input  logic [4:0] reg_b,
        input  logic [4:0] dest_reg,
        input  logic       has_dest,
        input  logic       writes_nzcv,
        output logic [ROB_IDX_WIDTH-1:0] tag_out
    );
        logic [63:0] vj;
        logic [63:0] vk;
        logic [ROB_IDX_WIDTH-1:0] qj;
        logic [ROB_IDX_WIDTH-1:0] qk;
        rs_entry_add_t entry;
        rob_entry_t rob_entry;
        begin
            while (rob_full || adder_full) @(negedge clk);
            resolve_gpr_sources(reg_a, reg_b, vj, qj, vk, qk);
            tag_out = alloc_rob_idx;

            entry              = '0;
            entry.Vj           = vj;
            entry.Vk           = vk;
            entry.Qj           = qj;
            entry.Qk           = qk;
            entry.rob_tag      = tag_out;
            entry.op           = op;
            entry.nzcv         = 4'b0;
            entry.branch_cond  = COND_AL;

            rob_entry              = '0;
            rob_entry.inst_type    = ROB_TYPE_ALU;
            rob_entry.dest_reg     = dest_reg;
            rob_entry.dest_type    = has_dest ? DEST_GPR : DEST_NONE;
            rob_entry.alloc_has_dest = has_dest;
            rob_entry.update_nzcv  = writes_nzcv;

            @(negedge clk);
            alloc_data        = rob_entry;
            alloc_has_dest    = has_dest;
            rob_alloc_valid   = 1'b1;
            adder_alloc_entry = entry;
            adder_alloc_valid = 1'b1;
            disp_wr_en        = has_dest;
            disp_wr_addr      = dest_reg;
            disp_rob_idx      = tag_out;
            disp_nzcv_wr_en   = writes_nzcv;
            disp_nzcv_rob_idx = tag_out;
            @(posedge clk);
            #1;
            clear_inputs();
        end
    endtask

    task automatic dispatch_logic_rr(
        input  adder_op_e op,
        input  logic [4:0] reg_a,
        input  logic [4:0] reg_b,
        input  logic [4:0] dest_reg,
        input  logic       has_dest,
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
            while (rob_full || logic_full) @(negedge clk);
            resolve_gpr_sources(reg_a, reg_b, vj, qj, vk, qk);
            tag_out = alloc_rob_idx;

            entry          = '0;
            entry.Vj       = vj;
            entry.Vk       = vk;
            entry.Qj       = qj;
            entry.Qk       = qk;
            entry.rob_tag  = tag_out;
            entry.op       = op;
            entry.nzcv     = 4'b0;

            rob_entry               = '0;
            rob_entry.inst_type     = ROB_TYPE_ALU;
            rob_entry.dest_reg      = dest_reg;
            rob_entry.dest_type     = has_dest ? DEST_GPR : DEST_NONE;
            rob_entry.alloc_has_dest = has_dest;
            rob_entry.update_nzcv   = writes_nzcv;

            @(negedge clk);
            alloc_data        = rob_entry;
            alloc_has_dest    = has_dest;
            rob_alloc_valid   = 1'b1;
            logic_alloc_entry = entry;
            logic_alloc_valid = 1'b1;
            disp_wr_en        = has_dest;
            disp_wr_addr      = dest_reg;
            disp_rob_idx      = tag_out;
            disp_nzcv_wr_en   = writes_nzcv;
            disp_nzcv_rob_idx = tag_out;
            @(posedge clk);
            #1;
            clear_inputs();
        end
    endtask

    task automatic dispatch_bcond(
        input  cond_code_e cond,
        input  logic [63:0] branch_pc,
        input  logic [63:0] branch_off,
        output logic [ROB_IDX_WIDTH-1:0] tag_out
    );
        logic [3:0] flags;
        logic [ROB_IDX_WIDTH-1:0] q_flags;
        rs_entry_add_t entry;
        rob_entry_t rob_entry;
        begin
            while (rob_full || adder_full) @(negedge clk);
            resolve_nzcv_source(flags, q_flags);
            tag_out = alloc_rob_idx;

            entry              = '0;
            entry.Vj           = branch_pc;
            entry.Vk           = branch_off;
            entry.Qj           = q_flags;
            entry.Qk           = '0;
            entry.rob_tag      = tag_out;
            entry.op           = OP_BCOND;
            entry.nzcv         = flags;
            entry.branch_cond  = cond;

            rob_entry              = '0;
            rob_entry.inst_type    = ROB_TYPE_BRANCH;
            rob_entry.dest_type    = DEST_NONE;
            rob_entry.alloc_has_dest = 1'b0;
            rob_entry.PC           = branch_pc;

            @(negedge clk);
            alloc_data        = rob_entry;
            alloc_has_dest    = 1'b0;
            rob_alloc_valid   = 1'b1;
            adder_alloc_entry = entry;
            adder_alloc_valid = 1'b1;
            @(posedge clk);
            #1;
            clear_inputs();
        end
    endtask

    task automatic dispatch_agu_rr(
        input  rob_type_e inst_type,
        input  logic [4:0] reg_a,
        input  logic [4:0] reg_b,
        output logic [ROB_IDX_WIDTH-1:0] tag_out
    );
        logic [63:0] vj;
        logic [63:0] vk;
        logic [ROB_IDX_WIDTH-1:0] qj;
        logic [ROB_IDX_WIDTH-1:0] qk;
        rs_entry_add_t entry;
        rob_entry_t rob_entry;
        begin
            while (rob_full || agu_full) @(negedge clk);
            resolve_gpr_sources(reg_a, reg_b, vj, qj, vk, qk);
            tag_out = alloc_rob_idx;

            entry         = '0;
            entry.Vj      = vj;
            entry.Vk      = vk;
            entry.Qj      = qj;
            entry.Qk      = qk;
            entry.rob_tag = tag_out;
            entry.op      = OP_ADD;

            rob_entry               = '0;
            rob_entry.inst_type     = inst_type;
            rob_entry.dest_type     = DEST_NONE;
            rob_entry.alloc_has_dest = 1'b0;

            @(negedge clk);
            alloc_data      = rob_entry;
            alloc_has_dest  = 1'b0;
            rob_alloc_valid = 1'b1;
            agu_alloc_entry = entry;
            agu_alloc_valid = 1'b1;
            @(posedge clk);
            #1;
            clear_inputs();
        end
    endtask

    task automatic dispatch_fpu_rr(
        input  logic [4:0] reg_a,
        input  logic [4:0] reg_b,
        input  logic [4:0] dest_reg,
        output logic [ROB_IDX_WIDTH-1:0] tag_out
    );
        logic [63:0] vj;
        logic [63:0] vk;
        logic [ROB_IDX_WIDTH-1:0] qj;
        logic [ROB_IDX_WIDTH-1:0] qk;
        rs_entry_fpmul_t entry;
        rob_entry_t rob_entry;
        begin
            while (rob_full || fpu_full) @(negedge clk);
            resolve_fp_sources(reg_a, reg_b, vj, qj, vk, qk);
            tag_out = alloc_rob_idx;

            entry            = '0;
            entry.Vj         = vj;
            entry.Vk         = vk;
            entry.Qj         = qj;
            entry.Qk         = qk;
            entry.rob_tag    = tag_out;
            entry.round_mode = 2'b00;

            rob_entry                = '0;
            rob_entry.inst_type      = ROB_TYPE_ALU;
            rob_entry.dest_reg       = dest_reg;
            rob_entry.dest_type      = DEST_FPR;
            rob_entry.alloc_has_dest = 1'b1;

            @(negedge clk);
            alloc_data       = rob_entry;
            alloc_has_dest   = 1'b1;
            rob_alloc_valid  = 1'b1;
            fpu_alloc_entry  = entry;
            fpu_alloc_valid  = 1'b1;
            disp_fp_wr_en    = 1'b1;
            disp_fp_wr_addr  = dest_reg;
            disp_fp_rob_idx  = tag_out;
            @(posedge clk);
            #1;
            clear_inputs();
        end
    endtask

    function automatic int find_adder_slot(input logic [ROB_IDX_WIDTH-1:0] tag);
        int idx;
        begin
            find_adder_slot = -1;
            for (idx = 0; idx < DEPTH; idx++) begin
                if (adder.entries[idx].valid && adder.entries[idx].rob_tag == tag) begin
                    find_adder_slot = idx;
                end
            end
        end
    endfunction

    function automatic int find_logic_slot(input logic [ROB_IDX_WIDTH-1:0] tag);
        int idx;
        begin
            find_logic_slot = -1;
            for (idx = 0; idx < DEPTH; idx++) begin
                if (logic_fu.entries[idx].valid && logic_fu.entries[idx].rob_tag == tag) begin
                    find_logic_slot = idx;
                end
            end
        end
    endfunction

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
                   (cycles < 80)) begin
                @(posedge clk);
                #1;
                cycles++;
            end
            check_u64(regstate.fp_reg[reg_idx].value, expected, label);
            check_true(!regstate.fp_reg[reg_idx].busy, {label, " busy clear"});
        end
    endtask

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
            while ((regstate.nzcv_reg.value[3:0] !== expected) &&
                   (cycles < 40)) begin
                @(posedge clk);
                #1;
                cycles++;
            end
            check_u4(regstate.nzcv_reg.value[3:0], expected, label);
            check_true(!regstate.nzcv_reg.busy, {label, " busy clear"});
        end
    endtask

    task automatic warmup_tag_zero();
        logic [ROB_IDX_WIDTH-1:0] warm_tag;
        logic [63:0] expected;
        begin
            expected = regstate.gp_reg[1].value | regstate.gp_reg[2].value;
            dispatch_logic_rr(OP_ORR, 5'd1, 5'd2, 5'd30, 1'b1, 1'b0, warm_tag);
            wait_for_gpr_value(30, expected, "warmup x30");
        end
    endtask

    task automatic test_reset_and_idle();
        begin
            $display("Running reset and idle smoke");
            reset_dut();
            check_true(rob.count == 0, "rob count reset");
            check_true(!rob_full, "rob not full after reset");
            check_true(!commit_valid, "no commit after reset");
            check_true(!cdb_broadcast.valid, "cdb idle after reset");
            check_true(!adder_req.valid, "adder request idle after reset");
            check_true(!logic_req.valid, "logic request idle after reset");
            check_true(!regstate.nzcv_reg.busy, "nzcv not busy after reset");
            check_true(!regstate.gp_reg[1].busy, "x1 not busy after reset");
        end
    endtask

    task automatic test_basic_adder_commit();
        logic [ROB_IDX_WIDTH-1:0] add_tag;
        begin
            $display("Running basic adder commit");
            reset_dut();
            preload_gpr(1, 64'd10);
            preload_gpr(2, 64'd7);
            dispatch_adder_rr(OP_ADD, 5'd1, 5'd2, 5'd3, 1'b1, 1'b0, add_tag);
            wait_for_gpr_value(3, 64'd17, "adder commit x3");
            check_true(rob.rob_entries[add_tag].ready, "adder rob entry became ready");
        end
    endtask

    task automatic test_basic_logic_commit();
        logic [ROB_IDX_WIDTH-1:0] logic_tag;
        begin
            $display("Running basic logic commit");
            reset_dut();
            preload_gpr(1, 64'hF0F0);
            preload_gpr(2, 64'h0FF0);
            dispatch_logic_rr(OP_AND, 5'd1, 5'd2, 5'd4, 1'b1, 1'b0, logic_tag);
            wait_for_gpr_value(4, 64'h00F0, "logic commit x4");
            check_true(rob.rob_entries[logic_tag].ready, "logic rob entry became ready");
        end
    endtask

    task automatic test_adder_internal_forwarding();
        logic [ROB_IDX_WIDTH-1:0] seed_tag;
        logic [ROB_IDX_WIDTH-1:0] prod_tag;
        logic [ROB_IDX_WIDTH-1:0] cons_tag;
        int cons_slot;
        begin
            $display("Running adder internal forwarding");
            reset_dut();
            preload_gpr(1, 64'd8);
            preload_gpr(2, 64'd3);
            preload_gpr(3, 64'd4);
            preload_gpr(6, 64'd5);
            warmup_tag_zero();

            dispatch_logic_rr(OP_ORR, 5'd1, 5'd2, 5'd10, 1'b1, 1'b0, seed_tag);
            dispatch_adder_rr(OP_ADD, 5'd10, 5'd3, 5'd4, 1'b1, 1'b0, prod_tag);
            dispatch_adder_rr(OP_ADD, 5'd4,  5'd6, 5'd5, 1'b1, 1'b0, cons_tag);

            // wait until producer issues, then check consumer was woken locally
            while (!(adder.result.valid && adder.result.rob_tag == prod_tag)) begin
                @(posedge clk);
                #1;
            end

            cons_slot = find_adder_slot(cons_tag);
            check_true(cons_slot >= 0, "adder consumer still in RS");
            if (cons_slot >= 0) begin
                check_true(adder.entries[cons_slot].Qj == '0, "adder consumer Qj cleared by local forward");
                check_u64(adder.entries[cons_slot].Vj, 64'd15, "adder consumer forwarded value");
            end

            wait_for_gpr_value(4, 64'd15, "adder producer commit x4");
            wait_for_gpr_value(5, 64'd20, "adder consumer commit x5");
        end
    endtask

    task automatic test_logic_internal_forwarding();
        logic [ROB_IDX_WIDTH-1:0] seed_tag;
        logic [ROB_IDX_WIDTH-1:0] prod_tag;
        logic [ROB_IDX_WIDTH-1:0] cons_tag;
        int cons_slot;
        begin
            $display("Running logic internal forwarding");
            reset_dut();
            preload_gpr(1, 64'hF0F0);
            preload_gpr(2, 64'h00FF);
            preload_gpr(3, 64'h0FF0);
            preload_gpr(6, 64'h000F);
            warmup_tag_zero();

            dispatch_adder_rr(OP_ADD, 5'd1, 5'd2, 5'd10, 1'b1, 1'b0, seed_tag);
            dispatch_logic_rr(OP_AND, 5'd10, 5'd3, 5'd4, 1'b1, 1'b0, prod_tag);
            dispatch_logic_rr(OP_ORR, 5'd4,  5'd6, 5'd5, 1'b1, 1'b0, cons_tag);

            while (!(logic_fu.result.valid && logic_fu.result.rob_tag == prod_tag)) begin
                @(posedge clk);
                #1;
            end

            cons_slot = find_logic_slot(cons_tag);
            check_true(cons_slot >= 0, "logic consumer still in RS");
            if (cons_slot >= 0) begin
                check_true(logic_fu.entries[cons_slot].Qj == '0, "logic consumer Qj cleared by local forward");
                check_u64(logic_fu.entries[cons_slot].Vj, 64'h01E0, "logic consumer forwarded value");
            end

            wait_for_gpr_value(4, 64'h01E0, "logic producer commit x4");
            wait_for_gpr_value(5, 64'h01EF, "logic consumer commit x5");
        end
    endtask

    task automatic test_nzcv_and_bcond_forwarding();
        logic [ROB_IDX_WIDTH-1:0] seed_tag;
        logic [ROB_IDX_WIDTH-1:0] flags_tag;
        logic [ROB_IDX_WIDTH-1:0] branch_tag;
        int branch_slot;
        begin
            $display("Running NZCV and B.cond forwarding");
            reset_dut();
            preload_gpr(1, 64'd1);
            preload_gpr(2, ~64'd0);
            preload_gpr(3, 64'd0);
            preload_nzcv(4'b0000);
            warmup_tag_zero();

            dispatch_logic_rr(OP_ORR, 5'd1, 5'd3, 5'd10, 1'b1, 1'b0, seed_tag);
            dispatch_adder_rr(OP_ADDS, 5'd10, 5'd2, 5'd4, 1'b1, 1'b1, flags_tag);
            dispatch_bcond(COND_EQ, 64'h1000, 64'd16, branch_tag);

            while (!(adder.result.valid && adder.result.rob_tag == flags_tag)) begin
                @(posedge clk);
                #1;
            end

            branch_slot = find_adder_slot(branch_tag);
            check_true(branch_slot >= 0, "bcond entry still in RS");
            if (branch_slot >= 0) begin
                check_true(adder.entries[branch_slot].Qj == '0, "bcond nzcv dependency cleared locally");
                check_u4(adder.entries[branch_slot].nzcv, 4'b0110, "bcond got forwarded nzcv");
                check_u64(adder.entries[branch_slot].Vj, 64'h1000, "bcond kept branch pc");
            end

            wait_for_gpr_value(4, 64'd0, "adds commit x4");
            wait_for_nzcv_value(4'b0110, "adds commit nzcv");

            while (!(adder.result.valid && adder.result.rob_tag == branch_tag)) begin
                @(posedge clk);
                #1;
            end
            check_u64(adder.result.br_target, 64'h1010, "bcond adder target");

            while (!(rob.rob_entries[branch_tag].ready)) begin
                @(posedge clk);
                #1;
            end
            check_true(rob.rob_entries[branch_tag].br_taken, "bcond taken");
            check_u64(rob.rob_entries[branch_tag].br_target, 64'h1010, "bcond target");
        end
    endtask

    task automatic test_agu_address_only_broadcast();
        logic [ROB_IDX_WIDTH-1:0] agu_tag;
        begin
            $display("Running AGU address-only broadcast");
            reset_dut();
            preload_gpr(1, 64'h1000);
            preload_gpr(2, 64'h0020);
            dispatch_agu_rr(ROB_TYPE_LOAD, 5'd1, 5'd2, agu_tag);

            while (!(agu_req.valid && agu_req.rob_tag == agu_tag)) begin
                @(posedge clk);
                #1;
            end

            check_u64(agu_req.value, 64'h1020, "agu effective address");
            check_true(!agu_req.cdb_value_en, "agu cdb value disabled");
            check_true(!agu_req.rob_wb_en, "agu rob writeback disabled");
            check_true(cdb_broadcast.valid, "agu wins cdb");
            check_true(!cdb_broadcast.cdb_value_en, "cdb marks agu as non-value");
            check_true(!rob.rob_entries[agu_tag].ready, "agu does not mark rob entry ready");

            src1_rob_idx = agu_tag;
            #1;
            check_true(!src1_ready, "rob source forwarding ignores agu address");
            clear_inputs();
        end
    endtask

    task automatic test_basic_fpu_commit();
        logic [ROB_IDX_WIDTH-1:0] fpu_tag;
        begin
            $display("Running basic fpu commit");
            reset_dut();
            preload_fpr(1, 64'h0000_0000_0000_3f80); // 1.0 in the FPU's 16-bit format
            preload_fpr(2, 64'h0000_0000_0000_3f80); // 1.0 in the FPU's 16-bit format
            dispatch_fpu_rr(5'd1, 5'd2, 5'd3, fpu_tag);

            while (!(fpu.result.valid && fpu.result.rob_tag == fpu_tag)) begin
                @(posedge clk);
                #1;
            end

            check_true(fpu.result.cdb_value_en, "fpu marks cdb value valid");
            check_true(fpu.result.rob_wb_en, "fpu marks rob writeback valid");
            check_u64(fpu.result.value, 64'h0000_0000_0000_3f80, "fpu result value");

            wait_for_fpr_value(3, 64'h0000_0000_0000_3f80, "fpu commit f3");
            check_true(rob.rob_entries[fpu_tag].ready, "fpu rob entry became ready");
        end
    endtask

    initial begin
        failures = 0;
        clear_inputs();

        test_reset_and_idle();
        test_basic_adder_commit();
        test_basic_logic_commit();
        test_adder_internal_forwarding();
        test_logic_internal_forwarding();
        test_nzcv_and_bcond_forwarding();
        test_agu_address_only_broadcast();
        test_basic_fpu_commit();

        if (failures != 0) begin
            $fatal(1, "tb_ozone_backend failed with %0d failures", failures);
        end

        $display("tb_ozone_backend passed");
        $finish;
    end
endmodule
/* verilator lint_on UNUSEDSIGNAL */
