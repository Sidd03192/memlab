	.arch armv8-a
	.text
	.align 2
	.global userspace_entry
userspace_entry:
    // Mixed taken/not-taken branch pattern over 1..32.
    // x0 accumulates +odd and -even => expected -16.
    movz x0, #0
    movz x1, #1
    movz x2, #33

.Lloop:
    cmp  x1, x2
    b.eq .Ldone

    and  x3, x1, #1
    cmp  x3, #0
    b.eq .Leven

    add  x0, x0, x1
    b    .Lnext

.Leven:
    sub  x0, x0, x1

.Lnext:
    add  x1, x1, #1
    b    .Lloop

.Ldone:
    // Minimal FP activity without memory dependencies.
    fadd d2, d0, d1
    fsub d3, d2, d0
    svc  #0

	.size userspace_entry, .-userspace_entry
	.section .note.GNU-stack,"",@progbits
