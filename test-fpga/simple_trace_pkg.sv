package simple_trace_pkg;
    localparam logic [5:0] REG_WRITE_ADDR   = 6'd0;
    localparam logic [5:0] REG_WRITE_DATA_LO= 6'd1;
    localparam logic [5:0] REG_WRITE_DATA_HI= 6'd2;
    localparam logic [5:0] REG_WRITE_GO     = 6'd3;
    localparam logic [5:0] REG_STATUS0      = 6'd4;

    localparam int DBG_GO_REG_BIT           = 0;
    localparam int DBG_READY_BIT            = 1;
    localparam int DBG_BUSY_BIT             = 2;
    localparam int DBG_DONE_PULSE_BIT       = 3;
endpackage
