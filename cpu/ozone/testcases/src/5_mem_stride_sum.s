	.arch armv8-a
	.text
	.align 2
	.global userspace_entry
userspace_entry:
    // Store four values on stack, then load in reverse and sum.
    sub  sp, sp, #48

    movz x1, #10
    movz x2, #20
    movz x3, #30
    movz x4, #40

    stur x1, [sp, #0]
    stur x2, [sp, #8]
    stur x3, [sp, #16]
    stur x4, [sp, #24]

    movz x0, #0
    ldur x5, [sp, #24]
    add  x0, x0, x5
    ldur x5, [sp, #16]
    add  x0, x0, x5
    ldur x5, [sp, #8]
    add  x0, x0, x5
    ldur x5, [sp, #0]
    add  x0, x0, x5

    // Minimal FP activity without memory dependencies.
    fadd d2, d0, d1
    fmul d3, d2, d2
    svc  #0

	.size userspace_entry, .-userspace_entry
	.section .note.GNU-stack,"",@progbits
