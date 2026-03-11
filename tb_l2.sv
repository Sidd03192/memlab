`timescale 1ns/1ps

// Directed testbench for l2_cache.
//
// NOTE: Procedural writes to unpacked-array module inputs from an initial
// block do not trigger the DUT's always_comb re-evaluation in Verilator.
// Fix: drive packed intermediates procedurally, bridge to unpacked arrays
// via always_comb to create proper dependency edges in the scheduler.
//
// Pipeline latency (posedges from send_miss return to l2 install):
//   P   : l2 accepts miss_in: empty_out[i]<=0, mm_miss_in[j]<=1
//   P+1 : mainmem accepts: countdown=20, active=1
//   P+2 : first countdown step: 20->19
//   P+21: countdown 1->0
//   P+22: mainmem resolve fires: mm.resolve_out[j]<=1
//   P+23: l2 installs: valid, contents, resolve_out[i]<=1 (cleared at P+24)
// => PIPE_CYCLES=23 posedges after send_miss; check at negedge after P+23.
//
// L2 hit: resolves at posedge P itself — visible at the negedge send_miss
// returns (before the default loop clears it at P+1).
//
// mainmem blk = pa[6 +: 14]:
//   PA_S0T0=0x400 -> blk 16  (BLOCK_A)
//   PA_S0T1=0x800 -> blk 32  (BLOCK_B)
//   PA_S0T2=0xC00 -> blk 48  (BLOCK_C)
//   PA_S0T3=0x1000-> blk 64  (BLOCK_D)
//   PA_S0T4=0x1400-> blk 80  (BLOCK_E)
//   PA_S1T0=0x440 -> blk 17  (BLOCK_A)
//
// LRU note: lru_mat only advances on L2 hits/dirty-evictions, NOT on cold
// installs. All cold misses land on way3 (lru=3 with all-zero lru_mat).
// fill_and_hit() fills a way then hits it once to advance lru to the next.

module tb_l2;

    localparam int PA_WIDTH    = 30;
    localparam int BLOCK_SIZE  = 64;
    localparam int L1_MSHRS   = 2;
    localparam int L2_CAPACITY = 4096;
    localparam int L2_WAYS     = 4;
    localparam int L2_SETS     = L2_CAPACITY / (BLOCK_SIZE * L2_WAYS);  // 16
    localparam int INDEX_BITS  = $clog2(L2_SETS);    // 4
    localparam int OFFSET_BITS = $clog2(BLOCK_SIZE);  // 6
    localparam int TAG_BITS    = PA_WIDTH - INDEX_BITS - OFFSET_BITS;  // 20

    localparam int PIPE_CYCLES = 23;  // posedges after send_miss for cold resolve

    // Physical addresses: {tag[19:0], index[3:0], offset[5:0]}
    localparam [PA_WIDTH-1:0] PA_S0T0 = {20'h00001, 4'h0, 6'h00};  // 0x400
    localparam [PA_WIDTH-1:0] PA_S0T1 = {20'h00002, 4'h0, 6'h00};  // 0x800
    localparam [PA_WIDTH-1:0] PA_S0T2 = {20'h00003, 4'h0, 6'h00};  // 0xC00
    localparam [PA_WIDTH-1:0] PA_S0T3 = {20'h00004, 4'h0, 6'h00};  // 0x1000
    localparam [PA_WIDTH-1:0] PA_S0T4 = {20'h00005, 4'h0, 6'h00};  // 0x1400
    localparam [PA_WIDTH-1:0] PA_S1T0 = {20'h00001, 4'h1, 6'h00};  // 0x440

    localparam [BLOCK_SIZE*8-1:0] BLOCK_A = {8{64'hAAAA_AAAA_AAAA_AAAA}};
    localparam [BLOCK_SIZE*8-1:0] BLOCK_B = {8{64'hBBBB_BBBB_BBBB_BBBB}};
    localparam [BLOCK_SIZE*8-1:0] BLOCK_C = {8{64'hCCCC_CCCC_CCCC_CCCC}};
    localparam [BLOCK_SIZE*8-1:0] BLOCK_D = {8{64'hDDDD_DDDD_DDDD_DDDD}};
    localparam [BLOCK_SIZE*8-1:0] BLOCK_E = {8{64'hEEEE_EEEE_EEEE_EEEE}};

    // ----------------------------------------------------------------
    // DUT signals
    // ----------------------------------------------------------------
    logic clk, rst_n;

    // Eviction port — driven directly (packed scalars, no issue)
    logic                    evict_in;
    logic [PA_WIDTH-1:0]     e_paddr_in;
    logic                    e_dirty_in;
    logic [BLOCK_SIZE*8-1:0] e_data_in;

    // L1-MSHR input ports are unpacked arrays. Verilator requires an RTL
    // dependency edge to propagate procedural writes correctly; we use
    // always_comb to bridge from packed driving signals to unpacked arrays.
    logic [L1_MSHRS-1:0]                    drv_miss;
    logic [L1_MSHRS-1:0][PA_WIDTH-1:0]      drv_paddr;
    logic [L1_MSHRS-1:0]                    drv_w;
    logic [L1_MSHRS-1:0][BLOCK_SIZE*8-1:0]  drv_data;

    logic                    miss_in  [L1_MSHRS];
    logic [PA_WIDTH-1:0]     paddr_in [L1_MSHRS];
    logic                    w_in     [L1_MSHRS];
    logic [BLOCK_SIZE*8-1:0] data_in  [L1_MSHRS];

    always_comb begin
        for (int i = 0; i < L1_MSHRS; i++) begin
            miss_in[i]  = drv_miss[i];
            paddr_in[i] = drv_paddr[i];
            w_in[i]     = drv_w[i];
            data_in[i]  = drv_data[i];
        end
    end

    wire                     empty_out        [L1_MSHRS];
    wire                     resolve_out      [L1_MSHRS];
    wire [BLOCK_SIZE*8-1:0]  superior_data_out[L1_MSHRS];

    integer pass_cnt, fail_cnt;

    l2_cache dut (
        .clk              (clk),
        .rst_n            (rst_n),
        .evict_in         (evict_in),
        .e_paddr_in       (e_paddr_in),
        .e_dirty_in       (e_dirty_in),
        .e_data_in        (e_data_in),
        .miss_in          (miss_in),
        .paddr_in         (paddr_in),
        .w_in             (w_in),
        .data_in          (data_in),
        .empty_out        (empty_out),
        .resolve_out      (resolve_out),
        .superior_data_out(superior_data_out)
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

    // ----------------------------------------------------------------
    // Port helpers
    // ----------------------------------------------------------------
    task automatic idle_inputs;
        evict_in   = 1'b0;
        e_paddr_in = '0;
        e_dirty_in = 1'b0;
        e_data_in  = '0;
        drv_miss   = '0;
        drv_paddr  = '0;
        drv_w      = '0;
        drv_data   = '0;
    endtask

    task automatic apply_reset;
        idle_inputs();
        rst_n = 1'b0;
        repeat (2) @(negedge clk);
        rst_n = 1'b1;
        @(negedge clk);
    endtask

    // Drive miss_in[mshr_idx] for one clock period (negedge to negedge).
    // Posedge P fires between the two negedges; l2 processes the miss there.
    // Returns at negedge after P:
    //   cold miss → empty_out[mshr_idx]=0, mm_miss_in[j]=1 both visible.
    //   L2 hit    → resolve_out[mshr_idx]=1 visible (cleared at P+1).
    task automatic send_miss;
        input [PA_WIDTH-1:0]     paddr;
        input integer            mshr_idx;
        input                    wr;
        input [BLOCK_SIZE*8-1:0] wdata;
        @(negedge clk);
        drv_miss[mshr_idx]  = 1'b1;
        drv_paddr[mshr_idx] = paddr;
        drv_w[mshr_idx]     = wr;
        drv_data[mshr_idx]  = wdata;
        @(negedge clk);   // posedge P fires between here and above
        drv_miss[mshr_idx] = 1'b0;
        drv_w[mshr_idx]    = 1'b0;
        drv_data[mshr_idx] = '0;
    endtask

    // Cold-miss helper: send then wait full pipeline + settle negedge.
    task automatic do_cold_miss;
        input [PA_WIDTH-1:0] paddr;
        input integer        mshr_idx;
        send_miss(paddr, mshr_idx, 1'b0, '0);
        repeat (PIPE_CYCLES) @(posedge clk);
        @(negedge clk);
    endtask

    // Fill way then immediately re-read (hit) to advance lru_mat.
    task automatic fill_and_hit;
        input [PA_WIDTH-1:0] paddr;
        do_cold_miss(paddr, 0);
        send_miss(paddr, 0, 1'b0, '0);   // L2 hit — resolve_out fires at posedge P
        @(negedge clk);                   // wait past resolve strobe
    endtask

    // ----------------------------------------------------------------
    // Main test body
    // ----------------------------------------------------------------
    initial begin
        pass_cnt = 0; fail_cnt = 0;
        idle_inputs();
        rst_n = 1'b1;

        // Pre-load mainmem (mem[] not cleared by rst_n).
        dut.mm.mem[16] = BLOCK_A;   // PA_S0T0
        dut.mm.mem[32] = BLOCK_B;   // PA_S0T1
        dut.mm.mem[48] = BLOCK_C;   // PA_S0T2
        dut.mm.mem[64] = BLOCK_D;   // PA_S0T3
        dut.mm.mem[80] = BLOCK_E;   // PA_S0T4
        dut.mm.mem[17] = BLOCK_A;   // PA_S1T0

        // ============================================================
        // T1: Reset — MSHRs idle, resolve strobes clear, no valid lines
        // ============================================================
        $display("\n=== T1: Reset and idle outputs ===");
        apply_reset();
        @(negedge clk);
        chk_bit("T1 empty_out[0] idle",    empty_out[0],    1'b1);
        chk_bit("T1 empty_out[1] idle",    empty_out[1],    1'b1);
        chk_bit("T1 resolve_out[0] clear", resolve_out[0],  1'b0);
        chk_bit("T1 resolve_out[1] clear", resolve_out[1],  1'b0);
        chk_bit("T1 valid[0][0] clear",    dut.valid[0][0], 1'b0);
        chk_bit("T1 n_evict_in clear",     dut.n_evict_in,  1'b0);

        // ============================================================
        // T2: Cold miss — l2 accepts, goes to mainmem, installs, resolves
        // ============================================================
        $display("\n=== T2: Cold miss fills L2 from mainmem ===");
        apply_reset();
        send_miss(PA_S0T0, 0, 1'b0, '0);
        // Posedge P just fired: l2 accepted, empty_out[0]=0, mm_miss_in[0]=1
        chk_bit("T2 empty_out[0] busy after accept", empty_out[0],        1'b0);
        chk_bit("T2 mm_miss_in[0] sent to mainmem",  dut.mm_miss_in[0],   1'b1);
        chk_bit("T2 resolve_out[0] not yet",         resolve_out[0],      1'b0);
        // Let pipeline complete
        repeat (PIPE_CYCLES) @(posedge clk);
        @(negedge clk);
        chk_bit ("T2 valid[0][3] set after install",   dut.valid[0][3],    1'b1);
        chk_wide("T2 contents[0][3] = BLOCK_A",        dut.contents[0][3], BLOCK_A);
        chk_pa  ("T2 tags[0][3] = PA_S0T0 tag",        dut.tags[0][3],
                 PA_S0T0[PA_WIDTH-1 -: TAG_BITS]);
        chk_bit ("T2 empty_out[0] free after resolve", empty_out[0],       1'b1);
        chk_bit ("T2 resolve_out[0] fired",            resolve_out[0],     1'b1);
        chk_wide("T2 superior_data_out[0] = BLOCK_A",  superior_data_out[0], BLOCK_A);

        // ============================================================
        // T3: L2 hit (load) — resolves in one cycle, no mainmem access
        // (continuing from T2: PA_S0T0 in set0/way3)
        // ============================================================
        $display("\n=== T3: L2 hit resolves in one cycle ===");
        @(negedge clk);  // wait past T2's resolve strobe
        send_miss(PA_S0T0, 0, 1'b0, '0);
        // resolve_out fires at posedge P and is visible now (before P+1 clears it)
        chk_bit ("T3 resolve_out[0] fires on hit",  resolve_out[0],       1'b1);
        chk_bit ("T3 empty_out[0] stays 1 on hit",  empty_out[0],         1'b1);
        chk_wide("T3 superior_data_out = BLOCK_A",  superior_data_out[0], BLOCK_A);
        chk_bit ("T3 mm_miss_in[0] not pulsed",     dut.mm_miss_in[0],    1'b0);

        // ============================================================
        // T4: L2 hit (write) — L2 contents updated, resolves in one cycle
        // ============================================================
        $display("\n=== T4: L2 write hit updates contents ===");
        @(negedge clk);  // wait past T3's resolve strobe
        send_miss(PA_S0T0, 0, 1'b1, BLOCK_B);
        chk_bit ("T4 resolve_out[0] fires on write hit", resolve_out[0],       1'b1);
        chk_wide("T4 superior_data_out = BLOCK_B (write)", superior_data_out[0], BLOCK_B);
        @(negedge clk);  // wait for contents to settle
        chk_wide("T4 contents[0][3] updated to BLOCK_B", dut.contents[0][3],  BLOCK_B);

        // ============================================================
        // T5: L1 dirty eviction received — L2 has block → contents updated
        //     (dirty bit NOT set — L2 code never marks its own dirty bit)
        // ============================================================
        $display("\n=== T5: L1 dirty eviction updates L2 contents ===");
        @(negedge clk);
        @(negedge clk);
        evict_in   = 1'b1;
        e_paddr_in = PA_S0T0;
        e_dirty_in = 1'b1;
        e_data_in  = BLOCK_C;
        @(negedge clk);   // posedge fires: e_hit=1, e_dirty_in=1 → update contents
        evict_in   = 1'b0;
        e_dirty_in = 1'b0;
        e_data_in  = '0;
        @(negedge clk);
        chk_wide("T5 L2 contents updated from L1 dirty eviction", dut.contents[0][3], BLOCK_C);
        chk_bit ("T5 dirty[0][3] = 0 (L2 never sets its dirty bit)", dut.dirty[0][3], 1'b0);

        // ============================================================
        // T6: L1 dirty eviction for block NOT in L2 — ignored
        // ============================================================
        $display("\n=== T6: Dirty eviction for absent block is ignored ===");
        evict_in   = 1'b1;
        e_paddr_in = PA_S0T1;   // not in L2
        e_dirty_in = 1'b1;
        e_data_in  = BLOCK_D;
        @(negedge clk);
        evict_in   = 1'b0;
        @(negedge clk);
        chk_bit ("T6 valid[0][0..2] still clear", dut.valid[0][0], 1'b0);
        chk_wide("T6 contents[0][3] unchanged",   dut.contents[0][3], BLOCK_C);

        // ============================================================
        // T7: Two L1 MSHRs miss simultaneously → both get resolved
        //     l2 handles one per cycle: MSHR 0 first, then MSHR 1
        // ============================================================
        $display("\n=== T7: Two outstanding L1 misses both resolve ===");
        apply_reset();
        send_miss(PA_S0T0, 0, 1'b0, '0);           // MSHR 0 → set 0
        chk_bit("T7 empty_out[0] busy",       empty_out[0], 1'b0);
        chk_bit("T7 empty_out[1] still free", empty_out[1], 1'b1);
        send_miss(PA_S1T0, 1, 1'b0, '0);           // MSHR 1 → set 1
        chk_bit("T7 empty_out[1] busy",       empty_out[1], 1'b0);
        // MSHR 1 fires ~2 cycles after MSHR 0; wait for both to resolve
        repeat (PIPE_CYCLES + 3) @(posedge clk);
        @(negedge clk);
        chk_bit ("T7 empty_out[0] free",         empty_out[0],       1'b1);
        chk_bit ("T7 empty_out[1] free",         empty_out[1],       1'b1);
        chk_bit ("T7 valid[0][3] set (PA_S0T0)", dut.valid[0][3],    1'b1);
        chk_wide("T7 contents[0][3] = BLOCK_A",  dut.contents[0][3], BLOCK_A);
        chk_bit ("T7 valid[1][3] set (PA_S1T0)", dut.valid[1][3],    1'b1);
        chk_wide("T7 contents[1][3] = BLOCK_A",  dut.contents[1][3], BLOCK_A);

        // ============================================================
        // T8: All 4 ways full → 5th miss evicts LRU way
        //     Strategy: fill_and_hit each way to advance lru_mat:
        //       fill way3, hit → lru=2
        //       fill way2, hit → lru=1
        //       fill way1, hit → lru=0
        //       fill way0 (all valid)
        //     5th miss → evicts way0 (holds PA_S0T3) → n_evict_in fires
        // ============================================================
        $display("\n=== T8: Fifth miss evicts LRU way from full set ===");
        apply_reset();
        fill_and_hit(PA_S0T0);   // → way3; hit advances lru to 2
        fill_and_hit(PA_S0T1);   // → way2; hit advances lru to 1
        fill_and_hit(PA_S0T2);   // → way1; hit advances lru to 0
        do_cold_miss(PA_S0T3, 0);// → way0; all 4 ways now valid
        chk_bit("T8 pre: all ways valid [0]", dut.valid[0][0], 1'b1);
        chk_bit("T8 pre: all ways valid [1]", dut.valid[0][1], 1'b1);
        chk_bit("T8 pre: all ways valid [2]", dut.valid[0][2], 1'b1);
        chk_bit("T8 pre: all ways valid [3]", dut.valid[0][3], 1'b1);
        // 5th miss: lru=0 → evict way0 (PA_S0T3), install PA_S0T4
        do_cold_miss(PA_S0T4, 0);
        // n_evict_in was a one-cycle pulse; n_e_paddr_in persists
        chk_pa  ("T8 n_e_paddr_in = PA_S0T3 (evicted)", dut.n_e_paddr_in, PA_S0T3);
        chk_bit ("T8 n_e_dirty_in = 0 (L2 never sets dirty)", dut.n_e_dirty_in, 1'b0);
        chk_wide("T8 PA_S0T4 installed in way0",  dut.contents[0][0], BLOCK_E);
        chk_wide("T8 way1 (PA_S0T2) intact",      dut.contents[0][1], BLOCK_C);
        chk_wide("T8 way2 (PA_S0T1) intact",      dut.contents[0][2], BLOCK_B);
        chk_wide("T8 way3 (PA_S0T0) intact",      dut.contents[0][3], BLOCK_A);

        // ============================================================
        // T9: Clean state after reset
        // ============================================================
        $display("\n=== T9: Clean idle after reset ===");
        apply_reset();
        @(negedge clk);
        chk_bit("T9 empty_out[0] idle",    empty_out[0],    1'b1);
        chk_bit("T9 empty_out[1] idle",    empty_out[1],    1'b1);
        chk_bit("T9 resolve_out[0] clear", resolve_out[0],  1'b0);
        chk_bit("T9 valid[0][0] clear",    dut.valid[0][0], 1'b0);
        chk_bit("T9 n_evict_in clear",     dut.n_evict_in,  1'b0);

        $display("\n==========================================");
        $display("  PASSED: %0d    FAILED: %0d", pass_cnt, fail_cnt);
        if (fail_cnt == 0) $display("  ALL TESTS PASSED");
        else               $display("  *** FAILURES DETECTED ***");
        $display("==========================================\n");
        $finish;
    end

    initial begin
        #5_000_000;
        $display("[TB] TIMEOUT");
        $finish;
    end

endmodule
