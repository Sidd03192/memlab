# `dev/why-nate` Minimal FPGA Debug Branch

This branch keeps two things:

1. The L1-to-memory bypass path.
2. A very small FPGA debug register intended to minimize fitter impact.

## What Changed

- `memory_subsystem` has a `BYPASS_L2` parameter.
- `memory_subsystem_avl_wrapper` sets `BYPASS_L2=1` by default on this branch.
- `send_trace.c` now times out on hard stalls and dumps a minimal debug snapshot.

## Bypass Mode

On this branch, the Avalon wrapper enables the bypass path by default:

- [mem_avl_wrapper.sv](/Users/spotta/Desktop/School/aca/memlab/mem_avl_wrapper.sv)

That means:

- L1 miss reads go straight to the memory interface.
- L1 writebacks go straight to the memory interface.
- L2 is skipped for the FPGA wrapper build.

If you want to compare against the original path, set `BYPASS_L2` back to `1'b0` in the wrapper instantiation or override the parameter from your top-level.

## Avalon Debug Register Map

Base control registers:

- `0x00` `trace_addr`
- `0x04` `trace_data`
- `0x08` `trace_valid`
- `0x0C` `trace_ready`
- `0x10` `debug_status0`

`debug_status0` bit layout:

- bit 0: `trace_valid_reg`
- bit 1: `trace_ready_wire`
- bit 4: `lsq_sq_ready`
- bit 7: `u_l1.mshr_full`
- bit 11: `BYPASS_L2`

## How To Use It

Build the sender:

```bash
gcc -Wall -Wextra -std=c11 -o send_trace_debug send_trace.c
```

Run it the same way as before:

```bash
./send_trace_debug mem-traces-v2/traces/dgemm3_lsq88_real.bin
```

If the FPGA hard-stalls, the program prints:

- whether `trace_valid_reg` is still high
- whether `trace_ready_wire` is low
- whether `lsq_sq_ready` is low
- whether `u_l1.mshr_full` is high
- whether the build is using `BYPASS_L2`

## What To Look For

The most useful pattern for the trace-195 question is:

- `trace_valid_reg = 1`
- `trace_ready_wire = 0`
- `lsq_sq_ready = 0`

That means the incoming store is blocked before it can enter the SQ.

If `u_l1.mshr_full = 1`, then the store path is likely blocked by L1 backpressure.

## Notes

- The wrapper Avalon slave address bus widened from 2 bits to 6 bits. If your Platform Designer wrapper hardcodes the old width, regenerate or reconnect that interface before testing.
- The normal simulation path is still intact. `tb_memsys_v2` still passes the 5k smoke run on this branch.
