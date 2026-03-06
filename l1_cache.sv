`timescale 1ns/1ps

module l1_cache #(
    parameter L1_CAPACITY   = 512,
    parameter L1_WAYS       = 2,
    parameter BLOCK_SIZE    = 64,
    parameter NUM_MSHRS     = 2,
    parameter VA_WIDTH      = 48,
    parameter PA_WIDTH      = 30,
    parameter DATA_WIDTH    = 64
)(
    input  logic                        clk,
    input  logic                        rst_n,

    // FROM TLB
  
    input  logic                        start_tag,          // TLB has valid output
    input  logic [PA_WIDTH-1:0]         tlb_paddr,          // Physical address from TLB

    // from lsq
    input  logic                        start_index,        // LSQ has valid request
    input  logic [VA_WIDTH-1:0]         trace_vaddr,        // Virtual address from LSQ
    input  logic                        is_write,           // 0=load, 1=store
    input  logic [DATA_WIDTH-1:0]       wdata,              // Store data (MISSING in memsys)

    // to lsq
    output logic                        isfull,             // Can't accept request
    output logic                        resp_valid,         // Response ready (MISSING in memsys)
    output logic [DATA_WIDTH-1:0]       resp_rdata,         // Load data (MISSING in memsys)

);

    // TODO: Implement L1 cache logic

    

endmodule
