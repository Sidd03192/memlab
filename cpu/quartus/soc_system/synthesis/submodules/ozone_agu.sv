// Address Generation Unit with its local reservation station: compute effective
// addresses for loads/stores and broadcast them for LSQ resolution via CDB.
module ozone_agu
  import ozone_pkg::*;
#(
  parameter DEPTH = 4
)(
  input  logic        clk,
  input  logic        rst_n,
  input  logic        flush,
 
  // --- dispatch allocates an entry ---
  input  logic        alloc_valid,
  input  rs_entry_add_t alloc_entry,
  // ---- RS full to dispatch ---
  output logic        full,
 
  // --- CDB snoop ---
  input  cdb_broadcast_t  cdb_in,
 
  // --- CDB broadcast out ---
  output cdb_broadcast_t cdb_out,
  input  logic        cdb_granted
);
 
  // RS entries
  rs_entry_add_t entries [0:DEPTH-1];
 
  // set RS full
  always_comb begin
    full = 1'b1;
    for (int i = 0; i < DEPTH; i++)
      if (!entries[i].valid) full = 1'b0;
  end
 
  // -------------------------------------------------------
  // Holds result if CDB not ready
  // -------------------------------------------------------
  cdb_broadcast_t result;
 
  logic fu_ready;
  assign fu_ready = !result.valid;
 
  // -------------------------------------------------------
  // Oldest-ready issue select
  // -------------------------------------------------------
  logic          issue_valid;
  rs_entry_add_t issue_entry;
 
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
  // Address adder
  // -------------------------------------------------------
  logic [63:0] add_result;
 
  always_comb begin
    // All AGU ops are base + offset. The AGU only produces effective
    // addresses, so the arithmetic is always the same.
    add_result = issue_entry.Vj + issue_entry.Vk;
  end
 
  // -------------------------------------------------------
  // Sequential logic — RS management + result register
  // -------------------------------------------------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      // Asynchronous reset
      for (int i = 0; i < DEPTH; i++)
        entries[i].valid <= 1'b0;
      result <= '0;

    end else if (flush) begin
      // Synchronous flush
      for (int i = 0; i < DEPTH; i++)
        entries[i].valid <= 1'b0;
      result <= '0;

    end else begin
 
      // --- CDB snoop: wake dependent entries ---
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
 
        // Latch result for CDB broadcast.
        // AGU results are effective addresses only. They stay visible on the
        // shared CDB so the LSQ can consume them, but they are never generic
        // value wakeups or direct ROB completions.
        result.valid       <= 1'b1;
        result.rob_tag     <= issue_entry.rob_tag;
        result.cdb_value_en<= 1'b0;
        result.rob_wb_en   <= 1'b0;
        result.value       <= add_result;
        result.update_nzcv <= 1'b0;
        result.nzcv        <= 4'b0;
        result.br_valid    <= 1'b0;
        result.br_taken    <= 1'b0;
        result.br_target   <= 64'b0;
        result.exc         <= 1'b0;
        result.exc_code    <= '0;
      end
 
      // --- CDB granted: free result register ---
      if (result.valid && cdb_granted)
        result.valid <= 1'b0;
 
    end
  end
 
  // -------------------------------------------------------
  // CDB output — directly from result register
  // -------------------------------------------------------
  assign cdb_out = result;
 
endmodule
