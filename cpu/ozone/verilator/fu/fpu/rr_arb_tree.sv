// Round-robin arbiter tree — common_cells stub for fpnew.
// Implements priority arbitration (lowest index wins) as a functional
// approximation of round-robin. Sufficient for OOO simulation correctness.
module rr_arb_tree #(
  parameter int unsigned NumIn     = 2,
  parameter type         DataType  = logic,
  parameter bit          ExtPrio   = 1'b0,
  parameter bit          AxiVldRdy = 1'b0,
  parameter bit          LockIn    = 1'b0
)(
  input  logic                        clk_i,
  input  logic                        rst_ni,
  input  logic                        flush_i,
  input  logic [$clog2(NumIn)-1:0]    rr_i,
  input  logic [NumIn-1:0]            req_i,
  output logic [NumIn-1:0]            gnt_o,
  input  DataType [NumIn-1:0]         data_i,
  input  logic                        gnt_i,
  output logic                        req_o,
  output DataType                     data_o,
  output logic [$clog2(NumIn)-1:0]    idx_o
);
  always_comb begin
    gnt_o  = '0;
    req_o  = 1'b0;
    data_o = '0;
    idx_o  = '0;

    for (int i = NumIn-1; i >= 0; i--) begin
      if (req_i[i]) begin
        gnt_o  = '0;
        gnt_o[i] = gnt_i;
        req_o  = 1'b1;
        data_o = data_i[i];
        idx_o  = $clog2(NumIn)'(i);
      end
    end
  end
endmodule
