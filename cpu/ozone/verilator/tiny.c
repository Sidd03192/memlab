#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

#define CSR_SPAN  0x00200000ULL // 2MB

int main() {
    int csr_fd = shm_open("/ozone_csr",  O_CREAT | O_RDWR, 0666);
    if (csr_fd == -1) {
        perror("shm_open");
        return -1;
    }

    uint8_t* csr_shm  = (uint8_t*)mmap(NULL, CSR_SPAN,  PROT_READ | PROT_WRITE, MAP_SHARED, csr_fd, 0);
    if (csr_shm == NULL) {
        perror("mmap");
        return -1;
    }

    *(volatile uint32_t *)csr_shm = 1;
    usleep(100);
    *(volatile uint32_t *)csr_shm = 0;

    return 0;
}