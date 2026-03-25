module simple_trace_avl_wrapper (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [5:0]  avs_address,
    input  logic        avs_write,
    input  logic        avs_read,
    input  logic [31:0] avs_writedata,
    output logic [31:0] avs_readdata,
    output logic [28:0] avm_address,
    output logic [7:0]  avm_burstcount,
    output logic        avm_read,
    output logic        avm_write,
    output logic [63:0] avm_writedata,
    output logic [7:0]  avm_byteenable,
    input  logic        avm_waitrequest
);
    import simple_trace_pkg::*;

    logic [31:0] write_addr_reg;
    logic [31:0] write_data_lo_reg;
    logic [31:0] write_data_hi_reg;
    logic        write_go_reg;
    logic        write_ready_wire;
    logic        busy_wire;
    logic        done_pulse_wire;
    logic [31:0] status0;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            write_addr_reg    <= '0;
            write_data_lo_reg <= '0;
            write_data_hi_reg <= '0;
            write_go_reg      <= 1'b0;
        end else begin
            if (write_go_reg && write_ready_wire)
                write_go_reg <= 1'b0;

            if (avs_write) begin
                case (avs_address)
                    REG_WRITE_ADDR:    write_addr_reg    <= avs_writedata;
                    REG_WRITE_DATA_LO: write_data_lo_reg <= avs_writedata;
                    REG_WRITE_DATA_HI: write_data_hi_reg <= avs_writedata;
                    REG_WRITE_GO:      write_go_reg      <= avs_writedata[0];
                    default: begin
                    end
                endcase
            end
        end
    end

    always_comb begin
        status0 = '0;
        status0[DBG_GO_REG_BIT]     = write_go_reg;
        status0[DBG_READY_BIT]      = write_ready_wire;
        status0[DBG_BUSY_BIT]       = busy_wire;
        status0[DBG_DONE_PULSE_BIT] = done_pulse_wire;
    end

    always_comb begin
        if (!avs_read) begin
            avs_readdata = '0;
        end else begin
            case (avs_address)
                REG_WRITE_ADDR:    avs_readdata = write_addr_reg;
                REG_WRITE_DATA_LO: avs_readdata = write_data_lo_reg;
                REG_WRITE_DATA_HI: avs_readdata = write_data_hi_reg;
                REG_WRITE_GO:      avs_readdata = {31'b0, write_go_reg};
                REG_STATUS0:       avs_readdata = status0;
                default:           avs_readdata = '0;
            endcase
        end
    end

    simple_trace_store_master u_master (
        .clk          (clk),
        .rst_n        (rst_n),
        .req_byte_addr(write_addr_reg),
        .req_wdata    ({write_data_hi_reg, write_data_lo_reg}),
        .req_valid    (write_go_reg),
        .req_ready    (write_ready_wire),
        .avm_address  (avm_address),
        .avm_burstcount(avm_burstcount),
        .avm_read     (avm_read),
        .avm_write    (avm_write),
        .avm_writedata(avm_writedata),
        .avm_byteenable(avm_byteenable),
        .avm_waitrequest(avm_waitrequest),
        .busy         (busy_wire),
        .done_pulse   (done_pulse_wire)
    );
endmodule
