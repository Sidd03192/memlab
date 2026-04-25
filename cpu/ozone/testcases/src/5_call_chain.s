	.arch armv8-a
	.text
	.align 2
	.global userspace_entry
userspace_entry:
    // Nested BL/RET chain with stack save/restore.
    movz x0, #5
    bl   func_a
    movz x30, #0
    ret

	.align 2
	.global func_a
func_a:
    sub  sp, sp, #16
    stur x30, [sp, #8]
    stur x19, [sp, #0]

    add  x19, x0, #3
    bl   func_b
    add  x0, x0, x19

    ldur x19, [sp, #0]
    ldur x30, [sp, #8]
    add  sp, sp, #16
    ret

	.align 2
	.global func_b
func_b:
    sub  sp, sp, #16
    stur x30, [sp, #8]

    add  x0, x0, #7

    ldur x30, [sp, #8]
    add  sp, sp, #16
    ret

	.size userspace_entry, .-userspace_entry
	.section .note.GNU-stack,"",@progbits
