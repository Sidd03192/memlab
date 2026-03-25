`timescale 1ns/1ps

module tb_simple_trace_avl_wrapper;
    import simple_trace_pkg::*;

    logic        clk;
    logic        rst_n;
    logic [5:0]  avs_address;
    logic        avs_write;
    logic        avs_read;
    logic [31:0] avs_writedata;
    logic [31:0] avs_readdata;
    logic [28:0] avm_address;
    logic [7:0]  avm_burstcount;
    logic        avm_read;
    logic        avm_write;
    logic [63:0] avm_writedata;
    logic [7:0]  avm_byteenable;
    logic        avm_waitrequest;

    integer cycle_count;
    integer write_count;
    integer submit_cycle;
    integer last_write_cycle;
    logic [28:0] last_write_addr;
    logic [63:0] last_write_data;

    simple_trace_avl_wrapper dut (
        .clk            (clk),
        .rst_n          (rst_n),
        .avs_address    (avs_address),
        .avs_write      (avs_write),
        .avs_read       (avs_read),
        .avs_writedata  (avs_writedata),
        .avs_readdata   (avs_readdata),
        .avm_address    (avm_address),
        .avm_burstcount (avm_burstcount),
        .avm_read       (avm_read),
        .avm_write      (avm_write),
        .avm_writedata  (avm_writedata),
        .avm_byteenable (avm_byteenable),
        .avm_waitrequest(avm_waitrequest)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    task automatic idle_bus;
        begin
            avs_address   = '0;
            avs_write     = 1'b0;
            avs_read      = 1'b0;
            avs_writedata = '0;
        end
    endtask

    task automatic mmio_write(
        input logic [5:0] addr,
        input logic [31:0] data
    );
        begin
            @(negedge clk);
            avs_address   = addr;
            avs_writedata = data;
            avs_write     = 1'b1;
            @(posedge clk);
            @(negedge clk);
            avs_write     = 1'b0;
            avs_writedata = '0;
        end
    endtask

    task automatic wait_ready(
        input [255:0] label
    );
        integer spins;
        begin
            spins = 0;
            avs_address = REG_STATUS0;
            avs_read    = 1'b1;
            @(posedge clk);
            while (!avs_readdata[DBG_READY_BIT]) begin
                spins = spins + 1;
                if (spins > 32)
                    $fatal(1, "%0s: ready stayed low", label);
                @(posedge clk);
            end
            @(negedge clk);
            avs_read = 1'b0;
        end
    endtask

    task automatic wait_go_clear(
        input [255:0] label
    );
        integer spins;
        begin
            spins = 0;
            avs_address = REG_WRITE_GO;
            avs_read    = 1'b1;
            @(posedge clk);
            if (!dut.write_go_reg)
                $fatal(1, "%0s: go register never asserted", label);
            while (avs_readdata[0]) begin
                spins = spins + 1;
                if (spins > 32)
                    $fatal(1, "%0s: go register did not clear", label);
                @(posedge clk);
            end
            @(negedge clk);
            avs_read = 1'b0;
        end
    endtask

    task automatic issue_write(
        input [255:0] label,
        input logic [31:0] byte_addr,
        input logic [63:0] wdata
    );
        begin
            wait_ready({label, " pre"});
            mmio_write(REG_WRITE_ADDR, byte_addr);
            mmio_write(REG_WRITE_DATA_LO, wdata[31:0]);
            mmio_write(REG_WRITE_DATA_HI, wdata[63:32]);
            submit_cycle = cycle_count;
            mmio_write(REG_WRITE_GO, 32'd1);
            wait_go_clear({label, " go"});
        end
    endtask

    initial begin
        logic [31:0] expected_addr_word;

        idle_bus();
        rst_n            = 1'b0;
        avm_waitrequest  = 1'b0;
        cycle_count      = 0;
        write_count      = 0;
        submit_cycle     = -1;
        last_write_cycle = -1;
        last_write_addr  = '0;
        last_write_data  = '0;

        repeat (5) @(posedge clk);
        rst_n = 1'b1;
        repeat (2) @(posedge clk);

        expected_addr_word = (32'h2000_0018 >> 3);
        issue_write("write0", 32'h2000_0018, 64'h1122_3344_5566_7788);
        if (dut.write_go_reg !== 1'b0)
            $fatal(1, "write0: go register should auto-clear");
        if (dut.u_master.busy !== 1'b1)
            $fatal(1, "write0: master should be busy after request acceptance");
        wait (write_count == 1);
        if (last_write_cycle <= submit_cycle + 1)
            $fatal(1, "write0: write did not respect one-cycle latency");
        if (avm_burstcount !== 8'd1 || avm_byteenable !== 8'hFF || avm_read !== 1'b0)
            $fatal(1, "write0: Avalon control outputs incorrect");
        if (last_write_addr !== expected_addr_word[28:0])
            $fatal(1, "write0: wrong address");
        if (last_write_data !== 64'h1122_3344_5566_7788)
            $fatal(1, "write0: wrong write data");
        wait_ready("write0 post");

        avm_waitrequest = 1'b1;
        issue_write("write1_waitrequest", 32'h2000_0040, 64'hA5A5_5A5A_0123_4567);
        repeat (3) @(posedge clk);
        if (write_count != 1)
            $fatal(1, "write1_waitrequest: write completed too early");
        if (dut.u_master.busy !== 1'b1 || avm_write !== 1'b1)
            $fatal(1, "write1_waitrequest: master did not hold under waitrequest");
        avm_waitrequest = 1'b0;
        wait (write_count == 2);
        wait_ready("write1_waitrequest post");

        issue_write("write2_back_to_back", 32'h2000_0088, 64'h0BAD_F00D_1234_5678);
        wait (write_count == 3);
        wait_ready("write2_back_to_back post");
        if (dut.u_master.done_pulse !== 1'b0)
            $display("Note: done_pulse is one cycle wide and may already be low here.");

        $display("PASS: tb_simple_trace_avl_wrapper");
        $finish;
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cycle_count      <= 0;
            write_count      <= 0;
            last_write_cycle <= -1;
            last_write_addr  <= '0;
            last_write_data  <= '0;
        end else begin
            cycle_count <= cycle_count + 1;
            if (avm_write && !avm_waitrequest) begin
                write_count      <= write_count + 1;
                last_write_cycle <= cycle_count;
                last_write_addr  <= avm_address;
                last_write_data  <= avm_writedata;
            end
        end
    end
endmodule
