#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <physical_hex_address> [number_of_64bit_words]\n", argv[0]);
        printf("Example: %s 0x20000000 8\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the requested physical address and word count
    off_t target_addr = strtoull(argv[1], NULL, 16);
    int num_words = (argc >= 3) ? atoi(argv[2]) : 8; // Default to reading 8 words (one 64B cache line)

    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("FATAL: Failed to open /dev/mem. Are you root?");
        return EXIT_FAILURE;
    }

    // Calculate the page-aligned base address and the exact offset
    size_t page_size = sysconf(_SC_PAGE_SIZE);
    off_t page_base = (target_addr / page_size) * page_size;
    off_t page_offset = target_addr - page_base;

    // Map the memory
    void *map_base = mmap(NULL, page_size + (num_words * 8), PROT_READ, MAP_SHARED, fd, page_base);
    if (map_base == MAP_FAILED) {
        perror("FATAL: mmap failed");
        close(fd);
        return EXIT_FAILURE;
    }

    // Create a pointer to the exact offset requested
    volatile uint64_t *target_ptr = (volatile uint64_t *)((uint8_t *)map_base + page_offset);

    printf("\nReading physical SDRAM starting at 0x%08llX:\n", (unsigned long long)target_addr);
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < num_words; i++) {
        printf(" [0x%08llX] : 0x%016llX\n", (unsigned long long)(target_addr + (i * 8)), target_ptr[i]);
    }
    printf("------------------------------------------------------------------\n");

    // Clean up
    munmap(map_base, page_size + (num_words * 8));
    close(fd);
    
    return EXIT_SUCCESS;
}