`timescale 1ns/1ps

// ============================================================================
// Testbench for l1_cache using the hardware TLB from main branch.
//
// Protocol (matches l1.sv state machine):
//   Cycle N  : assert start_in=1 with trace_vaddr_in  AND
//              assert tlb lookup (start=1, is_tlb_fill=0) with same vaddr
//   Cycle N+1: TLB result is ready; assert start_tag_in=1 with tlb_result_paddr
//
// TLB fills (OP_TLB_FILL records) are replayed into the hardware TLB one
// cycle before proceeding.
//
// Run with:
//   +TRACE_FILE=<path>   override trace (default: aca-mem-traces/traces/dgemm3.bin)
//   +WAVES               dump l1_tb.vcd for GTKWave
// ============================================================================

module l1_tb;

    // ----------------------------------------------------------------
    // Parameters — must match l1_cache defaults
    // ----------------------------------------------------------------
    localparam VA_WIDTH    = 48;
    localparam PA_WIDTH    = 30;
    localparam DATA_WIDTH  = 64;
    localparam BLOCK_SIZE  = 64;
    localparam L1_CAPACITY = 512;
    localparam L1_WAYS     = 2;
    localparam L1_MSHRS    = 2;

    // ----------------------------------------------------------------
    // Clock / reset
    // ----------------------------------------------------------------
    reg clk   = 0;
    reg rst_n = 0;
    always #5 clk = ~clk;  // 100 MHz

    // ----------------------------------------------------------------
    // Hardware TLB signals
    // ----------------------------------------------------------------
    reg                 tlb_start_r    = 0;
    reg                 tlb_is_fill_r  = 0;
    reg  [VA_WIDTH-1:0] tlb_vaddr_r    = 0;
    reg  [PA_WIDTH-1:0] tlb_paddr_r    = 0;
    wire                tlb_ready_w;
    wire                tlb_valid_w;
    wire [PA_WIDTH-1:0] tlb_result_w;
    wire                tlb_panic_w;

    tlb u_tlb (
        .clk            (clk),
        .rst_n          (rst_n),
        .start          (tlb_start_r),
        .is_tlb_fill    (tlb_is_fill_r),
        .vaddr          (tlb_vaddr_r),
        .paddr          (tlb_paddr_r),
        .ready          (tlb_ready_w),
        .valid          (tlb_valid_w),
        .result_paddr   (tlb_result_w),
        .panic_tlb_miss (tlb_panic_w)
    );

    // ----------------------------------------------------------------
    // L1 DUT interface
    // ----------------------------------------------------------------
    reg                    start_tag_in   = 0;
    reg  [PA_WIDTH-1:0]    tlb_paddr_in   = 0;
    reg                    start_in       = 0;
    reg  [VA_WIDTH-1:0]    trace_vaddr_in = 0;
    reg                    w_in           = 0;
    reg  [DATA_WIDTH-1:0]  wdata_in       = 0;
    wire                   stall_out;

    l1_cache #(
        .L1_CAPACITY (L1_CAPACITY),
        .L1_WAYS     (L1_WAYS),
        .BLOCK_SIZE  (BLOCK_SIZE),
        .L1_MSHRS    (L1_MSHRS),
        .VA_WIDTH    (VA_WIDTH),
        .PA_WIDTH    (PA_WIDTH)
    ) dut (
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

    // ----------------------------------------------------------------
    // Trace parsing (little-endian 16-byte records)
    // ----------------------------------------------------------------
    localparam OP_MEM_LOAD    = 3'd0;
    localparam OP_MEM_STORE   = 3'd1;
    localparam OP_MEM_RESOLVE = 3'd2;
    localparam OP_TLB_FILL    = 3'd4;

    reg [7:0]   buf_b [0:15];
    reg [127:0] tline;

    reg [2:0]  trc_op;
    reg [47:0] trc_vaddr;
    reg        trc_vaddr_valid;
    reg [29:0] trc_paddr;
    reg [63:0] trc_value;
    reg        trc_value_valid;

    task assemble_tline;
        integer k;
        begin
            for (k = 0; k < 16; k = k + 1)
                tline[k*8 +: 8] = buf_b[k];
            trc_op          = tline[54:52];
            trc_vaddr       = tline[47:0];
            trc_vaddr_valid = tline[55];
            trc_paddr       = tline[85:56];
            trc_value       = tline[119:56];
            trc_value_valid = tline[120];
        end
    endtask

    // ----------------------------------------------------------------
    // Stats
    // ----------------------------------------------------------------
    integer n_loads, n_stores, n_tlb_fills, n_stall_cycles, n_total;
    integer n_tlb_panics;

    // ----------------------------------------------------------------
    // Main stimulus
    // ----------------------------------------------------------------
    integer fd, fret;
    string  filename;

    initial begin
        n_loads = 0; n_stores = 0; n_tlb_fills = 0;
        n_stall_cycles = 0; n_total = 0; n_tlb_panics = 0;

        // Reset sequence
        repeat (4) @(posedge clk);
        rst_n = 1;
        @(posedge clk);

        // Open trace
        if (!$value$plusargs("TRACE_FILE=%s", filename))
            filename = "aca-mem-traces/traces/dgemm3.bin";
        fd = $fopen(filename, "rb");
        if (!fd) begin
            $display("[TB] ERROR: cannot open '%s'", filename);
            $finish;
        end
        $display("[TB] Replaying: %s", filename);

        fret = $fread(buf_b, fd);
        while (fret == 16) begin
            assemble_tline;

            case (trc_op)

                OP_TLB_FILL: begin
                    // Fill hardware TLB for one cycle
                    tlb_vaddr_r   = trc_vaddr;
                    tlb_paddr_r   = trc_paddr;
                    tlb_is_fill_r = 1;
                    tlb_start_r   = 1;
                    @(posedge clk);
                    tlb_start_r   = 0;
                    tlb_is_fill_r = 0;
                    n_tlb_fills = n_tlb_fills + 1;
                end

                OP_MEM_LOAD, OP_MEM_STORE: begin
                    // --- Wait out any MSHR stall ---
                    while (stall_out) begin
                        @(posedge clk);
                        n_stall_cycles = n_stall_cycles + 1;
                    end

                    // --- Cycle 1: send vaddr to L1, initiate TLB lookup ---
                    start_in       = 1;
                    trace_vaddr_in = trc_vaddr;
                    w_in           = (trc_op == OP_MEM_STORE);
                    wdata_in       = trc_value_valid ? trc_value : 0;
                    tlb_vaddr_r    = trc_vaddr;
                    tlb_paddr_r    = 0;
                    tlb_is_fill_r  = 0;
                    tlb_start_r    = 1;
                    @(posedge clk);  // L1 captures index, TLB does lookup
                    start_in    = 0;
                    tlb_start_r = 0;

                    // --- Cycle 2: TLB result ready, present to L1 ---
                    if (tlb_panic_w) begin
                        $display("[TB] TLB panic miss at vaddr=%h", trc_vaddr);
                        n_tlb_panics = n_tlb_panics + 1;
                    end
                    start_tag_in = 1;
                    tlb_paddr_in = tlb_result_w;
                    @(posedge clk);  // L1 does tag check
                    start_tag_in = 0;
                    tlb_paddr_in = 0;

                    if (trc_op == OP_MEM_LOAD) n_loads  = n_loads  + 1;
                    else                       n_stores = n_stores + 1;
                    n_total = n_total + 1;

                    if (n_total % 1000 == 0)
                        $display("[TB] %0d mem ops issued...", n_total);
                end

                default: ;
            endcase

            fret = $fread(buf_b, fd);
        end

        // Drain: allow in-flight MSHRs to resolve
        repeat (200) @(posedge clk);

        $fclose(fd);
        $display("=== Trace complete ===");
        $display("  Total mem ops  : %0d", n_total);
        $display("    Loads        : %0d", n_loads);
        $display("    Stores       : %0d", n_stores);
        $display("  TLB fills      : %0d", n_tlb_fills);
        $display("  TLB panics     : %0d  (miss with no entry)", n_tlb_panics);
        $display("  Stall cycles   : %0d  (MSHR full)", n_stall_cycles);
        $finish;
    end

    // Timeout watchdog (10 M cycles = 100 ms sim time)
    initial begin
        #100_000_000;
        $display("[TB] TIMEOUT — possible deadlock (MSHRs stuck?)");
        $finish;
    end

    // Optional waveform dump (+WAVES)
    initial begin
        if ($test$plusargs("WAVES")) begin
            $dumpfile("l1_tb.vcd");
            $dumpvars(0, l1_tb);
        end
    end

endmodule
