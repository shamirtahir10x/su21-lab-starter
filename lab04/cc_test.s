.globl main

.data
n: .word 5
    
.text
main:
    addi sp, sp, -48  
    sw ra, 0(sp)
    sw s0, 4(sp)        

    add s0, x0, x0   
    
    la t0, n
    lw a0, 0(t0)  
    mv t4,a0    
    addi t3, x0, 10     
    
    addi t0, sp, 8  
loop:    

   beq s0, t3, compare   
   
   jal subtraction               
   bge t2, x0, exit
    addi a2, x0, 0
    sw a2, 0(t0)           
                   
    addi a1,a2,0
    addi a0,x0,1
    ecall # Exit
    
    addi a1, x0, '\n'  
    addi a0, x0, 11
    ecall # Exit 
  
    addi t0, t0, 4        
    add sp,sp,t0

   addi s0,s0,1      
   j loop # Exit
   
compare:
    addi a2, x0, 1
    sw a2, 0(t0)           
    
    addi a1,a2,0            
    addi a0,x0,1
    ecall # Exit
    
    addi a1, x0, '\n'   
    addi a0, x0, 11
    ecall # Exit
   
    addi t0, t0, 4         
    addi s0,s0,1       
    j loop # Exit
    
exit:
    lw ra, 0(sp)    
    lw s0, 4(sp)    
    addi sp, sp, 48  

    addi a0, x0, 10
    ecall  # Exit


subtraction:
    sub t2, t4, s0    
    jr ra 