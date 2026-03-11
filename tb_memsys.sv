`timescale 1ns/1ps

// Integration testbench: L1 + L2 + mainmem combined memory system.
//
// DUT: l1_cache (which instantiates l2_cache, which instantiates mainmem).
// Strategy: pre-load dut.l2.mm.mem[], let the real pipeline run, no force/release.
//
// Pipeline latencies (posedges after send_req returns):
//
//   Full miss (L1 miss -> L2 miss -> mainmem):
//     P   : l1 sets l2_miss_in (register output)
//     P+1 : l2 accepts, sets mm_miss_in
//     P+2 : mm accepts, countdown=20
//     P+3..P+22 : countdown 20->0
//     P+23: mm.resolve_out fires
//     P+24: l2 installs, sets l2.resolve_out
//     P+25: l1 installs block, fires evict_in
//     P+26: l2 processes any dirty eviction from l1
//   => PIPE_FULL=26
//
//   L2 hit (L1 miss -> L2 hit):
//     P   : l1 sets l2_miss_in
//     P+1 : l2 sees miss + hit, resolves immediately (sets resolve_out)
//     P+2 : l1 installs block
//   => PIPE_L2HIT=2
//
// L1 geometry: L1_CAPACITY=512, WAYS=2, BLOCK_SIZE=64 -> 4 sets, INDEX_BITS=2, TAG_BITS=22
//   VA_S0 bits[7:6]=00 -> set 0; VA_S1 bits[7:6]=01 -> set 1
//   lru[s]=0 after reset; install into lru[s] way; update lru[s]=~hit_way on hit
//
// L2 geometry: L2_CAPACITY=4096, WAYS=4, BLOCK_SIZE=64 -> 16 sets, INDEX_BITS=4, TAG_BITS=20
//   PA_S0T0 = 0x100: L2 set 4,  mainmem blk 4
//   PA_S0T1 = 0x200: L2 set 8,  mainmem blk 8
//   PA_S0T2 = 0x300: L2 set 12, mainmem blk 12
//   PA_S1T0 = 0x440: L2 set 1,  mainmem blk 17
//   Cold misses land on way3 (lru_mat=0 at reset -> lru[s]=3).

module tb_memsys;

    localparam int PA_WIDTH    = 30;
    localparam int VA_WIDTH    = 48;
    localparam int BLOCK_SIZE  = 64;    // bytes; wdata port is [BLOCK_SIZE-1:0]=64-bit
    localparam int L1_WAYS     = 2;
    localparam int L1_SETS     = 4;
    localparam int L2_SETS     = 16;
    localparam int INDEX_BITS  = $clog2(L1_SETS);    // 2
    localparam int OFFSET_BITS = $clog2(BLOCK_SIZE);  // 6
    localparam int TAG_BITS    = PA_WIDTH - INDEX_BITS - OFFSET_BITS;  // 22

    localparam int PIPE_FULL   = 26;   // posedges for full mainmem miss
    localparam int PIPE_L2HIT  = 2;    // posedges for L2 hit fast path

    // Physical addresses: {tag[21:0], index[1:0], offset[5:0]}
    localparam [PA_WIDTH-1:0] PA_S0T0 = {22'h000001, 2'b00, 6'h00};  // 0x100
    localparam [PA_WIDTH-1:0] PA_S0T1 = {22'h000002, 2'b00, 6'h00};  // 0x200
    localparam [PA_WIDTH-1:0] PA_S0T2 = {22'h000003, 2'b00, 6'h00};  // 0x300
    localparam [PA_WIDTH-1:0] PA_S1T0 = {22'h000004, 2'b01, 6'h00};  // 0x440

    // Virtual addresses: bits[7:6] = cache set index
    localparam [VA_WIDTH-1:0] VA_S0 = 48'h0000_0000_0000;  // set 0
    localparam [VA_WIDTH-1:0] VA_S1 = 48'h0000_0000_0040;  // set 1

    localparam [BLOCK_SIZE*8-1:0] BLOCK_A = {8{64'hAAAA_AAAA_AAAA_AAAA}};
    localparam [BLOCK_SIZE*8-1:0] BLOCK_B = {8{64'hBBBB_BBBB_BBBB_BBBB}};
    localparam [BLOCK_SIZE*8-1:0] BLOCK_C = {8{64'hCCCC_CCCC_CCCC_CCCC}};
    localparam [63:0]             DIRTY_DATA = 64'hDEAD_BEEF_CAFE_0001;

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

    // Issue a load miss and wait PIPE_FULL posedges for full pipeline completion.
    task automatic do_miss;
        input [VA_WIDTH-1:0] vaddr;
        input [PA_WIDTH-1:0] paddr;
        send_req(vaddr, paddr, 1'b0, '0);
        repeat (PIPE_FULL) @(posedge clk);
        @(negedge clk);
    endtask

    // Issue a load that hits in L2 and wait PIPE_L2HIT posedges.
    task automatic do_l2hit;
        input [VA_WIDTH-1:0] vaddr;
        input [PA_WIDTH-1:0] paddr;
        send_req(vaddr, paddr, 1'b0, '0);
        repeat (PIPE_L2HIT) @(posedge clk);
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
        // rst_n does NOT clear mem[], so these persist across all apply_reset calls.
        dut.l2.mm.mem[4]  = BLOCK_A;   // PA_S0T0
        dut.l2.mm.mem[8]  = BLOCK_B;   // PA_S0T1
        dut.l2.mm.mem[12] = BLOCK_C;   // PA_S0T2
        dut.l2.mm.mem[17] = BLOCK_A;   // PA_S1T0

        // ============================================================
        // T1: Reset clears L1 and L2 state
        // ============================================================
        $display("\n=== T1: Reset clears L1 and L2 state ===");
        apply_reset();
        @(negedge clk);
        chk_bit("T1 stall low after reset",          stall_out,              1'b0);
        chk_bit("T1 L1 valid[0][0] clear",           dut.valid[0][0],        1'b0);
        chk_bit("T1 L1 valid[0][1] clear",           dut.valid[0][1],        1'b0);
        chk_bit("T1 L2 valid[4][3] clear",           dut.l2.valid[4][3],     1'b0);
        chk_bit("T1 L2 valid[8][3] clear",           dut.l2.valid[8][3],     1'b0);
        chk_bit("T1 l2_empty_out[0] idle",           dut.l2_empty_out[0],    1'b1);
        chk_bit("T1 l2_empty_out[1] idle",           dut.l2_empty_out[1],    1'b1);

        // ============================================================
        // T2: Cold miss fills BOTH L1 (set 0 way 0) and L2 (set 4 way 3)
        // ============================================================
        $display("\n=== T2: Cold miss fills L1 and L2 ===");
        apply_reset();
        do_miss(VA_S0, PA_S0T0);
        chk_bit ("T2 L1 valid[0][0] set",               dut.valid[0][0],        1'b1);
        chk_wide("T2 L1 contents[0][0] = BLOCK_A",      dut.contents[0][0],     BLOCK_A);
        chk_bit ("T2 L1 valid[0][1] untouched",         dut.valid[0][1],        1'b0);
        chk_bit ("T2 L2 valid[4][3] set",               dut.l2.valid[4][3],     1'b1);
        chk_wide("T2 L2 contents[4][3] = BLOCK_A",      dut.l2.contents[4][3],  BLOCK_A);
        chk_bit ("T2 stall low after fill",              stall_out,              1'b0);

        // ============================================================
        // T3: L1 hit — no l2_miss_in pulse, no pipeline activity
        // (continuing from T2: L1[0][0] = PA_S0T0 = BLOCK_A)
        // ============================================================
        $display("\n=== T3: L1 hit generates no L2 miss ===");
        send_req(VA_S0, PA_S0T0, 1'b0, '0);
        chk_bit("T3 l2_miss_in[0] silent on L1 hit",   dut.l2_miss_in[0],      1'b0);
        chk_bit("T3 l2_miss_in[1] silent on L1 hit",   dut.l2_miss_in[1],      1'b0);
        chk_bit("T3 stall low on L1 hit",              stall_out,              1'b0);
        // hit on way0: lru[0] = ~0 = 1
        chk_bit("T3 lru[0]=1 after way0 hit",          dut.lru[0],             1'b1);

        // ============================================================
        // T4: L2 hit fast path
        //
        // Setup: evict PA_S0T0 cleanly from L1 (it stays in L2), then
        // re-access PA_S0T0 → L1 miss, L2 hit, resolves in PIPE_L2HIT=2 cycles.
        //
        // LRU trace (starting from T2 state, after T3):
        //   lru[0]=1 (from T3 hit on way0)
        //   do_miss(PA_S0T1): installs into way1 (lru=1). lru stays 1.
        //   hit(PA_S0T1): lru[0]=~1=0
        //   do_miss(PA_S0T2): installs into way0 (lru=0), evicts PA_S0T0 CLEANLY
        //     (dirty[0][0]=0, so L2 ignores the eviction for set 4)
        //   PA_S0T0 still in L2.set4.way3 ✓
        //   L1[0][0]=PA_S0T2, L1[0][1]=PA_S0T1, lru[0]=0
        //
        //   do_l2hit(PA_S0T0): L1 miss -> L2 hit -> installs into way0 (lru=0)
        // ============================================================
        $display("\n=== T4: L2 hit fast path (PIPE_L2HIT=2 cycles) ===");
        // State entering T4: T2 filled L1[0][0]=PA_S0T0, T3 hit way0 -> lru[0]=1
        do_miss(VA_S0, PA_S0T1);   // installs way1, lru stays 1
        send_req(VA_S0, PA_S0T1, 1'b0, '0);  // hit way1 -> lru[0]=0
        @(negedge clk);            // settle after send_req returns
        do_miss(VA_S0, PA_S0T2);   // evicts PA_S0T0 from way0 (cleanly); L2 unaffected
        // Verify PA_S0T0 still in L2 after clean eviction
        chk_bit("T4 L2.valid[4][3] intact after clean L1 eviction",
                dut.l2.valid[4][3], 1'b1);
        chk_wide("T4 L2.contents[4][3] unchanged",
                 dut.l2.contents[4][3], BLOCK_A);
        // L2-hit access: should resolve in PIPE_L2HIT=2 posedges
        do_l2hit(VA_S0, PA_S0T0);
        chk_bit ("T4 L1.valid[0][0] set after L2 hit",     dut.valid[0][0],    1'b1);
        chk_wide("T4 L1.contents[0][0] = BLOCK_A",         dut.contents[0][0], BLOCK_A);
        chk_bit ("T4 stall low after L2 hit fill",          stall_out,          1'b0);

        // ============================================================
        // T5: Dirty L1 eviction propagates dirty data to L2
        //
        // Steps: reset; fill PA_S0T0; store hit (dirties L1 block);
        // fill PA_S0T1; hit PA_S0T1 (flip lru to 0);
        // fill PA_S0T2 (evicts dirty PA_S0T0 from L1 -> L2 updates contents[4][3]).
        // ============================================================
        $display("\n=== T5: Dirty L1 eviction propagates to L2 ===");
        apply_reset();
        do_miss(VA_S0, PA_S0T0);           // L1[0][0]=BLOCK_A, L2[4][3]=BLOCK_A, lru[0]=0
        send_req(VA_S0, PA_S0T0, 1'b1, DIRTY_DATA);  // store hit -> dirty[0][0]=1, lru[0]=1
        @(negedge clk);                    // settle
        do_miss(VA_S0, PA_S0T1);           // install way1; L2[8][3]=BLOCK_B; lru stays 1
        send_req(VA_S0, PA_S0T1, 1'b0, '0); // hit way1 -> lru[0]=0
        @(negedge clk);                    // settle
        do_miss(VA_S0, PA_S0T2);           // evicts dirty way0 (PA_S0T0) -> L2 updates set4.way3
                                            // (do_miss waits PIPE_FULL=26 cycles, which includes
                                            //  the P+26 posedge where L2 applies the dirty update)
        chk_bit("T5 L1 dirty[0][0] cleared after eviction",  dut.dirty[0][0],       1'b0);
        chk_bit("T5 e_dirty_in was 1 (still latched)",        dut.e_dirty_in,        1'b1);
        chk_64 ("T5 L2.contents[4][3][63:0] = DIRTY_DATA",
                dut.l2.contents[4][3][63:0], DIRTY_DATA);

        // ============================================================
        // T6: Reset clears L1+L2 state; mainmem data persists (new miss works)
        // ============================================================
        $display("\n=== T6: Reset clears caches; mainmem intact ===");
        apply_reset();
        @(negedge clk);
        chk_bit("T6 L1.valid[0][0] clear after reset",  dut.valid[0][0],        1'b0);
        chk_bit("T6 L1.valid[0][1] clear after reset",  dut.valid[0][1],        1'b0);
        chk_bit("T6 L2.valid[4][3] clear after reset",  dut.l2.valid[4][3],     1'b0);
        chk_bit("T6 L2.valid[8][3] clear after reset",  dut.l2.valid[8][3],     1'b0);
        // New miss should still resolve from mainmem
        do_miss(VA_S0, PA_S0T0);
        chk_bit ("T6 L1 refilled after reset+miss",          dut.valid[0][0],        1'b1);
        chk_wide("T6 L1 contents correct from mainmem",      dut.contents[0][0],     BLOCK_A);
        chk_bit ("T6 L2 refilled after reset+miss",          dut.l2.valid[4][3],     1'b1);
        chk_wide("T6 L2 contents correct from mainmem",      dut.l2.contents[4][3],  BLOCK_A);

        $display("\n==========================================");
        $display("  PASSED: %0d    FAILED: %0d", pass_cnt, fail_cnt);
        if (fail_cnt == 0) $display("  ALL TESTS PASSED");
        else               $display("  *** FAILURES DETECTED ***");
        $display("==========================================\n");
        $finish;
    end

    initial begin
        #1_000_000;
        $display("[TB] TIMEOUT");
        $finish;
    end

endmodule
