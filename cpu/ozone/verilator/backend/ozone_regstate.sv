// Notes for dispatychg
// In the same cycle, dispatch sends read addresses here and immediately gets back status *busy or not )
// Then dispatch immediately will decide vj vk qj qk
// Looks at ROB
// then it will drive wires for updating an entry (marking it busy)
// the above change will then take place on teh next clock cycle start.
//TODO: need to handle writing to x31 (return address register)




module ozone_regstate
  import ozone_pkg::*;
(
  input  logic                      clk,
  input  logic                      rst_n,
  input  logic                      flush,

  // dispatch will give registers it wants info for 
  input  logic [4:0]                src1_addr,      
  input  logic [4:0]                src2_addr,
  input  logic [4:0]                fp_src1_addr,
  input  logic [4:0]                fp_src2_addr,
  // we give output of those registers. -> combinationally 
  output reg_entry_t                src1_status,
  output reg_entry_t                src2_status,
  output reg_entry_t                fp_src1_status,
  output reg_entry_t                fp_src2_status,
  output reg_entry_t                nzcv_status,

  // Dispatch updats (we make a entry )
  input  logic                      disp_wr_en,
  input  logic [4:0]                disp_wr_addr,   // dest register
  input  logic [ROB_IDX_WIDTH-1:0]  disp_rob_idx,   // ROB tail
  input  logic                      disp_fp_wr_en,
  input  logic [4:0]                disp_fp_wr_addr,
  input  logic [ROB_IDX_WIDTH-1:0]  disp_fp_rob_idx,
  // same rob entry can also update nczv
  input  logic                      disp_nzcv_wr_en, // if instruction updates nzcv
  input  logic [ROB_IDX_WIDTH-1:0]  disp_nzcv_rob_idx, // this is what updates nzcv now

  // rob comit
  input  logic                      commit_en, // if rob is even comitting
  input  logic [4:0]                commit_addr,
  input  logic [63:0]               commit_value,
  input  logic [ROB_IDX_WIDTH-1:0]  commit_rob_idx,
  input  logic                      commit_fp_en,
  input  logic [4:0]                commit_fp_addr,
  input  logic [63:0]               commit_fp_value,
  input  logic [ROB_IDX_WIDTH-1:0]  commit_fp_rob_idx,
  input  logic                      commit_nzcv_en,
  input  logic [3:0]                commit_nzcv_value,
  input  logic [ROB_IDX_WIDTH-1:0]  commit_nzcv_rob_idx
);

  // actual regiters 
  reg_entry_t gp_reg [0:30];
  reg_entry_t fp_reg [0:31];
  reg_entry_t nzcv_reg;


  // output status wires (if valid / not)
  always_comb begin
    // TODO: need to handle writing to 31 (return address register) 
    src1_status = gp_reg[src1_addr];
    src2_status = gp_reg[src2_addr];
    fp_src1_status = fp_reg[fp_src1_addr];
    fp_src2_status = fp_reg[fp_src2_addr];
    nzcv_status = nzcv_reg;
  end

 
  // Sequential logic
  // Priority/order within a cycle:
  // 1. reset/flush clears busy bits
  // 2. commit updates the architectural value and clears busy for the
  //    matching retiring ROB writer
  // 3. dispatch marks new destinations busy with new ROB tag
  // Dispatch comes after commit so a same-cycle commit+dispatch to the same
  // architectural destination leaves that entry busy for the newer writer.
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      // Reset architectural state.
      for (int i = 0; i < 31; i++) begin
        gp_reg[i].value   <= 64'b0;
        gp_reg[i].busy    <= 1'b0;
        gp_reg[i].rob_idx <= {ROB_IDX_WIDTH{1'b0}};
      end
      for (int i = 0; i < 32; i++) begin
        fp_reg[i].value   <= 64'b0;
        fp_reg[i].busy    <= 1'b0;
        fp_reg[i].rob_idx <= {ROB_IDX_WIDTH{1'b0}};
      end
      nzcv_reg.value   <= 64'b0;
      nzcv_reg.busy    <= 1'b0;
      nzcv_reg.rob_idx <= {ROB_IDX_WIDTH{1'b0}};
    end else begin
      // --- Commit updates and clears the retiring RST entry ---
      // Always write the committed value unconditionally so the architectural
      // value is correct even if a speculative dispatch overwrote rob_idx.
      // Only use the rob_idx guard for clearing the busy bit: if a newer
      // writer (different rob_idx) is still in flight, leave busy asserted.
      if (commit_en && commit_addr != 5'd31) begin
        gp_reg[commit_addr].value <= commit_value;
        if (gp_reg[commit_addr].rob_idx == commit_rob_idx)
          gp_reg[commit_addr].busy <= 1'b0;
      end
      if (commit_fp_en) begin
        fp_reg[commit_fp_addr].value <= commit_fp_value;
        if (fp_reg[commit_fp_addr].rob_idx == commit_fp_rob_idx)
          fp_reg[commit_fp_addr].busy <= 1'b0;
      end
      if (commit_nzcv_en) begin
        nzcv_reg.value <= {60'b0, commit_nzcv_value};
        if (nzcv_reg.rob_idx == commit_nzcv_rob_idx)
          nzcv_reg.busy <= 1'b0;
      end

      if (!flush) begin
        // dispatch write — only when not flushing so speculative renames
        // don't pollute the rename table after a redirect
        if (disp_wr_en && disp_wr_addr != 5'd31) begin
          gp_reg[disp_wr_addr].busy    <= 1'b1;
          gp_reg[disp_wr_addr].rob_idx <= disp_rob_idx;
        end
        if (disp_fp_wr_en) begin
          fp_reg[disp_fp_wr_addr].busy    <= 1'b1;
          fp_reg[disp_fp_wr_addr].rob_idx <= disp_fp_rob_idx;
        end
        if (disp_nzcv_wr_en) begin
          nzcv_reg.busy    <= 1'b1;
          nzcv_reg.rob_idx <= disp_nzcv_rob_idx;
        end
      end else begin
        // Flush: kill speculative rename state; committed values already
        // written above in the commit block.
        for (int i = 0; i < 31; i++) begin
          gp_reg[i].busy    <= 1'b0;
          gp_reg[i].rob_idx <= {ROB_IDX_WIDTH{1'b0}};
        end
        for (int i = 0; i < 32; i++) begin
          fp_reg[i].busy    <= 1'b0;
          fp_reg[i].rob_idx <= {ROB_IDX_WIDTH{1'b0}};
        end
        nzcv_reg.busy    <= 1'b0;
        nzcv_reg.rob_idx <= {ROB_IDX_WIDTH{1'b0}};
      end
    end
  end

endmodule
