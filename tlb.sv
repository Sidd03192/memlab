module tlb (
    input  logic        clk,
    input  logic        rst_n,

    input  logic        is_tlb_fill,
    input  logic [47:0] vaddr,
    input  logic [29:0] paddr,
    input  logic        start,

    output logic        ready, // ready out
    output logic        valid,
    output logic [29:0] result_paddr,
    output logic        panic_tlb_miss
);

    logic [60:0] ways [16];
    logic [15:0] lrumat [16];
    logic [3:0]  way_index;
    logic        ready



    always @(posedge clk or negedge rst_n) begin:

        if (!rst_n) begin
            // clear array and set everything to :(
        end
        
        if (start) begin
            ready <= 0;
            if (is_tlb_fill) begin
                // do this
                // get way to update 

                // update lrumat -------------
                // finding where to put
                for (int i = 0; i < 16; i++) begin
                    if(lrumat[i] == 16'b0) begin
                        way_index <= i;
                        break;
                    end
                end
                
                // update lru
                lrumat[way_index] <= {16{1'b1}};
                for(int j = 0 ; j < 16; j++) begin
                    lrumat[j][way_index] <= 1'b0;
                end
                
                // [v, paddr_tag, vaddr_tag], vaddr contains index and block
                ways[way_index] <= {1'b1, paddr[29:6], vaddr[47:12]};
            end else begin
                // tlb index
                for (int i = 0; i < 16; i ++) begin
                    // Check valid bit and if the virtual addresses match
                    if (ways[i][60] && ways[i][35:0] == vaddr[47:12]) begin
                        // TLB hit
                        // {paddr, block offset}
                        result_paddr <= {ways[i][59:36], vaddr[5:0]};
                        break;
                    end 
                end
            end
            
            valid <= 1;
        end else begin
            ready <= 1;
            valid <= 0;
        end
    end
endmodule



// // // // // // // //     for (int i = 0; i < 16; i ++) begin
//         // whatever you do here\
//         if(lrumat[i] == 16'b0) begin
//             way_index = i;
//             break;
//         end
//     end// // 