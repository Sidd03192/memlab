#include <verilated.h>
#include "VTop.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

#define DRAM_SPAN 0x40000000ULL // 1GB
#define CSR_SPAN  0x00200000ULL // 2MB

// Cache line size must match BLOCK_SIZE parameter in memory_subsystem (64 bytes)
#define CACHE_LINE_BYTES 64
#define CACHE_LINE_WORDS (CACHE_LINE_BYTES / 4)  // 16 x 32-bit words

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    VTop* top = new VTop;
    top->clk = 0;
    top->reset = 1;
    top->eval();

    // 1. Setup Shared Memory
    shm_unlink("/ozone_dram");
    shm_unlink("/ozone_csr");

    int dram_fd = shm_open("/ozone_dram", O_CREAT | O_RDWR, 0666);
    int csr_fd  = shm_open("/ozone_csr",  O_CREAT | O_RDWR, 0666);

    ftruncate(dram_fd, DRAM_SPAN);
    ftruncate(csr_fd,  CSR_SPAN);

    uint8_t* dram_shm = (uint8_t*)mmap(NULL, DRAM_SPAN, PROT_READ | PROT_WRITE, MAP_SHARED, dram_fd, 0);
    uint8_t* csr_shm  = (uint8_t*)mmap(NULL, CSR_SPAN,  PROT_READ | PROT_WRITE, MAP_SHARED, csr_fd, 0);

    memset(csr_shm, 0, CSR_SPAN);

    std::cout << "[Verilator] Shared memory initialized. Waiting for reset..." << std::endl;

    bool last_reset = false;
    bool host_has_asserted_reset = false;
    bool run_complete = false;

    // Data memory response state (1-cycle read latency)
    bool     dmem_resp_pending  = false;
    uint32_t dmem_resp_paddr_r  = 0;
    uint8_t  dmem_resp_data[CACHE_LINE_BYTES] = {};

    while (!Verilated::gotFinish()) {
        uint32_t host_reset = *(volatile uint32_t*)(csr_shm + 0x0);

        if (run_complete) {
            if (host_reset) {
                run_complete = false;
            } else {
                usleep(1000);
                continue;
            }
        }

        // Toggle clock
        top->clk = 0; top->eval();
        top->clk = 1;

        // Sync Reset from SHM (Offset 0x0)
        if (host_reset) {
            host_has_asserted_reset = true;
        }
        top->reset = host_has_asserted_reset ? host_reset : 1;

        if (host_reset && !last_reset) {
            std::cout << "[Verilator] Reset asserted by Host." << std::endl;
        }
        last_reset = host_reset;

        // Instruction fetch memory read (combinational — set before posedge eval)
        if (top->mem_en) {
            if (top->mem_addr < DRAM_SPAN) {
                top->mem_rdata = *(uint32_t*)(&dram_shm[top->mem_addr]);
            }
        }

        // Data memory: deliver pending read response (1-cycle latency)
        top->dmem_req_ready  = 1;
        if (dmem_resp_pending) {
            top->dmem_resp_valid = 1;
            top->dmem_resp_paddr = dmem_resp_paddr_r;
            for (int i = 0; i < CACHE_LINE_WORDS; i++)
                top->dmem_resp_rdata[i] = *(uint32_t*)(&dmem_resp_data[i * 4]);
        } else {
            top->dmem_resp_valid = 0;
        }

        top->eval();

        // After posedge: sample data memory request for next cycle
        dmem_resp_pending = false;
        if (top->dmem_req_valid) {
            uint64_t paddr = (uint64_t)top->dmem_req_addr;
            if (top->dmem_req_is_write) {
                // Write cache line to DRAM (no response needed)
                if (paddr + CACHE_LINE_BYTES <= DRAM_SPAN) {
                    for (int i = 0; i < CACHE_LINE_WORDS; i++)
                        *(uint32_t*)(&dram_shm[paddr + i * 4]) = top->dmem_req_wdata[i];
                }
            } else {
                // Queue read response for next cycle
                if (paddr + CACHE_LINE_BYTES <= DRAM_SPAN)
                    memcpy(dmem_resp_data, &dram_shm[paddr], CACHE_LINE_BYTES);
                else
                    memset(dmem_resp_data, 0, CACHE_LINE_BYTES);
                dmem_resp_paddr_r = (uint32_t)paddr;
                dmem_resp_pending = true;
            }
        }

        // Sync State to SHM
        // Status (Offset 0x8)
        *(volatile uint32_t*)(csr_shm + 0x8) = (uint32_t)top->done;

        // X Registers (Offset 0x100)
        for (int i = 0; i < 31; i++) {
            *(volatile uint64_t*)(csr_shm + 0x100 + (i * 8)) = top->x_regs[i];
        }

        // FP Registers (Offset 0x200)
        for (int i = 0; i < 32; i++) {
            *(volatile uint64_t*)(csr_shm + 0x200 + (i * 8)) = top->fp_regs[i];
        }

        if (top->done) {
            std::cout << "\n[Verilator] Execution complete. Register state:\n";
            std::cout << "=== General Purpose Registers (X0-X30) ===\n";
            for (int i = 0; i < 31; i++) {
                std::cout << "  X" << std::dec << i << "\t= 0x" << std::hex << top->x_regs[i] << std::endl;
            }
            std::cout << "\n=== Floating Point Registers (D0-D31) ===\n";
            for (int i = 0; i < 32; i++) {
                std::cout << "  D" << std::dec << i << "\t= 0x" << std::hex << top->fp_regs[i] << std::endl;
            }
            std::cout << std::endl;
            run_complete = true;
        }

        usleep(100); // Slow down simulation for visibility
    }

    delete top;
    return 0;
}
