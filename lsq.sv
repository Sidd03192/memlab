`timescale 1ns/1ps

module lsq #(
    parameter NUM_ENTRIES = 16,         // Number of LSQ entries (spec says 16)
    parameter VA_WIDTH    = 48,         // Virtual address width
    parameter DATA_WIDTH  = 64,         // Data width (64-bit doubleword)
    parameter ID_WIDTH    = 4           // Operation ID width (4 bits = 16 possible IDs)
)(
    input  logic                    clk,
    input  logic                    rst_n,


    input  logic                    trace_valid,        // New operation available
    input  logic [2:0]              trace_op,           // Operation type (LOAD/STORE/RESOLVE)
    input  logic [ID_WIDTH-1:0]     trace_id,           // Operation ID for matching
    input  logic [VA_WIDTH-1:0]     trace_vaddr,        // Virtual address
    input  logic                    trace_vaddr_valid,  // Is address known?
    input  logic [DATA_WIDTH-1:0]   trace_value,        // Store data value
    input  logic                    trace_value_valid,  // Is store value known?
    output logic                    trace_ready,        // Can accept new operation

    //==========================================================================
    // L1 CACHE REQUEST INTERFACE
    //==========================================================================
    output logic                    l1_req_valid,       // Request to cache
    output logic                    l1_req_is_write,    // 0=load, 1=store
    output logic [VA_WIDTH-1:0]     l1_req_vaddr,       // Address for request
    output logic [DATA_WIDTH-1:0]   l1_req_wdata,       // Data for stores
    input  logic                    l1_req_ready,       // Cache can accept

    //==========================================================================
    // L1 CACHE RESPONSE INTERFACE
    //==========================================================================
    input  logic                    l1_resp_valid,      // Response from cache
    input  logic [DATA_WIDTH-1:0]   l1_resp_rdata,      // Data for loads


);

    //==========================================================================
    // OPERATION TYPE CONSTANTS
    //==========================================================================
    localparam [2:0] OP_MEM_LOAD    = 3'd0;
    localparam [2:0] OP_MEM_STORE   = 3'd1;
    localparam [2:0] OP_MEM_RESOLVE = 3'd2;

    //==========================================================================
    // LSQ ENTRY STRUCTURE
    //==========================================================================
    // Each entry tracks one memory operation through its lifecycle:
    //
    //   EMPTY -> WAITING -> READY -> ISSUED -> COMPLETED -> EMPTY
    //              ^                                          |
    //              |_________ RESOLVE updates addr/value _____|
    //
    //==========================================================================
    typedef struct packed {
        logic                   valid;          // Entry is in use
        logic                   is_store;       // 0 = load, 1 = store
        logic [ID_WIDTH-1:0]    id;             // Operation ID (for RESOLVE matching)

        logic [VA_WIDTH-1:0]    vaddr;          // Virtual address
        logic                   addr_valid;     // Is address known?

        logic [DATA_WIDTH-1:0]  value;          // Store data OR load result
        logic                   value_valid;    // Is value known? (stores: from trace, loads: from cache)

        logic                   issued;         // Has been sent to cache
        logic                   completed;      // Response received from cache
    } lsq_entry_t;

    //==========================================================================
    // LSQ STORAGE
    //==========================================================================
    lsq_entry_t entries [NUM_ENTRIES];

    // Circular buffer pointers
    logic [$clog2(NUM_ENTRIES)-1:0] head_ptr;   // Oldest entry (next to retire)
    logic [$clog2(NUM_ENTRIES)-1:0] tail_ptr;   // Next free slot
    logic [$clog2(NUM_ENTRIES):0]   count;      // Number of valid entries

    // Track which entry is currently being issued
    logic [$clog2(NUM_ENTRIES)-1:0] issuing_idx;
    logic                           has_issuable;

    //==========================================================================
    // STATUS SIGNALS
    //==========================================================================
    assign full = (count == NUM_ENTRIES);

    // Ready to accept new ops when:
    // - Not full (for LOAD/STORE)
    // - For RESOLVE: always ready (it updates existing entry, doesn't allocate)
    assign trace_ready = (trace_op == OP_MEM_RESOLVE) ? 1'b1 : !full;

    //==========================================================================
    // FIND ENTRY BY ID (for RESOLVE operations)
    //==========================================================================
    logic find_entry_valid;
    logic [$clog2(NUM_ENTRIES)-1:0] find_entry_idx;

    always_comb begin
        find_entry_valid = 1'b0;
        find_entry_idx = '0;

        for (int i = 0; i < NUM_ENTRIES; i++) begin
            if (entries[i].valid && entries[i].id == trace_id) begin
                find_entry_valid = 1'b1;
                find_entry_idx = i[$clog2(NUM_ENTRIES)-1:0];
            end
        end
    end

    //==========================================================================
    // FIND ISSUABLE ENTRY
    //==========================================================================
    // An entry can issue if:
    //   1. It's valid
    //   2. Address is known
    //   3. Value is known (for stores)
    //   4. Not already issued
    //   5. No conflicts with older entries
    //==========================================================================

    // Check if entry at idx can issue
    function automatic logic can_issue_entry(input int idx);
        lsq_entry_t e;
        e = entries[idx];

        // Basic requirements
        if (!e.valid)       return 1'b0;
        if (!e.addr_valid)  return 1'b0;
        if (e.issued)       return 1'b0;
        if (e.completed)    return 1'b0;

        // Stores need valid value
        if (e.is_store && !e.value_valid) return 1'b0;

        // Check for conflicts with older entries
        for (int i = 0; i < NUM_ENTRIES; i++) begin
            automatic logic [$clog2(NUM_ENTRIES)-1:0] older_idx;
            older_idx = (head_ptr + i) % NUM_ENTRIES;

            // Stop when we reach our entry
            if (older_idx == idx[$clog2(NUM_ENTRIES)-1:0]) break;

            // Skip invalid entries
            if (!entries[older_idx].valid) continue;

            // Skip completed entries (they don't affect ordering anymore)
            if (entries[older_idx].completed) continue;

            // RULE: Load cannot pass store with unknown address
            // (the store might be to the same address!)
            if (!e.is_store && entries[older_idx].is_store && !entries[older_idx].addr_valid) begin
                return 1'b0;
            end

            // RULE: Load cannot pass store to same address
            // (would get stale data - must wait for store or forward)
            if (!e.is_store && entries[older_idx].is_store &&
                entries[older_idx].addr_valid && entries[older_idx].vaddr == e.vaddr) begin
                return 1'b0;  // Could implement forwarding here instead
            end
        end

        return 1'b1;
    endfunction

    // Find the oldest issuable entry
    always_comb begin
        has_issuable = 1'b0;
        issuing_idx = '0;

        // Search from head (oldest) to find first issuable
        for (int i = 0; i < NUM_ENTRIES; i++) begin
            automatic logic [$clog2(NUM_ENTRIES)-1:0] idx;
            idx = (head_ptr + i) % NUM_ENTRIES;

            if (!has_issuable && can_issue_entry(idx)) begin
                has_issuable = 1'b1;
                issuing_idx = idx;
            end
        end
    end

    //==========================================================================
    // L1 REQUEST OUTPUTS
    //==========================================================================
    assign l1_req_valid    = has_issuable;
    assign l1_req_is_write = entries[issuing_idx].is_store;
    assign l1_req_vaddr    = entries[issuing_idx].vaddr;
    assign l1_req_wdata    = entries[issuing_idx].value;

    //==========================================================================
    // MAIN SEQUENTIAL LOGIC
    //==========================================================================
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // Reset all entries
            for (int i = 0; i < NUM_ENTRIES; i++) begin
                entries[i].valid <= 1'b0;
            end
            head_ptr <= '0;
            tail_ptr <= '0;
            count <= '0;

        end else begin

            //------------------------------------------------------------------
            // HANDLE TRACE INPUT
            //------------------------------------------------------------------
            if (trace_valid && trace_ready) begin
                case (trace_op)
                    OP_MEM_LOAD: begin
                        // Allocate new LOAD entry
                        entries[tail_ptr].valid       <= 1'b1;
                        entries[tail_ptr].is_store    <= 1'b0;
                        entries[tail_ptr].id          <= trace_id;
                        entries[tail_ptr].vaddr       <= trace_vaddr;
                        entries[tail_ptr].addr_valid  <= trace_vaddr_valid;
                        entries[tail_ptr].value       <= '0;
                        entries[tail_ptr].value_valid <= 1'b0;  // Load gets value from cache
                        entries[tail_ptr].issued      <= 1'b0;
                        entries[tail_ptr].completed   <= 1'b0;

                        tail_ptr <= tail_ptr + 1;
                        count <= count + 1;
                    end

                    OP_MEM_STORE: begin
                        // Allocate new STORE entry
                        entries[tail_ptr].valid       <= 1'b1;
                        entries[tail_ptr].is_store    <= 1'b1;
                        entries[tail_ptr].id          <= trace_id;
                        entries[tail_ptr].vaddr       <= trace_vaddr;
                        entries[tail_ptr].addr_valid  <= trace_vaddr_valid;
                        entries[tail_ptr].value       <= trace_value;
                        entries[tail_ptr].value_valid <= trace_value_valid;
                        entries[tail_ptr].issued      <= 1'b0;
                        entries[tail_ptr].completed   <= 1'b0;

                        tail_ptr <= tail_ptr + 1;
                        count <= count + 1;
                    end

                    OP_MEM_RESOLVE: begin
                        // Update existing entry (don't allocate new)
                        if (find_entry_valid) begin
                            // Update address if provided
                            entries[find_entry_idx].vaddr      <= trace_vaddr;
                            entries[find_entry_idx].addr_valid <= 1'b1;

                            // Update value if provided (for stores)
                            if (trace_value_valid && entries[find_entry_idx].is_store) begin
                                entries[find_entry_idx].value       <= trace_value;
                                entries[find_entry_idx].value_valid <= 1'b1;
                            end
                        end
                    end

                    default: begin
                        // Unknown op - ignore
                    end
                endcase
            end

            //------------------------------------------------------------------
            // HANDLE L1 REQUEST HANDSHAKE
            //------------------------------------------------------------------
            if (l1_req_valid && l1_req_ready) begin
                // Request accepted by cache - mark entry as issued
                entries[issuing_idx].issued <= 1'b1;
            end

            //------------------------------------------------------------------
            // HANDLE L1 RESPONSE
            //------------------------------------------------------------------
            if (l1_resp_valid) begin
                // Find the oldest issued entry waiting for response
                // (Responses should come back in order for simplicity)
                for (int i = 0; i < NUM_ENTRIES; i++) begin
                    automatic logic [$clog2(NUM_ENTRIES)-1:0] idx;
                    idx = (head_ptr + i) % NUM_ENTRIES;

                    if (entries[idx].valid && entries[idx].issued && !entries[idx].completed) begin
                        entries[idx].completed <= 1'b1;

                        // For loads, capture the returned data
                        if (!entries[idx].is_store) begin
                            entries[idx].value <= l1_resp_rdata;
                            entries[idx].value_valid <= 1'b1;
                        end

                        break;  // Only handle one response per cycle
                    end
                end
            end

            //------------------------------------------------------------------
            // RETIRE COMPLETED ENTRIES
            //------------------------------------------------------------------
            // Entries must retire IN ORDER (from head of queue)
            // This ensures program order is maintained
            if (entries[head_ptr].valid && entries[head_ptr].completed) begin
                entries[head_ptr].valid <= 1'b0;  // Free the entry
                head_ptr <= head_ptr + 1;
                count <= count - 1;
            end

        end
    end

endmodule
