VERILATOR = verilator
V_FLAGS = -Wall -Wno-fatal --cc --exe --build -j --top-module Top
FILES = types.sv \
	fu/fpu/fpnew_pkg.sv \
	ozone_pkg.sv \
	Top.sv \
	frontend/ozone_itlb.sv \
	frontend/ozone_decode.sv \
	backend/ozone_dispatch.sv \
	backend/ozone_rob.sv \
	backend/ozone_regstate.sv \
	fu/ozone_adder.sv \
	fu/ozone_logic.sv \
	fu/ozone_fpu.sv \
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
