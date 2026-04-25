module blink (
    input clk,
    output led
);
    reg [26:0] counter;

    always @(posedge clk) counter <= counter + 1'b1;

    assign led = counter[26];
endmodule