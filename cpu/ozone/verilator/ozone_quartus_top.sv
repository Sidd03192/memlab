`timescale 1ns/1ps

module ozone_quartus_top (
    input  logic        clk_clk,
    input  logic        reset_reset,
    input  logic [63:0] start_pc_export,

    output logic        done_export
);

    logic [63:0] mem_addr_unused;
    logic        mem_en_unused;

    logic        dmem_req_valid_unused;
    logic        dmem_req_is_write_unused;
    logic [29:0] dmem_req_addr_unused;
    logic [511:0] dmem_req_wdata_unused;

    logic        ptw_req_valid_unused;
    logic [29:0] ptw_req_addr_unused;

    logic        sim_store_valid_unused;
    logic [29:0] sim_store_paddr_unused;
    logic [63:0] sim_store_data_unused;

    logic [63:0] x_regs_unused [0:30];
    logic [63:0] fp_regs_unused [0:31];

    Top u_top (
        .clk              (clk_clk),
        .reset            (reset_reset),
        .start_pc         (start_pc_export),

        .mem_addr         (mem_addr_unused),
        .mem_rdata        ('0),
        .mem_en           (mem_en_unused),

        .dmem_req_valid   (dmem_req_valid_unused),
        .dmem_req_is_write(dmem_req_is_write_unused),
        .dmem_req_addr    (dmem_req_addr_unused),
        .dmem_req_wdata   (dmem_req_wdata_unused),
        .dmem_req_ready   (1'b0),
        .dmem_resp_valid  (1'b0),
        .dmem_resp_paddr  ('0),
        .dmem_resp_rdata  ('0),

        .ptw_req_valid    (ptw_req_valid_unused),
        .ptw_req_addr     (ptw_req_addr_unused),
        .ptw_req_ready    (1'b0),
        .ptw_resp_valid   (1'b0),
        .ptw_resp_data    ('0),

        .sim_store_valid  (sim_store_valid_unused),
        .sim_store_paddr  (sim_store_paddr_unused),
        .sim_store_data   (sim_store_data_unused),

        .done             (done_export),
        .x_regs           (x_regs_unused),
        .fp_regs          (fp_regs_unused)
    );

endmodule
