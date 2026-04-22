VERILATOR = verilator
V_FLAGS = -Wall --cc --exe --build -j
FILES = Top.sv frontend/ozone_itlb.sv

all: obj_dir/VTop

obj_dir/VTop: Top.sv sim_main.cpp
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

clean:
	rm -rf obj_dir