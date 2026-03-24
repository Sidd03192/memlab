`timescale 1ns/1ps

module tb_memsys_sq_backpressure;

    localparam int VA_WIDTH    = 48;
    localparam int PA_WIDTH    = 30;
    localparam int DATA_WIDTH  = 64;
    localparam int BLOCK_SIZE  = 64;
    localparam int TRACE_WIDTH = 121;
    localparam int LINE_W      = BLOCK_SIZE * 8;

    localparam logic [2:0] OP_MEM_LOAD    = 3'd0;
    localparam logic [2:0] OP_MEM_STORE   = 3'd1;
    localparam logic [2:0] OP_MEM_RESOLVE = 3'd2;
    localparam logic [2:0] OP_TLB_FILL    = 3'd4;

    logic                   clk;
    logic                   rst_n;
    logic [TRACE_WIDTH-1:0] trace_data;
    logic                   trace_valid;
    wire                    trace_ready;

    wire                    mem_req_valid;
    wire                    mem_req_is_write;
    wire [PA_WIDTH-1:0]     mem_req_addr;
    wire [LINE_W-1:0]       mem_req_wdata;
    logic                   mem_req_ready;
    logic                   mem_resp_valid;
    logic [PA_WIDTH-1:0]    mem_resp_paddr;
    logic [LINE_W-1:0]      mem_resp_rdata;

    logic [28:0] avm_address;
    logic [7:0]  avm_burstcount;
    logic        avm_read;
    logic        avm_write;
    logic [63:0] avm_writedata;
    logic [7:0]  avm_byteenable;
    logic [63:0] avm_readdata;
    logic        avm_readdatavalid;
    logic        avm_waitrequest;

    memory_subsystem dut (
        .clk             (clk),
        .rst_n           (rst_n),
        .trace_data      (trace_data),
        .trace_addr      ('0),
        .trace_data_chunk('0),
        .trace_valid     (trace_valid),
        .trace_write     (1'b0),
        .trace_ready     (trace_ready),
        .mem_req_valid   (mem_req_valid),
        .mem_req_is_write(mem_req_is_write),
        .mem_req_addr    (mem_req_addr),
        .mem_req_wdata   (mem_req_wdata),
        .mem_req_ready   (mem_req_ready),
        .mem_resp_valid  (mem_resp_valid),
        .mem_resp_paddr  (mem_resp_paddr),
        .mem_resp_rdata  (mem_resp_rdata),
        .avm_address     (avm_address),
        .avm_burstcount  (avm_burstcount),
        .avm_read        (avm_read),
        .avm_write       (avm_write),
        .avm_writedata   (avm_writedata),
        .avm_byteenable  (avm_byteenable),
        .avm_readdata    (avm_readdata),
        .avm_readdatavalid(avm_readdatavalid),
        .avm_waitrequest (avm_waitrequest)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    task automatic idle_inputs;
        begin
            trace_data       = '0;
            trace_valid      = 1'b0;
            mem_req_ready    = 1'b1;
            mem_resp_valid   = 1'b0;
            mem_resp_paddr   = '0;
            mem_resp_rdata   = '0;
            avm_readdata     = '0;
            avm_readdatavalid = 1'b0;
            avm_waitrequest  = 1'b0;
        end
    endtask

    task automatic apply_reset;
        begin
            idle_inputs();
            rst_n = 1'b0;
            repeat (3) @(posedge clk);
            rst_n = 1'b1;
            @(posedge clk);
        end
    endtask

    function automatic logic [TRACE_WIDTH-1:0] make_store_packet(
        input logic [3:0]         id,
        input logic [VA_WIDTH-1:0] vaddr,
        input logic               vaddr_valid,
        input logic [DATA_WIDTH-1:0] value,
        input logic               value_valid
    );
        logic [TRACE_WIDTH-1:0] packet;
        begin
            packet = '0;
            packet[54:52]  = OP_MEM_STORE;
            packet[51:48]  = id;
            packet[47:0]   = vaddr;
            packet[55]     = vaddr_valid;
            packet[119:56] = value;
            packet[120]    = value_valid;
            make_store_packet = packet;
        end
    endfunction

    function automatic logic [TRACE_WIDTH-1:0] make_resolve_packet(
        input logic [3:0]          id,
        input logic [VA_WIDTH-1:0] vaddr,
        input logic                vaddr_valid,
        input logic [DATA_WIDTH-1:0] value,
        input logic                value_valid
    );
        logic [TRACE_WIDTH-1:0] packet;
        begin
            packet = '0;
            packet[54:52]  = OP_MEM_RESOLVE;
            packet[51:48]  = id;
            packet[47:0]   = vaddr;
            packet[55]     = vaddr_valid;
            packet[119:56] = value;
            packet[120]    = value_valid;
            make_resolve_packet = packet;
        end
    endfunction

    task automatic send_when_ready(
        input logic [TRACE_WIDTH-1:0] packet
    );
        begin
            @(negedge clk);
            trace_data  = packet;
            trace_valid = 1'b1;
            @(posedge clk);
            while (!trace_ready)
                @(posedge clk);
            @(negedge clk);
            trace_valid = 1'b0;
            trace_data  = '0;
        end
    endtask

    initial begin
        logic [TRACE_WIDTH-1:0] blocked_store;
        int non_empty_sq;

        $display("========================================");
        $display(" tb_memsys_sq_backpressure");
        $display("========================================");

        apply_reset();

        // Fill all 8 SQ entries with stores whose data is known but address is not.
        for (int i = 0; i < 8; i++) begin
            send_when_ready(make_store_packet(4'(8 + i), '0, 1'b0, 64'h100 + i, 1'b1));
        end

        @(posedge clk);
        non_empty_sq = 0;
        for (int i = 0; i < 8; i++) begin
            if (dut.u_lsq.sq_state[i] != 3'd0)
                non_empty_sq++;
        end

        if (non_empty_sq != 8 || dut.u_lsq.sq_ready !== 1'b0) begin
            $display("FAIL: expected full SQ after 8 unresolved-address stores");
            $display("      non_empty_sq=%0d sq_ready=%0b", non_empty_sq, dut.u_lsq.sq_ready);
            $fatal(1);
        end

        $display("PASS: SQ filled as expected, sq_ready dropped");

        // Model the FPGA sender stalling on the next store:
        // trace_valid stays high on a store packet while trace_ready is low.
        blocked_store = make_store_packet(4'd8, '0, 1'b0, 64'hDEAD_BEEF, 1'b1);
        @(negedge clk);
        trace_data  = blocked_store;
        trace_valid = 1'b1;

        repeat (20) @(posedge clk);
        if (trace_ready !== 1'b0 || dut.u_lsq.sq_ready !== 1'b0) begin
            $display("FAIL: expected blocked store to hold ready low while no resolves arrive");
            $display("      trace_ready=%0b sq_ready=%0b", trace_ready, dut.u_lsq.sq_ready);
            $fatal(1);
        end

        $display("PASS: with sender stuck on a blocked store, ready stays low");

        // Release the blocked store and inject a resolve for one older entry.
        @(negedge clk);
        trace_valid = 1'b0;
        trace_data  = '0;

        send_when_ready(make_resolve_packet(4'd8, 48'h0000_0000_4000, 1'b1, '0, 1'b0));

        // Give the LSQ a chance to observe the resolve and retire one store.
        repeat (4) @(posedge clk);

        if (dut.u_lsq.sq_ready !== 1'b1) begin
            $display("FAIL: resolving an older store should free SQ space");
            $display("      sq_ready=%0b sq_head=%0d sq_tail=%0d", dut.u_lsq.sq_ready,
                     dut.u_lsq.sq_head, dut.u_lsq.sq_tail);
            $fatal(1);
        end

        $display("PASS: once a resolve is allowed through, SQ space reopens");
        $display("========================================");
        $display(" Result: host-side wait on blocked store can deadlock progress");
        $display("========================================");
        $finish;
    end

    initial begin
        #100000;
        $display("TIMEOUT: tb_memsys_sq_backpressure");
        $fatal(1);
    end

endmodule
