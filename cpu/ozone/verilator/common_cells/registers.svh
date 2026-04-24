// Minimal stub of pulp-platform/common_cells registers.svh
// Provides the FF register macros used by the fpnew library.

`ifndef COMMON_CELLS_REGISTERS_SVH_
`define COMMON_CELLS_REGISTERS_SVH_

// FF: basic flip-flop, active-low async reset. Uses implicit clk_i / rst_ni.
`define FF(q, d, rst_val) \
  always_ff @(posedge clk_i or negedge rst_ni) begin \
    if (!rst_ni) q <= rst_val; \
    else         q <= d; \
  end

// FFL: FF with synchronous load enable. Uses implicit clk_i / rst_ni.
`define FFL(q, d, load, rst_val) \
  always_ff @(posedge clk_i or negedge rst_ni) begin \
    if (!rst_ni)  q <= rst_val; \
    else if (load) q <= d; \
  end

// FFLARNC: FF with load, explicit clk/rst, active-high async clear (arst).
// ARNC = Async Reset, No (sync) Clear.
`define FFLARNC(q, d, load, arst, rst_val, clk, rstn) \
  always_ff @(posedge clk or negedge rstn or posedge arst) begin \
    if (!rstn || arst) q <= rst_val; \
    else if (load)     q <= d; \
  end

// FFLNR: FF with load, explicit clock, no reset.
`define FFLNR(q, d, load, clk) \
  always_ff @(posedge clk) begin \
    if (load) q <= d; \
  end

`endif
