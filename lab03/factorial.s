.globl factorial

.data
n: .word 5

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a0, x0, 1
    addi a1, t0, 0
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    addi sp, sp, -4     # make space on the stack
    sw ra, 0(sp)        # save return address
    li t0, 1            # set t0 to 1 for multiplication
    loop:
        beqz a0, done   # base case, exit loop
        mul t0, t0, a0  # multiply running total by current value of n
        addi a0, a0, -1 # decrement n for the next iteration
        j loop
    done:
        lw ra, 0(sp)    # restore return address
        addi sp, sp, 4  # restore stack pointer
        jr ra