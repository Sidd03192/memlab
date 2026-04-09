// Two-level branch predictor: maintain global history + PHT counters for
// taken/not-taken prediction and update on resolved branches.
module ozone_bpred #(
    parameter int VADDR_WIDTH = 48,      // virtual address bits  (mem_pkg)
    parameter int GHR_WIDTH   = 8        // global history register width
)(
    input  logic clk,
    input  logic rst_n,
    // wires for producing prediction
    input   logic [VADDR_WIDTH-1:0]     pred_pc_in,             // the vaddr of the branch instruction to predict taken/not taken
    output  logic                       take_out,               // the prediction: 1 - taken, 0 - not taken
    output  logic [GHR_WIDTH-1:0]       ghr_snapshot_out,       // needed so that upon resolution correct PHT index may be recovered

    // wires to record branch resolution
    input   logic                       resolve_v_in,           // signal to represent when a branch resolution has occurred
    input   logic                       resolve_taken_in,       // whether the resolved instruction was a taken branch
    input   logic [VADDR_WIDTH-1:0]     resolve_pc_in,          // the vaddr of the instruction which has resolved
    input   logic [GHR_WIDTH-1:0]       resolve_ghr_in          // old value of ghr at time of prediction

);
    localparam int PHT_ENTRIES = 1 << GHR_WIDTH;        // 256


    // ================================================================
    // Two-Level Adaptive Predictor (GAp)
    // ================================================================
    logic [GHR_WIDTH-1:0] ghr;
    logic [1:0]           pht [PHT_ENTRIES];   // 2-bit saturating counters
    assign ghr_snapshot_out = ghr;

    logic [GHR_WIDTH-1:0] pht_pred_idx;
    assign pht_pred_idx = ghr ^ pred_pc_in[GHR_WIDTH+1:2];
    assign take_out = pht[pht_pred_idx][1];     // prediction


    logic [GHR_WIDTH-1:0] pht_update_idx;
    assign pht_update_idx = resolve_ghr_in ^ resolve_pc_in[GHR_WIDTH+1:2];
    
    logic [1:0] pht_cur_val;    
    logic [1:0] pht_updated_val_t;
    logic [1:0] pht_updated_val_nt;
    logic [1:0] pht_updated_val;

    assign pht_cur_val = pht[pht_update_idx];
    assign pht_updated_val_t = pht_cur_val == 3 ? 3 : pht_cur_val + 1;
    assign pht_updated_val_nt = pht_cur_val == 0 ? 0 : pht_cur_val - 1;
    assign pht_updated_val = resolve_taken_in ? pht_updated_val_t : pht_updated_val_nt;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // reset
            ghr <= '0;
            foreach (pht[i]) pht[i] <= 2'b01;  // weakly not-taken
        end else begin
            if (resolve_v_in) begin
                // update GHR,
                ghr <= {ghr[GHR_WIDTH-2:0], resolve_taken_in};
                // update PHT
                pht[pht_update_idx] <= pht_updated_val;
            end
        end
    end
endmodule
