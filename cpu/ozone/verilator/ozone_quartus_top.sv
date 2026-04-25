`timescale 1ns/1ps

module ozone_quartus_top (
    input  logic        clk,
    input  logic        reset,
    input  logic [63:0] start_pc,

    output logic [63:0] mem_addr,
    input  logic [31:0] mem_rdata,
    output logic        mem_en,

    output logic        dmem_req_valid,
    output logic        dmem_req_is_write,
    output logic [29:0] dmem_req_addr,
    output logic [511:0] dmem_req_wdata,
    input  logic        dmem_req_ready,
    input  logic        dmem_resp_valid,
    input  logic [29:0] dmem_resp_paddr,
    input  logic [511:0] dmem_resp_rdata,

    output logic        ptw_req_valid,
    output logic [29:0] ptw_req_addr,
    input  logic        ptw_req_ready,
    input  logic        ptw_resp_valid,
    input  logic [63:0] ptw_resp_data,

    output logic        sim_store_valid,
    output logic [29:0] sim_store_paddr,
    output logic [63:0] sim_store_data,

    output logic        done
);

    logic [63:0] x_regs_unused [0:30];
    logic [63:0] fp_regs_unused [0:31];

    Top u_top (
        .clk              (clk),
        .reset            (reset),
        .start_pc         (start_pc),

        .mem_addr         (mem_addr),
        .mem_rdata        (mem_rdata),
        .mem_en           (mem_en),

        .dmem_req_valid   (dmem_req_valid),
        .dmem_req_is_write(dmem_req_is_write),
        .dmem_req_addr    (dmem_req_addr),
        .dmem_req_wdata   (dmem_req_wdata),
        .dmem_req_ready   (dmem_req_ready),
        .dmem_resp_valid  (dmem_resp_valid),
        .dmem_resp_paddr  (dmem_resp_paddr),
        .dmem_resp_rdata  (dmem_resp_rdata),

        .ptw_req_valid    (ptw_req_valid),
        .ptw_req_addr     (ptw_req_addr),
        .ptw_req_ready    (ptw_req_ready),
        .ptw_resp_valid   (ptw_resp_valid),
        .ptw_resp_data    (ptw_resp_data),

        .sim_store_valid  (sim_store_valid),
        .sim_store_paddr  (sim_store_paddr),
        .sim_store_data   (sim_store_data),

        .done             (done),
        .x_regs           (x_regs_unused),
        .fp_regs          (fp_regs_unused)
    );

endmodule
