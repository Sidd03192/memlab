module simple_trace_store_master (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] req_byte_addr,
    input  logic [63:0] req_wdata,
    input  logic        req_valid,
    output logic        req_ready,
    output logic [28:0] avm_address,
    output logic [7:0]  avm_burstcount,
    output logic        avm_read,
    output logic        avm_write,
    output logic [63:0] avm_writedata,
    output logic [7:0]  avm_byteenable,
    input  logic        avm_waitrequest,
    output logic        busy,
    output logic        done_pulse
);
    typedef enum logic [1:0] {
        S_IDLE,
        S_HOLD1,
        S_WRITE_WAIT
    } state_t;

    state_t state;
    logic [31:0] latched_addr;
    logic [63:0] latched_wdata;

    assign req_ready      = (state == S_IDLE);
    assign busy           = (state != S_IDLE);
    assign avm_address    = latched_addr[31:3];
    assign avm_burstcount = 8'd1;
    assign avm_read       = 1'b0;
    assign avm_write      = (state == S_WRITE_WAIT);
    assign avm_writedata  = latched_wdata;
    assign avm_byteenable = 8'hFF;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state       <= S_IDLE;
            latched_addr<= '0;
            latched_wdata <= '0;
            done_pulse  <= 1'b0;
        end else begin
            done_pulse <= 1'b0;

            case (state)
                S_IDLE: begin
                    if (req_valid && req_ready) begin
                        latched_addr  <= {req_byte_addr[31:3], 3'b000};
                        latched_wdata <= req_wdata;
                        state         <= S_HOLD1;
                    end
                end

                S_HOLD1: begin
                    state <= S_WRITE_WAIT;
                end

                S_WRITE_WAIT: begin
                    if (!avm_waitrequest) begin
                        done_pulse <= 1'b1;
                        state      <= S_IDLE;
                    end
                end

                default: begin
                    state <= S_IDLE;
                end
            endcase
        end
    end
endmodule
