`timescale 1ns/1ps

// Directed testbench for l1_cache (max/mshr l1.sv).
//
// Strategy: pre-load dut.l2.mm.mem[] with known blocks before simulation,
// then let the real l1->l2->mainmem->l2->l1 pipeline run.
// No force/release — avoids iverilog/Verilator unpacked-array limitations.
//
// Pipeline latency (posedges from l2_miss_in strobe to l1 install):
//   P+0 : l2_miss_in fires (l1 always_ff output)
//   P+1 : l2 accepts, mm_miss_in set
//   P+2 : mm accepts, countdown=20, active=1
//   P+3..P+22 : countdown 20->0 (20 posedges)
//   P+23: mm.resolve_out fires
//   P+24: l2 installs, l2.resolve_out fires
//   P+25: l1 installs block  <-- install posedge
// PIPE_CYCLES=26 after send_req return guarantees install is visible.
//
// mainmem blk index = pa[6 +: 14]:
//   PA_S0T0 = 0x100 -> blk 4   (BLOCK_A)
//   PA_S0T1 = 0x200 -> blk 8   (BLOCK_B)
//   PA_S0T2 = 0x300 -> blk 12  (BLOCK_C)
//   PA_S1T0 = 0x440 -> blk 17  (BLOCK_A)
//   PA_S1T1 = 0x540 -> blk 21  (BLOCK_B)

module tb_l1_accurate;

    localparam int PA_WIDTH    = 30;
    localparam int VA_WIDTH    = 48;
    localparam int BLOCK_SIZE  = 64;   // bytes; wdata port is [BLOCK_SIZE-1:0]=64-bit
    localparam int L1_MSHRS   = 2;
    localparam int L1_CAPACITY = 512;
    localparam int L1_WAYS     = 2;
    localparam int L1_SETS     = L1_CAPACITY / (BLOCK_SIZE * L1_WAYS);  // 4
    localparam int INDEX_BITS  = $clog2(L1_SETS);    // 2
    localparam int OFFSET_BITS = $clog2(BLOCK_SIZE);  // 6
    localparam int TAG_BITS    = PA_WIDTH - INDEX_BITS - OFFSET_BITS;  // 22

    // Posedges to wait after send_req returns for l1 block install.
    localparam int PIPE_CYCLES = 26;

    // Physical addresses: {tag[21:0], index[1:0], offset[5:0]}
    localparam [PA_WIDTH-1:0] PA_S0T0 = {22'h000001, 2'b00, 6'h00};  // 0x100
    localparam [PA_WIDTH-1:0] PA_S0T1 = {22'h000002, 2'b00, 6'h00};  // 0x200
    localparam [PA_WIDTH-1:0] PA_S0T2 = {22'h000003, 2'b00, 6'h00};  // 0x300
    localparam [PA_WIDTH-1:0] PA_S1T0 = {22'h000004, 2'b01, 6'h00};  // 0x440
    localparam [PA_WIDTH-1:0] PA_S1T1 = {22'h000005, 2'b01, 6'h00};  // 0x540

    // Virtual addresses: bits[7:6] = cache set index
    localparam [VA_WIDTH-1:0] VA_S0 = 48'h0000_0000_0000;  // bits[7:6]=00 -> set 0
    localparam [VA_WIDTH-1:0] VA_S1 = 48'h0000_0000_0040;  // bits[7:6]=01 -> set 1

    localparam [BLOCK_SIZE*8-1:0] BLOCK_A = {8{64'hAAAA_AAAA_AAAA_AAAA}};
    localparam [BLOCK_SIZE*8-1:0] BLOCK_B = {8{64'hBBBB_BBBB_BBBB_BBBB}};
    localparam [BLOCK_SIZE*8-1:0] BLOCK_C = {8{64'hCCCC_CCCC_CCCC_CCCC}};

    // ----------------------------------------------------------------
    // DUT
    // ----------------------------------------------------------------
    logic                  clk;
    logic                  rst_n;
    logic                  start_tag_in;
    logic [PA_WIDTH-1:0]   tlb_paddr_in;
    logic                  start_in;
    logic [VA_WIDTH-1:0]   trace_vaddr_in;
    logic                  w_in;
    logic [BLOCK_SIZE-1:0] wdata_in;
    wire                   stall_out;

    integer pass_cnt, fail_cnt;

    l1_cache dut (
        .clk            (clk),
        .rst_n          (rst_n),
        .start_tag_in   (start_tag_in),
        .tlb_paddr_in   (tlb_paddr_in),
        .start_in       (start_in),
        .trace_vaddr_in (trace_vaddr_in),
        .w_in           (w_in),
        .wdata_in       (wdata_in),
        .stall_out      (stall_out)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    // ----------------------------------------------------------------
    // Check helpers
    // ----------------------------------------------------------------
    task automatic chk_bit;
        input [255:0] name; input got; input exp;
        if (got === exp) begin
            $display("  PASS  %s", name); pass_cnt++;
        end else begin
            $display("  FAIL  %s  got=%b exp=%b @%0t", name, got, exp, $time);
            fail_cnt++;
        end
    endtask

    task automatic chk_pa;
        input [255:0] name;
        input [PA_WIDTH-1:0] got, exp;
        if (got === exp) begin
            $display("  PASS  %s", name); pass_cnt++;
        end else begin
            $display("  FAIL  %s  got=%0h exp=%0h @%0t", name, got, exp, $time);
            fail_cnt++;
        end
    endtask

    task automatic chk_wide;
        input [255:0] name;
        input [BLOCK_SIZE*8-1:0] got, exp;
        if (got === exp) begin
            $display("  PASS  %s", name); pass_cnt++;
        end else begin
            $display("  FAIL  %s  got=%0h exp=%0h @%0t", name, got, exp, $time);
            fail_cnt++;
        end
    endtask

    task automatic chk_64;
        input [255:0] name; input [63:0] got, exp;
        if (got === exp) begin
            $display("  PASS  %s", name); pass_cnt++;
        end else begin
            $display("  FAIL  %s  got=%0h exp=%0h @%0t", name, got, exp, $time);
            fail_cnt++;
        end
    endtask

    // ----------------------------------------------------------------
    // Port helpers
    // ----------------------------------------------------------------
    task automatic idle_inputs;
        start_tag_in   = 1'b0;
        tlb_paddr_in   = '0;
        start_in       = 1'b0;
        trace_vaddr_in = '0;
        w_in           = 1'b0;
        wdata_in       = '0;
    endtask

    task automatic apply_reset;
        idle_inputs();
        rst_n = 1'b0;
        repeat (2) @(negedge clk);
        rst_n = 1'b1;
        @(negedge clk);
    endtask

    // 2-cycle request protocol.
    // Negedge 1: assert start_in + vaddr
    // Negedge 2: deassert start_in, assert start_tag_in + paddr
    //            (posedge between negedge2 and negedge3 = tag-check posedge P)
    // Negedge 3: deassert start_tag_in.  Returns here.
    //   At this point l2_miss_in[free_idx]=1 (one-cycle strobe) if it was a miss.
    task automatic send_req;
        input [VA_WIDTH-1:0] vaddr;
        input [PA_WIDTH-1:0] paddr;
        input                wr;
        input [63:0]         data;
        @(negedge clk);
        start_in       = 1'b1;
        trace_vaddr_in = vaddr;
        w_in           = wr;
        wdata_in       = data[BLOCK_SIZE-1:0];
        @(negedge clk);
        start_in     = 1'b0;
        start_tag_in = 1'b1;
        tlb_paddr_in = paddr;
        @(negedge clk);
        start_tag_in = 1'b0;
        tlb_paddr_in = '0;
    endtask

    // Issue a load miss and wait for the full pipeline to install the block.
    // After return, valid/contents/tags are stable at the negedge.
    task automatic do_miss;
        input [VA_WIDTH-1:0] vaddr;
        input [PA_WIDTH-1:0] paddr;
        send_req(vaddr, paddr, 1'b0, '0);
        repeat (PIPE_CYCLES) @(posedge clk);
        @(negedge clk);
    endtask

    // ----------------------------------------------------------------
    // Main test body
    // ----------------------------------------------------------------
    initial begin
        pass_cnt = 0; fail_cnt = 0;
        idle_inputs();
        rst_n = 1'b1;

        // Pre-load mainmem with known blocks.
        // rst_n does NOT clear mem[], so this survives all apply_reset calls.
        dut.l2.mm.mem[4]  = BLOCK_A;   // PA_S0T0
        dut.l2.mm.mem[8]  = BLOCK_B;   // PA_S0T1
        dut.l2.mm.mem[12] = BLOCK_C;   // PA_S0T2
        dut.l2.mm.mem[17] = BLOCK_A;   // PA_S1T0
        dut.l2.mm.mem[21] = BLOCK_B;   // PA_S1T1

        // ============================================================
        // T1: Reset — stall low, all state clear
        // ============================================================
        $display("\n=== T1: Reset and idle outputs ===");
        apply_reset();
        @(negedge clk);
        chk_bit("T1 stall low after reset",    stall_out,           1'b0);
        chk_bit("T1 evict_in clear",           dut.evict_in,        1'b0);
        chk_bit("T1 valid[0][0] clear",        dut.valid[0][0],     1'b0);
        chk_bit("T1 valid[0][1] clear",        dut.valid[0][1],     1'b0);
        chk_bit("T1 l2_miss_in[0] clear",      dut.l2_miss_in[0],   1'b0);
        chk_bit("T1 l2_empty_out[0] idle",     dut.l2_empty_out[0], 1'b1);
        chk_bit("T1 l2_empty_out[1] idle",     dut.l2_empty_out[1], 1'b1);

        // ============================================================
        // T2: Cold miss — l2_miss_in pulses, paddr captured, MSHR busy
        // ============================================================
        $display("\n=== T2: Cold miss allocates an MSHR ===");
        apply_reset();
        send_req(VA_S0, PA_S0T0, 1'b0, '0);
        // send_req returns at negedge after tag-check posedge P.
        // l2_miss_in[0] was set at P, readable now.
        chk_bit("T2 l2_miss_in[0] pulsed",      dut.l2_miss_in[0],  1'b1);
        chk_pa ("T2 l2_paddr_in[0] = PA_S0T0",  dut.l2_paddr_in[0], PA_S0T0);
        // Wait one posedge (P+1): l2 accepts, l2_empty_out[0] -> 0
        @(posedge clk); @(negedge clk);
        chk_bit("T2 MSHR 0 busy after l2 accepts", dut.l2_empty_out[0], 1'b0);
        chk_bit("T2 stall low (MSHR 1 still free)", stall_out,           1'b0);
        // Let pipeline complete
        repeat (PIPE_CYCLES - 1) @(posedge clk);
        @(negedge clk);
        chk_bit("T2 MSHR 0 free after resolve",    dut.l2_empty_out[0], 1'b1);

        // ============================================================
        // T3: Pipeline installs block in L1
        // ============================================================
        $display("\n=== T3: Miss fills L1 after pipeline ===");
        apply_reset();
        do_miss(VA_S0, PA_S0T0);
        chk_bit ("T3 valid[0][0] set",           dut.valid[0][0],    1'b1);
        chk_wide("T3 contents[0][0] = BLOCK_A",  dut.contents[0][0], BLOCK_A);
        chk_pa  ("T3 tags[0][0] = PA_S0T0 tag",  dut.tags[0][0],
                 PA_S0T0[PA_WIDTH-1 -: TAG_BITS]);

        // ============================================================
        // T4: Load hit — no l2_miss_in pulse, lru updates
        // (continuing from T3 state: way0 has PA_S0T0)
        // ============================================================
        $display("\n=== T4: Load hit does not generate miss ===");
        send_req(VA_S0, PA_S0T0, 1'b0, '0);
        // At this negedge (after tag-check posedge): lru already updated, no miss
        chk_bit("T4 l2_miss_in[0] silent on hit", dut.l2_miss_in[0], 1'b0);
        chk_bit("T4 l2_miss_in[1] silent on hit", dut.l2_miss_in[1], 1'b0);
        chk_bit("T4 stall low on hit",             stall_out,         1'b0);
        // hit_way=0, lru[0] <= ~0 = 1 (way1 is now LRU)
        chk_bit("T4 lru[0]=1 after way0 hit",      dut.lru[0],        1'b1);

        // ============================================================
        // T5: Store hit — dirty bit set, wdata written into contents
        // (continuing: way0 PA_S0T0, lru[0]=1)
        // ============================================================
        $display("\n=== T5: Store hit sets dirty and writes wdata ===");
        send_req(VA_S0, PA_S0T0, 1'b1, 64'hDEAD_CAFE_1234_5678);
        // hit fires at tag-check posedge; dirty and contents updated there
        chk_bit("T5 l2_miss_in[0] silent",      dut.l2_miss_in[0],         1'b0);
        chk_bit("T5 dirty[0][0] set",           dut.dirty[0][0],            1'b1);
        chk_64 ("T5 wdata in contents[0][0]",   dut.contents[0][0][63:0],
                                                 64'hDEAD_CAFE_1234_5678);

        // ============================================================
        // T6: Second miss fills way1 (lru[0]=1 after T4 hit)
        // (way0: PA_S0T0 dirty; lru[0]=1 -> install into way1)
        // ============================================================
        $display("\n=== T6: Second miss fills way1 ===");
        do_miss(VA_S0, PA_S0T1);
        chk_bit ("T6 valid[0][1] set",           dut.valid[0][1],    1'b1);
        chk_wide("T6 contents[0][1] = BLOCK_B",  dut.contents[0][1], BLOCK_B);
        // way0 must be untouched
        chk_bit ("T6 valid[0][0] still set",     dut.valid[0][0],    1'b1);
        chk_bit ("T6 dirty[0][0] still dirty",   dut.dirty[0][0],    1'b1);
        // Installing into an empty/invalid way must NOT produce a dirty eviction
        chk_bit ("T6 no dirty eviction on empty-way fill", dut.e_dirty_in, 1'b0);

        // ============================================================
        // T7: Hit on way1 flips lru to 0
        // (both ways valid; hit way1 -> lru[0] = ~1 = 0 -> way0 is LRU)
        // ============================================================
        $display("\n=== T7: Hit on way1 sets lru[0]=0 ===");
        send_req(VA_S0, PA_S0T1, 1'b0, '0);
        chk_bit("T7 no miss on hit",            dut.l2_miss_in[0], 1'b0);
        chk_bit("T7 lru[0]=0 after way1 hit",   dut.lru[0],        1'b0);

        // ============================================================
        // T8: Third miss evicts way0 (dirty) -> e_dirty_in=1, e_paddr=PA_S0T0
        // (lru[0]=0 -> evict way0 which holds dirty PA_S0T0)
        // ============================================================
        $display("\n=== T8: Third miss evicts dirty way0 ===");
        do_miss(VA_S0, PA_S0T2);
        // evict_in was a one-cycle pulse at install posedge; now cleared.
        // e_paddr_in / e_dirty_in persist until next eviction.
        chk_bit ("T8 e_dirty_in = 1",           dut.e_dirty_in,     1'b1);
        chk_pa  ("T8 e_paddr_in = PA_S0T0",     dut.e_paddr_in,     PA_S0T0);
        chk_wide("T8 BLOCK_C installed in way0", dut.contents[0][0], BLOCK_C);

        // ============================================================
        // T9: Two outstanding misses -> both MSHRs fill -> stall
        // ============================================================
        $display("\n=== T9: Two misses fill both MSHRs -> stall ===");
        apply_reset();
        // First miss: PA_S1T0 (set 1). free_mshr_idx picks MSHR 0.
        send_req(VA_S1, PA_S1T0, 1'b0, '0);
        chk_bit("T9 l2_miss_in[0] pulsed (1st miss)", dut.l2_miss_in[0], 1'b1);
        chk_pa ("T9 l2_paddr_in[0] = PA_S1T0",        dut.l2_paddr_in[0], PA_S1T0);
        // Wait one posedge for l2 to accept MSHR 0
        @(posedge clk); @(negedge clk);
        chk_bit("T9 MSHR 0 busy",               dut.l2_empty_out[0], 1'b0);
        chk_bit("T9 stall low (MSHR 1 free)",   stall_out,           1'b0);
        // Second miss: PA_S0T0 (set 0). Only MSHR 1 free -> uses MSHR 1.
        send_req(VA_S0, PA_S0T0, 1'b0, '0);
        chk_bit("T9 l2_miss_in[1] pulsed (2nd miss)", dut.l2_miss_in[1], 1'b1);
        chk_pa ("T9 l2_paddr_in[1] = PA_S0T0",        dut.l2_paddr_in[1], PA_S0T0);
        // Wait one posedge for l2 to accept MSHR 1
        @(posedge clk); @(negedge clk);
        chk_bit("T9 MSHR 1 busy",               dut.l2_empty_out[1], 1'b0);
        chk_bit("T9 stall high (both full)",    stall_out,           1'b1);
        // Wait for both pipelines to complete.
        // MSHR 1 fires 3 posedges after MSHR 0, so finishes 3 cycles later.
        repeat (PIPE_CYCLES + 4) @(posedge clk);
        @(negedge clk);
        chk_bit("T9 stall clears after both resolve", stall_out,           1'b0);
        chk_bit("T9 MSHR 0 free",                     dut.l2_empty_out[0], 1'b1);
        chk_bit("T9 MSHR 1 free",                     dut.l2_empty_out[1], 1'b1);

        // ============================================================
        // T10: Clean idle state after reset
        // ============================================================
        $display("\n=== T10: Clean idle after reset ===");
        apply_reset();
        @(negedge clk);
        chk_bit("T10 stall low",         stall_out,           1'b0);
        chk_bit("T10 evict_in low",      dut.evict_in,        1'b0);
        chk_bit("T10 valid[0][0] clear", dut.valid[0][0],     1'b0);
        chk_bit("T10 valid[1][0] clear", dut.valid[1][0],     1'b0);
        chk_bit("T10 l2_empty_out[0]",   dut.l2_empty_out[0], 1'b1);
        chk_bit("T10 l2_empty_out[1]",   dut.l2_empty_out[1], 1'b1);

        $display("\n==========================================");
        $display("  PASSED: %0d    FAILED: %0d", pass_cnt, fail_cnt);
        if (fail_cnt == 0) $display("  ALL TESTS PASSED");
        else               $display("  *** FAILURES DETECTED ***");
        $display("==========================================\n");
        $finish;
    end

    initial begin
        #500_000;
        $display("[TB] TIMEOUT");
        $finish;
    end

endmodule
