`timescale 1ns/1ps

// Thin wrapper around tb_memsys_v2 so MPKI runs have a dedicated top module.
// Compile this top with:
//   -P tb_memsys_v2_mpki.ENABLE_PREFETCH=0   // baseline
//   -P tb_memsys_v2_mpki.ENABLE_PREFETCH=1   // next-line prefetch enabled
//
// Example:
//   iverilog -g2012 -s tb_memsys_v2_mpki \
//     -P tb_memsys_v2_mpki.ENABLE_PREFETCH=1 \
//     -o /tmp/tb_memsys_v2_mpki.out \
//     tb/tb_memsys_v2_mpki.sv tb/tb_memsys_v2.sv memsys.sv l1_cache.sv \
//     l2.sv lsq.sv tlb.sv l2_sdram_master.sv

module tb_memsys_v2_mpki;
    parameter bit ENABLE_PREFETCH = 1'b0;

    tb_memsys_v2 #(
        .ENABLE_PREFETCH(ENABLE_PREFETCH)
    ) inner();
endmodule
