# Ozone Backend High-Level Behavior

## ROB

The ROB tracks instructions in program order.
`head` points to the oldest in-flight entry.
`tail` points to the next free entry.
`count` tracks occupancy.

Dispatch allocates a new ROB entry at `tail`.
The allocated ROB index becomes the tag for later wakeups.
The ROB stores destination metadata, result data, branch data, exception data, and NZCV state.

The ROB also answers dispatch source queries.
If a source tag is already ready in the ROB, dispatch can read the value directly.
If the CDB is broadcasting that same tag in the current cycle, the ROB forwards the CDB value combinationally.

The ROB commits only from `head`.
A head entry commits when it is valid and ready.
Commit is in program order.
Commit drives register-state updates for GPR, FPR, and NZCV.

## CDB

The CDB is a single shared result bus.
Only one FU may broadcast in a cycle.
The CDB itself has no state.

Each FU presents one held result request.
The CDB compares all valid requests.
The winner is the request with the smallest age relative to the current ROB head.

Age is:

```text
age = (rob_tag - rob_head) % ROB_DEPTH
```

The CDB broadcasts the winning payload unchanged.
It also asserts only the winning FU's grant.
The winning FU clears its held result on the next clock edge.
Losing FUs keep holding their result and retry next cycle.

When the CDB broadcasts a valid result, the ROB consumes it on `cdb_in`.
On the next clock edge, the ROB writes that payload into `rob_entries[rob_tag]` and marks the entry ready.
All RS snoopers also see the same broadcast.

## Adder

The adder has a 4-entry reservation station.
It accepts one allocated RS entry from dispatch when space is available.
It issues one ready entry when its output register is free.

The adder holds completed output in a local `result` register.
That result stays valid until the CDB grants it.
This prevents the FU from losing a completed result.

The adder handles:
- `ADD`
- `ADDS`
- `SUB`
- `SUBS`
- `CMP`
- `CMN`
- `ADRP_ADD`
- `B`
- `BL`
- `BCOND`

`ADDS`, `SUBS`, `CMP`, and `CMN` produce NZCV.
`CMP` and `CMN` are flags-only operations.
They do not produce a data result.

`B`, `BL`, and `BCOND` produce branch metadata.
They do not produce a data result.

The adder snoops the CDB for normal value wakeup.
It also has local same-cycle forwarding inside its own RS.
If an issued instruction produces a normal data value, younger waiting entries can capture that value immediately.

`BCOND` is special.
It consumes NZCV, not a normal data value.
If its `Qj` dependency matches a CDB result with `update_nzcv=1`, it captures `nzcv` instead of `value`.
The adder also does local same-cycle NZCV forwarding for a waiting `BCOND` when an older flag-setting adder op issues in that cycle.

## Logic

The logic FU also has a 4-entry reservation station.
Its structure matches the adder.
It also holds completed output in a local `result` register until the CDB grants it.

The logic FU handles:
- `AND`
- `ORR`
- `EOR`
- `ORN`
- `MVN`
- `ANDS`
- `TST`

`ANDS` produces both a data result and NZCV.
`TST` produces NZCV only.
`TST` does not produce a normal data result.

The logic FU snoops the CDB for normal value wakeup.
It also has local same-cycle value forwarding inside its own RS.
It does not currently consume NZCV from the CDB because none of its implemented ops depend on flags as an input.

## How They Work Together

Dispatch allocates ROB entries and RS entries.
The RS entry carries source values or source tags.
The ROB tag identifies the future producer.

An FU waits until its operands are ready.
Then it issues the oldest ready entry in that RS.
The FU computes the result in one cycle.
The FU stores the completed payload in its local `result` register.

The CDB picks one completed FU result.
That result is broadcast to the ROB and all RS snoopers.
The ROB records the result in the matching entry.
Dependent RS entries clear matching tags and capture the value.

Later, when that ROB entry reaches `head`, the ROB commits it.
Commit updates architectural state in regstate.
That is how speculative execution becomes architectural state.

## Dispatch-Specific Cases

Dispatch needs to set up a few special cases correctly.

For `BCOND`:
- `Vj` should hold the branch PC.
- `Vk` should hold the branch offset.
- `Qj` should track the NZCV-producing ROB tag when flags are not ready yet.
- The adder will treat `Qj` as a flags dependency for `BCOND`.

For `CMP` and `CMN`:
- there is no architectural data destination
- the uop should still mark that it updates NZCV

For `TST`:
- there is no architectural data destination
- the uop should still mark that it updates NZCV

For `ANDS`:
- the uop has a normal destination
- the uop also updates NZCV

For `MVN`:
- the real source operand must be placed in `Vk`
- the logic FU implements `MVN` as `~Vk`

For `ADRP_ADD`:
- the logic side must produce `PC & ~12'hFFF`
- the adder then adds the shifted page immediate

For branch-only adder ops such as `B`, `BL`, and `BCOND`:
- dispatch should not expect a normal data value from the FU result
- those uops communicate through branch metadata instead
