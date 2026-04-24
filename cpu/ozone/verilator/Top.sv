module Top
  import ozone_pkg::*;
(
    input clk,
    input reset,

    // Simple Memory Interface
    output reg [63:0] mem_addr,
    input      [31:0] mem_rdata,
    output reg        mem_en,

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
    // Temporary bring-up switch: standalone ELF tests should start executing
    // at the ELF entry point instead of the EL1 reset vector/config block.
    // Set back to 1'b0 for the real reset-vector boot path.
    localparam logic USE_STANDALONE_ENTRY_PC = 1'b1;
    localparam logic [47:0] STANDALONE_ENTRY_PC = 48'h0000_0040_0000;

    reg [31:0] state;
    reg [47:0] pc;
    reg [29:0] pa_pc;
    reg [17:0] ttbr0;

    logic [63:0] tte;
    logic [31:0] insn_bits;
    logic        state7_sent;
    logic        reset_seen;

    logic rst_n;
    assign rst_n = ~reset;

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
    logic        rob_full;
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
    logic        pipe_flush;
    logic [63:0] flush_target_pc;
    logic        exception_valid;
    logic [63:0] exception_pc;
    logic [3:0]  exception_code;

    logic             adder_alloc_valid, adder_full, adder_granted;
    rs_entry_add_t    adder_alloc_entry;
    logic             logic_alloc_valid, logic_full, logic_granted;
    rs_entry_t        logic_alloc_entry;
    logic           fpu_alloc_valid, fpu_full, fpu_granted;
    rs_entry_fp_t   fpu_alloc_entry;
    logic             agu_alloc_valid, agu_full, agu_granted;
    rs_entry_add_t    agu_alloc_entry;

    cdb_broadcast_t adder_req, logic_req, fpu_req, agu_req, cdb_broadcast;

    assign halt_fetch = pipe_flush;

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
        .the_insn_bits(insn_bits),
        .the_insn_pc  (pc),
        .insn_ready   (insn_ready),
        .ready_for_uop(ready_for_uop),
        .decoder_ready(decoder_ready),
        .uop_out      (uop_out),
        .uop_valid    (uop_valid)
    );

    ozone_dispatch dispatch (
        .clk              (clk),
        .rst_n            (rst_n),
        .flush            (pipe_flush),
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
        .rob_src2_ready   (rob_src2_ready),
        .rob_src1_val     (rob_src1_val),
        .rob_src2_val     (rob_src2_val),
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
        .agu_full         (agu_full)
    );

    ozone_regstate regstate (
        .clk            (clk),
        .rst_n          (rst_n),
        .flush          (pipe_flush),
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
        .flush          (pipe_flush),
        .flush_target_pc(flush_target_pc),
        .exception_valid(exception_valid),
        .exception_pc   (exception_pc),
        .exception_code (exception_code)
    );

    ozone_rs_adder adder (
        .clk        (clk),
        .rst_n      (rst_n),
        .flush      (pipe_flush),
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
        .flush      (pipe_flush),
        .alloc_valid(logic_alloc_valid),
        .alloc_entry(logic_alloc_entry),
        .full       (logic_full),
        .cdb_in     (cdb_broadcast),
        .cdb_out    (logic_req),
        .cdb_granted(logic_granted)
    );

    ozone_agu agu (
        .clk        (clk),
        .rst_n      (rst_n),
        .flush      (pipe_flush),
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
        .flush      (pipe_flush),
        .alloc_valid(fpu_alloc_valid),
        .alloc_entry(fpu_alloc_entry),
        .full       (fpu_full),
        .cdb_in     (cdb_broadcast),
        .cdb_out    (fpu_req),
        .cdb_granted(fpu_granted)
    );

    ozone_cdb cdb (
        .adder_req    (adder_req),
        .logic_req    (logic_req),
        .fpu_req      (fpu_req),
        .mem_req      (agu_req),
        .rob_head     (rob_head),
        .cdb_broadcast(cdb_broadcast),
        .adder_granted(adder_granted),
        .logic_granted(logic_granted),
        .fpu_granted  (fpu_granted),
        .mem_granted  (agu_granted)
    );

    always @(posedge clk) begin
        if (reset) begin
            state           <= 0;
            done            <= 0;
            pc              <= USE_STANDALONE_ENTRY_PC ? STANDALONE_ENTRY_PC
                                                       : 48'h20000000;
            pa_pc           <= '0;
            ttbr0           <= '0;
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

            if (!reset_seen) begin
                $display("Did reset!\n");
                reset_seen <= 1'b1;
            end
        end else if (!done) begin
            reset_seen <= 1'b0;
            insn_ready <= 1'b0;
            itlb_flush <= 1'b0;

            if (commit_reg_en && commit_reg_addr != 5'd31) begin
                x_regs[commit_reg_addr] <= commit_reg_value;
            end

            if (commit_fp_en) begin
                fp_regs[commit_fp_addr] <= commit_fp_value;
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

            if (commit_valid &&
                commit_data.inst_type == ROB_TYPE_BRANCH &&
                commit_data.br_taken &&
                commit_data.br_target == 64'b0) begin
                $display("[TOP] done: committed branch to zero");
                done <= 1'b1;
            end

            if (pipe_flush) begin
                $display("[TOP] flush redirect -> 0x%016h", flush_target_pc);
                pc              <= flush_target_pc[47:0];
                state           <= 0;
                state7_sent     <= 1'b0;
                mem_en          <= 1'b0;
                itlb_lookup_req <= 1'b0;
                itlb_fill_req   <= 1'b0;
            end else begin
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
                        state <= 7;
                    end

                    7: begin
                        if (!halt_fetch) begin
                            if (!state7_sent) begin
                                $display("[TOP] send to decode pc=0x%012h insn=0x%08h", pc, insn_bits);
                                insn_ready <= 1'b1;
                                state7_sent <= 1'b1;
                            end else if (decoder_ready) begin
                                $display("[TOP] decoder consumed pc=0x%012h", pc);
                                pc <= pc + 48'd4;
                                state <= 0;
                                state7_sent <= 1'b0;
                            end
                        end
                    end

                    default: state <= 0;
                endcase
            end
        end
    end

endmodule
