#define _FILE_OFFSET_BITS 64

#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

#define HW_REGS_BASE      0xFF200000u
#define HW_REGS_SPAN      0x00200000u
#define WRITE_BASE_OFFSET 0x00000000u

#define OFF_WRITE_ADDR    0x0u
#define OFF_WRITE_DATA_LO 0x4u
#define OFF_WRITE_DATA_HI 0x8u
#define OFF_WRITE_GO      0xCu
#define OFF_STATUS0       0x10u

#define STATUS_GO_BIT     0u
#define STATUS_READY_BIT  1u
#define STATUS_BUSY_BIT   2u
#define STATUS_DONE_BIT   3u

#define WAIT_POLL_LIMIT   10000000u

typedef struct {
    int   fd;
    void *hw_base;
    void *write_base;
} fpga_handle_t;

typedef struct {
    int       fd;
    long      page_size;
    uint64_t  mapped_page_base;
    uint8_t  *mapped_page;
    bool      page_valid;
} sdram_reader_t;

static inline void mmio_write(void *base, uint32_t byte_off, uint32_t value)
{
    *((volatile uint32_t *)((uint8_t *)base + byte_off)) = value;
}

static inline uint32_t mmio_read(void *base, uint32_t byte_off)
{
    return *((volatile uint32_t *)((uint8_t *)base + byte_off));
}

static void dump_status(void *write_base)
{
    uint32_t status = mmio_read(write_base, OFF_STATUS0);

    printf("status0 = 0x%08" PRIX32 "\n", status);
    printf("  go_reg = %" PRIu32 "\n", (status >> STATUS_GO_BIT) & 1u);
    printf("  ready  = %" PRIu32 "\n", (status >> STATUS_READY_BIT) & 1u);
    printf("  busy   = %" PRIu32 "\n", (status >> STATUS_BUSY_BIT) & 1u);
    printf("  done   = %" PRIu32 "\n", (status >> STATUS_DONE_BIT) & 1u);
}

static int wait_for_ready(void *write_base)
{
    uint32_t polls = 0;

    while (((mmio_read(write_base, OFF_STATUS0) >> STATUS_READY_BIT) & 1u) == 0u) {
        if (++polls >= WAIT_POLL_LIMIT) {
            fprintf(stderr, "Timed out waiting for ready\n");
            dump_status(write_base);
            return -1;
        }
    }
    return 0;
}

static int wait_for_go_clear(void *write_base)
{
    uint32_t polls = 0;

    while ((mmio_read(write_base, OFF_WRITE_GO) & 1u) != 0u) {
        if (++polls >= WAIT_POLL_LIMIT) {
            fprintf(stderr, "Timed out waiting for go to clear\n");
            dump_status(write_base);
            return -1;
        }
    }
    return 0;
}

static int fpga_open(fpga_handle_t *fpga)
{
    fpga->fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fpga->fd < 0) {
        perror("open /dev/mem");
        return -1;
    }

    fpga->hw_base = mmap(NULL, HW_REGS_SPAN, PROT_READ | PROT_WRITE, MAP_SHARED,
                         fpga->fd, (off_t)HW_REGS_BASE);
    if (fpga->hw_base == MAP_FAILED) {
        perror("mmap control window");
        close(fpga->fd);
        fpga->fd = -1;
        return -1;
    }

    fpga->write_base = (uint8_t *)fpga->hw_base + WRITE_BASE_OFFSET;
    return 0;
}

static void fpga_close(fpga_handle_t *fpga)
{
    if (fpga->hw_base && fpga->hw_base != MAP_FAILED)
        munmap(fpga->hw_base, HW_REGS_SPAN);
    if (fpga->fd >= 0)
        close(fpga->fd);

    fpga->fd = -1;
    fpga->hw_base = NULL;
    fpga->write_base = NULL;
}

static int issue_fpga_write(void *write_base, uint32_t byte_addr, uint64_t value)
{
    if (wait_for_ready(write_base) < 0)
        return -1;

    mmio_write(write_base, OFF_WRITE_ADDR, byte_addr);
    mmio_write(write_base, OFF_WRITE_DATA_LO, (uint32_t)(value & 0xFFFFFFFFu));
    mmio_write(write_base, OFF_WRITE_DATA_HI, (uint32_t)(value >> 32));
    mmio_write(write_base, OFF_WRITE_GO, 1u);

    return wait_for_go_clear(write_base);
}

