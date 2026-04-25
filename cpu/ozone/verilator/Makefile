VERILATOR = verilator
V_FLAGS = -Wall -Wno-fatal --cc --exe --build -j --top-module Top -I. -I../../..
FILES = types.sv \
	fu/fpu/fpnew_pkg.sv \
	fu/fpu/lzc.sv \
	fu/fpu/rr_arb_tree.sv \
	fu/fpu/fpnew_classifier.sv \
	fu/fpu/fpnew_rounding.sv \
	fu/fpu/fpnew_fma.sv \
	fu/fpu/fpnew_fma_multi.sv \
	fu/fpu/fpnew_noncomp.sv \
	fu/fpu/fpnew_cast_multi.sv \
	fu/fpu/fpnew_divsqrt_multi.sv \
	fu/fpu/fpnew_divsqrt_th_32.sv \
	fu/fpu/fpnew_divsqrt_th_64_multi.sv \
	fu/fpu/fpnew_opgroup_fmt_slice.sv \
	fu/fpu/fpnew_opgroup_multifmt_slice.sv \
	fu/fpu/fpnew_opgroup_block.sv \
	fu/fpu/fpnew_top_core.sv \
	ozone_pkg.sv \
	fu/fpu/fpnew_top.sv \
	../../../mem_pkg.sv \
	../../../ooo_pkg.sv \
	../../../barrel_shifter.sv \
	../../../tlb.sv \
	../../../lsq.sv \
	../../../l1_cache.sv \
	../../../l2.sv \
	../../../l2_sdram_master.sv \
	../../../memsys.sv \
	Top.sv \
	frontend/ozone_itlb.sv \
	frontend/ozone_decode.sv \
	frontend/ozone_btb.sv \
	frontend/ozone_bpred.sv \
	backend/ozone_dispatch.sv \
	backend/ozone_rob.sv \
	backend/ozone_regstate.sv \
	fu/ozone_adder.sv \
	fu/ozone_logic.sv \
	fu/ozone_agu.sv \
	ozone_cdb.sv

all: obj_dir/VTop

obj_dir/VTop: $(FILES) sim_main.cpp
	$(VERILATOR) $(V_FLAGS) $(FILES) sim_main.cpp -o VTop

decode_tb: obj_dir/Vdecode_tb
obj_dir/Vdecode_tb: tb/tb_ozone_decode.sv frontend/ozone_decode.sv ozone_pkg.sv types.sv
	$(VERILATOR) --binary --timing -Wno-fatal -j \
		--top-module tb_ozone_decode \
		types.sv ozone_pkg.sv frontend/ozone_decode.sv tb/tb_ozone_decode.sv \
		-o Vdecode_tb

decode_tb_cases: obj_dir/Vdecode_tb_cases
obj_dir/Vdecode_tb_cases: tb/tb_ozone_decode_cases.sv frontend/ozone_decode.sv ozone_pkg.sv types.sv
	$(VERILATOR) --binary --timing -Wno-fatal -j \
		--top-module tb_ozone_decode_cases \
		types.sv ozone_pkg.sv frontend/ozone_decode.sv tb/tb_ozone_decode_cases.sv \
		-o Vdecode_tb_cases

DISPATCH_SRCS = ozone_pkg.sv \
                backend/ozone_dispatch.sv \
                backend/ozone_rob.sv \
                backend/ozone_regstate.sv \
                fu/ozone_adder.sv \
                fu/ozone_logic.sv \
                fu/ozone_fpu.sv \
                fu/ozone_agu.sv \
                tb/tb_ozone_dispatch.sv

dispatch_tb: obj_dir/Vdispatch_tb
obj_dir/Vdispatch_tb: $(DISPATCH_SRCS)
	$(VERILATOR) --binary --timing -Wno-fatal -j \
		--top-module tb_ozone_dispatch \
		$(DISPATCH_SRCS) \
		-o Vdispatch_tb

clean:
	rm -rf obj_dir
