// FPU Top Level Module, taken from that one GitHub Repo and edited to work with OOO

module fpnew_top
  import ozone_pkg::*;
#(
  parameter fpnew_pkg::fpu_features_t       Features       = fpnew_pkg::RV64D_Xsflt,
  parameter fpnew_pkg::fpu_implementation_t Implementation = fpnew_pkg::DEFAULT_SNITCH,
  parameter fpnew_pkg::divsqrt_unit_t       DivSqrtSel     = fpnew_pkg::PULP,
  parameter int unsigned                    TrueSIMDClass  = 0,
  parameter int unsigned                    EnableSIMDMask = 0,
  parameter int unsigned                    DEPTH          = 4,
  // Do not change
  localparam int unsigned NumLanes     = fpnew_pkg::max_num_lanes(Features.Width, Features.FpFmtMask, Features.EnableVectors),
  localparam int unsigned WIDTH        = Features.Width,
  localparam int unsigned NUM_OPERANDS = 3
)(
  input  logic            clk,
  input  logic            rst_n,
  input  logic            flush,

  // --- dispatch allocates an entry ---
  input  logic            alloc_valid,
  input  rs_entry_fp_t    alloc_entry,
  // --- RS full to dispatch ---
  output logic            full,

  // --- CDB snoop ---
  input  cdb_broadcast_t  cdb_in,

  // --- CDB broadcast out ---
  output cdb_broadcast_t  cdb_out,
  input  logic            cdb_granted
);

  // ---------------------------------------------------
  // RS entries
  // ---------------------------------------------------
  rs_entry_fp_t entries [0:DEPTH-1];

  always_comb begin
    full = 1'b1;
    for (int i = 0; i < DEPTH; i++)
      if (!entries[i].valid) full = 1'b0;
  end

  // ---------------------------------------------------
  // Result holding register
  // ---------------------------------------------------
  cdb_broadcast_t result;
  logic fu_ready;
  assign fu_ready = !result.valid;

  // ---------------------------------------------------
  // Issue selection — oldest ready entry
  // ---------------------------------------------------
  logic         issue_valid;
  rs_entry_fp_t issue_entry;

  always_comb begin
    issue_valid = 1'b0;
    issue_entry = '0;
    for (int i = 0; i < DEPTH; i++) begin
      if (entries[i].valid &&
          entries[i].Qj == '0 &&
          entries[i].Qk == '0 &&
          fu_ready) begin
        if (!issue_valid ||
            entries[i].rob_tag < issue_entry.rob_tag) begin
          issue_valid = 1'b1;
          issue_entry = entries[i];
        end
      end
    end
  end

  // ---------------------------------------------------
  // FPU core instantiation
  // TagType is the ROB tag so it flows through the pipeline
  // ---------------------------------------------------
  localparam type TagType = logic [ROB_IDX_WIDTH-1:0];

  logic [NUM_OPERANDS-1:0][WIDTH-1:0] fpu_operands;
  always_comb begin
    fpu_operands = '0;
    unique case (issue_entry.op)
      fpnew_pkg::ADD,
      fpnew_pkg::ADDS: begin
        // fpnew implements ADD/SUB on the FMA datapath as 1.0 * B +/- C.
        fpu_operands[1] = WIDTH'(issue_entry.Vj);
        fpu_operands[2] = WIDTH'(issue_entry.Vk);
      end
      default: begin
        fpu_operands[0] = WIDTH'(issue_entry.Vj);
        fpu_operands[1] = WIDTH'(issue_entry.Vk);
      end
    endcase
  end

  logic [WIDTH-1:0]        fpu_result;
  fpnew_pkg::status_t      fpu_status;
  TagType                  fpu_tag_out;
  logic                    fpu_out_valid;
  logic                    fpu_in_ready;

  fpnew_top_core #(
    .Features       ( Features       ),
    .Implementation ( Implementation ),
    .DivSqrtSel     ( DivSqrtSel     ),
    .TagType        ( TagType        ),
    .TrueSIMDClass  ( TrueSIMDClass  ),
    .EnableSIMDMask ( EnableSIMDMask )
  ) i_fpu (
    .clk_i          ( clk                      ),
    .rst_ni         ( rst_n                    ),
    .operands_i     ( fpu_operands             ),
    .rnd_mode_i     ( issue_entry.rnd_mode     ),
    .op_i           ( issue_entry.op           ),
    .op_mod_i       ( issue_entry.op_mod       ),
    .src_fmt_i      ( issue_entry.src_fmt      ),
    .dst_fmt_i      ( issue_entry.dst_fmt      ),
    .int_fmt_i      ( issue_entry.int_fmt      ),
    .vectorial_op_i ( issue_entry.vectorial_op ),
    .tag_i          ( issue_entry.rob_tag      ),
    .simd_mask_i    ( '1                       ),
    .in_valid_i     ( issue_valid              ),
    .in_ready_o     ( fpu_in_ready             ),
    .flush_i        ( flush                    ),
    .result_o       ( fpu_result               ),
    .status_o       ( fpu_status               ),
    .tag_o          ( fpu_tag_out              ),
    .out_valid_o    ( fpu_out_valid            ),
    .out_ready_i    ( fu_ready                 ),
    .busy_o         (                          ),
    .early_valid_o  (                          )
  );

  // ---------------------------------------------------
  // Sequential: RS management + capture FPU output
  // ---------------------------------------------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n || flush) begin
      for (int i = 0; i < DEPTH; i++)
        entries[i].valid <= 1'b0;
      result <= '0;

    end else begin

      // --- CDB snoop: wake up waiting operands ---
      if (cdb_in.valid && cdb_in.cdb_value_en) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (entries[i].valid) begin
            if (entries[i].Qj != '0 &&
                entries[i].Qj == cdb_in.rob_tag) begin
              entries[i].Vj <= cdb_in.value;
              entries[i].Qj <= '0;
            end
            if (entries[i].Qk != '0 &&
                entries[i].Qk == cdb_in.rob_tag) begin
              entries[i].Vk <= cdb_in.value;
              entries[i].Qk <= '0;
            end
          end
        end
      end

      // --- allocate new entry from dispatch ---
      if (alloc_valid && !full) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (!entries[i].valid) begin
            entries[i]       <= alloc_entry;
            entries[i].valid <= 1'b1;
            break;
          end
        end
      end

      // --- clear issued entry when FPU accepts it ---
      if (issue_valid && fpu_in_ready) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (entries[i].valid &&
              entries[i].rob_tag == issue_entry.rob_tag) begin
            entries[i].valid <= 1'b0;
            break;
          end
        end
      end

      // --- capture FPU result into holding register ---
      if (fpu_out_valid && fu_ready) begin
        result.valid        <= 1'b1;
        result.rob_tag      <= fpu_tag_out;
        result.cdb_value_en <= 1'b1;
        result.rob_wb_en    <= 1'b1;
        result.value        <= 64'(fpu_result);
        result.update_nzcv  <= 1'b0;
        result.nzcv         <= '0;
        result.br_valid     <= 1'b0;
        result.br_taken     <= 1'b0;
        result.br_target    <= '0;
        result.exc          <= 1'b0;
        result.exc_code     <= '0;
        result.fp_status    <= fpu_status; // {NV, DZ, OF, UF, NX}
      end

      // --- CDB granted: free holding register ---
      if (result.valid && cdb_granted)
        result.valid <= 1'b0;

    end
  end

  // ---------------------------------------------------
  // CDB output
  // ---------------------------------------------------
  assign cdb_out = result;

endmodule
