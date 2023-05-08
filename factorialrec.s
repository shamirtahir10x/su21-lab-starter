.data 
# start data section here
    number: .word 4
    result: .word 0
# end data section here



.align 12

.section ".tohost","aw",@progbits;                            

.align 4; .global tohost; tohost: .dword 0;                     

.align 4; .global fromhost; fromhost: .dword 0; 

.text              
main:
    la t0, number    
    lw a0, 0(t0)   
    jal ra,loop
   
    la a1, result       
    sw a0, 0(a1)      

    addi a1,a0,0         #print
    addi a0,x0,1
    ecall
    addi a1, x0, '\n'   
    addi a0, x0, 11
    ecall

    addi a0,x0, 10
    ecall  
    
    
    
loop:
    addi sp, sp, -8     
    sw ra, 0(sp)
    mv s0, a0          
    sw s0, 4(sp)       
    
    li t5,1
    
    ble a0,t5, cond      
   
               
    addi a0, a0, -1   
    jal ra, loop           
  
    lw a2, 4(sp)       
   
    mul a0, a0, a2       
    j exit              
    
    
cond:
    li a0,1            
    

exit:
    lw ra, 0(sp)    
    addi sp, sp, 8   
    jr ra            

write_tohost:

    li x1, 1

    sw x1, tohost, t5

    j write_tohost

    


