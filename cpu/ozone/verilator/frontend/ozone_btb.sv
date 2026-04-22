// Branch Target Buffer: predict next PC targets in fetch and update entries
// when branch instructions resolve at commit.
module ozone_btb #(
    parameter int VADDR_WIDTH = 48,
    parameter int INSTR_OFFSET_WIDTH = 2,
    parameter int BTB_SETS = 8
    // WE ONLY HAVE ONE WAY PER SET
)(
    input  logic clk,
    input  logic rst_n,
    // wires for producing prediction
    input  logic [VADDR_WIDTH-1:0]      pred_pc_in,         // PC of the instruction for which to predict branch location
    output logic [VADDR_WIDTH-1:0]      pred_vaddr_out,     // the VADDR of the predicted branch location
    output logic                        pred_hit_out,       // whether a prediction has been made

    // wires to record branch resolution
    input  logic                        resolve_v_in,       // signal to initiate recording of branch resolution
    input  logic [VADDR_WIDTH-1:0]      resolve_pc_in,      // PC of the branch instruction which just resolved
    input  logic [VADDR_WIDTH-1:0]      resolve_vaddr_in    // virtual address that the resolved branch instruction jumped to

);
    localparam int INDEX_BITS = $clog2(BTB_SETS);
    localparam int TAG_WIDTH = VADDR_WIDTH - INSTR_OFFSET_WIDTH - INDEX_BITS;
    localparam int DATA_WIDTH = VADDR_WIDTH - INSTR_OFFSET_WIDTH;
    
    // state
    logic                   valid [BTB_SETS];
    logic [TAG_WIDTH-1:0]   tags  [BTB_SETS];
    logic [DATA_WIDTH-1:0]   predictions [BTB_SETS];

    // prediction state
    logic [INDEX_BITS-1:0] pred_index;
    // prediction wires
    assign pred_index = pred_pc_in[INDEX_BITS+INSTR_OFFSET_WIDTH-1:INSTR_OFFSET_WIDTH];
    assign pred_vaddr_out = {predictions[pred_index], {INSTR_OFFSET_WIDTH{1'b0}}};
    assign pred_hit_out = valid[pred_index] & (tags[pred_index] == pred_pc_in[VADDR_WIDTH-1 : VADDR_WIDTH-TAG_WIDTH]);

    // resolution state
    logic [INDEX_BITS-1:0] resolve_index;
    // resolution wires
    assign resolve_index = resolve_pc_in[INDEX_BITS+INSTR_OFFSET_WIDTH-1:INSTR_OFFSET_WIDTH];

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            foreach (valid[i]) valid[i] <= 0;
            foreach (tags[i]) tags[i] <= '0;
            foreach (predictions[i]) predictions[i] <= '0;
        end else begin
            // resolution logic
            if (resolve_v_in) begin
                valid[resolve_index] <= 1;
                tags[resolve_index] <= resolve_pc_in[VADDR_WIDTH-1:VADDR_WIDTH-TAG_WIDTH];
                predictions[resolve_index] <= resolve_vaddr_in[VADDR_WIDTH-1:VADDR_WIDTH-DATA_WIDTH];
            end
        end
    end
endmodule
