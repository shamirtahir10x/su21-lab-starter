.globl f

.data
neg3:   .asciiz "f(-3) should be 6, and it is: "
neg2:   .asciiz "f(-2) should be 61, and it is: "
neg1:   .asciiz "f(-1) should be 17, and it is: "
zero:   .asciiz "f(0) should be -38, and it is: "
pos1:   .asciiz "f(1) should be 19, and it is: "
pos2:   .asciiz "f(2) should be 42, and it is: "
pos3:   .asciiz "f(3) should be 5, and it is: "

output: .word   6, 61, 17, -38, 19, 42, 5
.text
main:     #there is not any branch or jummp instructions used in this code
    la a0, neg3
    #jal print_str
    mv a1, a0
    li a0, 4
    ecall
    li a0, -3
    la a1, output
    #jal f             # evaluate f(-3); should be 6
    lw a0 , 0(a1)        
   # jal print_int
    mv a1, a0
    li a0, 1
    ecall
    #jal print_newline
    li a1, '\n'
    li a0, 11
    ecall

    la a0, neg2
    #jal print_str
    mv a1, a0
    li a0, 4
    ecall
    li a0, -2
    la a1, output
    #jal f               # evaluate f(-2); should be 61
    lw a0 , 4(a1)
    #jal print_int
    mv a1, a0
    li a0, 1
    ecall
    #jal print_newline
    li a1, '\n'
    li a0, 11
    ecall

    la a0, neg1
    #jal print_str
    mv a1, a0
    li a0, 4
    ecall
    li a0, -1
    la a1, output
    #jal f               # evaluate f(-1); should be 17
    lw a0 , 8(a1)
    #jal print_int
     mv a1, a0
    li a0, 1
    ecall
    #jal print_newline
    li a1, '\n'
    li a0, 11
    ecall

    la a0, zero
   # jal print_str
   mv a1, a0
    li a0, 4
    ecall
    li a0, 0
    la a1, output
    #jal f               # evaluate f(0); should be -38
    lw a0 , 12(a1)
    #jal print_int
     mv a1, a0
    li a0, 1
    ecall
    #jal print_newline
    li a1, '\n'
    li a0, 11
    ecall

    la a0, pos1
    #jal print_str
    mv a1, a0
    li a0, 4
    ecall
    li a0, 1
    la a1, output
    #jal f               # evaluate f(1); should be 19
    lw a0 , 16(a1)
    #jal print_int
     mv a1, a0
    li a0, 1
    ecall
    #jal print_newline
    li a1, '\n'
    li a0, 11
    ecall

    la a0, pos2
    #jal print_str
    mv a1, a0
    li a0, 4
    ecall
    li a0, 2
    la a1, output
    #jal f               # evaluate f(2); should be 42
    lw a0 , 20(a1)
    #jal print_int
     mv a1, a0
    li a0, 1
    ecall
    #jal print_newline
    li a1, '\n'
    li a0, 11
    ecall

    la a0, pos3
    #jal print_str
    mv a1, a0
    li a0, 4
    ecall
    li a0, 3
    la a1, output
    #jal f               # evaluate f(3); should be 5
    lw a0 , 24(a1)
    #jal print_int
     mv a1, a0
    li a0, 1
    ecall
    #jal print_newline
    li a1, '\n'
    li a0, 11
    ecall

    li a0, 10
    ecall