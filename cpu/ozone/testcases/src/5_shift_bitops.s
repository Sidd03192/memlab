	.arch armv8-a
	.text
	.align 2
	.global userspace_entry
userspace_entry:
    // Shift/bitwise test using immediate-encoded constants plus LSR/ASR.
    movz x0, #0x8000, lsl #16
    movk x0, #0x0001

    lsr  x1, x0, #8
    asr  x2, x0, #4

    eor  x3, x1, x2
    and  x0, x3, #0xffff

    // Minimal FP activity without memory dependencies.
    fadd d2, d0, d1
    fneg d3, d2

    svc  #0

	.size userspace_entry, .-userspace_entry
	.section .note.GNU-stack,"",@progbits
