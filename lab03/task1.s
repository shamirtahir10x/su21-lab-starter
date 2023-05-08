.data
a:
  .word 7
b:
  .word 0, 0, 0

.text
main:
  # initialize variables
  li s0, 0   # i = 0
  la s1, a   # s1 = &a[0]
  la s2, b   # s2 = &b[0]
  li s3, 3

loop:
  # check if loop condition (i < 3) is met
  bge s0, s3, done

  # calculate b[i] = a + (i * a)
#   slli t0, s0, 2      # t0 = i * 4
  lw t1, 0(s1)        # t1 = a[i]
  lw t2, 0(s1)        # t2 = a[i]
  mul t4, t2, s0      # t2 = a[i] * i
  add t3, t1, t4      # t3 = a[i] + (a[i] * i)
  sw t3, 0(s2)        # b[i] = a[i] + (a[i] * i)

    


  # increment i
  addi s0, s0, 1

  # advance to the next element of a and b
  addi s2, s2, 4

  # jump to the beginning of the loop
  j loop

done:
    li s3, 3
    li s0, 0 
    addi s2, s2, -12
    printloop:

    bge s0, s3, exe
    lw a3, 0(s2)
    addi a0, x0, 1
    addi a1, a3, 0
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    # increment i
    addi s0, s0, 1

    # advance to the next element of a and b
    addi s2, s2, 4

    # jump to the beginning of the loop
    j printloop
exe:
    addi a0, x0, 10
    ecall # Exit
    
