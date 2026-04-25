module avalon_control(
  /* verilator lint_off UNUSED */
  input logic clk,
  input logic reset,
  /* verilator lint_on UNUSED */
  input logic [31:0] avs_s0_writedata,
  input logic avs_s0_write,
  input logic avs_s0_address,
  output logic do_read,
  output logic do_write,
  output logic [255:0] in_data
);

// Address map:
//   0x0 — write: trigger a read from SDR
//   0x1 — write: trigger a write to SDR (data latched from avs_s0_writedata,
//                padded to 256 bits)

assign do_read  = avs_s0_write && (avs_s0_address == 1'b0);
assign do_write = avs_s0_write && (avs_s0_address == 1'b1);

// Pad the 32-bit Avalon write data into the 256-bit SDR write bus.
// Adjust the mapping here if wider data is needed.
assign in_data  = {{224{1'b0}}, avs_s0_writedata};

endmodule