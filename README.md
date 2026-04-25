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
- [x] Distinguish between different types of exceptions.
- [x] Make it so writing a terminate value to the special-purpose register `ACTLR_EL1` causes the processor to enter a low power state. This will be tested by either placing a finger on the FPGA to see if it's hot, or seeing whether a core is being hogged by Verilator.
- [ ] Make your front end 2-way superscalar, and beef up your back end so that it has the capacity to handle this without stalling uselessly.
- [x] Add the `SVC` instruction, and use a particular value to do clean termination, rather than using just a segfault. You should be able to differentiate between a segfault termination and an `SVC` termination. Effectively, this is implementing a sycall. Syscalls with different numbers should fail with a completely different error (in a different exception handler).
