	.arch armv8-a
	.text
	.align 2
	.global userspace_entry
userspace_entry:
    // Branch-selected syscall: equal path should invoke bad-syscall handler.
    movz x0, #7
    movz x1, #7
    cmp  x0, x1
    b.ne .Lterminate

    svc  #1
    b    .Ldone

.Lterminate:
    svc  #0

.Ldone:
    movz x30, #0
    ret

	.size userspace_entry, .-userspace_entry
	.section .note.GNU-stack,"",@progbits
