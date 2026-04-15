// input assumptions are commented in 
// Basically a copy of the adders structure
// Need to handle decodde logic for MVN adn TST right. 
// We need to make sure that we handle things withotu destination registers correctly. 
// MVN and TST dotn really have a desitnation reg. 
module ozone_logic
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
  /* verilator lint_off UNUSEDSIGNAL */
  input  cdb_broadcast_t  cdb_in,
  /* verilator lint_on UNUSEDSIGNAL */

  // --- CDB broadcast out ---
  output cdb_broadcast_t cdb_out,
  input  logic          cdb_granted       // if cdb accepted :)
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

  // only accept new value when output register free.

  //TODO: try to optimize but combinationally selecting this ? so we dont unecessarily stall.
  logic fu_ready;
  assign fu_ready = !result.valid;

  // -------------------------------------------------------
  // Next thing logic
  // -------------------------------------------------------
  logic      issue_valid;
  /* verilator lint_off UNUSEDSIGNAL */
  rs_entry_t issue_entry;
  /* verilator lint_on UNUSEDSIGNAL */

  // Look through RS for next thing to compute if things are not done. RS tags cant be 0 
  // same logic from the adder
  always_comb begin
    issue_valid = 1'b0;
    issue_entry = '0;
    for (int i = 0; i < DEPTH; i++) begin
      if (entries[i].valid &&
          entries[i].Qj == '0 &&
          entries[i].Qk == '0 &&
          fu_ready) begin
        // oldest first
        if (!issue_valid ||
            entries[i].rob_tag < issue_entry.rob_tag) begin
          issue_valid = 1'b1;
          issue_entry = entries[i];
        end
      end
    end
  end

  // logic FU
  logic [63:0] logic_result;
  logic        logic_value_valid;
  logic [3:0]  logic_nzcv;
  logic        logic_flags_valid;
  logic        logic_br_valid;
  logic        logic_br_taken;
  logic [63:0] logic_br_target;
  logic        logic_exc;
  logic [7:0]  logic_exc_code;

  always_comb begin

    logic_result      = issue_entry.Vj;
    logic_value_valid = 1'b1;
    logic_nzcv        = 4'b0;
    logic_flags_valid = 1'b0;
    logic_br_valid    = 1'b0;
    logic_br_taken    = 1'b0;
    logic_br_target   = '0;
    logic_exc         = 1'b0;
    logic_exc_code    = '0;

    case (issue_entry.op)
      OP_AND: begin
        logic_result = issue_entry.Vj & issue_entry.Vk;
      end

      OP_ORR: begin
        logic_result = issue_entry.Vj | issue_entry.Vk;
      end

      OP_EOR: begin
        logic_result = issue_entry.Vj ^ issue_entry.Vk;
      end

      OP_ORN: begin
        logic_result = issue_entry.Vj | (~issue_entry.Vk);
      end

      OP_MVN: begin
        // Source operand goes in Vk 
        logic_result = ~issue_entry.Vk;
      end

      OP_ANDS: begin
        logic_result      = issue_entry.Vj & issue_entry.Vk;
        logic_flags_valid = 1'b1;
        logic_nzcv[3]     = logic_result[63];        // N
        logic_nzcv[2]     = (logic_result == 64'b0); // Z
        logic_nzcv[1]     = 1'b0;                    // C
        logic_nzcv[0]     = 1'b0;                    // V
      end

      OP_TST: begin
        logic_result      = issue_entry.Vj & issue_entry.Vk;
        logic_value_valid = 1'b0;
        logic_flags_valid = 1'b1;
        logic_nzcv[3]     = logic_result[63];        // N
        logic_nzcv[2]     = (logic_result == 64'b0); // Z
        logic_nzcv[1]     = 1'b0;                    // C
        logic_nzcv[0]     = 1'b0;                    // V
      end

      default: begin
        logic_result = issue_entry.Vj;
      end
    endcase
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

      // --- CDB snoop --- (dont need to read for the nzcv cause nothing relies)
      if (cdb_in.valid) begin
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
      // free up entry when we computed something
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
        if (logic_value_valid) begin
          for (int i = 0; i < DEPTH; i++) begin
            if (entries[i].valid &&
                entries[i].Qj == issue_entry.rob_tag) begin
              entries[i].Vj <= logic_result;
              entries[i].Qj <= '0;
            end
            if (entries[i].valid &&
                entries[i].Qk == issue_entry.rob_tag) begin
              entries[i].Vk <= logic_result;
              entries[i].Qk <= '0;
            end
          end
        end

        // connect result wires
        result.valid       <= 1'b1;
        result.rob_tag     <= issue_entry.rob_tag;
        result.value       <= logic_result;
        result.update_nzcv <= logic_flags_valid;
        result.nzcv        <= logic_nzcv;
        result.br_valid    <= logic_br_valid;
        result.br_taken    <= logic_br_taken;
        result.br_target   <= logic_br_target;
        result.exc         <= logic_exc;
        result.exc_code    <= logic_exc_code;
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
