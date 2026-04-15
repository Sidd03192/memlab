# ozone_cdb — Interface & Functionality

## Inputs

One `cdb_broadcast_t` request per FU (adder, logic, fpu, mem):

```
input  cdb_broadcast_t  adder_req   // from ozone_rs_adder.cdb_out
input  cdb_broadcast_t  logic_req   // from ozone_logic.cdb_out
input  cdb_broadcast_t  fpu_req     // from ozone_fpu.cdb_out
input  cdb_broadcast_t  mem_req     // from ozone_mem_fu.cdb_out
input  logic            clk
input  logic            rst_n
```

## Outputs

**Broadcast** (goes to ROB's `cdb_in` and all RS snoops' `cdb_in`):

```
output cdb_broadcast_t  cdb_broadcast
```

**Grant signals** (back to each FU's `cdb_granted`):

```
output logic  adder_granted
output logic  logic_granted
output logic  fpu_granted
output logic  mem_granted
```

## Priority

Use **oldest-first arbitration**: among all FUs with `req.valid == 1`, the one whose `req.rob_tag` is numerically smallest wins. This matches the priority scheme already used inside each RS (see `ozone_adder.sv:68-74` where the RS picks the entry with the smallest `rob_tag` to issue). Using the same criterion at the CDB level means the oldest instruction in the pipeline gets its result broadcast first, which unblocks the most downstream dependents the soonest.

If two FUs happen to finish an instruction with the same `rob_tag` that is a hardware bug (two instructions cannot share a ROB slot), so no tiebreak is needed.

Only one FU wins per cycle. All others keep their result register held and will compete again next cycle. There is no skipping or reordering — every completed result eventually wins a cycle.

## Broadcast

The CDB broadcast is a **purely combinational mux**. Each cycle, the winning FU's `cdb_broadcast_t` is driven directly onto `cdb_broadcast`. There are no registers inside the CDB itself — the broadcast is valid for exactly one cycle (the cycle the FU wins), and consumers must capture or react to it in that same cycle.

`cdb_broadcast` is fanned out to every module that needs to snoop results:
- **`ozone_rob`** (`cdb_in`) — on the same cycle the broadcast is live, the ROB combinationally forwards the value to dispatch reads (lines 87-94 in `ozone_rob.sv`). On the following clock edge, it writes the value/nzcv/branch fields into the matching ROB entry and marks it `ready`.
- **Every RS** (`cdb_in`) — on the following clock edge, any RS entry whose `Qj` or `Qk` matches `cdb_broadcast.rob_tag` captures the value and clears its tag to `0`, making that source operand ready for issue.

When no FU has a result, `cdb_broadcast.valid` is driven `0`. All consumers check `.valid` before acting, so a quiet cycle is a no-op everywhere.

## Functionality

1. **Arbitration** — Combinationally scan all four `*_req` inputs each cycle. Among those with `.valid == 1`, select the one with the lowest `.rob_tag`. Assert only that FU's `_granted` output; all others stay `0`.

2. **Broadcast** — Mux the winning request onto `cdb_broadcast`. If no request is valid, drive `cdb_broadcast` to all-zero (`.valid = 0`).

3. **Grant handshake** — The winning FU sees its `_granted` pulse for one cycle. On the next clock edge it clears its internal `result.valid`, freeing it to accept the next issue from its RS. A FU that is not granted holds `result.valid = 1` and keeps presenting the same `cdb_out` until it wins.

4. **No-win cycle** — Drive `cdb_broadcast.valid = 0`. The ROB and all RSes ignore the bus this cycle.

5. **Losers stall** — A non-granted FU does not lose its result. It holds `result.valid = 1` and re-presents the same `cdb_out` next cycle. Its RS cannot issue a new instruction until the result clears, but that is intentional — the FU pipeline is naturally back-pressured until the CDB drains it.

## Key Connection Points

| Signal | File | Direction |
|---|---|---|
| `ozone_rs_adder.cdb_out` | `fu/ozone_adder.sv:28` | FU → CDB input |
| `ozone_rs_adder.cdb_granted` | `fu/ozone_adder.sv:29` | CDB grant → FU |
| `ozone_rs_adder.cdb_in` | `fu/ozone_adder.sv:22` | CDB broadcast → RS snoop |
| `ozone_rob.cdb_in` | `backend/ozone_rob.sv:30` | CDB broadcast → ROB |
