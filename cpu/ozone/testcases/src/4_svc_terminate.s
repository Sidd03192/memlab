	.arch armv8-a
	.text
	.align	2
.global userspace_entry
userspace_entry:
    movz x0, #0
    svc #0
    movz x30, #0
    ret

	.size	userspace_entry, .-userspace_entry
	.section	.note.GNU-stack,"",@progbits
