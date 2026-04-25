// Floating-point execution unit with its local reservation station: wrap the
// provided FPU ready/valid interface and return ROB-tagged results on CDB.
// ozone_rs_fpmult.sv
//
// Internal FSM states (per-slot):
//   The multiplier is multi-cycle (P iterations for the shift-add loop).
//   A single shared datapath is used (one multiply at a time); the RS
//   holds up to DEPTH speculative operands and issues the oldest ready one
//   when the datapath is free.

`timescale 1ns/1ps

module ozone_rs_fpmult
  import ozone_pkg::*;
#(
  parameter int DEPTH = 4,
  parameter int P     = 8,   // mantissa bits (including hidden bit)
  parameter int Q     = 8    // exponent bits
)(
  input  logic              clk,
  input  logic              rst_n,
  input  logic              flush,

  // --- dispatch allocates an entry ---
  input  logic              alloc_valid,
  input  rs_entry_fpmul_t   alloc_entry,   // see ozone_pkg for struct
  output logic              full,

  // --- CDB snoop ---
  input  cdb_broadcast_t    cdb_in,

  // --- CDB broadcast out ---
  output cdb_broadcast_t    cdb_out,
  input  logic              cdb_granted
);

  // -------------------------------------------------------
  // Local parameters
  // -------------------------------------------------------
  localparam int BIAS        = (1 << (Q-1)) - 1;
  localparam int CNT_W       = $clog2(P);   // width of iteration counter

  // -------------------------------------------------------
  // RS entry array
  // -------------------------------------------------------
  rs_entry_fpmul_t entries [0:DEPTH-1];

  // Full when every slot is occupied
  always_comb begin
    full = 1'b1;
    for (int i = 0; i < DEPTH; i++)
      if (!entries[i].valid) full = 1'b0;
  end

  // -------------------------------------------------------
  // Datapath state  (shared; one in-flight multiply at a time)
  // -------------------------------------------------------
  typedef enum logic [2:0] {
    FPM_IDLE    = 3'd0,
    FPM_SHIFT   = 3'd1,
    FPM_ADDEXP  = 3'd2,
    FPM_NORM    = 3'd3,
    FPM_ROUND   = 3'd4,
    FPM_FINISH  = 3'd5
  } fpm_state_t;

  fpm_state_t          dp_state;

  // Latch of the issued RS entry
  rs_entry_fpmul_t     dp_entry;

  // Multiply datapath registers  (match fpmult.sv naming)
  logic [P-1:0]        multiplicand;
  logic [2*P-1:0]      shift_add;
  logic [CNT_W-1:0]    shift_add_counter;
  logic                sticky_r, guard_r, round_r;
  logic                result_sign;
  logic [Q:0]          result_exp;      // one extra bit for overflow detection
  logic [P-1:0]        product;

  // Special-value flags
  logic                is_nan_result;
  logic                is_inf_result;
  logic [P+Q-1:0]      nan_value;

  // Rounding mode latched from dp_entry
  logic [1:0]          rounding_mode;

  // -------------------------------------------------------
  // Datapath is free when idle
  // -------------------------------------------------------
  logic dp_ready;
  assign dp_ready = (dp_state == FPM_IDLE);

  // -------------------------------------------------------
  // Oldest-ready issue select  (mirrors adder's combinational picker)
  // -------------------------------------------------------
  logic             issue_valid;
  rs_entry_fpmul_t  issue_entry;

  always_comb begin
    issue_valid = 1'b0;
    issue_entry = '0;
    for (int i = 0; i < DEPTH; i++) begin
      if (entries[i].valid    &&
          entries[i].Qj == '0 &&
          entries[i].Qk == '0 &&
          dp_ready) begin
        if (!issue_valid ||
            entries[i].rob_tag < issue_entry.rob_tag) begin
          issue_valid = 1'b1;
          issue_entry = entries[i];
        end
      end
    end
  end

  // -------------------------------------------------------
  // Result register  (mirrors adder's `result` broadcast reg)
  // -------------------------------------------------------
  cdb_broadcast_t result;

  // -------------------------------------------------------
  // Sequential: RS management + datapath FSM
  // -------------------------------------------------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      for (int i = 0; i < DEPTH; i++)
        entries[i].valid <= 1'b0;
      result           <= '0;
      dp_state         <= FPM_IDLE;
      dp_entry         <= '0;
      multiplicand     <= '0;
      shift_add        <= '0;
      shift_add_counter<= '0;
      sticky_r         <= 1'b0;
      guard_r          <= 1'b0;
      round_r          <= 1'b0;
      result_sign      <= 1'b0;
      result_exp       <= '0;
      product          <= '0;
      is_nan_result    <= 1'b0;
      is_inf_result    <= 1'b0;
      nan_value        <= '0;
      rounding_mode    <= 2'b00;

    end else if (flush) begin
      for (int i = 0; i < DEPTH; i++)
        entries[i].valid <= 1'b0;
      result           <= '0;
      dp_state         <= FPM_IDLE;
      dp_entry         <= '0;
      multiplicand     <= '0;
      shift_add        <= '0;
      shift_add_counter<= '0;
      sticky_r         <= 1'b0;
      guard_r          <= 1'b0;
      round_r          <= 1'b0;
      result_sign      <= 1'b0;
      result_exp       <= '0;
      product          <= '0;
      is_nan_result    <= 1'b0;
      is_inf_result    <= 1'b0;
      nan_value        <= '0;
      rounding_mode    <= 2'b00;

    end else begin

      // =======================================================
      // 1. CDB snoop – wake dependent entries
      // =======================================================
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

      // =======================================================
      // 2. Dispatch – allocate new entry
      // =======================================================
      if (alloc_valid && !full) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (!entries[i].valid) begin
            entries[i]       <= alloc_entry;
            entries[i].valid <= 1'b1;
            break;
          end
        end
      end

      // =======================================================
      // 3. Issue – grab the oldest ready entry, clear its slot
      //    (only when datapath is idle AND result reg is free)
      // =======================================================
      if (issue_valid && dp_ready && !result.valid) begin
        // Clear the issued slot
        for (int i = 0; i < DEPTH; i++) begin
          if (entries[i].valid    &&
              entries[i].Qj == '0 &&
              entries[i].Qk == '0 &&
              entries[i].rob_tag == issue_entry.rob_tag) begin
            entries[i].valid <= 1'b0;
            break;
          end
        end

        // Latch issued entry for the datapath
        dp_entry      <= issue_entry;
        rounding_mode <= issue_entry.round_mode;

        // -------------------------------------------------------
        // Special-value pre-check  (mirrors fpmult state-0 logic)
        // -------------------------------------------------------
        begin
          // Shorthands inside the procedural block
          logic [Q-1:0] xe, ye;
          logic [P-2:0] xm, ym;
          xe = issue_entry.Vj[P+Q-2 : P-1];
          ye = issue_entry.Vk[P+Q-2 : P-1];
          xm = issue_entry.Vj[P-2 : 0];
          ym = issue_entry.Vk[P-2 : 0];

          if (xe == {Q{1'b1}} && xm != '0) begin   // X is NaN
            is_nan_result <= 1'b1;
            is_inf_result <= 1'b0;
            nan_value     <= {issue_entry.Vj[P+Q-1], {Q{1'b1}}, 1'b1, issue_entry.Vj[P-3:0]};
            dp_state      <= FPM_FINISH;

          end else if (ye == {Q{1'b1}} && ym != '0) begin  // Y is NaN
            is_nan_result <= 1'b1;
            is_inf_result <= 1'b0;
            nan_value     <= {issue_entry.Vk[P+Q-1], {Q{1'b1}}, 1'b1, issue_entry.Vk[P-3:0]};
            dp_state      <= FPM_FINISH;

          end else if ((xe == {Q{1'b1}} && xm == '0 && issue_entry.Vk[P+Q-2:0] == '0) ||
                       (ye == {Q{1'b1}} && ym == '0 && issue_entry.Vj[P+Q-2:0] == '0)) begin  // Inf×0
            is_nan_result <= 1'b1;
            is_inf_result <= 1'b0;
            nan_value     <= {issue_entry.Vj[P+Q-1] ^ issue_entry.Vk[P+Q-1],
                              {Q{1'b1}}, 1'b1, {(P-2){1'b0}}};
            dp_state      <= FPM_FINISH;

          end else if ((xe == {Q{1'b1}} && xm == '0) ||
                       (ye == {Q{1'b1}} && ym == '0)) begin  // Inf × finite
            is_nan_result <= 1'b0;
            is_inf_result <= 1'b1;
            result_sign   <= issue_entry.Vj[P+Q-1] ^ issue_entry.Vk[P+Q-1];
            dp_state      <= FPM_FINISH;

          end else begin                                      // Normal path
            is_nan_result    <= 1'b0;
            is_inf_result    <= 1'b0;
            result_sign      <= issue_entry.Vj[P+Q-1] ^ issue_entry.Vk[P+Q-1];
            // Y is the multiplicand (static during shift-add)
            multiplicand     <= {(ye != '0), ym};
            // X is the multiplier (shifts right each cycle)
            shift_add        <= {{P{1'b0}}, (xe != '0), xm};
            shift_add_counter<= '0;
            sticky_r         <= 1'b0;
            dp_state         <= FPM_SHIFT;
          end
        end
      end

      // =======================================================
      // 4. Datapath FSM
      // =======================================================
      case (dp_state)

        // -------------------------------------------------------
        FPM_IDLE: ; // nothing – waiting for issue

        // -------------------------------------------------------
        FPM_SHIFT: begin
          // Shift-and-add iteration (P bits, one per cycle)
          if (shift_add[0])
            shift_add <= {{1'b0, shift_add[2*P-1:P]} + {1'b0, multiplicand},
                          shift_add[P-1:1]};
          else
            shift_add <= {1'b0, shift_add[2*P-1:1]};

          // Accumulate sticky for low-order discarded bits
          if (shift_add_counter < CNT_W'(P-2))
            sticky_r <= sticky_r | shift_add[0];

          shift_add_counter <= shift_add_counter + 1'b1;

          if (shift_add_counter >= CNT_W'(P-1)) begin
            guard_r  <= shift_add[P-1];
            round_r  <= shift_add[P-2];
            dp_state <= FPM_ADDEXP;
          end
        end

        // -------------------------------------------------------
        FPM_ADDEXP: begin
          // Add biased exponents, subtract one BIAS
          begin
            logic [Q-1:0] xe2, ye2;
            xe2 = dp_entry.Vj[P+Q-2 : P-1];
            ye2 = dp_entry.Vk[P+Q-2 : P-1];
            result_exp <= ( (Q+1)'(xe2 == '0 ? (Q+1)'(1) : (Q+1)'(xe2)) +
                            (Q+1)'(ye2 == '0 ? (Q+1)'(1) : (Q+1)'(ye2)) -
                            (Q+1)'(BIAS) );
          end
          dp_state <= FPM_NORM;
        end

        // -------------------------------------------------------
        FPM_NORM: begin
          // Exponent overflow / special – go straight to finish
          if (result_exp == {1'b0, {Q{1'b1}}} ||
              (result_exp[Q] == 1'b1 && result_exp[Q-1] == 1'b0)) begin
            dp_state <= FPM_FINISH;

          // Product is zero
          end else if (shift_add == '0) begin
            product      <= '0;
            result_exp   <= '0;
            if (rounding_mode == 2'b00 || rounding_mode == 2'b01)
              {sticky_r, round_r} <= 2'b00;
            else if (rounding_mode == 2'b10 && result_sign == 1'b0)
              {sticky_r, round_r} <= 2'b00;
            else if (rounding_mode == 2'b11 && result_sign == 1'b1)
              {sticky_r, round_r} <= 2'b00;
            dp_state <= FPM_ROUND;

          // Denormal: exponent too small, shift right
          end else if ($signed(result_exp) < 1) begin
            shift_add  <= {1'b0, shift_add[2*P-1:1]};
            result_exp <= result_exp + 1;
            sticky_r   <= sticky_r | shift_add[0];
            // stay in FPM_NORM

          // MSB set (post-mult carry) – right-normalise
          end else if (shift_add[2*P-1] == 1'b1) begin
            product    <= shift_add[2*P-1 : P];
            sticky_r   <= |shift_add[P-2:0];
            round_r    <= shift_add[P-1];
            result_exp <= result_exp + 1;
            dp_state   <= FPM_ROUND;

          // Implied leading 1 already in place
          end else if (shift_add[2*P-2] == 1'b1) begin
            product  <= shift_add[2*P-2 : P-1];
            round_r  <= shift_add[P-2];
            sticky_r <= |shift_add[P-3:0];
            dp_state <= FPM_ROUND;

          // Exponent is 1 – cap and pack as subnormal
          end else if (result_exp <= 1) begin
            product    <= shift_add[2*P-2 : P-1];
            result_exp <= '0;
            round_r    <= shift_add[P-2];
            sticky_r   <= sticky_r | (|shift_add[P-3:0]);
            dp_state   <= FPM_ROUND;

          // Shift left to normalise
          end else begin
            shift_add  <= {shift_add[2*P-2:0], 1'b0};
            result_exp <= result_exp - 1;
            guard_r    <= shift_add[P-2];
            round_r    <= shift_add[P-3];
            sticky_r   <= sticky_r | shift_add[P-4];
            // stay in FPM_NORM
          end
        end

        // -------------------------------------------------------
        FPM_ROUND: begin
          case (rounding_mode)
            2'b00: begin  // Round to Nearest, ties to Even
              if (round_r) begin
                if (sticky_r) begin
                  // > 0.5 ulp: round up
                  if (product == {P{1'b1}}) begin
                    product    <= {1'b1, {(P-1){1'b0}}};
                    result_exp <= result_exp + 1;
                  end else
                    product <= product + 1;
                end else begin
                  // Exactly 0.5 ulp: round to even
                  if (product[0]) begin
                    if (product == {P{1'b1}}) begin
                      product    <= {1'b1, {(P-1){1'b0}}};
                      result_exp <= result_exp + 1;
                    end else
                      product <= product + 1;
                  end
                end
              end
            end

            2'b01: ; // Round toward zero – truncate (product already correct)

            2'b10: begin  // Round down (toward −∞)
              if (result_sign && (round_r || sticky_r)) begin
                if (product == {P{1'b1}}) begin
                  product    <= {1'b1, {(P-1){1'b0}}};
                  result_exp <= result_exp + 1;
                end else
                  product <= product + 1;
              end
            end

            2'b11: begin  // Round up (toward +∞)
              if (!result_sign && (round_r || sticky_r)) begin
                if (product == {P{1'b1}}) begin
                  product    <= {1'b1, {(P-1){1'b0}}};
                  result_exp <= result_exp + 1;
                end else
                  product <= product + 1;
              end
            end
          endcase

          dp_state <= FPM_FINISH;
        end

        // -------------------------------------------------------
        FPM_FINISH: begin
          // Pack result into a 64-bit CDB value.
          // The FP word occupies bits [P+Q-1:0]; upper bits are zeroed.
          logic [P+Q-1:0] fp_result;

          if (is_nan_result) begin
            fp_result = nan_value;
          end else if (is_inf_result) begin
            fp_result = {result_sign, {Q{1'b1}}, {(P-1){1'b0}}};
          end else if (result_exp == {1'b0, {Q{1'b1}}} ||
                       (result_exp[Q] == 1'b1 && result_exp[Q-1] == 1'b0)) begin
            // Overflow
            if (rounding_mode == 2'b00 ||
                (rounding_mode[1] && (rounding_mode[0] != result_sign)))
              fp_result = {result_sign, {Q{1'b1}}, {(P-1){1'b0}}};   // ±Inf
            else
              fp_result = {result_sign, {(Q-1){1'b1}}, 1'b0, {(P-1){1'b1}}}; // max finite
          end else begin
            fp_result = {result_sign, result_exp[Q-1:0], product[P-2:0]};
          end

          // Write into result broadcast register (mirrors adder)
          result.valid       <= 1'b1;
          result.rob_tag     <= dp_entry.rob_tag;
          result.cdb_value_en<= 1'b1;
          result.rob_wb_en   <= 1'b1;
          result.value       <= 64'(fp_result);  // zero-extend to 64-bit bus
          result.update_nzcv <= 1'b0;
          result.nzcv        <= 4'b0;
          result.br_valid    <= 1'b0;
          result.br_taken    <= 1'b0;
          result.br_target   <= '0;
          result.exc         <= 1'b0;
          result.exc_code    <= '0;

          dp_state <= FPM_IDLE;
        end

      endcase // dp_state

      // =======================================================
      // 5. CDB granted – clear result register
      // =======================================================
      if (result.valid && cdb_granted)
        result.valid <= 1'b0;

    end // else (!rst_n)
  end // always_ff

  // -------------------------------------------------------
  // CDB output – driven directly from result register
  // -------------------------------------------------------
  assign cdb_out = result;

endmodule


// -------------------------------------------------------
// Package additions needed in ozone_pkg.sv
// -------------------------------------------------------
//
// Add the following struct alongside rs_entry_add_t:
//
// typedef struct packed {
//   logic              valid;
//   rob_tag_t          rob_tag;
//   logic [63:0]       Vj;          // operand X (FP word in low P+Q bits)
//   logic [63:0]       Vk;          // operand Y (FP word in low P+Q bits)
//   rob_tag_t          Qj;          // producer tag for Vj (0 = ready)
//   rob_tag_t          Qk;          // producer tag for Vk (0 = ready)
//   logic [1:0]        round_mode;  // rounding specifier
// } rs_entry_fpmul_t;