static int sdram_reader_init(sdram_reader_t *reader, int fd)
{
    reader->fd = fd;
    reader->page_size = sysconf(_SC_PAGESIZE);
    reader->mapped_page_base = 0;
    reader->mapped_page = NULL;
    reader->page_valid = false;

    if (reader->page_size <= 0) {
        perror("sysconf(_SC_PAGESIZE)");
        return -1;
    }

    return 0;
}

static void sdram_reader_close(sdram_reader_t *reader)
{
    if (reader->page_valid && reader->mapped_page != NULL)
        munmap(reader->mapped_page, (size_t)reader->page_size);

    reader->mapped_page = NULL;
    reader->page_valid = false;
}

static int sdram_reader_read64(sdram_reader_t *reader, uint64_t byte_addr, uint64_t *value_out)
{
    uint64_t page_mask = (uint64_t)reader->page_size - 1u;
    uint64_t page_base = byte_addr & ~page_mask;
    size_t page_offset = (size_t)(byte_addr - page_base);

    if (!reader->page_valid || reader->mapped_page_base != page_base) {
        if (reader->page_valid && reader->mapped_page != NULL)
            munmap(reader->mapped_page, (size_t)reader->page_size);

        reader->mapped_page = mmap(NULL, (size_t)reader->page_size, PROT_READ | PROT_WRITE,
                                   MAP_SHARED, reader->fd, (off_t)page_base);
        if (reader->mapped_page == MAP_FAILED) {
            perror("mmap SDRAM page");
            reader->mapped_page = NULL;
            reader->page_valid = false;
            return -1;
        }

        reader->mapped_page_base = page_base;
        reader->page_valid = true;
    }

    *value_out = *((volatile uint64_t *)(reader->mapped_page + page_offset));
    return 0;
}

int main(int argc, char *argv[])
{
    fpga_handle_t fpga = { .fd = -1, .hw_base = NULL, .write_base = NULL };
    sdram_reader_t reader;
    uint32_t start_addr;
    uint32_t count;
    uint32_t index;
    int exit_code = EXIT_FAILURE;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <start_byte_addr_hex> <count>\n", argv[0]);
        return EXIT_FAILURE;
    }

    start_addr = (uint32_t)strtoul(argv[1], NULL, 0);
    count      = (uint32_t)strtoul(argv[2], NULL, 0);

    if ((start_addr & 0x7u) != 0u) {
        fprintf(stderr, "Start address must be 8-byte aligned\n");
        return EXIT_FAILURE;
    }

    if (count == 0u) {
        fprintf(stderr, "Count must be greater than zero\n");
        return EXIT_FAILURE;
    }

    if (fpga_open(&fpga) < 0)
        goto cleanup;

    if (sdram_reader_init(&reader, fpga.fd) < 0)
        goto cleanup;

    printf("Issuing %u FPGA write(s) starting at 0x%08" PRIX32 "\n", count, start_addr);

    for (index = 0; index < count; ++index) {
        uint32_t byte_addr = start_addr + (index * 8u);
        uint64_t expected = 0xA5A5000000000000ULL | (uint64_t)index;
        uint64_t actual = 0;

        if (issue_fpga_write(fpga.write_base, byte_addr, expected) < 0) {
            sdram_reader_close(&reader);
            goto cleanup;
        }

        if (sdram_reader_read64(&reader, byte_addr, &actual) < 0) {
            sdram_reader_close(&reader);
            goto cleanup;
        }

        if (actual != expected) {
            fprintf(stderr,
                    "Mismatch @ 0x%08" PRIX32 ": expected 0x%016" PRIX64
                    ", got 0x%016" PRIX64 "\n",
                    byte_addr, expected, actual);
            sdram_reader_close(&reader);
            goto cleanup;
        }

        printf("  [%-4" PRIu32 "] addr=0x%08" PRIX32 " data=0x%016" PRIX64 " OK\n",
               index, byte_addr, expected);
    }

    sdram_reader_close(&reader);
    printf("PASS: direct FPGA write smoke test completed with zero mismatches.\n");
    exit_code = EXIT_SUCCESS;

cleanup:
    fpga_close(&fpga);
    return exit_code;
}
