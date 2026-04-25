	.arch armv8-a
	.text
	.align 2
	.global userspace_entry
userspace_entry:
    // Iterative GCD via subtraction-based Euclidean algorithm.
    // Computes GCD(252, 105); expected result in x0: 21.
    // Exercises loops, comparisons, and mixed taken/not-taken branches.
    movz x0, #252
    movz x1, #105

.Lgcd_loop:
    cmp  x0, x1
    b.eq .Lgcd_done
    b.lt .Lgcd_b_larger
    sub  x0, x0, x1
    b    .Lgcd_loop

.Lgcd_b_larger:
    sub  x1, x1, x0
    b    .Lgcd_loop

.Lgcd_done:
    // x0 = 21
    svc  #0

	.size userspace_entry, .-userspace_entry
	.section .note.GNU-stack,"",@progbits
