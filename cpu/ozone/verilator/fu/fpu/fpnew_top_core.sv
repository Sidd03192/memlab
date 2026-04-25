// fpnew_top_core: original fpnew_top interface, renamed so our OOO wrapper
// (fpnew_top.sv) can instantiate it without a name clash.
// Based on the ETH Zurich FPnew library (pulp-platform/fpnew).
// SPDX-License-Identifier: SHL-0.51

module fpnew_top_core #(
  parameter fpnew_pkg::divsqrt_unit_t       DivSqrtSel     = fpnew_pkg::THMULTI,
  parameter int unsigned                    FpuWidth       = 64,
  parameter logic                           EnableVectors  = 1'b1,
  parameter fpnew_pkg::fmt_logic_t          FpFmtMask      = 5'b11111,
  parameter fpnew_pkg::ifmt_logic_t         IntFmtMask     = 4'b1111,
  parameter fpnew_pkg::opgrp_fmt_unsigned_t PipeRegs       = '{default: 1},
  parameter fpnew_pkg::opgrp_fmt_unit_types_t UnitTypes    = '{
    '{default: fpnew_pkg::PARALLEL},
    '{default: fpnew_pkg::DISABLED},
    '{default: fpnew_pkg::PARALLEL},
    '{default: fpnew_pkg::MERGED}
  },
  parameter fpnew_pkg::pipe_config_t        PipeConfig     = fpnew_pkg::BEFORE,
  parameter int unsigned             TagWidth    = 1,
  parameter int unsigned                    TrueSIMDClass  = 0,
  parameter int unsigned                    EnableSIMDMask = 0,
  // Do not change
  parameter int unsigned NumLanes     = 8,
  parameter int unsigned WIDTH        = FpuWidth,
  parameter int unsigned NUM_OPERANDS = 3
)(
  input  logic                               clk_i,
  input  logic                               rst_ni,
  // Input operands
  input  logic [NUM_OPERANDS-1:0][WIDTH-1:0] operands_i,
  input  fpnew_pkg::roundmode_e              rnd_mode_i,
  input  fpnew_pkg::operation_e              op_i,
  input  logic                               op_mod_i,
  input  fpnew_pkg::fp_format_e              src_fmt_i,
  input  fpnew_pkg::fp_format_e              dst_fmt_i,
  input  fpnew_pkg::int_format_e             int_fmt_i,
  input  logic                               vectorial_op_i,
  input  logic [TagWidth-1:0]                             tag_i,
  input  logic [NumLanes-1:0]                simd_mask_i,
  // Input handshake
  input  logic                               in_valid_i,
  output logic                               in_ready_o,
  input  logic                               flush_i,
  // Output signals
  output logic [WIDTH-1:0]                   result_o,
  output fpnew_pkg::status_t                 status_o,
  output logic [TagWidth-1:0]                             tag_o,
  // Output handshake
  output logic                               out_valid_o,
  input  logic                               out_ready_i,
  // Indication of valid data in flight
  output logic                               busy_o,
  output logic                               early_valid_o
);

  // Generate loop indices
  genvar g;


  localparam int unsigned NUM_OPGROUPS = fpnew_pkg::NUM_OPGROUPS;
  localparam int unsigned NUM_FORMATS  = fpnew_pkg::NUM_FP_FORMATS;

  // NaN-box: all values passed in are already properly NaN-boxed (scalar FP64).
  logic [NUM_FORMATS-1:0][NUM_OPERANDS-1:0] is_boxed;
  assign is_boxed = '1;

  // -----------------------------------------------------------------------
  // Per-opgroup routing
  // -----------------------------------------------------------------------
  // Determine which opgroup the input operation belongs to
  fpnew_pkg::opgroup_e op_group;
  assign op_group = fpnew_pkg::get_opgroup(op_i);

  // Opgroup input valids: only the matching opgroup sees in_valid
  logic [NUM_OPGROUPS-1:0] opgrp_in_valid;
  always_comb begin
    for (int unsigned g = 0; g < NUM_OPGROUPS; g++)
      opgrp_in_valid[g] = in_valid_i && (op_group == fpnew_pkg::opgroup_e'(g));
  end

  // Opgroup ready, output valid, busy, early_valid, result, status, tag, ext_bit
  logic [NUM_OPGROUPS-1:0]   opgrp_in_ready;
  logic [NUM_OPGROUPS-1:0]   opgrp_out_valid;
  logic [NUM_OPGROUPS-1:0]   opgrp_out_ready;
  logic [NUM_OPGROUPS-1:0]   opgrp_busy;
  logic [NUM_OPGROUPS-1:0]   opgrp_early_valid;
  logic [NUM_OPGROUPS-1:0][WIDTH-1:0] opgrp_result;
  fpnew_pkg::status_t [NUM_OPGROUPS-1:0] opgrp_status;
  logic [NUM_OPGROUPS-1:0][TagWidth-1:0] opgrp_tag;

  // -----------------------------------------------------------------------
  // Opgroup block instantiation
  // -----------------------------------------------------------------------
  generate
  for (g = 0; g < NUM_OPGROUPS; g++) begin : gen_opgroups
    // Only instantiate if at least one format is enabled for this opgroup
    if (|UnitTypes[g]) begin : active
      fpnew_opgroup_block #(
        .OpGroup       ( fpnew_pkg::opgroup_e'(g)           ),
        .Width         ( WIDTH                               ),
        .EnableVectors ( EnableVectors                       ),
        .DivSqrtSel    ( DivSqrtSel                         ),
        .FpFmtMask     ( FpFmtMask                          ),
        .IntFmtMask    ( IntFmtMask                         ),
        .FmtPipeRegs   ( PipeRegs[g]                        ),
        .FmtUnitTypes  ( UnitTypes[g]                       ),
        .PipeConfig    ( PipeConfig                         ),
        .TagWidth       ( TagWidth                           ),
        .TrueSIMDClass ( TrueSIMDClass                      ),
        .NUM_LANES     ( NumLanes                           )
      ) i_opgroup_block (
        .clk_i         ( clk_i               ),
        .rst_ni        ( rst_ni              ),
        .operands_i    ( operands_i          ),
        .is_boxed_i    ( is_boxed            ),
        .rnd_mode_i    ( rnd_mode_i          ),
        .op_i          ( op_i               ),
        .op_mod_i      ( op_mod_i           ),
        .src_fmt_i     ( src_fmt_i          ),
        .dst_fmt_i     ( dst_fmt_i          ),
        .int_fmt_i     ( int_fmt_i          ),
        .vectorial_op_i( vectorial_op_i     ),
        .tag_i         ( tag_i             ),
        .simd_mask_i   ( simd_mask_i        ),
        .in_valid_i    ( opgrp_in_valid[g]  ),
        .in_ready_o    ( opgrp_in_ready[g]  ),
        .flush_i       ( flush_i            ),
        .result_o      ( opgrp_result[g]    ),
        .status_o      ( opgrp_status[g]    ),
        .extension_bit_o(                   ),  // unused
        .tag_o         ( opgrp_tag[g]       ),
        .out_valid_o   ( opgrp_out_valid[g] ),
        .out_ready_i   ( opgrp_out_ready[g] ),
        .busy_o        ( opgrp_busy[g]      ),
        .early_valid_o ( opgrp_early_valid[g])
      );
    end else begin : inactive
      assign opgrp_in_ready[g]    = 1'b0;
      assign opgrp_out_valid[g]   = 1'b0;
      assign opgrp_busy[g]        = 1'b0;
      assign opgrp_early_valid[g] = 1'b0;
      assign opgrp_result[g]      = '0;
      assign opgrp_status[g]      = '0;
      assign opgrp_tag[g]         = '0;
    end
  end
  endgenerate

  // -----------------------------------------------------------------------
  // Input handshake: ready when the target opgroup is ready
  // -----------------------------------------------------------------------
  always_comb begin
    in_ready_o = 1'b0;
    for (int unsigned g = 0; g < NUM_OPGROUPS; g++)
      if (op_group == fpnew_pkg::opgroup_e'(g))
        in_ready_o = opgrp_in_ready[g];
  end

  // -----------------------------------------------------------------------
  // Output arbitration: priority encoder (ADDMUL > DIVSQRT > NONCOMP > CONV)
  // -----------------------------------------------------------------------
  logic [NUM_OPGROUPS-1:0] winner_oh;  // one-hot winner

  always_comb begin
    winner_oh = '0;
    for (int unsigned g = 0; g < NUM_OPGROUPS; g++) begin
      if (opgrp_out_valid[g] && !(|winner_oh)) begin
        winner_oh[g] = 1'b1;
      end
    end
  end

  // Drive opgroup out_ready: only winner gets out_ready_i
  always_comb begin
    for (int unsigned g = 0; g < NUM_OPGROUPS; g++)
      opgrp_out_ready[g] = winner_oh[g] && out_ready_i;
  end

  // Mux result from winner
  always_comb begin
    result_o      = '0;
    status_o      = '0;
    tag_o         = '0;
    out_valid_o   = 1'b0;
    early_valid_o = 1'b0;
    for (int unsigned g = 0; g < NUM_OPGROUPS; g++) begin
      if (winner_oh[g]) begin
        result_o      = opgrp_result[g];
        status_o      = opgrp_status[g];
        tag_o         = opgrp_tag[g];
        out_valid_o   = opgrp_out_valid[g];
        early_valid_o = opgrp_early_valid[g];
      end
    end
  end

  // Busy if any opgroup is busy
  assign busy_o = |opgrp_busy;

endmodule
