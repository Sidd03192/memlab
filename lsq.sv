`timescale 1ns/1ps

// =============================================================================
// LSQ — combined load/store queue
//
// Two separate entry arrays (LQ: 8 entries, SQ: 8 entries) with independent
// head/tail pointers, sharing a single module and interface.
//
// Integrated with a full OoO pipeline:
//   - ROB assigns tags at dispatch; LSQ stores ROB entry IDs per entry
//   - CDB is monitored to resolve address/data dependencies for pending entries
//   - Loads broadcast their result on the CDB when data returns from cache
//   - Stores broadcast readiness on the CDB so the ROB can mark them committable
//   - Stores only retire to memory when the ROB pulses commit_sq_head
//   - Full flush support: all state cleared on ROB flush signal
//
// Load lifecycle:
//   LQ_EMPTY -> LQ_WAITING_ADDR -> LQ_WAITING_ISSUE -> LQ_IN_FLIGHT -> LQ_EMPTY
//
// Store lifecycle:
//   SQ_EMPTY -> SQ_UNRESOLVED / SQ_WAITING_ADDR / SQ_WAITING_DATA
//            -> SQ_WAITING_ISSUE -> SQ_COMMITTED -> SQ_EMPTY
//
// Forwarding:
//   Store-to-load: if a load's EA matches a completed older store's EA, the
//                  store's wdata is forwarded directly; no cache access needed.
//   Load-to-load:  a load is blocked if any older store (recorded in
//                  lq_sq_tail_snap) has an unresolved EA that could alias.
//
// CDB interaction:
//   - LSQ watches every CDB broadcast each cycle for rob_tag matches against
//     pending lq_rob_wdata_id / sq_rob_wdata_id fields to capture EA or wdata.
//   - On load completion, LSQ drives cdb_out with the load result and holds it
//     until cdb_granted is asserted by the CDB arbiter.
//   - On store ready, LSQ broadcasts a zero-data CDB entry (rob_wb_en=1) so
//     the ROB marks the store as committable.
// =============================================================================

import ooo_pkg::*;   // pulls in cdb_broadcast_t, ROB_IDX_WIDTH, etc.

module lsq #(
    parameter LQ_ENTRIES  = 8,
    parameter SQ_ENTRIES  = 8,
    parameter VA_WIDTH    = 48,
    parameter DATA_WIDTH  = 64
)(
    input  logic clk,
    input  logic rst_n,

    // -------------------------------------------------------------------------
    // FROM ROB — dispatch
    // -------------------------------------------------------------------------
    input  logic [ROB_IDX_WIDTH-1:0]  rob_entry_id,        // ROB tag for this op
    input  logic [ROB_IDX_WIDTH-1:0]  rob_wdata_entry_id,  // STORES: ROB tag whose result is the store data
    input  logic [DATA_WIDTH-1:0]     rob_wdata,           // STORES: immediate store data (if ready)
    input  logic                      rob_wdata_ready,      // STORES: 1 = rob_wdata is valid now
    input  logic                      is_load,              // 1 = load, 0 = store
    input  logic                      valid_in,             // dispatch this cycle

    // FROM ROB — control
    input  logic                      flush,                // squash everything
    input  logic                      commit_sq_head,       // retire head store to memory

    // TO ROB
    output logic                      lq_full,
    output logic                      sq_full,

    // -------------------------------------------------------------------------
    // TO MEM_SYS — issue
    // -------------------------------------------------------------------------
    output logic [VA_WIDTH-1:0]       issue_vaddr,
    output logic [DATA_WIDTH-1:0]     issue_wdata,
    output logic                      issue_is_load,
    output logic [ROB_IDX_WIDTH-1:0]  issue_lq_id,         // load entry tag sent to cache
    output logic                      valid_out,            // issue strobe

    // FROM MEM_SYS — load data return
    // Cache returns data alongside the LQ entry ID it was given at issue time.
    input  logic [ROB_IDX_WIDTH-1:0]  mem_resp_lq_id,      // which LQ entry is returning
    input  logic [DATA_WIDTH-1:0]     mem_resp_data,        // returned load data
    input  logic                      mem_resp_valid,       // data is valid this cycle

    // Handshake for L1 and TLB accepting the issued request
    input  logic                      l1_ready,
    input  logic                      tlb_ready,

    // -------------------------------------------------------------------------
    // CDB — monitor (broadcast from other FUs)
    // -------------------------------------------------------------------------
    input  cdb_broadcast_t            cdb_in,

    // CDB — drive (load result or store readiness)
    output cdb_broadcast_t            cdb_out,
    input  logic                      cdb_granted          // arbiter accepted our broadcast
);

    // =========================================================================
    // Derived widths
    // =========================================================================
    localparam int LQ_PTR_WIDTH = $clog2(LQ_ENTRIES);
    localparam int SQ_PTR_WIDTH = $clog2(SQ_ENTRIES);

    // =========================================================================
    // LOAD QUEUE STATE
    // =========================================================================
    typedef enum logic [2:0] {
        LQ_EMPTY         = 3'd0,
        LQ_WAITING_ADDR  = 3'd1,  // dispatched; EA not yet known
        LQ_WAITING_ISSUE = 3'd2,  // EA known; waiting for clear path to L1
        LQ_IN_FLIGHT     = 3'd3   // issued to cache; awaiting data return
    } lq_state_t;

    lq_state_t                   lq_state      [LQ_ENTRIES];
    logic [VA_WIDTH-1:0]         lq_vaddr      [LQ_ENTRIES];
    logic [ROB_IDX_WIDTH-1:0]    lq_rob_id     [LQ_ENTRIES];  // ROB tag for this load
    logic [ROB_IDX_WIDTH-1:0]    lq_rob_waddr_id [LQ_ENTRIES]; // ROB tag whose result = EA
    logic [SQ_ENTRIES-1:0]       lq_before_vec [LQ_ENTRIES];  // SQ entries older than this load
    logic [SQ_PTR_WIDTH-1:0]     lq_sq_tail_snap [LQ_ENTRIES]; // SQ tail at dispatch (load-to-load)

    logic [LQ_PTR_WIDTH-1:0]     lq_head, lq_tail;

    assign lq_full = (lq_state[lq_tail] != LQ_EMPTY);

    // =========================================================================
    // STORE QUEUE STATE
    // =========================================================================
    typedef enum logic [2:0] {
        SQ_EMPTY         = 3'd0,
        SQ_UNRESOLVED    = 3'd1,  // EA and wdata both unknown
        SQ_WAITING_ADDR  = 3'd2,  // wdata known, EA unknown
        SQ_WAITING_DATA  = 3'd3,  // EA known, wdata unknown
        SQ_WAITING_ISSUE = 3'd4,  // EA and wdata resolved; waiting for ROB commit
        SQ_COMMITTED     = 3'd5   // ROB committed; write in progress / done
    } sq_state_t;

    sq_state_t                   sq_state      [SQ_ENTRIES];
    logic [VA_WIDTH-1:0]         sq_vaddr      [SQ_ENTRIES];
    logic [DATA_WIDTH-1:0]       sq_wdata      [SQ_ENTRIES];
    logic [ROB_IDX_WIDTH-1:0]    sq_rob_id     [SQ_ENTRIES];  // ROB tag for this store
    logic [ROB_IDX_WIDTH-1:0]    sq_rob_wdata_id [SQ_ENTRIES]; // ROB tag whose result = wdata

    // Track whether we have already broadcast store-ready on CDB for this entry
    logic                        sq_cdb_sent   [SQ_ENTRIES];

    logic [SQ_PTR_WIDTH-1:0]     sq_head, sq_tail;

    assign sq_full = (sq_state[sq_tail] != SQ_EMPTY);



    // =========================================================================
    // LOAD ISSUE ARBITRATION
    // Walk from lq_head in age order; pick oldest LQ_WAITING_ISSUE entry.
    // =========================================================================
    logic                        lq_found;
    logic [LQ_PTR_WIDTH-1:0]     lq_found_entry;

    always_comb begin
        lq_found       = 1'b0;
        lq_found_entry = '0;
        for (int i = 0; i < LQ_ENTRIES; i++) begin
            logic [LQ_PTR_WIDTH-1:0] idx;
            idx = lq_head + LQ_PTR_WIDTH'(i);
            if (!lq_found && lq_state[idx] == LQ_WAITING_ISSUE)
                begin lq_found = 1'b1; lq_found_entry = idx; end
        end
    end

    // =========================================================================
    // STORE-TO-LOAD FORWARDING CANDIDATE
    // For the found load, scan SQ for the youngest completed store whose EA
    // matches the load EA and is older than the load (in lq_before_vec).
    // =========================================================================
    logic                        fwd_hit;
    logic [DATA_WIDTH-1:0]       fwd_data;

    always_comb begin
        fwd_hit  = 1'b0;
        fwd_data = '0;
        if (lq_found) begin
            // Walk from sq_tail-1 downward to sq_head (youngest to oldest)
            // so that the most recent matching store wins.
            for (int i = SQ_ENTRIES-1; i >= 0; i--) begin
                logic [SQ_PTR_WIDTH-1:0] idx;
                idx = sq_head + SQ_PTR_WIDTH'(i);
                if (!fwd_hit
                    && lq_before_vec[lq_found_entry][idx]
                    && (sq_state[idx] == SQ_WAITING_ISSUE || sq_state[idx] == SQ_COMMITTED)
                    && sq_vaddr[idx] == lq_vaddr[lq_found_entry]) begin
                    fwd_hit  = 1'b1;
                    fwd_data = sq_wdata[idx];
                end
            end
        end
    end

    // =========================================================================
    // UNRESOLVED STORE CHECK (blocks load issue)
    // A load cannot issue if any older store's EA is unknown — it could alias.
    // Uses lq_sq_tail_snap so the scan is bounded to stores that existed when
    // the load was dispatched (load-to-load ordering preservation).
    // =========================================================================
    logic is_unresolved_store;

    always_comb begin
        is_unresolved_store = 1'b0;
        for (int i = 0; i < SQ_ENTRIES; i++) begin
            logic [SQ_PTR_WIDTH-1:0] idx;
            idx = sq_head + SQ_PTR_WIDTH'(i);
            if (lq_found && lq_before_vec[lq_found_entry][idx]) begin
                // Older store has an unknown EA — cannot prove no alias
                if (sq_state[idx] == SQ_UNRESOLVED || sq_state[idx] == SQ_WAITING_ADDR)
                    is_unresolved_store = 1'b1;
                // Older store has known EA matching load EA but data not yet available
                if (sq_state[idx] == SQ_WAITING_DATA
                    && sq_vaddr[idx] == lq_vaddr[lq_found_entry])
                    is_unresolved_store = 1'b1;
            end
        end
    end

    // =========================================================================
    // STORE ISSUE ARBITRATION
    // Only the head store may retire; it must be in SQ_COMMITTED state
    // (meaning the ROB has already pulsed commit_sq_head for it).
    // =========================================================================
    logic sq_found;
    logic sq_head_blocked;

    always_comb begin
        sq_found       = (sq_state[sq_head] == SQ_COMMITTED);
        sq_head_blocked = (sq_state[sq_head] != SQ_EMPTY && !sq_found);
    end

    // =========================================================================
    // UNRESOLVED LOAD CHECK (blocks store issue — memory ordering)
    // =========================================================================
    logic is_unresolved_load;

    always_comb begin
        is_unresolved_load = 1'b0;
        for (int i = 0; i < LQ_ENTRIES; i++) begin
            logic [LQ_PTR_WIDTH-1:0] idx;
            idx = lq_head + LQ_PTR_WIDTH'(i);
            if (sq_found && lq_state[idx] == LQ_WAITING_ADDR)
                is_unresolved_load = 1'b1;
        end
    end

    // =========================================================================
    // SEQUENTIAL LOGIC
    // =========================================================================
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            lq_head          <= '0;
            lq_tail          <= '0;
            sq_head          <= '0;
            sq_tail          <= '0;
            valid_out        <= 1'b0;
            cdb_out          <= '0;
            for (int i = 0; i < LQ_ENTRIES; i++) begin
                lq_state[i]      <= LQ_EMPTY;
                lq_before_vec[i] <= '0;
            end
            for (int i = 0; i < SQ_ENTRIES; i++) begin
                sq_state[i]    <= SQ_EMPTY;
                sq_cdb_sent[i] <= 1'b0;
            end

        end else begin

            // -----------------------------------------------------------------
            // DEFAULT DE-ASSERTIONS
            // -----------------------------------------------------------------
            valid_out <= 1'b0;

            // Clear CDB output once arbiter acknowledges
            if (cdb_granted)
                cdb_out <= '0;

            // -----------------------------------------------------------------
            // FLUSH — squash entire LSQ
            // -----------------------------------------------------------------
            if (flush) begin
                lq_head           <= '0;
                lq_tail           <= '0;
                sq_head           <= '0;
                sq_tail           <= '0;
                cdb_out           <= '0;
                for (int i = 0; i < LQ_ENTRIES; i++) begin
                    lq_state[i]      <= LQ_EMPTY;
                    lq_before_vec[i] <= '0;
                end
                for (int i = 0; i < SQ_ENTRIES; i++) begin
                    sq_state[i]    <= SQ_EMPTY;
                    sq_cdb_sent[i] <= 1'b0;
                end

            end else begin

                // -------------------------------------------------------------
                // CDB MONITOR — resolve pending EA / wdata from other FUs
                // Any cycle a valid CDB broadcast appears, scan LQ and SQ for
                // entries waiting on that ROB tag.
                // -------------------------------------------------------------
                if (cdb_in.valid) begin

                    // --- Load queue: EA resolution ---
                    for (int i = 0; i < LQ_ENTRIES; i++) begin
                        if (lq_state[i] == LQ_WAITING_ADDR
                            && lq_rob_waddr_id[i] == cdb_in.rob_tag) begin
                            lq_vaddr[i] <= cdb_in.value[VA_WIDTH-1:0];
                            lq_state[i] <= LQ_WAITING_ISSUE;
                        end
                    end

                    // --- Store queue: EA and/or wdata resolution ---
                    for (int i = 0; i < SQ_ENTRIES; i++) begin
                        if (sq_state[i] != SQ_EMPTY && sq_state[i] != SQ_WAITING_ISSUE
                            && sq_state[i] != SQ_COMMITTED) begin

                            // EA arrives
                            if (sq_rob_id[i] == cdb_in.rob_tag) begin
                                sq_vaddr[i] <= cdb_in.value[VA_WIDTH-1:0];
                                case (sq_state[i])
                                    SQ_UNRESOLVED:   sq_state[i] <= SQ_WAITING_DATA;
                                    SQ_WAITING_ADDR: sq_state[i] <= SQ_WAITING_ISSUE;
                                    default: ;
                                endcase
                            end

                            // wdata arrives
                            if (sq_rob_wdata_id[i] == cdb_in.rob_tag) begin
                                sq_wdata[i] <= cdb_in.value;
                                case (sq_state[i])
                                    SQ_UNRESOLVED:   sq_state[i] <= SQ_WAITING_ADDR;
                                    SQ_WAITING_DATA: sq_state[i] <= SQ_WAITING_ISSUE;
                                    default: ;
                                endcase
                            end
                        end
                    end
                end

                // -------------------------------------------------------------
                // DISPATCH — new entry from ROB
                // -------------------------------------------------------------
                if (valid_in) begin
                    if (is_load && !lq_full) begin
                        lq_rob_id[lq_tail]      <= rob_entry_id;
                        lq_rob_waddr_id[lq_tail] <= rob_entry_id; // EA tag same as op tag at dispatch
                        lq_vaddr[lq_tail]        <= '0;
                        lq_state[lq_tail]        <= LQ_WAITING_ADDR;
                        lq_sq_tail_snap[lq_tail] <= sq_tail;
                        // Mark which SQ entries are older than this load
                        for (int i = 0; i < SQ_ENTRIES; i++) begin
                            lq_before_vec[lq_tail][i] <= (sq_state[i] != SQ_EMPTY);
                        end
                        lq_tail <= lq_tail + 1'b1;

                    end else if (!is_load && !sq_full) begin
                        sq_rob_id[sq_tail]       <= rob_entry_id;
                        sq_rob_wdata_id[sq_tail] <= rob_wdata_entry_id;
                        sq_cdb_sent[sq_tail]     <= 1'b0;
                        sq_vaddr[sq_tail]        <= '0;

                        if (rob_wdata_ready) begin
                            sq_wdata[sq_tail] <= rob_wdata;
                            sq_state[sq_tail] <= SQ_WAITING_ADDR; // EA still unknown at dispatch
                        end else begin
                            sq_wdata[sq_tail] <= '0;
                            sq_state[sq_tail] <= SQ_UNRESOLVED;
                        end
                        sq_tail <= sq_tail + 1'b1;
                    end
                end

                // -------------------------------------------------------------
                // ROB COMMIT — move head store to SQ_COMMITTED
                // -------------------------------------------------------------
                if (commit_sq_head && sq_state[sq_head] == SQ_WAITING_ISSUE) begin
                    sq_state[sq_head] <= SQ_COMMITTED;
                end

                // -------------------------------------------------------------
                // STORE READY BROADCAST — CDB notification to ROB
                // As soon as a store reaches SQ_WAITING_ISSUE, broadcast once
                // so the ROB knows it is safe to commit when it reaches head.
                // -------------------------------------------------------------
                for (int i = 0; i < SQ_ENTRIES; i++) begin
                    if (sq_state[i] == SQ_WAITING_ISSUE && !sq_cdb_sent[i]
                        && !cdb_out.valid) begin
                        cdb_out.valid       <= 1'b1;
                        cdb_out.rob_tag     <= sq_rob_id[i];
                        cdb_out.rob_wb_en   <= 1'b1;
                        cdb_out.value       <= '0;
                        cdb_out.update_nzcv <= 1'b0;
                        cdb_out.nzcv        <= '0;
                        cdb_out.br_valid    <= 1'b0;
                        cdb_out.br_taken    <= 1'b0;
                        cdb_out.br_target   <= '0;
                        cdb_out.exc         <= 1'b0;
                        cdb_out.exc_code    <= '0;
                        sq_cdb_sent[i]      <= 1'b1;
                        break;
                    end
                end

                // -------------------------------------------------------------
                // LOAD ISSUE
                // Gated on !cdb_out.valid — if the CDB slot is occupied we
                // stall for the cycle, preventing any overwrite of an in-flight
                // broadcast. cdb_out.valid is the sole occupancy flag.
                //
                //   fwd_hit  → retire entry immediately via forwarding
                //   !fwd_hit → send to cache; entry moves to LQ_IN_FLIGHT
                // -------------------------------------------------------------
                if (lq_found && !is_unresolved_store && l1_ready && tlb_ready
                    && !cdb_out.valid) begin

                    if (fwd_hit) begin
                        lq_state[lq_found_entry] <= LQ_EMPTY;

                        cdb_out.valid        <= 1'b1;
                        cdb_out.rob_tag      <= lq_rob_id[lq_found_entry];
                        cdb_out.cdb_value_en <= 1'b1;
                        cdb_out.rob_wb_en    <= 1'b1;
                        cdb_out.value        <= fwd_data;
                        cdb_out.update_nzcv <= 1'b0;
                        cdb_out.nzcv        <= '0;
                        cdb_out.br_valid    <= 1'b0;
                        cdb_out.br_taken    <= 1'b0;
                        cdb_out.br_target   <= '0;
                        cdb_out.exc         <= 1'b0;
                        cdb_out.exc_code    <= '0;

                        if (lq_found_entry == lq_head)
                            lq_head <= lq_head + 1'b1;

                    end else begin
                        issue_vaddr   <= lq_vaddr[lq_found_entry];
                        issue_wdata   <= '0;
                        issue_is_load <= 1'b1;
                        issue_lq_id   <= lq_rob_id[lq_found_entry];
                        valid_out     <= 1'b1;
                        lq_state[lq_found_entry] <= LQ_IN_FLIGHT;
                    end
                end

                // -------------------------------------------------------------
                // STORE ISSUE (retire committed head store to memory)
                // -------------------------------------------------------------
                if (sq_found && !is_unresolved_load && l1_ready && tlb_ready) begin
                    issue_vaddr   <= sq_vaddr[sq_head];
                    issue_wdata   <= sq_wdata[sq_head];
                    issue_is_load <= 1'b0;
                    issue_lq_id  <= '0;
                    valid_out     <= 1'b1;
                    sq_state[sq_head] <= SQ_EMPTY;
                    sq_head           <= sq_head + 1'b1;
                end

                // -------------------------------------------------------------
                // CACHE RETURN — load data arrives
                // Gated on !cdb_out.valid for the same reason as load issue.
                // The cache must hold mem_resp_valid high until accepted.
                // -------------------------------------------------------------
                if (mem_resp_valid && !cdb_out.valid) begin
                    for (int i = 0; i < LQ_ENTRIES; i++) begin
                        if (lq_state[i] == LQ_IN_FLIGHT
                            && lq_rob_id[i] == mem_resp_lq_id) begin

                            lq_state[i] <= LQ_EMPTY;

                            cdb_out.valid        <= 1'b1;
                            cdb_out.rob_tag      <= lq_rob_id[i];
                            cdb_out.cdb_value_en <= 1'b1;
                            cdb_out.rob_wb_en    <= 1'b1;
                            cdb_out.value        <= mem_resp_data;
                            cdb_out.update_nzcv <= 1'b0;
                            cdb_out.nzcv        <= '0;
                            cdb_out.br_valid    <= 1'b0;
                            cdb_out.br_taken    <= 1'b0;
                            cdb_out.br_target   <= '0;
                            cdb_out.exc         <= 1'b0;
                            cdb_out.exc_code    <= '0;

                            if (i[LQ_PTR_WIDTH-1:0] == lq_head)
                                lq_head <= lq_head + 1'b1;
                        end
                    end
                end

                // -------------------------------------------------------------
                // HEAD POINTER ADVANCE — skip over already-emptied slots
                // -------------------------------------------------------------
                if (lq_state[lq_head] == LQ_EMPTY && lq_head != lq_tail)
                    lq_head <= lq_head + 1'b1;

                if (sq_state[sq_head] == SQ_EMPTY && sq_head != sq_tail)
                    sq_head <= sq_head + 1'b1;



            end // !flush
        end // rst
    end

endmodule