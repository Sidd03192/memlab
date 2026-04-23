// Shared Ozone definitions: parameters, enums, packed structs, uop formats,
// ROB/RS/LSQ metadata types, exception codes, and common constants.
package ozone_pkg;

// FPU Import
import fpnew_pkg::*;

// -------------------------------------------------------
// Global Parameters
// -------------------------------------------------------
localparam int ROB_IDX_WIDTH = 6;   // 64-entry ROB
localparam int OPCODE_W      = 6;   // 64 possible micro-ops

typedef enum logic [1:0] {
    ROB_TYPE_ALU    = 2'd0,
    ROB_TYPE_BRANCH = 2'd1,
    ROB_TYPE_LOAD   = 2'd2,
    ROB_TYPE_STORE  = 2'd3
} rob_type_e;

typedef enum logic [1:0] {
    DEST_NONE = 2'd0,
    DEST_GPR  = 2'd1,
    DEST_FPR  = 2'd2
} dest_type_e;

// -------------------------------------------------------
// Micro-op Opcodes (for adder FU)
// -------------------------------------------------------
typedef enum logic [OPCODE_W-1:0] {
    // Arithmetic
    OP_ADD      = 6'd0,
    OP_ADDS     = 6'd1,   // ADD with flags
    OP_SUB      = 6'd2,
    OP_SUBS     = 6'd3,   // SUB with flags
    OP_CMP      = 6'd4,   // SUB with flags, no writeback
    OP_CMN      = 6'd5,   // ADD with flags, no writeback
    OP_ADRP_ADD = 6'd6,   // ADD portion of ADRP (Vj = PC & ~0xFFF, Vk = imm << 12)
    // Logic
    OP_AND      = 6'd7,
    // Unconditional branches
    OP_B        = 6'd8,
    OP_BL       = 6'd9,   // branch and link (writes return addr)
    OP_BR       = 6'd10,  // branch register
    OP_BLR      = 6'd11,  // branch-link register
    OP_RET      = 6'd12,  // return (BR X30)
    // Compare-and-branch
    OP_CBZ      = 6'd16,
    OP_CBNZ     = 6'd17,
    // Conditional branch (B.cond) - checks NZCV
    OP_BCOND    = 6'd18,
    OP_ORR      = 6'd19,
    OP_EOR      = 6'd20,
    OP_ORN      = 6'd21,
    OP_MVN      = 6'd22,
    OP_ANDS     = 6'd23,
    OP_TST      = 6'd24,
    OP_LSL      = 6'd25,
    OP_LSR      = 6'd26,
    OP_ASR      = 6'd27
} adder_op_e;


typedef enum logic [3:0] {
    COND_EQ = 4'h0,   // Equal (Z==1)
    COND_NE = 4'h1,   // Not equal (Z==0)
    COND_CS = 4'h2,   // Carry set / unsigned >= (C==1)
    COND_CC = 4'h3,   // Carry clear / unsigned < (C==0)
    COND_MI = 4'h4,   // Minus / negative (N==1)
    COND_PL = 4'h5,   // Plus / positive or zero (N==0)
    COND_VS = 4'h6,   // Overflow (V==1)
    COND_VC = 4'h7,   // No overflow (V==0)
    COND_HI = 4'h8,   // Unsigned > (C==1 && Z==0)
    COND_LS = 4'h9,   // Unsigned <= (C==0 || Z==1)
    COND_GE = 4'hA,   // Signed >= (N==V)
    COND_LT = 4'hB,   // Signed < (N!=V)
    COND_GT = 4'hC,   // Signed > (Z==0 && N==V)
    COND_LE = 4'hD,   // Signed <= (Z==1 || N!=V)
    COND_AL = 4'hE,   // Always
    COND_NV = 4'hF    // Always (alternate encoding)
} cond_code_e;

typedef struct packed {
    logic [63:0]                 value;      // actual architectural state
    logic                        busy;       // if somehing will update this
    logic [ROB_IDX_WIDTH-1:0]    rob_idx;    // rob entry for why its busy (wakeup)
} reg_entry_t;


// Reservation station entry 
typedef struct packed {
    logic                       value;     // computed value (when ready)
    logic [63:0]                Vj;       // value of source 1 (when ready)
    logic [63:0]                Vk;       // value of source 2 (when ready)
    logic [ROB_IDX_WIDTH-1:0]   Qj;       // ROB tag for source 1 (0 = ready)
    logic [ROB_IDX_WIDTH-1:0]   Qk;       // ROB tag for source 2 (0 = ready)
    logic [ROB_IDX_WIDTH-1:0]   rob_tag; // which ROB entry gets the result
    logic                       valid;
    logic [OPCODE_W-1:0]        op; // FU can do multiple micro-ops
    logic [3:0]                 nzcv;      // NZCV flags for this instruction 
    logic                       updates_nzcv; // does this instruction update NZCV?
} rs_entry_t;


