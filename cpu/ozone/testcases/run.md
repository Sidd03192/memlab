To run 
first go to /verilator
make clean && make all

cd /obj_dir && ./VTop

open new terminal

go to ozone folder. 
do ./ozone ozone-config.json run_verilator testcases/bin/0_add.elf
