	.arch armv8-a
	.text
	.align 2
	.global userspace_entry
userspace_entry:
    // Trigger a store page fault by writing to VA 0x0 (unmapped in EL0).
    movz x1, #0

    movz x0, #0x5a
    stur x0, [x1, #0]

    // Should not be reached.
    movz x30, #0
    ret

	.size userspace_entry, .-userspace_entry
	.section .note.GNU-stack,"",@progbits
