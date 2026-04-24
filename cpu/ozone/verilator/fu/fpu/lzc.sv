// Leading zero/one counter — common_cells stub for fpnew.
// MODE=1: counts leading zeros (finds first 1 from MSB).
// MODE=0: counts leading ones  (finds first 0 from MSB).
module lzc #(
  parameter int unsigned WIDTH = 8,
  parameter bit          MODE  = 1'b0
)(
  input  logic [WIDTH-1:0]         in_i,
  output logic [$clog2(WIDTH):0]   cnt_o,
  output logic                     empty_o
);
  localparam int unsigned CNT_W = $clog2(WIDTH) + 1;

  always_comb begin
    automatic int found;
    found   = -1;
    for (int i = 0; i < WIDTH; i++) begin
      // Scan MSB → LSB; record the first matching bit position.
      if (found < 0) begin
        if (MODE ? in_i[WIDTH-1-i] : !in_i[WIDTH-1-i])
          found = i;
      end
    end
    if (found >= 0) begin
      cnt_o   = CNT_W'(found);
      empty_o = 1'b0;
    end else begin
      cnt_o   = '0;
      empty_o = 1'b1;
    end
  end
endmodule
