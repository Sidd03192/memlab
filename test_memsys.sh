#!/usr/bin/env bash
# Compile and run the L1+L2+mainmem integration testbench via Verilator.
# Usage: ./test_memsys.sh

set -euo pipefail

UNIT_SRCS="mem_pkg.sv mainmem.sv l2.sv l1.sv tb_memsys.sv"
OUT="tb_memsys_v"
OBJ_DIR="obj_dir"

echo "=== Compiling with Verilator ==="
verilator --binary --timing -sv +1800-2012ext+sv \
  -Wno-WIDTH -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
  --top-module tb_memsys $UNIT_SRCS -o "$OUT"

echo ""
echo "=== Running tests ==="
"$OBJ_DIR/$OUT"
