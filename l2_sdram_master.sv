// =============================================================================
// l2_sdram_master.sv
//
// Avalon-MM Burst Master: L2 Cache <-> HPS f2h_sdram port
// Target board : DE10-Nano (Cyclone V SX)
// SDRAM bridge : f2h_sdram0  (64-bit Avalon-MM slave on HPS side)
// Cache line   : 64 bytes  -> 8 x 64-bit beats per transfer
//
// Interface contract with your L2:
//   - Assert req_valid with req_addr (byte-aligned to 64B), req_we, and
//     (if writing) req_wdata / req_wbe for each beat sequentially.
//   - Hold req_addr / req_we stable for the entire transaction.
//   - For writes: present req_wdata[63:0] and req_wbe[7:0] on each beat;
//     advance to the next beat when beat_ack is pulsed.
//   - For reads:  rdata_valid pulses for each beat with rdata[63:0].
//   - done pulses for one cycle when all 8 beats are complete.
//   - busy is high for the full duration; do not assert req_valid again
//     until busy is low.
//
// Avalon-MM signals to wire to hps_0 / Platform Designer:
//   avm_*   ->  connect directly to f2h_sdram0_data port
// =============================================================================

module l2_sdram_master (
    // -------------------------------------------------------------------------
    // System
    // -------------------------------------------------------------------------
    input  logic        clk,         
    input  logic        rst_n,

    // -------------------------------------------------------------------------
    // L2 cache interface
    // -------------------------------------------------------------------------
    input  logic        req_valid,    // Pulse high to start a transaction
    input  logic [29:0] req_addr,     // Byte address, must be 64-byte aligned
    input  logic        req_we,       // 1 = write (eviction), 0 = read (fill)

    // Write path — L2 provides one beat per cycle when beat_ack is high
    input  logic [511:0] req_wdata,    // Write data for current beat
    input  logic   [7:0] req_wbe,      // Byte enables for current beat

    // Read path — master returns one beat per cycle
    output logic [511:0] rdata,        // Read data for request
    output logic         rdata_valid,  // Pulses once all bursts are read

    output logic        beat_ack,     // Pulses when master consumed/emitted beat
    output logic        busy,         // High for full duration of transaction
    output logic        done,         // Single-cycle pulse on completion
    output logic        err,          // Pulses if Avalon returns slverr/decoderr

    // -------------------------------------------------------------------------
    // Avalon-MM Master port  (wire to f2h_sdram0_data in Platform Designer)
    // -------------------------------------------------------------------------
    output logic [28:0] avm_address,       // Byte address
    output logic  [7:0] avm_burstcount,    // Fixed 8 for a 64-byte line
    input  logic        avm_waitrequest,
    input  logic [63:0] avm_readdata,
    input  logic        avm_readdatavalid,
    output logic        avm_read,
    output logic [63:0] avm_writedata,
    output logic  [7:0] avm_byteenable,
    output logic        avm_write,
);

    // -------------------------------------------------------------------------
    // Parameters
    // -------------------------------------------------------------------------
    localparam int BEATS        = 8;       // 64 bytes / 8 bytes per beat
    localparam int BEAT_W       = 3;       // clog2(BEATS)
    localparam bit [7:0] BURST  = 8'd8;

    // -------------------------------------------------------------------------
    // State machine
    // -------------------------------------------------------------------------
    typedef enum logic [2:0] {
        S_IDLE,
        S_WRITE_CMD,   // Issue first write beat (cmd + first data together)
        S_WRITE_BURST, // Issue beats 1..7
        S_READ_CMD,    // Issue read command
        S_READ_DATA,   // Collect read data beats
        S_DONE
    } state_t;

    state_t state, next;

    // -------------------------------------------------------------------------
    // Internal registers
    // -------------------------------------------------------------------------
    logic [31:0]       r_addr;
    logic [BEAT_W-1:0] wbeat_cnt;   // Which beat we are on (0-7)
    logic [BEAT_W-1:0] rbeat_cnt;  // Read beat counter

    // -------------------------------------------------------------------------
    // FSM — sequential
    // -------------------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state     <= S_IDLE;
            r_addr    <= '0;
            wbeat_cnt <= '0;
            rbeat_cnt <= '0;
        end else begin
            state <= next;

            case (state)
                S_IDLE: begin
                    wbeat_cnt  <= '0;
                    rbeat_cnt <= '0;
                    if (req_valid) begin
                        // Latch address; enforce 64-byte alignment
                        r_addr <= {req_addr[31:6], 6'b0};
                    end
                end

                S_WRITE_CMD,
                S_WRITE_BURST: begin
                    // Advance beat counter only when Avalon accepts the beat
                    if (!avm_waitrequest) begin
                        wbeat_cnt <= wbeat_cnt + 1'b1;
                    end
                end

                S_READ_DATA: begin
                    if (avm_readdatavalid) begin
                        rbeat_cnt <= rbeat_cnt + 1'b1;
                    end
                end

                default: ;
            endcase
        end
    end

    // -------------------------------------------------------------------------
    // FSM — combinational next-state
    // -------------------------------------------------------------------------
    always_comb begin
        next = state;
        case (state)
            S_IDLE:
                if (req_valid)
                    next = req_we ? S_WRITE_CMD : S_READ_CMD;

            S_WRITE_CMD:
                // Stay until Avalon accepts; then move to burst beats
                if (!avm_waitrequest)
                    next = S_WRITE_BURST;

            S_WRITE_BURST:
                if (!avm_waitrequest && (wbeat_cnt == 3'd7))
                    next = S_DONE;

            S_READ_CMD:
                if (!avm_waitrequest)
                    next = S_READ_DATA;

            S_READ_DATA:
                if (avm_readdatavalid && (rbeat_cnt == 3'd7))
                    next = S_DONE;

            S_DONE:
                next = S_IDLE;

            default:
                next = S_IDLE;
        endcase
    end

    // -------------------------------------------------------------------------
    // Avalon-MM outputs
    // -------------------------------------------------------------------------
    always_comb begin
        // Defaults
        avm_address    = r_addr;
        avm_read       = 1'b0;
        avm_write      = 1'b0;
        avm_writedata  = req_wdata;
        avm_byteenable = req_wbe;
        avm_burstcount = BURST;

        case (state)
            S_WRITE_CMD,
            S_WRITE_BURST: begin
                avm_write      = 1'b1;
                avm_writedata  = req_wdata;
                avm_byteenable = req_wbe;
            end

            S_READ_CMD: begin
                avm_read = 1'b1;
            end

            default: ;
        endcase
    end

    // -------------------------------------------------------------------------
    // L2-facing outputs
    // -------------------------------------------------------------------------
    assign busy        = (state != S_IDLE);
    assign done        = (state == S_DONE);
    assign beat_ack    = ((state == S_WRITE_CMD || state == S_WRITE_BURST)
                           && !avm_waitrequest)
                       || (state == S_READ_DATA && avm_readdatavalid);

    assign rdata       = avm_readdata;
    assign rdata_valid = (state == S_READ_DATA) && avm_readdatavalid;

    // Error: flag any non-OKAY Avalon response on valid data beats
    assign err = avm_readdatavalid && (avm_response != 2'b00);

    // -------------------------------------------------------------------------
    // Assertions (synthesises away; useful in simulation)
    // -------------------------------------------------------------------------
    // pragma translate_off
    always_ff @(posedge clk) begin
        if (rst_n && req_valid && busy)
            $warning("l2_sdram_master: req_valid asserted while busy — ignored");
        if (rst_n && req_valid && (req_addr[5:0] != 6'b0))
            $error("l2_sdram_master: req_addr is not 64-byte aligned: %h", req_addr);
    end
    // pragma translate_on

endmodule