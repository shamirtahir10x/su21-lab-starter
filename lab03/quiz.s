.data
g:
  .word 7
h:
  .word 9

.text
main:
    la  s0, g     
    la  s1, h   
    lw  t0, 0(s0)     
    lw  t1, 0(s1)      
    bge t0, t1, iflabel   
    sub t0, t0, t1  
    j exit     
iflabel:
    add t0, t0, t1 
exit:
    sw t0, 0(s1)
    addi a0, x0, 10
    ecall