# `test-fpga`

This folder now contains the simplest FPGA SDRAM smoke test in the repo: write an address and 64-bit value over MMIO, pulse `go`, and verify the FPGA write reached SDRAM.

Local entry points:

- `make sim` runs the self-contained SystemVerilog smoke test.
- `make host` builds the HPS/Linux direct-write checker.
- `make all` runs both.

Board bring-up and validation steps live in [FPGA_TEST.md](/Users/spotta/Desktop/School/aca/memlab/test-fpga/FPGA_TEST.md).
