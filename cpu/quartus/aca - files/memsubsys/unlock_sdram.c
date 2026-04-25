#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>

// The page-aligned base address of the Cyclone V System Manager
#define SYSMGR_BASE 0xFFC25000 
// The offset to the FPGAPORTRST register
#define FPGAPORTRST_OFFSET 0x080 
#define STATICCFG_OFFSET 0x05C

int main() {
    printf("Opening /dev/mem to access System Manager...\n");
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("FATAL: Failed to open /dev/mem. Are you running as root?");
        return EXIT_FAILURE;
    }

    // Map exactly one memory page (4KB) starting at the System Manager base
    void *map_base = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, SYSMGR_BASE);
    if (map_base == MAP_FAILED) {
        perror("FATAL: mmap failed");
        close(fd);
        return EXIT_FAILURE;
    }

    // Create a volatile pointer to the exact memory address of the reset register
    volatile uint32_t *reset_reg = (volatile uint32_t *)((uint8_t *)map_base + FPGAPORTRST_OFFSET);
    volatile uint32_t *static_cfg = (volatile uint32_t *)((uint8_t *)map_base + STATICCFG_OFFSET);



    printf("Previous SDRAM Port Reset State: 0x%08X\n", *reset_reg);

    // The Magic Hack: Write 0 to forcefully pull all FPGA-to-SDRAM ports out of hardware reset
    *reset_reg = 0x00000000;

    printf("New SDRAM Port Reset State:      0x%08X\n", *reset_reg);

    printf("Applying Configuration...\n");
    *static_cfg |= 0x1;  // Set bit 0 (APPLYCFG)

    // Clean up
    munmap(map_base, 4096);
    close(fd);

    printf("SUCCESS: SDRAM Ports are now AWAKE and ready for Avalon commands.\n");
    return EXIT_SUCCESS;
}