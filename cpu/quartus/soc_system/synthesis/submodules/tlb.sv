`timescale 1ns/1ps

// Simulation-first data TLB used by the memory subsystem.
//
// Interface contract:
// - `start && is_tlb_fill` inserts/updates the translation for `vaddr`.
// - `start && !is_tlb_fill` performs a lookup.
// - Lookup hits return in 1 cycle (`valid` pulses on the next posedge).
// - Lookup misses can optionally trigger a simulated DRAM-backed page walk.
//   The page walk uses the Ozone convention: TTBR0 + (VPN << 3), reading one
//   64-bit page-table entry from the shared-memory DRAM model.
module tlb #(
    parameter int VA_WIDTH = 48,
    parameter int PA_WIDTH = 30,
    parameter int NUM_ENTRIES = 16,
    parameter int PAGE_OFFSET_BITS = 12,
    parameter int LINE_OFFSET_BITS = 6,
    parameter bit ENABLE_PAGE_WALK = 1'b0,
    parameter bit PAGE_WALK_STRICT = 1'b1
) (
    input  logic                clk,
    input  logic                rst_n,
    input  logic                is_tlb_fill,
    input  logic [VA_WIDTH-1:0] vaddr,
    input  logic [PA_WIDTH-1:0] paddr,
    input  logic [PA_WIDTH-1:0] page_walk_base_i,
    input  logic                start,
    output logic                ptw_req_valid,
    output logic [PA_WIDTH-1:0] ptw_req_addr,
    input  logic                ptw_req_ready,
    input  logic                ptw_resp_valid,
    input  logic [63:0]         ptw_resp_data,
    output logic                ready,
    output logic                valid,
    output logic [PA_WIDTH-1:0] result_paddr
);

    localparam int VPN_BITS = VA_WIDTH - PAGE_OFFSET_BITS;
    localparam int PAGE_PPN_BITS = PA_WIDTH - PAGE_OFFSET_BITS;
    localparam int WAY_BITS = $clog2(NUM_ENTRIES);

    // Matches the visibility expected by the existing testbenches:
    //   ways[i] = {valid, PPN, VPN}
    logic [VPN_BITS + PAGE_PPN_BITS:0] ways   [0:NUM_ENTRIES-1];
    logic [NUM_ENTRIES-1:0]       lrumat [0:NUM_ENTRIES-1];

    logic                    walk_active;
    logic                    walk_issued;
    logic [VPN_BITS-1:0]     walk_vpn;
    logic [PAGE_OFFSET_BITS-LINE_OFFSET_BITS-1:0] walk_page_line_off;
    logic [LINE_OFFSET_BITS-1:0] walk_offset;
    logic [PA_WIDTH-1:0]     walk_addr;

    logic                    hit_now;
    logic [WAY_BITS-1:0]     hit_way_now;

    function automatic [WAY_BITS-1:0] pick_fill_way;
        integer i;
        begin
            pick_fill_way = '0;

            // Prefer the first invalid entry before consulting LRU state.
            for (i = 0; i < NUM_ENTRIES; i++) begin
                if (!ways[i][VPN_BITS + PAGE_PPN_BITS]) begin
                    pick_fill_way = WAY_BITS'(i);
                    return pick_fill_way;
                end
            end

            // Matrix LRU victim = row with all zeros.
            for (i = 0; i < NUM_ENTRIES; i++) begin
                if (lrumat[i] == '0) begin
                    pick_fill_way = WAY_BITS'(i);
                    return pick_fill_way;
                end
            end
        end
    endfunction

    task automatic touch_way(input logic [WAY_BITS-1:0] way);
        integer r;
        begin
            for (r = 0; r < NUM_ENTRIES; r++) begin
                if (r == way) begin
                    lrumat[r] <= ({NUM_ENTRIES{1'b1}} & ~(NUM_ENTRIES'(1'b1) << way));
                end else begin
                    lrumat[r][way] <= 1'b0;
                end
            end
        end
    endtask

    task automatic install_translation(
        input logic [VPN_BITS-1:0] vpn_i,
        input logic [PAGE_PPN_BITS-1:0] ppn_i
    );
        logic [WAY_BITS-1:0] target_way;
        begin
            if (hit_now) begin
                target_way = hit_way_now;
            end else begin
                target_way = pick_fill_way();
            end

            ways[target_way] <= {1'b1, ppn_i, vpn_i};
            touch_way(target_way);
        end
    endtask

    always_comb begin
        logic [VPN_BITS-1:0] curr_vpn;

        curr_vpn = vaddr[VA_WIDTH-1:PAGE_OFFSET_BITS];
        hit_now = 1'b0;
        hit_way_now = '0;
        for (int i = 0; i < NUM_ENTRIES; i++) begin
            if (!hit_now
                && ways[i][VPN_BITS + PAGE_PPN_BITS]
                && ways[i][VPN_BITS-1:0] == curr_vpn) begin
                hit_now = 1'b1;
                hit_way_now = WAY_BITS'(i);
            end
        end

    end

    assign ptw_req_valid = ENABLE_PAGE_WALK && walk_active && !walk_issued;
    assign ptw_req_addr  = walk_addr;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ready          <= 1'b1;
            valid          <= 1'b0;
            result_paddr   <= '0;
            walk_active    <= 1'b0;
            walk_issued    <= 1'b0;
            walk_vpn       <= '0;
            walk_page_line_off <= '0;
            walk_offset    <= '0;
            walk_addr      <= '0;
            for (int i = 0; i < NUM_ENTRIES; i++) begin
                ways[i]   <= '0;
                lrumat[i] <= '0;
            end
        end else begin
            if (ENABLE_PAGE_WALK && walk_active)
                ready <= 1'b0;
            else if (!start)
                ready <= 1'b1;

            valid        <= 1'b0;
            result_paddr <= '0;

            if (walk_active) begin
                // sim_main samples ptw_req_valid after the posedge and returns
                // ptw_resp_valid on the next posedge. Accept that response even
                // if this same edge is also the one marking the request issued.
                if (ptw_resp_valid) begin
                    $display("[TLB] ptw resp addr=0x%08h data=0x%016h valid_bit=%0b",
                             walk_addr, ptw_resp_data, ptw_resp_data[0]);
                    walk_active <= 1'b0;
                    walk_issued <= 1'b0;
                    if (ptw_resp_data[0]) begin
                        logic [PAGE_PPN_BITS-1:0] walk_ppn;
                        walk_ppn = ptw_resp_data[29:12];
                        install_translation(walk_vpn, walk_ppn);
                        result_paddr <= {walk_ppn, walk_page_line_off, walk_offset};
                        valid        <= 1'b1;
                    end else begin
                        if (PAGE_WALK_STRICT) begin
                            $error("tlb page walk miss: walk_addr=0x%0h vpn=0x%0h", walk_addr, walk_vpn);
                        end
                        result_paddr <= '0;
                        valid        <= 1'b1;
                    end
                end else if (!walk_issued && ptw_req_ready) begin
                    $display("[TLB] ptw issue addr=0x%08h vpn=0x%09h", walk_addr, walk_vpn);
                    walk_issued <= 1'b1;
                end
            end

            if (start && !walk_active) begin
                ready <= 1'b0;
                if (is_tlb_fill) begin
                    logic [VPN_BITS-1:0] fill_vpn;
                    logic [PAGE_PPN_BITS-1:0] fill_ppn;
                    fill_vpn = vaddr[VA_WIDTH-1:PAGE_OFFSET_BITS];
                    fill_ppn = paddr[PA_WIDTH-1:PAGE_OFFSET_BITS];
                    $display("[TLB] fill vpn=0x%09h ppn=0x%06h paddr=0x%08h",
                             fill_vpn, fill_ppn, paddr);
                    install_translation(fill_vpn, fill_ppn);
                end else if (hit_now) begin
                    logic [PAGE_PPN_BITS-1:0] hit_ppn;
                    hit_ppn      = ways[hit_way_now][VPN_BITS + PAGE_PPN_BITS-1:VPN_BITS];
                    result_paddr <= {hit_ppn, vaddr[PAGE_OFFSET_BITS-1:0]};
                    valid        <= 1'b1;
                    $display("[TLB] hit vaddr=0x%012h way=%0d paddr=0x%08h",
                             vaddr, hit_way_now, {hit_ppn, vaddr[PAGE_OFFSET_BITS-1:0]});
                    touch_way(hit_way_now);
                end else if (ENABLE_PAGE_WALK) begin
                    walk_active <= 1'b1;
                    walk_issued <= 1'b0;
                    walk_vpn    <= vaddr[VA_WIDTH-1:PAGE_OFFSET_BITS];
                    walk_page_line_off <= vaddr[PAGE_OFFSET_BITS-1:LINE_OFFSET_BITS];
                    walk_offset <= vaddr[LINE_OFFSET_BITS-1:0];
                    walk_addr   <= page_walk_base_i
                                   + ({PA_WIDTH{1'b0}} | (vaddr[VA_WIDTH-1:PAGE_OFFSET_BITS] << 3));
                    $display("[TLB] miss start walk vaddr=0x%012h base=0x%08h walk_addr=0x%08h",
                             vaddr,
                             page_walk_base_i,
                             page_walk_base_i
                             + ({PA_WIDTH{1'b0}} | (vaddr[VA_WIDTH-1:PAGE_OFFSET_BITS] << 3)));
                end else begin
                    result_paddr <= '0;
                    valid        <= 1'b1;
                end
            end
        end
    end

endmodule
