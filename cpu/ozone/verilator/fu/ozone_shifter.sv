// Shifter execution cluster with its local reservation station: LSL/LSR/ASR
// issue, operand wakeup, execution, and CDB result output.
module ozone_shifter
  import ozone_pkg::*;
#(
  parameter DEPTH = 4
)(
  input  logic          clk,
  input  logic          rst_n,
  input  logic          flush,

  // --- dispatch allocates an entry ---
  input  logic          alloc_valid,
  input  rs_entry_t     alloc_entry,
  // ---- RS full to dispatch ---
  output logic          full,

  // --- CDB snoop ---
  input  cdb_broadcast_t  cdb_in,

  // --- CDB broadcast out ---
  output cdb_broadcast_t cdb_out,
  input  logic          cdb_granted
);

  // RS entries
  rs_entry_t entries [0:DEPTH-1];

  // set RS full.
  always_comb begin
    full = 1'b1;
    for (int i = 0; i < DEPTH; i++)
      if (!entries[i].valid) full = 1'b0;
  end

  // -------------------------------------------------------
  // Holds Results if CDB not ready
  // -------------------------------------------------------
  cdb_broadcast_t result;

  logic fu_ready;
  assign fu_ready = !result.valid;

  // -------------------------------------------------------
  // Next thing logic
  // -------------------------------------------------------
  logic      issue_valid;
  rs_entry_t issue_entry;

  // Look through RS for next thing to compute if things are not done.
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

  // -------------------------------------------------------
  // Shifter
  // -------------------------------------------------------
  logic [63:0] shift_result;
  logic [5:0]  shift_amt;
  logic        carry_out;
  logic [3:0]  shift_nzcv;
  logic        shift_flags_valid;

  always_comb begin
    shift_amt         = issue_entry.Vk[5:0];
    shift_result      = issue_entry.Vj;
    carry_out         = 1'b0;
    shift_nzcv        = 4'b0;
    shift_flags_valid = issue_entry.updates_nzcv;

    case (issue_entry.op)
      OP_LSL: begin
        shift_result = issue_entry.Vj << shift_amt;
        if (shift_amt != 6'd0)
          carry_out = issue_entry.Vj[64 - shift_amt];
      end

      OP_LSR: begin
        shift_result = issue_entry.Vj >> shift_amt;
        if (shift_amt != 6'd0)
          carry_out = issue_entry.Vj[shift_amt - 1'b1];
      end

      OP_ASR: begin
        shift_result = $signed(issue_entry.Vj) >>> shift_amt;
        if (shift_amt != 6'd0)
          carry_out = issue_entry.Vj[shift_amt - 1'b1];
      end

      default: begin
        shift_result = issue_entry.Vj;
      end
    endcase

    // Only the carry bit is meaningful for shifter-generated flags.
    shift_nzcv[1] = carry_out;
  end

  // -------------------------------------------------------
  // Sequential logic — RS management + result register
  // -------------------------------------------------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n || flush) begin
      for (int i = 0; i < DEPTH; i++)
        entries[i].valid <= 1'b0;
      result <= '0;

    end else begin

      // --- CDB snoop ---
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

      // --- alloc new entry from dispatch ---
      if (alloc_valid && !full) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (!entries[i].valid) begin
            entries[i]       <= alloc_entry;
            entries[i].valid <= 1'b1;
            break;
          end
        end
      end

      // --- issue + compute ---
      if (issue_valid && fu_ready) begin
        // clear the issued entry
        for (int i = 0; i < DEPTH; i++) begin
          if (entries[i].valid    &&
              entries[i].Qj == '0 &&
              entries[i].Qk == '0 &&
              entries[i].rob_tag == issue_entry.rob_tag) begin
            entries[i].valid <= 1'b0;
            break;
          end
        end

        // local forwarding.
        for (int i = 0; i < DEPTH; i++) begin
          if (entries[i].valid &&
              entries[i].Qj == issue_entry.rob_tag) begin
            entries[i].Vj <= shift_result;
            entries[i].Qj <= '0;
          end
          if (entries[i].valid &&
              entries[i].Qk == issue_entry.rob_tag) begin
            entries[i].Vk <= shift_result;
            entries[i].Qk <= '0;
          end
        end

        // connect result wires
        result.valid        <= 1'b1;
        result.rob_tag      <= issue_entry.rob_tag;
        result.cdb_value_en <= 1'b1;
        result.rob_wb_en    <= 1'b1;
        result.value        <= shift_result;
        result.update_nzcv  <= shift_flags_valid;
        result.nzcv         <= shift_nzcv;
        result.br_valid     <= 1'b0;
        result.br_taken     <= 1'b0;
        result.br_target    <= '0;
        result.exc          <= 1'b0;
        result.exc_code     <= '0;
      end

      // --- CDB granted this cycle ---
      // clear result register so we can accept next issue
      if (result.valid && cdb_granted)
        result.valid <= 1'b0;

    end
  end

  // -------------------------------------------------------
  // CDB request outputs — directly from result register
  // -------------------------------------------------------
  assign cdb_out = result;

endmodule
