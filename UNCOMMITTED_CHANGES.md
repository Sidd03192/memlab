### Change 2.3: RESOLVE finds only the oldest match (`resolve_done` flag)

**Old (loads):**

```systemverilog
for (int i = 0; i < LQ_ENTRIES; i++) begin
    logic [LQ_PTR_WIDTH-1:0] idx;
    idx = lq_head + i[LQ_PTR_WIDTH - 1:0];
    if (lq_id[idx] == id_in && lq_state[idx] == LQ_WAITING_ADDR) begin
        lq_vaddr[idx] <= vaddr_in;
        lq_state[idx] <= LQ_WAITING_ISSUE;
    end
end
```

**New (loads):**

```systemverilog
logic resolve_done;
resolve_done = 1'b0;
for (int i = 0; i < LQ_ENTRIES; i++) begin
    logic [LQ_PTR_WIDTH-1:0] idx;
    idx = lq_head + i[LQ_PTR_WIDTH - 1:0];
    if (!resolve_done && lq_id[idx] == id_in && lq_state[idx] == LQ_WAITING_ADDR) begin
        if (vaddr_ready) begin
            lq_vaddr[idx] <= vaddr_in;
            lq_state[idx] <= LQ_WAITING_ISSUE;
        end
        resolve_done = 1'b1;
    end
end
```

**Why it was wrong:**
IDs are reused in a circular fashion (loads use IDs 0–7, stores use IDs 8–15). At any point, there could be **two entries with the same ID** — an older one that hasn't been issued yet and a newer one just dispatched. The RESOLVE record targets the **oldest incomplete** entry with that ID.

The old code had no `resolve_done` flag, so it resolved **every** entry with the matching ID and state. If two load queue entries had the same ID (one old, one new), both would get the resolve's vaddr — but the newer one might need a different address from a future resolve.

The `replay_trace.c` reference model (which generates the ground-truth expected state) uses this exact "oldest first" semantic: it walks from `q_head` and stops at the first match.

**What would happen:** Multiple entries resolved simultaneously → newer entries get incorrect addresses → loads to wrong memory locations → wrong data returned or wrong store-to-load forwarding.

---

### Change 2.4: RESOLVE gates updates with `vaddr_ready` / `wdata_ready`

**Old (stores, SQ_WAITING_ADDR case):**

```systemverilog
if (sq_state[idx] == SQ_WAITING_ADDR) begin
    sq_vaddr[idx] <= vaddr_in;
    sq_state[idx] <= SQ_WAITING_ISSUE;
end
```

**New:**

```systemverilog
if (sq_state[idx] == SQ_WAITING_ADDR) begin
    if (vaddr_ready) begin
        sq_vaddr[idx] <= vaddr_in;
        sq_state[idx] <= SQ_WAITING_ISSUE;
    end
end
```

**Why it was wrong:**
A RESOLVE record in the `_real` traces can carry:

- Only an address (`vaddr_ready=1, wdata_ready=0`)
- Only data (`vaddr_ready=0, wdata_ready=1`)
- Both (`vaddr_ready=1, wdata_ready=1`)

The old code unconditionally wrote `vaddr_in` without checking `vaddr_ready`. When a resolve carries only data (no address), `vaddr_in` contains garbage (or zeros), and the old code would overwrite the store's address with that garbage.

The same pattern applies to `SQ_WAITING_DATA` (now gates with `wdata_ready`) and `SQ_UNRESOLVED` (gates both).

**What would happen:** Stores get incorrect addresses or data → writes to wrong memory locations → data corruption.

---

### Change 2.5: SQ_UNRESOLVED can resolve both fields at once

**Old:**

```systemverilog
else if (sq_state[idx] == SQ_UNRESOLVED) begin
    if (vaddr_ready) begin
        sq_vaddr[idx] <= vaddr_in;
        sq_state[idx] <= SQ_WAITING_DATA;
    end
    else if (wdata_ready) begin
        sq_wdata[idx] <= wdata_in;
        sq_state[idx] <= SQ_WAITING_ADDR;
    end
end
```

**New:**

```systemverilog
else if (sq_state[idx] == SQ_UNRESOLVED) begin
    if (vaddr_ready && wdata_ready) begin
        sq_vaddr[idx] <= vaddr_in;
        sq_wdata[idx] <= wdata_in;
        sq_state[idx] <= SQ_WAITING_ISSUE;   // both resolved → ready!
    end
    else if (vaddr_ready) begin
        sq_vaddr[idx] <= vaddr_in;
        sq_state[idx] <= SQ_WAITING_DATA;
    end
    else if (wdata_ready) begin
        sq_wdata[idx] <= wdata_in;
        sq_state[idx] <= SQ_WAITING_ADDR;
    end
end
```

**Why it was wrong:**
The old code handled the case where a RESOLVE carries only an address OR only data, but not both. If a single RESOLVE record carries both `vaddr_ready=1` and `wdata_ready=1` (both fields resolved at once), the old code would only process the `vaddr_ready` branch (because of `if/else if`) and transition to `SQ_WAITING_DATA`. The wdata would be ignored.

The entry would then sit in `SQ_WAITING_DATA` waiting for another RESOLVE that never comes (since the data was already sent in the first resolve).

**What would happen:** Stores get stuck in `SQ_WAITING_DATA` forever → the store queue fills up → `sq_ready=0` → the trace pipeline stalls permanently → simulation timeout.

---
