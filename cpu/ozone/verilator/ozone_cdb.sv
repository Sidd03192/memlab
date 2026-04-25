// Common Data Bus arbitration and broadcast: choose one FU result each cycle
// based on ROB age relative to head, then broadcast it to the ROB and all
// snoopers. Only the winning FU is granted in a given cycle.
module ozone_cdb
  import ozone_pkg::*;
#(
    parameter ROB_IDX_BITS = ROB_IDX_WIDTH
)(
    // one held result request from each FU
    input  cdb_broadcast_t              adder_req,
    input  cdb_broadcast_t              logic_req,
    input  cdb_broadcast_t              fpu_req,
    input  cdb_broadcast_t              mem_req,
    input  cdb_broadcast_t              lsq_req,
    input  cdb_broadcast_t              shifter_req,
    // for oldest rob comparison
    input  logic [ROB_IDX_BITS-1:0]     rob_head,

    // one shared broadcast
    output cdb_broadcast_t              cdb_broadcast,
    // grants for what won
    output logic                        adder_granted,
    output logic                        logic_granted,
    output logic                        fpu_granted,
    output logic                        mem_granted,
    output logic                        lsq_granted,
    output logic                        shifter_granted
);

    typedef enum logic [2:0] {
        WIN_NONE    = 3'd0,
        WIN_ADDER   = 3'd1,
        WIN_LOGIC   = 3'd2,
        WIN_FPU     = 3'd3,
        WIN_MEM     = 3'd4,
        WIN_LSQ     = 3'd5,
        WIN_SHIFTER = 3'd6
    } cdb_winner_e;

    logic [ROB_IDX_BITS-1:0] adder_age;
    logic [ROB_IDX_BITS-1:0] logic_age;
    logic [ROB_IDX_BITS-1:0] fpu_age;
    logic [ROB_IDX_BITS-1:0] mem_age;
    logic [ROB_IDX_BITS-1:0] lsq_age;
    logic [ROB_IDX_BITS-1:0] shifter_age;

    function automatic logic [ROB_IDX_BITS-1:0] rob_age(
        input logic [ROB_IDX_BITS-1:0] rob_tag,
        input logic [ROB_IDX_BITS-1:0] head
    );
        rob_age = rob_tag - head;
    endfunction

    assign adder_age   = rob_age(adder_req.rob_tag,   rob_head);
    assign logic_age   = rob_age(logic_req.rob_tag,   rob_head);
    assign fpu_age     = rob_age(fpu_req.rob_tag,     rob_head);
    assign mem_age     = rob_age(mem_req.rob_tag,     rob_head);
    assign lsq_age     = rob_age(lsq_req.rob_tag,     rob_head);
    assign shifter_age = rob_age(shifter_req.rob_tag, rob_head);

    always_comb begin
        cdb_winner_e                winner;
        logic [ROB_IDX_BITS-1:0]    best_age;

        cdb_broadcast   = '0;
        adder_granted   = 1'b0;
        logic_granted   = 1'b0;
        fpu_granted     = 1'b0;
        mem_granted     = 1'b0;
        lsq_granted     = 1'b0;
        shifter_granted = 1'b0;

        winner   = WIN_NONE;
        best_age = '0;

        if (adder_req.valid) begin
            winner   = WIN_ADDER;
            best_age = adder_age;
        end

        if (logic_req.valid &&
            ((winner == WIN_NONE) || (logic_age < best_age))) begin
            winner   = WIN_LOGIC;
            best_age = logic_age;
        end

        if (fpu_req.valid &&
            ((winner == WIN_NONE) || (fpu_age < best_age))) begin
            winner   = WIN_FPU;
            best_age = fpu_age;
        end

        if (mem_req.valid &&
            ((winner == WIN_NONE) || (mem_age < best_age))) begin
            winner   = WIN_MEM;
            best_age = mem_age;
        end

        if (lsq_req.valid &&
            ((winner == WIN_NONE) || (lsq_age < best_age))) begin
            winner   = WIN_LSQ;
            best_age = lsq_age;
        end

        if (shifter_req.valid &&
            ((winner == WIN_NONE) || (shifter_age < best_age))) begin
            winner = WIN_SHIFTER;
        end

        case (winner)
            WIN_ADDER: begin
                cdb_broadcast = adder_req;
                adder_granted = 1'b1;
            end
            WIN_LOGIC: begin
                cdb_broadcast = logic_req;
                logic_granted = 1'b1;
            end
            WIN_FPU: begin
                cdb_broadcast = fpu_req;
                fpu_granted   = 1'b1;
            end
            WIN_MEM: begin
                cdb_broadcast = mem_req;
                mem_granted   = 1'b1;
            end
            WIN_LSQ: begin
                cdb_broadcast = lsq_req;
                lsq_granted   = 1'b1;
            end
            WIN_SHIFTER: begin
                cdb_broadcast   = shifter_req;
                shifter_granted = 1'b1;
            end
            WIN_NONE: begin
                cdb_broadcast = '0;
            end
            default: begin
                cdb_broadcast = '0;
            end
        endcase
    end

endmodule
