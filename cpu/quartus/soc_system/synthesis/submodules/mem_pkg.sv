package mem_pkg;
    // Define the Operations
    typedef enum logic [2:0] {
        OP_MEM_LOAD    = 3'b000,
        OP_MEM_STORE   = 3'b001,
        OP_MEM_RESOLVE = 3'b010,
        OP_TLB_FILL    = 3'b100
    } op_e;

    // Define cache line size, address sizes, etc.
    localparam VADDR_WIDTH = 48;
    localparam PADDR_WIDTH = 30; // From your trace spec
    localparam DATA_WIDTH  = 64;
endpackage
