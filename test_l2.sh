#!/usr/bin/env bash
# Compile and run directed L2 unit tests via Verilator.
# Usage: ./test_l2.sh

set -euo pipefail

UNIT_SRCS="mem_pkg.sv mainmem.sv l2.sv tb_l2.sv"
OUT="tb_l2_v"
OBJ_DIR="obj_dir"

echo "=== Compiling with Verilator ==="
verilator --binary --timing -sv +1800-2012ext+sv \
  -Wno-WIDTH -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
  --top-module tb_l2 $UNIT_SRCS -o "$OUT"

echo ""
echo "=== Running tests ==="
"$OBJ_DIR/$OUT"
