module memory_subsystem_avl_wrapper #(
    parameter VA_WIDTH    = 48,
    parameter PA_WIDTH    = 30,
    parameter DATA_WIDTH  = 64,
    parameter BLOCK_SIZE  = 64,
    parameter TRACE_WIDTH = 121,
    parameter LSQ_ENTRIES = 16,
    parameter TLB_ENTRIES = 16,
    parameter L1_CAPACITY = 512,
    parameter L1_WAYS     = 2,
    parameter L1_MSHRS    = 2,
    parameter L2_CAPACITY = 4096,
    parameter L2_WAYS     = 4,
    parameter L2_MSHRS    = 4,
    parameter BYPASS_L2   = 1'b1
)(
    input  logic        clk,
    input  logic        rst_n,

    // ── Avalon-MM slave (HPS → FPGA) ─────────────────────────────────
    // Platform Designer connects the HPS lightweight HPS-to-FPGA bridge here.
    // Address is word-addressed:
    //   0x0  trace_addr  [1:0]   write-only
    //   0x4  trace_data  [31:0]  write-only
    //   0x8  trace_valid [0]     write-only
    //   0xC  trace_ready [0]     read-only
    //   0x10  debug/status register, documented in docs/dev-why-nate.md
    input  logic [5:0]  avs_address,
    input  logic        avs_write,
    input  logic        avs_read,
    input  logic [31:0] avs_writedata,
    output logic [31:0] avs_readdata,

    // ── Avalon-MM master (FPGA → SDRAM) ──────────────────────────────
    output logic [28:0] avm_address,
    output logic  [7:0] avm_burstcount,
    output logic        avm_read,
    output logic        avm_write,
    output logic [63:0] avm_writedata,
    output logic  [7:0] avm_byteenable,
    input  logic [63:0] avm_readdata,
    input  logic        avm_readdatavalid,
    input  logic        avm_waitrequest
);
    logic [1:0]  trace_addr_reg;
    logic [31:0] trace_data_reg;
    logic        trace_valid_reg;
    logic        trace_ready_wire;
    logic [31:0] debug_status0;
    logic        dbg_lsq_sq_ready;
    logic        dbg_l1_mshr_full;

    localparam logic [5:0] REG_TRACE_ADDR   = 6'd0;
    localparam logic [5:0] REG_TRACE_DATA   = 6'd1;
    localparam logic [5:0] REG_TRACE_VALID  = 6'd2;
    localparam logic [5:0] REG_TRACE_READY  = 6'd3;
    localparam logic [5:0] REG_DEBUG_STATUS0 = 6'd4;

    // Pulse high for exactly one cycle when trace_data is written.
    // This is what actually clocks the chunk into trace_line inside
    // memory_subsystem — addr must already be set before this fires.
    logic trace_data_write_pulse;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            trace_addr_reg        <= '0;
            trace_data_reg        <= '0;
            trace_valid_reg       <= '0;
            trace_data_write_pulse <= '0;
        end else begin
            // Default: pulse is only high for one cycle
            trace_data_write_pulse <= 1'b0;

            // Auto-clear the software request once the memsys handshake occurs
            // so one MMIO "valid=1" write can only submit one trace record.
            if (trace_valid_reg && trace_ready_wire)
                trace_valid_reg <= 1'b0;

            if (avs_write) begin
                case (avs_address)
                    REG_TRACE_ADDR: trace_addr_reg  <= avs_writedata[1:0];  // step 1
                    REG_TRACE_DATA: begin
                        trace_data_reg        <= avs_writedata;    // step 2
                        trace_data_write_pulse <= 1'b1;            // fires chunk write
                    end
                    REG_TRACE_VALID: trace_valid_reg <= avs_writedata[0];
                endcase
            end
        end
    end

    always_comb begin
        debug_status0 = '0;
        debug_status0[0]  = trace_valid_reg;
        debug_status0[1]  = trace_ready_wire;
        debug_status0[4]  = dbg_lsq_sq_ready;
        debug_status0[7]  = dbg_l1_mshr_full;
        debug_status0[11] = BYPASS_L2;
    end

    // Read handler
    always_comb begin
        case (avs_address)
            REG_TRACE_ADDR:    avs_readdata = {30'b0, trace_addr_reg};
            REG_TRACE_DATA:    avs_readdata = trace_data_reg;
            REG_TRACE_VALID:   avs_readdata = {31'b0, trace_valid_reg};
            REG_TRACE_READY:   avs_readdata = {31'b0, trace_ready_wire};
            REG_DEBUG_STATUS0: avs_readdata = debug_status0;
            default: avs_readdata = '0;
        endcase
    end

    // ── Instantiate your existing memory_subsystem unchanged ─────────
    memory_subsystem #(
        .VA_WIDTH      (VA_WIDTH),
        .PA_WIDTH      (PA_WIDTH),
        .DATA_WIDTH    (DATA_WIDTH),
        .BLOCK_SIZE    (BLOCK_SIZE),
        .TRACE_WIDTH   (TRACE_WIDTH),
        .LSQ_ENTRIES   (LSQ_ENTRIES),
        .TLB_ENTRIES   (TLB_ENTRIES),
        .L1_CAPACITY   (L1_CAPACITY),
        .L1_WAYS       (L1_WAYS),
        .L1_MSHRS      (L1_MSHRS),
        .L2_CAPACITY   (L2_CAPACITY),
        .L2_WAYS       (L2_WAYS),
        .L2_MSHRS      (L2_MSHRS),
        .USE_AVALON_MEM(1'b1),
        .BYPASS_L2     (BYPASS_L2)
    ) u_mem_subsystem (
        .clk            (clk),
        .rst_n          (rst_n),

        // Trace — driven by the registered Avalon writes
        .trace_data     ('0),
        .trace_addr     (trace_addr_reg),
        .trace_data_chunk(trace_data_reg),
        .trace_valid    (trace_valid_reg),
        .trace_write    (trace_data_write_pulse),
        .trace_ready    (trace_ready_wire),

        .mem_req_valid  (),
        .mem_req_is_write(),
        .mem_req_addr   (),
        .mem_req_wdata  (),
        .mem_req_ready  (1'b0),
        .mem_resp_valid (1'b0),
        .mem_resp_paddr ('0),
        .mem_resp_rdata ('0),

        // SDRAM — pass straight through to top-level ports
        .avm_address       (avm_address),
        .avm_burstcount    (avm_burstcount),
        .avm_read          (avm_read),
        .avm_write         (avm_write),
        .avm_writedata     (avm_writedata),
        .avm_byteenable    (avm_byteenable),
        .avm_readdata      (avm_readdata),
        .avm_readdatavalid (avm_readdatavalid),
        .avm_waitrequest   (avm_waitrequest),
        .dbg_lsq_sq_ready  (dbg_lsq_sq_ready),
        .dbg_l1_mshr_full  (dbg_l1_mshr_full)
    );

endmodule
