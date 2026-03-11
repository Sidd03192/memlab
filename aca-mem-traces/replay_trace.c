#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    OP_MEM_LOAD = 0,
    OP_MEM_STORE = 1,
    OP_MEM_RESOLVE = 2,
    OP_TLB_FILL = 4
} op_e;

typedef struct {
    uint8_t op;
    uint64_t vaddr;
    uint8_t vaddr_valid;
    uint64_t value;
    uint8_t value_valid;
    uint8_t active;
    int access_num;
} PendingOp;

#define MAX_IDS 256
PendingOp pending[MAX_IDS];

typedef struct MemEntry {
    uint64_t addr;
    uint64_t value;
    int last_access_num;
    struct MemEntry *next;
} MemEntry;

#define HASH_SIZE 4096
MemEntry *hashtable[HASH_SIZE];
int total_entries = 0;

uint32_t hash(uint64_t addr) {
    return (uint32_t)(addr % HASH_SIZE);
}

void update_mem(uint64_t addr, uint64_t value, int access_num) {
    uint32_t h = hash(addr);
    MemEntry *e = hashtable[h];
    while (e) {
        if (e->addr == addr) {
            e->value = value;
            e->last_access_num = access_num;
            return;
        }
        e = e->next;
    }
    e = malloc(sizeof(MemEntry));
    e->addr = addr;
    e->value = value;
    e->last_access_num = access_num;
    e->next = hashtable[h];
    hashtable[h] = e;
    total_entries++;
}

int compare_entries(const void *a, const void *b) {
    MemEntry *ea = *(MemEntry **)a;
    MemEntry *eb = *(MemEntry **)b;
    if (ea->addr < eb->addr) return -1;
    if (ea->addr > eb->addr) return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <trace_file> [timestep_limit]\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (!f) { perror("fopen"); return 1; }

    int limit = -1;
    if (argc > 2) limit = atoi(argv[2]);

    uint8_t buf[16];
    int timestep = 0;
    int access_counter = 0;

    while (fread(buf, 16, 1, f) == 1) {
        timestep++;
        if (limit > 0 && timestep > limit) break;

        uint64_t vaddr = 0;
        for (int i = 0; i < 6; i++) vaddr |= ((uint64_t)buf[i] << (i * 8));

        uint8_t byte6 = buf[6];
        uint8_t id = byte6 & 0x0F;
        uint8_t op = (byte6 >> 4) & 0x07;
        uint8_t vaddr_valid = (byte6 >> 7) & 0x01;

        uint64_t value = 0;
        for (int i = 0; i < 8; i++) value |= ((uint64_t)buf[7+i] << (i * 8));
        uint8_t value_valid = buf[15] & 0x01;

        if (op == OP_MEM_LOAD || op == OP_MEM_STORE) {
            int current_access = access_counter++;
            pending[id].op = op;
            pending[id].vaddr = vaddr;
            pending[id].vaddr_valid = vaddr_valid;
            pending[id].value = value;
            pending[id].value_valid = value_valid;
            pending[id].active = 1;
            pending[id].access_num = current_access;

            if (op == OP_MEM_STORE && vaddr_valid && value_valid) {
                update_mem(vaddr, value, current_access);
            }
        } else if (op == OP_MEM_RESOLVE) {
            if (vaddr_valid) {
                pending[id].vaddr = vaddr;
                pending[id].vaddr_valid = 1;
            } else {
                pending[id].value = value;
                pending[id].value_valid = 1;
            }

            if (pending[id].active && pending[id].op == OP_MEM_STORE && 
                pending[id].vaddr_valid && pending[id].value_valid) {
                update_mem(pending[id].vaddr, pending[id].value, pending[id].access_num);
            }
        }
    }

    if (total_entries > 0) {
        MemEntry **sorted_list = malloc(sizeof(MemEntry *) * total_entries);
        int idx = 0;
        for (int i = 0; i < HASH_SIZE; i++) {
            MemEntry *e = hashtable[i];
            while (e) {
                sorted_list[idx++] = e;
                e = e->next;
            }
        }

        qsort(sorted_list, total_entries, sizeof(MemEntry *), compare_entries);

        printf("Memory state (only modified addresses):\n");
        printf("%-14s | %-18s | %-10s\n", "Address", "Value", "Last Acc #");
        printf("------------------------------------------------------------\n");

        for (int i = 0; i < total_entries; i++) {
            printf("0x%012lx | 0x%016lx | %-10d\n", sorted_list[i]->addr, sorted_list[i]->value, sorted_list[i]->last_access_num);
        }
        free(sorted_list);
    } else {
        printf("No memory modifications recorded.\n");
    }

    fclose(f);
    return 0;
}
