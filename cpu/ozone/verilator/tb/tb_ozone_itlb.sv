/* verilator lint_off UNUSEDSIGNAL */
`timescale 1ns/1ps

module tb_ozone_itlb;

    // Parameters matching the DUT
    localparam int VA_BITS = 48;
    localparam int VPN_BITS = VA_BITS - 12;
    localparam int PA_BITS = 30;
    localparam int PPN_BITS = PA_BITS - 12;
    
    // DUT Signals
    logic clk_i;
    logic rst_ni;
    
    logic lookup_req_i;
    logic [VA_BITS-1:0] lookup_vaddr_i;
    logic lookup_hit_o;
    logic [PA_BITS-1:0] lookup_paddr_o;
    
    logic fill_req_i;
    logic [VPN_BITS-1:0] fill_vpn_i;
    logic [PPN_BITS-1:0] fill_ppn_i;
    
    logic flush_all_i;
    
    logic lookup_ack_i; // Note: output from DUT
    logic fill_ack_i;   // Note: output from DUT
    logic flush_ack_i;  // Note: output from DUT

    // Instantiate the Device Under Test (DUT)
    ozone_itlb #(
        .VA_BITS(VA_BITS),
        .VPN_BITS(VPN_BITS),
        .PA_BITS(PA_BITS),
        .PPN_BITS(PPN_BITS),
        .NUM_ENTRIES(16)
    ) dut (
        .*
    );

    // Clock Generation (10ns period)
    initial begin
        clk_i = 1'b0;
        forever #5 clk_i = ~clk_i;
    end

    // ---------------------------------------------------------
    // Helper Tasks
    // ---------------------------------------------------------
    
    // Task to safely reset the DUT
    task reset_dut();
        @(posedge clk_i);
        rst_ni = 1'b0;
        lookup_req_i = 1'b0;
        fill_req_i   = 1'b0;
        flush_all_i  = 1'b0;
        repeat(2) @(posedge clk_i);
        rst_ni = 1'b1;
        @(posedge clk_i);
    endtask

    // Task to fill a TLB entry
    task fill_entry(input logic [VPN_BITS-1:0] vpn, input logic [PPN_BITS-1:0] ppn);
        @(posedge clk_i);
        fill_req_i = 1'b1;
        fill_vpn_i = vpn;
        fill_ppn_i = ppn;
        @(posedge clk_i);
        fill_req_i = 1'b0;
    endtask

    // Task to lookup a VA and check the expected PA and Hit status
    task check_lookup(
        input logic [VA_BITS-1:0] va, 
        input logic expected_hit, 
        input logic [PA_BITS-1:0] expected_pa
    );
        @(posedge clk_i);
        lookup_req_i = 1'b1;
        lookup_vaddr_i = va;
        
        // Combinational outputs should be valid immediately, but we sample just before the next edge
        #1; 
        
        if (lookup_hit_o !== expected_hit) begin
            $error("[FAIL] VA: %h | Expected Hit: %b, Got: %b", va, expected_hit, lookup_hit_o);
        end else if (expected_hit && (lookup_paddr_o !== expected_pa)) begin
            $error("[FAIL] VA: %h | Expected PA: %h, Got: %h", va, expected_pa, lookup_paddr_o);
        end else begin
            $display("[PASS] VA: %h -> Hit: %b, PA: %h", va, lookup_hit_o, expected_hit ? lookup_paddr_o : 30'h0);
        end
        
        @(posedge clk_i);
        lookup_req_i = 1'b0;
    endtask

    // ---------------------------------------------------------
    // Main Test Sequence
    // ---------------------------------------------------------
    initial begin
        $display("========================================");
        $display(" Starting ozone_itlb Testbench");
        $display("========================================");

        reset_dut();

        // ---------------------------------------------------------
        $display("\n--- Test 1: Cold Miss ---");
        // Look up an unmapped address immediately after reset
        check_lookup(.va(48'h0000_1234_5000), .expected_hit(1'b0), .expected_pa(30'h0));

        // ---------------------------------------------------------
        $display("\n--- Test 2: Basic Fill & Hit ---");
        // Fill VPN 0x12345 -> PPN 0xABC
        fill_entry(.vpn(36'h000_0001_2345), .ppn(18'h0_0ABC));
        
        // Lookup exact base address
        check_lookup(.va(48'h0000_1234_5000), .expected_hit(1'b1), .expected_pa(30'h00A_BC000));

        // ---------------------------------------------------------
        $display("\n--- Test 3: Page Offset Passthrough ---");
        // Ensure the bottom 12 bits pass through unchanged
        // VA = VPN(0x12345) + Offset(0xFFF) -> PA = PPN(0xABC) + Offset(0xFFF)
        check_lookup(.va(48'h0000_1234_5FFF), .expected_hit(1'b1), .expected_pa(30'h00A_BCFFF));
        check_lookup(.va(48'h0000_1234_5008), .expected_hit(1'b1), .expected_pa(30'h00A_BC008));

        // ---------------------------------------------------------
        $display("\n--- Test 4: FIFO Eviction (Wrap-around) ---");
        // The TLB holds 16 entries. If we write 17 entries, the first one should be evicted.
        for (int i = 0; i < 16; i++) begin
            fill_entry(.vpn(36'h100 + 36'(i)), .ppn(18'h200 + 18'(i)));
        end
        
        // Verify entry 0 (the oldest) is still there before we overwrite it
        check_lookup(.va({36'h100, 12'h0}), .expected_hit(1'b1), .expected_pa({18'h200, 12'h0}));
        
        // Write the 17th entry. This should overwrite index 0 (VPN 0x100)
        fill_entry(.vpn(36'h999), .ppn(18'h777));
        
        // Verify VPN 0x100 is now a MISS
        check_lookup(.va({36'h100, 12'h0}), .expected_hit(1'b0), .expected_pa(30'h0));
        // Verify the new VPN 0x999 is a HIT
        check_lookup(.va({36'h999, 12'h0}), .expected_hit(1'b1), .expected_pa({18'h777, 12'h0}));
        // Verify entry 1 (VPN 0x101) was NOT overwritten
        check_lookup(.va({36'h101, 12'h0}), .expected_hit(1'b1), .expected_pa({18'h201, 12'h0}));

        // ---------------------------------------------------------
        $display("\n--- Test 5: Global Flush ---");
        // Assert flush
        @(posedge clk_i);
        flush_all_i = 1'b1;
        @(posedge clk_i);
        flush_all_i = 1'b0;
        
        // Verify previously valid entries now miss
        check_lookup(.va({36'h999, 12'h0}), .expected_hit(1'b0), .expected_pa(30'h0));
        check_lookup(.va({36'h101, 12'h0}), .expected_hit(1'b0), .expected_pa(30'h0));

        $display("\n========================================");
        $display(" Simulation Complete");
        $display("========================================");
        $finish;
    end

endmodule
/* verilator lint_on UNUSEDSIGNAL */
