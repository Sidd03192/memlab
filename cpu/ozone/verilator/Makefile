VERILATOR = verilator
V_FLAGS = -Wall --cc --exe --build -j

all: obj_dir/VTop

# obj_dir/VTop: Top.sv sim_main.cpp
# 	$(VERILATOR) $(V_FLAGS) Top.sv sim_main.cpp -o VTop -LDFLAGS "-lrt"

obj_dir/VTop: Top.sv sim_main.cpp
	$(VERILATOR) $(V_FLAGS) Top.sv sim_main.cpp -o VTop

clean:
	rm -rf obj_dir
