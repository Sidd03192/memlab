# `l1_cache.sv` Potential Issues

This file records likely bugs and design risks in [`l1_cache.sv`](/c:/Users/hisre/Desktop/Sid%20projects/UT/ACA/memlab/l1_cache.sv). Some are functional bugs, and some are interface limitations that will matter once LSQ/L2 are wired up.

---

## ✅ 1. Address decomposition does not match `BLOCK_SIZE = 64` — FIXED

`TAG_SIZE = 24` was a hardcoded parameter. Removed it from the parameter list and replaced with derived localparams:

```systemverilog
localparam int OFFSET_BITS = $clog2(BLOCK_SIZE);           // 6 for 64-byte blocks
localparam int WORD_BITS   = $clog2(BLOCK_SIZE * 8 / DATA_WIDTH); // 3: 8 words/block
localparam int TAG_SIZE    = PA_WIDTH - INDEX_BITS - OFFSET_BITS; // 30-2-6 = 22
```

Index extraction now uses `trace_vaddr[OFFSET_BITS +: INDEX_BITS]` instead of hardcoded `[7:6]`. Writeback address reconstruction (`PA_WIDTH - TAG_SIZE - INDEX_BITS`) now yields the correct 6-bit offset field.

---

## ⚠️ 2. No load response path exists — OPEN

- [`l1_cache.sv:27`]( /c:/Users/hisre/Desktop/Sid%20projects/UT/ACA/memlab/l1_cache.sv#L27 ) to [`l1_cache.sv:29`]( /c:/Users/hisre/Desktop/Sid%20projects/UT/ACA/memlab/l1_cache.sv#L29 ) comment out the LSQ response interface.

The cache can accept requests, allocate MSHRs, and install lines, but there is no architectural way to return load data to the LSQ. `resp_valid` and `resp_rdata` need to be wired up and driven on hit (and after MSHR install for a load miss).

---

## ✅ 3. Store path ignores the word offset and writes the wrong width into the line — FIXED

Added `curr_word_offset` register (3 bits, latched from `trace_vaddr[OFFSET_BITS-1 -: WORD_BITS]` in state 0). Store hit now writes:

```systemverilog
set_contents[curr_index][hit_way][curr_word_offset * DATA_WIDTH +: DATA_WIDTH] <= curr_wdata;
```

Only the correct 64-bit word within the 512-bit line is updated.

---

## ✅ 4. LRU update on hit is inverted — FIXED

Changed [`l1_cache.sv:234`]( /c:/Users/hisre/Desktop/Sid%20projects/UT/ACA/memlab/l1_cache.sv#L234 ) from:

```systemverilog
lru[curr_index] <= hit_way[0];     // wrong: marks just-used way as next victim
```
to:
```systemverilog
lru[curr_index] <= ~hit_way[0];    // correct: evict the OTHER way next
```

Now consistent with the install path (`lru <= ~evict_way_l`).

---

## ✅ 5. LSQ backpressure is not a proper ready/valid handshake — FIXED

Removed the register-based stall assignments. Replaced with a single combinational assign:

```systemverilog
assign l1_stall_out_to_lsq = (state != 3'd0) || mshr_full;
```

This fixes both hazards: stall goes high immediately when entering state 1 (TLB wait), and drops automatically when returning to idle with free MSHRs — no hit/idle path can leave it stuck.

---

## ✅ 6. Multiple outstanding MSHRs collapse onto one shared L2 request port — FIXED

**Sub-problem A (arbitration):** The loop previously let the highest-index UNRESOLVED MSHR overwrite all earlier ones, hiding them from L2 permanently. Fixed by adding `!l2_req_valid` guard so the lowest-index UNRESOLVED slot wins and later slots are skipped:

```systemverilog
if (mshr_state[i] == MS_UNRESOLVED && !l2_req_valid) begin
```

**Sub-problem B (no `l2_req_ready`):** Not an issue given L2's design. `l2_req_valid/paddr` stay asserted every cycle the MSHR is UNRESOLVED. L2 fetches and responds via `l2_data_valid`; the response is the implicit confirmation. A request-side handshake is only needed if L2 can reject requests, which it does not.

---

## ⚠️ 7. Only one writeback can be buffered — OPEN

- [`l1_cache.sv:88`]( /c:/Users/hisre/Desktop/Sid%20projects/UT/ACA/memlab/l1_cache.sv#L88 ) to [`l1_cache.sv:90`]( /c:/Users/hisre/Desktop/Sid%20projects/UT/ACA/memlab/l1_cache.sv#L90 ) define a single writeback buffer.
- The MSHR install loop overwrites `wb_paddr`/`wb_value` unconditionally when a dirty victim is found, with no check on whether `wb_valid` is still set.

With `NUM_MSHRS = 2`, two MSHRs can resolve on consecutive cycles. If both evict dirty lines and `l2_wb_ack` has not arrived between them, the first writeback is silently lost. Fix: stall the install loop if `wb_valid` is still set, or use a small writeback queue (depth = NUM_MSHRS).

---

## ⚠️ 8. Module is parameterized as generic but several internals are hardcoded for 2-way — OPEN

- `lru` is 1 bit per set — only correct for `L1_WAYS = 2`.
- The eviction way selection in the install loop explicitly checks only ways `0` and `1`.

Not a bug for the current configuration, but will silently produce wrong behavior if `L1_WAYS` is changed. Low priority until associativity needs to scale.
