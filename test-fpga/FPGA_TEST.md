# FPGA Direct-Write Smoke Test Guide

## Purpose

This is the simplest useful FPGA memory test in the repo.

It answers one question only:

- can the HPS write an address and 64-bit value into the FPGA over MMIO
- can the FPGA turn that into a single Avalon-MM SDRAM write
- does the written data show up in SDRAM when Linux reads it back

There is no trace parsing, no cache, no TLB, no LSQ, and no replay logic.

## Files To Use

- [simple_trace_pkg.sv](/Users/spotta/Desktop/School/aca/memlab/test-fpga/simple_trace_pkg.sv)
- [simple_trace_store_master.sv](/Users/spotta/Desktop/School/aca/memlab/test-fpga/simple_trace_store_master.sv)
- [simple_trace_avl_wrapper.sv](/Users/spotta/Desktop/School/aca/memlab/test-fpga/simple_trace_avl_wrapper.sv)
- [test_fpga_trace_store.c](/Users/spotta/Desktop/School/aca/memlab/test-fpga/test_fpga_trace_store.c)
- [Makefile](/Users/spotta/Desktop/School/aca/memlab/test-fpga/Makefile)

## Register Map

The MMIO contract is now just `addr/data/go`:

- `0x00`: `write_addr` byte address, must be 8-byte aligned
- `0x04`: `write_data_lo`
- `0x08`: `write_data_hi`
- `0x0C`: `write_go`
- `0x10`: `status0`

`status0` bit layout:

- bit 0: `go_reg`
- bit 1: `ready`
- bit 2: `busy`
- bit 3: `done_pulse`

Behavior:

- software writes address and data
- software writes `1` to `write_go`
- wrapper handshakes the request and auto-clears `write_go`
- hardware waits 1 cycle
- hardware issues one 64-bit Avalon write with `burstcount=1`

## Platform Designer / Quartus Wiring Checklist

Instantiate `simple_trace_avl_wrapper` as the FPGA smoke-test block and connect it as follows:

- connect the wrapper Avalon-MM slave to the lightweight HPS-to-FPGA bridge
- connect the wrapper Avalon-MM master to `f2h_sdram0`
- keep the slave address bus wide enough for register indices `0` through `4`
- make sure the software-visible base offset for the wrapper matches `WRITE_BASE_OFFSET` in the C tool

Expected default constants in this bundle:

- lightweight bridge base: `0xFF200000`
- wrapper offset inside bridge window: `0x00000000`

## Local Sanity Check Before Hardware

From this folder:

```bash
make all
```

That should:

- pass the standalone RTL simulation
- build the host-side executable at `build/test_fpga_trace_store`

## Build And Program The FPGA

1. Add the `simple_trace_avl_wrapper` RTL to your Quartus project.
2. Connect it in Platform Designer using the checklist above.
3. Rebuild the FPGA image.
4. Program the `.sof` onto the board.
5. Boot Linux on the HPS.

## Build The Host Tool On The Board

From the repo:

```bash
cd test-fpga
make host
```

That produces:

```bash
build/test_fpga_trace_store
```

## Run Flow On Hardware

Issue 8 writes starting at `0x20000000`:

```bash
sudo ./build/test_fpga_trace_store 0x20000000 8
```

Issue 64 writes starting at `0x20001000`:

```bash
sudo ./build/test_fpga_trace_store 0x20001000 64
```

The host utility:

- writes sequential 64-bit test patterns through the MMIO registers
- pulses `go` for each request
- reads SDRAM back through `/dev/mem`
- compares actual contents against the expected pattern immediately

## What Success Looks Like

You want to see all of the following:

- the program does not time out waiting for `ready`
- `go_reg` does not get stuck high
- the FPGA write path returns to ready between requests
- every readback matches
- the program ends with:

```text
PASS: direct FPGA write smoke test completed with zero mismatches.
```

## Failure Triage

### `ready` stuck low

Likely causes:

- reset is not releasing
- the wrapper is stuck waiting for SDRAM to accept a write
- the wrong MMIO base or offset is being used

What to inspect:

- `status0`
- `busy`
- `avm_waitrequest`

### `go_reg` does not clear

Likely causes:

- the wrapper never saw the request handshake
- `ready` never went high
- the MMIO slave wiring is wrong

What to inspect:

- writes to `0x0C`
- reads from `0x10`
- `status0[0:2]`

### Writes never get accepted

Likely causes:

- Avalon master is not connected to `f2h_sdram0`
- SDRAM bridge is not exported or clocked correctly
- `avm_waitrequest` never deasserts

What to inspect:

- `avm_write`
- `avm_waitrequest`
- `avm_address`
- `avm_writedata`

### Readback mismatches

Likely causes:

- Linux is reading a different SDRAM window than the FPGA is writing
- the address passed to the host tool is not the actual SDRAM byte address
- the system has caching or mapping side effects outside this simple path

What to inspect:

- the address you passed to `test_fpga_trace_store`
- the exported SDRAM base in Platform Designer
- the value on `avm_address` during writes

## Notes

- The wrapper forces 8-byte alignment internally before driving Avalon.
- Start with a small count like `8` before trying larger runs.
- If you change MMIO base addresses in Platform Designer, update [test_fpga_trace_store.c](/Users/spotta/Desktop/School/aca/memlab/test-fpga/test_fpga_trace_store.c) to match.
