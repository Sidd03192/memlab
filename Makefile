# ============================================================================
# Makefile for l1_cache testbench
# Requires: iverilog + vvp  (or set SIM=verilator — see Verilator target below)
# ============================================================================

SV_SRCS      = mem_pkg.sv mainmem.sv l2.sv l1.sv tlb.sv l1_tb.sv
SIM_OUT      = l1_tb.vvp
UNIT_SRCS    = mem_pkg.sv mainmem.sv l2.sv l1.sv tb_l1_accurate.sv
UNIT_OUT     = tb_l1_accurate.vvp
UNIT_L2_SRCS    = mem_pkg.sv mainmem.sv l2.sv tb_l2.sv
UNIT_L2_OUT     = tb_l2.vvp
UNIT_SYS_SRCS   = mem_pkg.sv mainmem.sv l2.sv l1.sv tb_memsys.sv
TRACE   ?= aca-mem-traces/traces/dgemm3.bin

FLAGS    = -g2012 -Wall -Wno-sensitivity-entire-array

# ----------------------------------------------------------------------------
# iverilog targets
# ----------------------------------------------------------------------------
.PHONY: sim waves unit unit_v unit_l2_v unit_sys_v clean

sim: $(SIM_OUT)
	vvp $(SIM_OUT) +TRACE_FILE=$(TRACE)

waves: $(SIM_OUT)
	vvp $(SIM_OUT) +TRACE_FILE=$(TRACE) +WAVES
	@command -v gtkwave >/dev/null 2>&1 && gtkwave l1_tb.vcd & || \
	  echo "[Makefile] gtkwave not found — open l1_tb.vcd manually"

$(SIM_OUT): $(SV_SRCS)
	iverilog $(FLAGS) -o $@ $^

# Directed unit tests for l1_cache (T1-T10)
unit: $(UNIT_OUT)
	vvp $(UNIT_OUT)

$(UNIT_OUT): $(UNIT_SRCS)
	iverilog $(FLAGS) -o $@ $^

unit_v:
	verilator --binary --timing -sv +1800-2012ext+sv \
	  -Wno-WIDTH -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
	  --top-module tb_l1_accurate $(UNIT_SRCS) -o tb_l1_accurate_v
	./obj_dir/tb_l1_accurate_v

unit_l2_v:
	verilator --binary --timing -sv +1800-2012ext+sv \
	  -Wno-WIDTH -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
	  --top-module tb_l2 $(UNIT_L2_SRCS) -o tb_l2_v
	./obj_dir/tb_l2_v

unit_sys_v:
	verilator --binary --timing -sv +1800-2012ext+sv \
	  -Wno-WIDTH -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
	  --top-module tb_memsys $(UNIT_SYS_SRCS) -o tb_memsys_v
	./obj_dir/tb_memsys_v

# Run against a different trace (e.g. make sim TRACE=aca-mem-traces/traces/dgemm3_real.bin)

# ----------------------------------------------------------------------------
# Verilator target (optional, faster for long traces)
# ----------------------------------------------------------------------------
.PHONY: verilator
verilator:
	verilator --binary --timing -sv +1800-2012ext+sv \
	  -Wno-WIDTH -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
	  --top-module l1_tb $(SV_SRCS) -o l1_tb_v
	./obj_dir/l1_tb_v +TRACE_FILE=$(TRACE)

# ----------------------------------------------------------------------------
# Trace utilities (build in the aca-mem-traces subdir)
# ----------------------------------------------------------------------------
.PHONY: parse_trace replay_trace
parse_trace:
	$(MAKE) -C aca-mem-traces parse_trace

replay_trace:
	$(MAKE) -C aca-mem-traces replay_trace

# Run replay against the same trace for a gold-standard memory dump:
replay: replay_trace
	./aca-mem-traces/replay_trace $(TRACE) 0

clean:
	$(RM) $(SIM_OUT) $(UNIT_OUT) l1_tb.vcd
	$(RM) -r obj_dir
