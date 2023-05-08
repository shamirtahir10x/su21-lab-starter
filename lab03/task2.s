.data
num:
  .word 5
.text
main:
  addi sp, sp, -40
  # initialize variables
  li s0, 0   # i = 0
  lw a0, 0(sp)  
  la s1, num 
  lw s1, 0(s1) # num
  li s3, 10    # total iterations
  li t0, 0     # loop counter
  

loop:
  # check if loop condition (i < 10) is met
  bge s0, s3, exe
  # compare function called
  jal comp
  # t1 result for labels is stored in sp
      sw t1, 0(sp)
      lw a3, 0(sp)
    
    addi a0, x0, 1
    addi a1, a3, 0
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline
    
  # increment i
  addi s0, s0, 1

  # advance to the next element of a and b
  addi sp, sp, 4

  # jump to the beginning of the loop
  j loop

comp:
    addi sp, sp, -4
    sw ra, 0(sp) 
    sub t0, s1, s0
    bge t0 ,x0, one  
    
    li t1, 0
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra

one:
    li t1, 1
    jr ra

exe:
    
    addi a0, x0, 10
    ecall # Exit