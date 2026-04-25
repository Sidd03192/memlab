module avalon_sdr (
  // clk and reset are always required.
  input   logic         clk,
  input   logic         reset,
  // Bidirectional ports i.e. read and write.
  output  logic         avm_m0_read,
  output  logic         avm_m0_write,
  output  logic [255:0] avm_m0_writedata,
  output  logic [31:0]  avm_m0_address,
  input   logic [255:0] avm_m0_readdata,
  input   logic         avm_m0_readdatavalid,
  output  logic [31:0]  avm_m0_byteenable,
  input   logic         avm_m0_waitrequest,
  output  logic [10:0]  avm_m0_burstcount,
  // External.
  input   logic         do_read,
  input   logic         do_write,
  input   logic [255:0] in_data,
  output  logic [255:0] out_data
);

localparam INIT        = 3'd0;
localparam READ_START  = 3'd1;
localparam READ_END    = 3'd2;
localparam WRITE_START = 3'd3;
localparam WRITE_END   = 3'd4;

logic [2:0] cur_state;
logic [2:0] next_state;

// ------------------------------------------------------------
// State register
// ------------------------------------------------------------
always_ff @(posedge clk) begin
  if (reset) cur_state <= INIT;
  else       cur_state <= next_state;
end

// ------------------------------------------------------------
// Next-state logic
// ------------------------------------------------------------
always_comb begin
  next_state = cur_state;
  case (cur_state)
    INIT: begin
      if      (do_read)  next_state = READ_START;
      else if (do_write) next_state = WRITE_START;
    end

    READ_START: begin
      // Hold until the bus accepts the command.
      if (!avm_m0_waitrequest) next_state = READ_END;
    end

    READ_END: begin
      // Hold until read data comes back.
      if (avm_m0_readdatavalid) next_state = INIT;
    end

    WRITE_START: begin
      // Hold until the bus accepts the command.
      if (!avm_m0_waitrequest) next_state = WRITE_END;
    end

    WRITE_END: begin
      // Avalon write response: one idle cycle, then return to INIT.
      // If your target asserts waitrequest on write you can extend here.
      next_state = INIT;
    end

    default: next_state = INIT;
  endcase
end

// ------------------------------------------------------------
// Output / command logic (combinational)
// ------------------------------------------------------------
always_comb begin
  // Safe defaults — bus is idle.
  avm_m0_address   = 32'd0;
  avm_m0_read      = 1'b0;
  avm_m0_write     = 1'b0;
  avm_m0_writedata = 256'd0;
  avm_m0_byteenable = 32'd0;
  avm_m0_burstcount = 11'd0;

  case (cur_state)

    READ_START: begin
      avm_m0_address    = 32'h2000_0000;
      avm_m0_read       = 1'b1;
      avm_m0_byteenable = 32'h0000_000F; // 32-bit access.
      avm_m0_burstcount = 11'd1;
    end

    WRITE_START: begin
      avm_m0_address    = 32'h2000_0000;
      avm_m0_write      = 1'b1;
      avm_m0_writedata  = write_data_reg;  // driven from registered copy
      avm_m0_byteenable = 32'h0000_000F;   // 32-bit access — adjust as needed.
      avm_m0_burstcount = 11'd1;
    end

    default: begin
    end
  endcase
end

// ------------------------------------------------------------
// Data registers
// ------------------------------------------------------------

// Latch write data when the write request is accepted so that
// in_data can change freely after do_write is deasserted.
logic [255:0] write_data_reg;

always_ff @(posedge clk) begin
  if (reset) begin
    write_data_reg <= 256'd0;
    out_data       <= 256'd0;
  end else begin
    case (cur_state)

      INIT: begin
        // Capture write payload on the same cycle we leave INIT.
        if (do_write) write_data_reg <= in_data;
      end

      READ_END: begin
        if (avm_m0_readdatavalid) out_data <= avm_m0_readdata;
      end

      default: begin
      end
    endcase
  end
end

endmodule