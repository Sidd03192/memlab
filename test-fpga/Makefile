BUILD_DIR := build
SIM_EXE := $(BUILD_DIR)/tb_simple_trace_avl_wrapper.vvp
HOST_EXE := $(BUILD_DIR)/test_fpga_trace_store

IVERILOG ?= iverilog
VVP ?= vvp
CC ?= gcc
CFLAGS ?= -Wall -Wextra -Werror -std=c11 -O2

.PHONY: all sim host clean

all: sim host

sim: $(SIM_EXE)
	$(VVP) $(SIM_EXE)

$(SIM_EXE): simple_trace_pkg.sv simple_trace_store_master.sv simple_trace_avl_wrapper.sv tb_simple_trace_avl_wrapper.sv | $(BUILD_DIR)
	$(IVERILOG) -g2012 -o $(SIM_EXE) simple_trace_pkg.sv simple_trace_store_master.sv simple_trace_avl_wrapper.sv tb_simple_trace_avl_wrapper.sv

host: $(HOST_EXE)

$(HOST_EXE): test_fpga_trace_store.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(HOST_EXE) test_fpga_trace_store.c

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
