# Ozone (Out-Of-Order) Processor for UT CS 350C Spring 2026

## Members
- Siddharth Potta (@Sidd03192)
- Brayden Strong (@bstrong04)
- Rishab Pradeep (@rispop)
- Nathan Tran (@nathandktran)
- Sean McCain (@shaewn)
- Max Feldman (@MaxFeldman1)

## Build and Testing Instructions

To run the standard tests:
```bash
cd cpu/ozone
# If your ARM cross-compiler uses a different prefix, specify it here
# (or edit the CROSS_COMPILE variable in the Makefile)
make tests CROSS_COMPILE=aarch64-linux-gnu-
```

To build the Verilator simulation:
```bash
cd cpu/ozone/verilator
env CCACHE_DISABLED=1 make all
```
*(Note: `env CCACHE_DISABLED=1` disables the `ccache` compiler cache. This ensures Verilator performs a fully fresh compilation of the C++ simulation models without relying on previously cached object files, which guarantees your build matches the latest RTL code.)*

To run the comparison tests between our simulator and the RTL behavior using Verilator:
```bash
cd cpu/ozone
./run_compare_tests.py --timeout 20
```

### Advanced Testing Options
The `run_compare_tests.py` script supports running specific subsets of tests by supplying a glob pattern. For example, to run only the tests starting with `el1_4_`:
```bash
./run_compare_tests.py --timeout 20 'el1_4_*.elf'
```

Other useful flags include:
- `--all`: Run all `.elf` files in the directory instead of just standard `el1_` tests.
- `--include-sys`: In addition to GPRs, floating-point registers, and memory, also compare PC, PSTATE, and system registers between the sim and RTL.

### What `run_compare_tests.py` Does
This script automates the verification process by checking that the RTL implementation matches the golden software simulator:
1. **Simulation:** Runs the ELF testcase in the pure C software simulator (`sim`) and parses the resulting final architectural state (registers, memory, exceptions).
2. **RTL Execution:** Runs the identical testcase on the Verilator RTL simulation (`run_verilator`), which executes the actual hardware logic.
3. **Comparison:** Extracts the final architectural state from the RTL simulation's shared memory, and rigorously compares the two states. If there are any mismatches in general-purpose registers, floating-point registers, or tracked memory addresses, it prints a diff and marks the test as failed.

## Extra Credit Features
- [x] Distinguish between different types of exceptions. **Covered by:** `el1_4_svc_bad_syscall` and `el1_4_svc_terminate` (different `SVC` numbers route to different handlers/exception paths).
- [x] Make it so writing a terminate value to the special-purpose register `ACTLR_EL1` causes the processor to enter a low power state. This will be tested by either placing a finger on the FPGA to see if it's hot, or seeing whether a core is being hogged by Verilator. **Covered by:** `el1_4_svc_terminate` (handler writes terminate value to `ACTLR_EL1`).
- [ ] Make your front end 2-way superscalar, and beef up your back end so that it has the capacity to handle this without stalling uselessly.
- [x] Add the `SVC` instruction, and use a particular value to do clean termination, rather than using just a segfault. You should be able to differentiate between a segfault termination and an `SVC` termination. Effectively, this is implementing a syscall. Syscalls with different numbers should fail with a completely different error (in a different exception handler). **Covered by:** `el1_4_svc_bad_syscall` and `el1_4_svc_terminate`.


### New `5_*` Tests Added
The six new tests are in `cpu/ozone/testcases/src`:

- `5_branch_mix.s`: Mixed taken/not-taken branch loop that alternates add/sub behavior and stresses conditional control flow.
- `5_branch_mix.s`: Mixed taken/not-taken branch loop (+odd/−even accumulation) followed by floating-point ops (`FADD`, `FSUB`) and `SVC #0` termination.
- `5_call_chain.s`: Nested `BL`/`RET` call chain with stack save/restore of link and callee-saved registers.
- `5_mem_stride_sum.s`: Stack-based `STUR`/`LDUR` reverse-order integer sum plus floating-point ops (`FADD`, `FMUL`) and `SVC #0` termination.
- `5_shift_bitops.s`: Integer shift/bitwise datapath checks (`LSR`, `ASR`, `EOR`, `AND`) plus floating-point ops (`FADD`, `FNEG`) and `SVC #0` termination.
- `5_store_page_fault.s`: Intentional EL0 store to unmapped VA (0x0) to validate store page-fault exception path.
- `5_svc_select.s`: Branch-selected syscall path that can exercise different `SVC` numbers/handlers.