typedef struct packed {
    logic [63:0]                value;     // computed value (when ready)
    logic [63:0]                Vj;       // value of source 1 (when ready)
    logic [63:0]                Vk;       // value of source 2 (when ready)
    logic [ROB_IDX_WIDTH-1:0]   Qj;       // ROB tag for source 1 (0 = ready)
    logic [ROB_IDX_WIDTH-1:0]   Qk;       // ROB tag for source 2 (0 = ready)
    logic [ROB_IDX_WIDTH-1:0]   rob_tag; // which ROB entry gets the result
    logic                       valid;
    adder_op_e                  op;
    logic [3:0]                 nzcv;
    cond_code_e                 branch_cond;
    logic                      branch_target;
    logic                      branch_taken;
    logic                      pred_taken;
    logic                      has_rd;
} rs_entry_add_t;

typedef struct packed {
    logic [63:0]                Vj;
    logic [63:0]                Vk;
    logic [ROB_IDX_WIDTH-1:0]   Qj;
    logic [ROB_IDX_WIDTH-1:0]   Qk;
    logic [ROB_IDX_WIDTH-1:0]   rob_tag;
    logic                       valid;
    fpnew_pkg::operation_e      op;
    logic                       op_mod;
    fpnew_pkg::fp_format_e      src_fmt;
    fpnew_pkg::fp_format_e      dst_fmt;
    fpnew_pkg::int_format_e     int_fmt;
    fpnew_pkg::roundmode_e      rnd_mode;
    logic                       vectorial_op;
} rs_entry_fp_t;

typedef struct packed {
    logic                       valid;        // result ready to broadcast
    logic [ROB_IDX_WIDTH-1:0]   rob_tag;      // which ROB entry completed
    logic                       cdb_value_en; // this CDB payload is a normal value wakeup
    logic                       rob_wb_en;    // this CDB payload completes the ROB entry
    logic [63:0]                value;        // computed result 
    
    // flags (for ALU ops like ADDS, SUBS, CMP)
    logic                       update_nzcv;
    logic [3:0]                 nzcv;

    // FPU flags
    fpnew_pkg::status_t         fp_status;    // {NV, DZ, OF, UF, NX}
    
    // branch resolution (adder)
    logic                       br_valid;     // this is a branch result
    logic                       br_taken;
    logic [63:0]                br_target;
    
    // exceptions 
    logic                       exc;
    logic [7:0]                 exc_code;
} cdb_broadcast_t;

typedef struct packed {
    logic                       valid;
    rob_type_e                  inst_type;
    logic [4:0]                 dest_reg;
    dest_type_e                 dest_type;
    logic                       alloc_has_dest;
    logic [63:0]                value;
    logic                       update_nzcv;
    logic [3:0]                 nzcv;
    logic                       ready;
    logic                       exc;
    logic [3:0]                 exc_code;
    logic [63:0]                PC;
    logic                       pred_taken; // set by dispatch
    logic                       br_taken;
    logic [63:0]                br_target;
    logic [63:0]                store_addr;
} rob_entry_t;

// -------------------------------------------------------
// Micro-op type (from types.sv, consolidated here so a
// single "import ozone_pkg::*" covers all shared types)
// -------------------------------------------------------
typedef enum logic [3:0] {
    UOP_AGU        = 4'd0,
    UOP_RD         = 4'd1,
    UOP_WR         = 4'd2,
    UOP_AND        = 4'd3,
    UOP_OR         = 4'd4,
    UOP_ADD        = 4'd5,
    UOP_XOR        = 4'd7,
    UOP_LSL        = 4'd8,
    UOP_LSR        = 4'd9,
    UOP_ASR        = 4'd10,
    UOP_COND_CHECK = 4'd11,
    UOP_NAN_CHECK  = 4'd12,
    UOP_FADD       = 4'd13,
    UOP_FMUL       = 4'd14,
    UOP_ERET       = 4'd15
} uop_type_e;

typedef struct packed {
    uop_type_e uop_type;
    logic [5:0] a, b, c;
    logic neg_c_or_imm;
    logic imm_opnd;
    logic [47:0] pc;
    logic [63:0] imm_bits;
    logic fp_bit;
    logic set_flags;
    logic check_target;
} uop_t;

endpackage
