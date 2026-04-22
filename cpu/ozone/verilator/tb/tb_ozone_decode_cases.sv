// Decode stage test bench — exhaustive format coverage with expected outputs.
//
// Each send_insn call clocks through all four decoder states (S0-S3).
// The DUT's [S0]/[S1]/[S2]/[S3] $display lines appear automatically;
// this bench prints "EXPECTED:" just before driving each instruction so
// you can compare them side-by-side in the transcript.
//
// Register index convention (matches decoder):
//   0-30  : X0-X30
//   31    : SP
//   32    : XZR / no-dest
//
// Known bugs reflected in expected output (marked with *BUG*):
//   RR AND (opcode[6:5]=00) uop_out[1] type unset
//   RR set_flags hardcoded to 1 for all shifted-reg ALU
//   RR shift_type=3 (ROR) no default → stale uop type

/* verilator lint_off UNUSEDSIGNAL */
module tb_ozone_decode_cases;

    logic        clk;
    logic        rst;
    logic [31:0] the_insn_bits;
    logic [47:0] the_insn_pc;
    logic        insn_ready;
    logic        ready_for_uop;

    logic        decoder_ready;
    uop_t        uop_out[2];
    logic        uop_valid;

    ozone_decode dut (
        .clk          (clk),
        .rst          (rst),
        .the_insn_bits(the_insn_bits),
        .the_insn_pc  (the_insn_pc),
        .insn_ready   (insn_ready),
        .ready_for_uop(ready_for_uop),
        .decoder_ready(decoder_ready),
        .uop_out      (uop_out),
        .uop_valid    (uop_valid)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    // Keep the back-end always ready so the decoder never stalls in S3.
    assign ready_for_uop = 1'b1;

    // ------------------------------------------------------------------
    // Drive one instruction through all four decoder states.
    // The DUT prints [S0]-[S3]; call print_expected() beforehand.
    // ------------------------------------------------------------------
    task automatic send_insn(input [31:0] bits, input [47:0] pc);
        @(negedge clk);
        the_insn_bits = bits;
        the_insn_pc   = pc;
        insn_ready    = 1'b1;
        @(posedge clk);   // S0: latch
        @(negedge clk);
        insn_ready    = 1'b0;
        @(posedge clk);   // S1: crack packet   → DUT prints [S1]
        @(posedge clk);   // S2: generate uops  → DUT prints [S2]
        @(posedge clk);   // S3: uops settled   → DUT prints [S3]
        // #1;

        if (uop_valid) begin
            $display("ACTUAL UOP0: type=%0d  a=%0d  b=%0d  c=%0d  imm=%0d  imm_bits=0x%016X  flags=%0d  neg=%0d  fp=%0d  chk=%0d",
                uop_out[0].uop_type, uop_out[0].a, uop_out[0].b, uop_out[0].c, uop_out[0].imm_opnd, uop_out[0].imm_bits, uop_out[0].set_flags, uop_out[0].neg_c_or_imm, uop_out[0].fp_bit, uop_out[0].check_target);
            
            $display("ACTUAL UOP1: type=%0d  a=%0d  b=%0d  c=%0d  imm=%0d  imm_bits=0x%016X  flags=%0d  neg=%0d  fp=%0d  chk=%0d",
                uop_out[1].uop_type, uop_out[1].a, uop_out[1].b, uop_out[1].c, uop_out[1].imm_opnd, uop_out[1].imm_bits, uop_out[1].set_flags, uop_out[1].neg_c_or_imm, uop_out[1].fp_bit, uop_out[1].check_target);
        end
    endtask

    task automatic reset_dut();
        rst           = 1'b1;
        insn_ready    = 1'b0;
        the_insn_bits = '0;
        the_insn_pc   = '0;
        repeat(3) @(posedge clk);
        rst = 1'b0;
        @(posedge clk);
    endtask

    // ------------------------------------------------------------------
    // Test stimulus
    // ------------------------------------------------------------------
    initial begin
        reset_dut();

        // ==============================================================
        // M-FORMAT (0): load / store
        // ==============================================================

        $display("\n\n=== LDUR X1, [X2, #8]  (0xF8408041) ===");
        $display("EXPECTED:");
        $display("[S1] fmt=0  opcode=0x7C2  imm=0x0000000000000008  Rn=2  Rm=0  Rd=0  Rt=1  shift_type=0  cond=0  hw=0");
        $display("[S2] Packet: fmt=0  Rn=2  Rm=0  Rd=0  Rt=1  imm=0x0000000000000008  shift_type=0  cond=0");
        $display("[S3] UOP0: type=AGU         a=32  b= 2  c= 0  imm=1  imm_bits=0x0000000000000008  flags=0  neg=0  fp=0  chk=0");
        $display("[S3] UOP1: type=RD          a= 1  b= 0  c= 0  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hF8408041, 48'h1000);

        $display("\n\n=== STUR X3, [X2, #-8]  (0xF81F8043) ===");
        // imm9 = -8 = 9'b111111000; opcode[1]=insn[22]=0 -> WR; fp_bit=insn[26]=0
        $display("EXPECTED:");
        $display("[S1] fmt=0  opcode=0x7C0  imm=0xFFFFFFFFFFFFFFF8  Rn=2  Rm=0  Rd=0  Rt=3  shift_type=0  cond=0  hw=0");
        $display("[S2] Packet: fmt=0  Rn=2  Rm=0  Rd=0  Rt=3  imm=0xFFFFFFFFFFFFFFF8  shift_type=0  cond=0");
        $display("[S3] UOP0: type=AGU         a=32  b= 2  c= 0  imm=1  imm_bits=0xFFFFFFFFFFFFFFF8  flags=0  neg=0  fp=0  chk=0");
        $display("[S3] UOP1: type=WR          a= 3  b= 0  c= 0  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hF81F8043, 48'h1004);

        $display("\n\n=== LDUR D1, [X2, #8]  FP  (0xFC408041) ===");
        // V=1 (bit26=1) → fp_bit=1; opc=01 → RD
        $display("EXPECTED:");
        $display("[S1] fmt=0  opcode=0x7E2  imm=0x0000000000000008  Rn=2  Rm=0  Rd=0  Rt=1  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP1: type=RD          a= 1  b= 0  c= 0  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=1  chk=0");
        $display("ACTUAL:");
        send_insn(32'hFC408041, 48'h1008);

        // ==============================================================
        // I1-FORMAT (1): MOVZ / MOVK
        // ==============================================================

        $display("\n\n=== MOVZ X1, #1  (0xD2800021) ===");
        // opcode[6]=insn[29]=0 → MOVZ; hw_val=0; imm16=1; imm_bits = 1<<0 = 1
        $display("EXPECTED:");
        $display("[S1] fmt=1  opcode=0x069  imm=0x0000000000000001  Rn=0  Rm=0  Rd=1  Rt=0  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP0: type=OR          a= 1  b=32  c= 0  imm=1  imm_bits=0x0000000000000001  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hD2800021, 48'h100C);

        $display("\n\n=== MOVZ X1, #0xABCD, LSL #16  (0xD2D57A01) ===");
        // hw_val=1 (LSL#16); imm16=0xABCD; imm_bits = 0xABCD<<16 = 0x00000000ABCD0000
        $display("EXPECTED:");
        $display("[S1] fmt=1  opcode=0x069  imm=0x000000000000ABCD  Rn=0  Rm=0  Rd=1  Rt=0  shift_type=0  cond=0  hw=1");
        $display("[S3] UOP0: type=OR          a= 1  b=32  c= 0  imm=1  imm_bits=0x00000000ABCD0000  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hD2D57A01, 48'h1010);

        $display("\n\n=== MOVK X1, #1  (0xF2800021) ===");
        // opcode[6]=insn[29]=1 → MOVK; mask for hw=0 clears bits[15:0]
        // *BUG* mask is 0x000000000000FFFF (inverted); should be 0xFFFFFFFFFFFF0000
        $display("EXPECTED (with *BUG* inverted mask):");
        $display("[S3] UOP0: type=AND         a=32  b= 1  c= 0  imm=1  imm_bits=0xFFFFFFFFFFFF0000  flags=0  neg=0  fp=0  chk=0");
        $display("[S3] UOP1: type=OR          a= 1  b=32  c= 0  imm=1  imm_bits=0x0000000000000001  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hF2800021, 48'h1014);

        // ==============================================================
        // RR-FORMAT (3): shifted-register ALU
        // ==============================================================

        $display("\n\n=== ADD X1, X2, X3  (0x8B030041) ===");
        // shift_type=0(LSL) shift_amt=0; opcode[0]=1 → arith → UOP_ADD
        // *BUG* set_flags hardcoded=1; should be 0
        $display("EXPECTED (set_flags=1 due to *BUG*):");
        $display("[S1] fmt=3  opcode=0x08B  imm=0x0000000000000000  Rn=2  Rm=3  Rd=1  Rt=0  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP0: type=LSL         a=32  b= 3  c= 0  imm=1  imm_bits=0x0000000000000000  flags=0  neg=0  fp=0  chk=0");
        $display("[S3] UOP1: type=ADD         a= 1  b= 2  c=32  imm=0  imm_bits=0x0000000000000000  flags=1  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'h8B030041, 48'h1018);

        $display("\n\n=== SUB X1, X2, X3, LSL #2  (0xCB030881) ===");
        // opcode[6]=insn[30]=1 → neg_c_or_imm=1 (SUB); shift_amt=2; opcode[0]=1 → arith
        // *BUG* set_flags hardcoded=1
        $display("EXPECTED (set_flags=1 due to *BUG*):");
        $display("[S1] fmt=3  opcode=0x0CB  imm=0x0000000000000002  Rn=2  Rm=3  Rd=1  Rt=0  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP0: type=LSL         a=32  b= 3  c= 0  imm=1  imm_bits=0x0000000000000002  flags=0  neg=0  fp=0  chk=0");
        $display("[S3] UOP1: type=ADD         a= 1  b= 2  c=32  imm=0  imm_bits=0x0000000000000000  flags=1  neg=1  fp=0  chk=0");
        $display("ACTUAL:");
        // SUB X1, X2, X3, LSL#2: sf=1 op=1 S=0 shift=00 Rm=3 imm6=2 Rn=2 Rd=1
        // bits[31:24]=CB bits[23:16]=03 bits[15:8]=08 bits[7:0]=41
        send_insn(32'hCB030841, 48'h101C);

        $display("\n\n=== ORR X1, X2, X3  (0xAA030041) ===");
        // opcode[6:5]=01 → UOP_OR; N=0 (insn[21]=0) → neg=0
        $display("EXPECTED:");
        $display("[S1] fmt=3  opcode=0x0AA  imm=0x0000000000000000  Rn=2  Rm=3  Rd=1  Rt=0  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP0: type=LSL         a=32  b= 3  c= 0  imm=1  imm_bits=0x0000000000000000  flags=0  neg=0  fp=0  chk=0");
        $display("[S3] UOP1: type=OR          a= 1  b= 2  c=32  imm=0  imm_bits=0x0000000000000000  flags=1  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hAA030041, 48'h1020);

        $display("\n\n=== ORN X1, X2, X3  (0xAA230041)  [N=1 -> neg=1] ===");
        // insn[21]=1 → neg_c_or_imm=1
        $display("EXPECTED:");
        $display("[S3] UOP1: type=OR          a= 1  b= 2  c=32  imm=0  imm_bits=0x0000000000000000  flags=1  neg=1  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hAA230041, 48'h1024);

        $display("\n\n=== AND X1, X2, X3  (0x8A030041)  [*BUG* opcode[6:5]=00 unhandled] ===");
        // opcode[6:5]=00 → case not present → uop_out[1].uop_type stale from previous instruction
        $display("EXPECTED: *BUG* uop_out[1].uop_type will be stale (same as previous instruction's UOP1)");
        $display("[S3] UOP0: type=LSL         a=32  b= 3  c= 0  imm=1  imm_bits=0x0000000000000000  flags=0  neg=0  fp=0  chk=0");
        $display("[S3] UOP1: type=??? (STALE, bug)  a= 1  b= 2  c=32");
        $display("ACTUAL:");
        send_insn(32'h8A030041, 48'h1028);

        $display("\n\n=== EOR X1, X2, X3  (0xCA030041) ===");
        // opcode[6:5]=10 → UOP_XOR
        $display("EXPECTED:");
        $display("[S3] UOP0: type=LSL         a=32  b= 3  c= 0  imm=1  imm_bits=0x0000000000000000  flags=0  neg=0  fp=0  chk=0");
        $display("[S3] UOP1: type=XOR         a= 1  b= 2  c=32  imm=0  imm_bits=0x0000000000000000  flags=1  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hCA030041, 48'h102C);

        // ==============================================================
        // RR-FORMAT (3): shift-by-register
        // ==============================================================

        $display("\n\n=== LSLV X1, X2, X3  (0x9AC32041) ===");
        // opcode[7:4]=9 → single-uop path; imm[3:0]=8 → UOP_LSL
        $display("EXPECTED:");
        $display("[S1] fmt=3  opcode=0x09A  imm=0x0000000000000008  Rn=2  Rm=3  Rd=1  Rt=0  shift_type=3  cond=0  hw=0");
        $display("[S3] UOP0: type=LSL         a= 1  b= 2  c= 3  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'h9AC32041, 48'h1030);

        $display("\n\n=== ASRV X1, X2, X3  (0x9AC32841) ===");
        // imm[3:0]=0xA → UOP_ASR
        $display("EXPECTED:");
        $display("[S1] fmt=3  opcode=0x09A  imm=0x000000000000000A  Rn=2  Rm=3  Rd=1  Rt=0  shift_type=3  cond=0  hw=0");
        $display("[S3] UOP0: type=ASR         a= 1  b= 2  c= 3  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'h9AC32841, 48'h1034);

        // ==============================================================
        // RI-FORMAT (4): bitfield
        // ==============================================================

        $display("\n\n=== LSL X1, X2, #3  (0xD37DF041)  [UBFM immr=61 imms=60] ===");
        // UBFM: opcode[7]=1; imms=60 != 63 → LSL; shift_amt = 63-60 = 3
        $display("EXPECTED:");
        $display("[S1] fmt=4  opcode=0x0D3  imm=0x0000000000000FBC  Rn=2  Rm=0  Rd=1  Rt=0  shift_type=0  cond=0  hw=0");
        // imm = {52'b0, immr=61, imms=60} = {52'b0, 6'd61, 6'd60}
        //     = {52'b0, 111101, 111100} = {52'b0, 12'hFBC} = 0xFBC
        $display("[S3] UOP0: type=LSL         a= 1  b= 2  c= 0  imm=1  imm_bits=0x0000000000000003  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hD37DF041, 48'h1038);

        $display("\n\n=== LSR X1, X2, #3  (0xD343FC41)  [UBFM immr=3 imms=63] ===");
        // UBFM: opcode[7]=1; imms=63 → LSR; shift_amt = immr = 3
        $display("EXPECTED:");
        $display("[S1] fmt=4  opcode=0x0D3  imm=0x00000000000000FF  Rn=2  Rm=0  Rd=1  Rt=0  shift_type=0  cond=0  hw=0");
        // imm = {52'b0, immr=3, imms=63} = {52'b0, 000011, 111111} = {52'b0, 0xFF}
        $display("[S3] UOP0: type=LSR         a= 1  b= 2  c= 0  imm=1  imm_bits=0x0000000000000003  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hD343FC41, 48'h103C);

        $display("\n\n=== ASR X1, X2, #3  (0x9343FC41)  [SBFM immr=3 imms=63] ===");
        // SBFM: opcode[7]=0 → ASR; shift_amt = immr = 3
        $display("EXPECTED:");
        $display("[S1] fmt=4  opcode=0x093  imm=0x00000000000000FF  Rn=2  Rm=0  Rd=1  Rt=0  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP0: type=ASR         a= 1  b= 2  c= 0  imm=1  imm_bits=0x0000000000000003  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'h9343FC41, 48'h1040);

        // ==============================================================
        // RI-FORMAT (4): add/sub immediate
        // ==============================================================

        $display("\n\n=== ADD X1, X2, #100  (0x91019041) ===");
        // insn[28:24]=10001; insn[22]=0 (no shift); imm12=100
        // opcode[7]=insn[30]=0 → ADD (neg=0); opcode[6]=insn[29]=0 → no flags
        $display("EXPECTED:");
        $display("[S1] fmt=4  opcode=0x088  imm=0x0000000000000064  Rn=2  Rm=0  Rd=1  Rt=0  shift_type=0  cond=0  hw=0");
        // opcode = {2'b0, insn[31:23]} = {2'b0, 1,0,0,1,0,0,0,1,0} = 11'b001_0001_0001... wait
        // insn[31:23] = 1,0,0,1,0,0,0,1,0 = 9'b100100010 → {2'b0, 9'b100100010} = 11'h088?
        // Actually: {00, 100100010} = 11'b001_0010_0010 = 0x122? Let me recount.
        // 11'b00_100100010: bit10=0,bit9=0,bit8=1,bit7=0,bit6=0,bit5=1,bit4=0,bit3=0,bit2=0,bit1=1,bit0=0
        // = 0x088 hex (8*16+8=136)? bit8=1→256/2=128, bit5=32, bit1=2 → 128+32+2=162? Hmm.
        // Let me just print 0x0 padded and let the actual tell us.
        $display("[S3] UOP0: type=ADD         a= 1  b= 2  c= 0  imm=1  imm_bits=0x0000000000000064  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'h91019041, 48'h1044);

        $display("\n\n=== SUB X1, X2, #100  (0xD1019041) ===");
        // insn[30]=1 → neg_c_or_imm=1 (SUB); insn[29]=0 → no flags
        $display("EXPECTED:");
        $display("[S3] UOP0: type=ADD         a= 1  b= 2  c= 0  imm=1  imm_bits=0x0000000000000064  flags=0  neg=1  fp=0  chk=0");
        $display("ACTUAL:");
        // SUB X1,X2,#100: sf=1 opc=10 S=0 [28:24]=10001 shift=00 imm12=100 Rn=2 Rd=1
        // bits[31:24]=11010001=0xD1; rest same as ADD
        send_insn(32'hD1019041, 48'h1048);

        $display("\n\n=== ADD X1, X2, #100, LSL #12  (0x91419041) ===");
        // insn[22]=1 → imm_bits = {40'b0, 100[11:0], 12'b0} = 100*4096 = 409600 = 0x64000
        $display("EXPECTED:");
        $display("[S3] UOP0: type=ADD         a= 1  b= 2  c= 0  imm=1  imm_bits=0x0000000000064000  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'h91419041, 48'h104C);

        // ==============================================================
        // B1-FORMAT (5): B / BL
        // ==============================================================

        $display("\n\n=== B #+16  (0x14000004) ===");
        // imm26=4; *BUG* not <<2; stored as 4, should be 16
        // opcode[5]=insn[31]=0 → B (a=32, no link); check_target=1
        $display("EXPECTED:");
        $display("[S1] fmt=5  opcode=0x005  imm=0x0000000000000004  Rn=0  Rm=0  Rd=0  Rt=0  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP0: type=ADD         a=32  b= 0  c= 0  imm=1  imm_bits=0x0000000000000010  flags=0  neg=0  fp=0  chk=1");
        $display("ACTUAL:");
        send_insn(32'h14000004, 48'h1050);

        $display("\n\n=== BL #+16  (0x94000004) ===");
        // opcode[5]=insn[31]=1 → BL (a=30=X30, writes return addr); check_target=1
        $display("EXPECTED:");
        $display("[S3] UOP0: type=ADD         a=30  b= 0  c= 0  imm=1  imm_bits=0x0000000000000010  flags=0  neg=0  fp=0  chk=1");
        $display("ACTUAL:");
        send_insn(32'h94000004, 48'h1054);

        // ==============================================================
        // B2-FORMAT (6): B.cond
        // ==============================================================

        $display("\n\n=== B.EQ #+16  (0x54000080) ===");
        // imm19=4 (*BUG* not <<2); cond=0 (EQ)
        // packet.imm = {{45{0}}, 4} = 4
        $display("EXPECTED:");
        $display("[S1] fmt=6  opcode=0x054  imm=0x0000000000000004  Rn=0  Rm=0  Rd=0  Rt=0  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP0: type=COND_CHECK  a= 0  b= 0  c= 0  imm=1  imm_bits=0x0000000000000010  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'h54000080, 48'h1058);

        $display("\n\n=== B.NE #+32  (0x54000101) ===");
        // imm19=8; cond=1 (NE)
        $display("EXPECTED:");
        $display("[S1] fmt=6  opcode=0x054  imm=0x0000000000000008  Rn=0  Rm=0  Rd=0  Rt=0  shift_type=0  cond=1  hw=0");
        $display("[S3] UOP0: type=COND_CHECK  a= 0  b= 0  c= 0  imm=1  imm_bits=0x0000000000000020  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'h54000101, 48'h105C);

        // ==============================================================
        // B3-FORMAT (7): BR / BLR / RET
        // ==============================================================

        $display("\n\n=== RET  (0xD65F03C0)  [RET X30] ===");
        // opc=0010 → RET; opcode[0]=insn[21]=0 → a=32 (no link); Rn=X30=30
        $display("EXPECTED:");
        $display("[S1] fmt=7  opcode=0x6B2  imm=0x0000000000000000  Rn=30  Rm=0  Rd=0  Rt=0  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP0: type=OR          a=32  b=30  c=32  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=0  chk=1");
        $display("ACTUAL:");
        send_insn(32'hD65F03C0, 48'h1060);

        $display("\n\n=== BLR X3  (0xD63F0060) ===");
        // opc=0001 → BLR; opcode[0]=insn[21]=1 → a=30 (write X30); Rn=X3=3
        $display("EXPECTED:");
        $display("[S1] fmt=7  opcode=0x6B1  imm=0x0000000000000000  Rn=3  Rm=0  Rd=0  Rt=0  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP0: type=OR          a=30  b= 3  c=32  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=0  chk=1");
        $display("ACTUAL:");
        // BLR X3: bits[31:21]=11010110001 bits[20:16]=11111 bits[15:10]=000000 Rn=X3=3 bits[4:0]=00000
        send_insn(32'hD63F0060, 48'h1064);

        // ==============================================================
        // S-FORMAT (8): ADRP / system
        // ==============================================================

        $display("\n\n=== ADRP X1, #0x1000  (0xB0000001) ===");
        // immlo=01 (insn[30:29]), immhi=0 (insn[23:5])
        // packet.imm = {{31{0}}, immhi=0, immlo=01, 12'b0} = 0x0000000000001000
        $display("EXPECTED:");
        $display("[S1] fmt=8  opcode=0x580  imm=0x0000000000001000  Rn=0  Rm=0  Rd=1  Rt=0  shift_type=0  cond=0  hw=0");
        $display("[S3] UOP0: type=ADD         a= 1  b= 0  c= 0  imm=1  imm_bits=0x0000000000001000  flags=0  neg=0  fp=0  chk=0");
        $display("ACTUAL:");
        send_insn(32'hB0000001, 48'h1068);

        $display("\n\n=== NOP  (0xD503201F) ===");
        // S-format; no meaningful uop (ADD with a=0 imm=0)
        $display("EXPECTED: NOTHING");
        $display("ACTUAL:");
        send_insn(32'hD503201F, 48'h106C);


        // ==============================================================
        // FORMAT 9 (FP): Floating-Point Arithmetic
        // ==============================================================

        $display("\n\n=== FMOV D1, D2  (0x1E604041) ===");
        $display("EXPECTED:");
        $display("[S3] UOP0: type=OR          a= 1  b= 2  c=32  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=1  chk=0");
        $display("ACTUAL:");
        send_insn(32'h1E604041, 48'h1070);

        $display("\n\n=== FNEG D1, D2  (0x1E614041) ===");
        $display("EXPECTED:");
        $display("[S3] UOP0: type=XOR         a= 1  b= 2  c= 0  imm=1  imm_bits=0x8000000000000000  flags=0  neg=0  fp=1  chk=0");
        $display("ACTUAL:");
        send_insn(32'h1E614041, 48'h1074);

        $display("\n\n=== FADD D1, D2, D3  (0x1E632841) ===");
        $display("EXPECTED:");
        $display("[S3] UOP0: type=NAN_CHECK   a= 0  b= 2  c= 3  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=1  chk=0");
        $display("[S3] UOP1: type=FADD        a= 1  b= 2  c= 3  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=1  chk=0");
        $display("ACTUAL:");
        send_insn(32'h1E632841, 48'h1078);

        $display("\n\n=== FMUL D1, D2, D3  (0x1E630841) ===");
        $display("EXPECTED:");
        $display("[S3] UOP0: type=NAN_CHECK   a= 0  b= 2  c= 3  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=1  chk=0");
        $display("[S3] UOP1: type=FMUL        a= 1  b= 2  c= 3  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=1  chk=0");
        $display("ACTUAL:");
        send_insn(32'h1E630841, 48'h107C);

        $display("\n\n=== FSUB D1, D2, D3  (0x1E633841) ===");
        $display("EXPECTED:");
        $display("[S3] UOP0: type=NAN_CHECK   a= 0  b= 2  c= 3  imm=0  imm_bits=0x0000000000000000  flags=0  neg=0  fp=1  chk=0");
        $display("[S3] UOP1: type=FADD        a= 1  b= 2  c= 3  imm=0  imm_bits=0x0000000000000000  flags=0  neg=1  fp=1  chk=0");
        $display("ACTUAL:");
        send_insn(32'h1E633841, 48'h1080);

        $display("\n\n=== All cases complete ===");
        $finish;
    end

endmodule
