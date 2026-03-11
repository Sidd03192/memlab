#!/usr/bin/env bash
# Compile and run directed L1 unit tests via Verilator.
# Usage: ./test_l1.sh

set -euo pipefail

UNIT_SRCS="mem_pkg.sv mainmem.sv l2.sv l1.sv tb_l1_accurate.sv"
OUT="tb_l1_accurate_v"
OBJ_DIR="obj_dir"

echo "=== Compiling with Verilator ==="
verilator --binary --timing -sv +1800-2012ext+sv \
  -Wno-WIDTH -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
  --top-module tb_l1_accurate $UNIT_SRCS -o "$OUT"

echo ""
echo "=== Running tests ==="
"$OBJ_DIR/$OUT"
