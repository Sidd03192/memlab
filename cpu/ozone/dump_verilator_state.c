#include <fcntl.h>
#include <inttypes.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define DRAM_SPAN 0x40000000ULL
#define CSR_SPAN  0x00200000ULL

#define CSR_X_REGS_BASE 0x100
#define CSR_STATUS      0x8
#define CSR_PC          0x200
#define CSR_PSTATE      0x208
#define CSR_SP_EL0      0x210
#define CSR_SP_EL1      0x218
#define CSR_SPSR_EL1    0x220
#define CSR_ELR_EL1     0x228
#define CSR_ESR_EL1     0x230
#define CSR_TTBR0_EL1   0x238
#define CSR_VBAR_EL1    0x240
#define CSR_ACTLR_EL1   0x248
#define CSR_V_REGS_BASE 0x200

static uint64_t read64(void *base, uint64_t off) {
    return *(volatile uint64_t *)((uint8_t *)base + off);
}

static uint32_t read32(void *base, uint64_t off) {
    return *(volatile uint32_t *)((uint8_t *)base + off);
}

int main(int argc, char **argv) {
    int dram_fd = shm_open("/ozone_dram", O_RDWR, 0666);
    int csr_fd = shm_open("/ozone_csr", O_RDWR, 0666);
    if (dram_fd < 0 || csr_fd < 0) {
        fprintf(stderr, "failed to open Verilator shared memory; is VTop running? dram_fd=%d csr_fd=%d errno=%d\n",
                dram_fd, csr_fd, errno);
        return 1;
    }

    void *dram = mmap(NULL, DRAM_SPAN, PROT_READ, MAP_SHARED, dram_fd, 0);
    void *csr = mmap(NULL, CSR_SPAN, PROT_READ | PROT_WRITE, MAP_SHARED, csr_fd, 0);
    if (dram == MAP_FAILED || csr == MAP_FAILED) {
        fprintf(stderr, "failed to mmap Verilator shared memory\n");
        return 1;
    }

    if (argc == 2 && strcmp(argv[1], "--clear-status") == 0) {
        *(volatile uint32_t *)((uint8_t *)csr + CSR_STATUS) = 0;
        munmap(dram, DRAM_SPAN);
        munmap(csr, CSR_SPAN);
        close(dram_fd);
        close(csr_fd);
        return 0;
    }

    for (int i = 0; i < 31; i++) {
        printf("x%d 0x%016" PRIx64 "\n", i, read64(csr, CSR_X_REGS_BASE + (uint64_t)i * 8));
    }
    for (int i = 0; i < 32; i++) {
        printf("v%d 0x%016" PRIx64 "\n", i, read64(csr, CSR_V_REGS_BASE + (uint64_t)i * 8));
    }

    printf("pc 0x%016" PRIx64 "\n", read64(csr, CSR_PC));
    printf("pstate 0x%016" PRIx64 "\n", (uint64_t)read32(csr, CSR_PSTATE));
    printf("sp_el0 0x%016" PRIx64 "\n", read64(csr, CSR_SP_EL0));
    printf("sp_el1 0x%016" PRIx64 "\n", read64(csr, CSR_SP_EL1));
    printf("spsr_el1 0x%016" PRIx64 "\n", read64(csr, CSR_SPSR_EL1));
    printf("elr_el1 0x%016" PRIx64 "\n", read64(csr, CSR_ELR_EL1));
    printf("esr_el1 0x%016" PRIx64 "\n", read64(csr, CSR_ESR_EL1));
    printf("ttbr0_el1 0x%016" PRIx64 "\n", read64(csr, CSR_TTBR0_EL1));
    printf("vbar_el1 0x%016" PRIx64 "\n", read64(csr, CSR_VBAR_EL1));
    printf("actlr_el1 0x%016" PRIx64 "\n", read64(csr, CSR_ACTLR_EL1));

    for (int i = 1; i < argc; i++) {
        char *end = NULL;
        uint64_t addr = strtoull(argv[i], &end, 0);
        if (end == argv[i] || addr > DRAM_SPAN - 8) {
            printf("mem 0x%016" PRIx64 " <out-of-range>\n", addr);
        } else {
            printf("mem 0x%016" PRIx64 " 0x%016" PRIx64 "\n", addr, read64(dram, addr));
        }
    }

    munmap(dram, DRAM_SPAN);
    munmap(csr, CSR_SPAN);
    close(dram_fd);
    close(csr_fd);
    return 0;
}
