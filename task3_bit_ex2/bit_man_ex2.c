#include <stdio.h>

#define CSR_VAL 0x8000abcd00001234UL

#define ADDRESS 0x5300f000U

unsigned long int my_csr = CSR_VAL;

int main(void)

{
    // (a) here:
    my_csr |= 0x1UL; // all bits remain the same but the first bit is set

    // (b) here:
    my_csr &= ~(1<<0x2UL); // all bits remain the same but the third bit is zero


    // (c) here:
    my_csr &= 0xffffffffffff00ffUL; 
    my_csr |= 0x000000000000ee00UL; // ee is moved in bit 8 to 15 

    // (d) here:
    // unsigned long int addr_bits = (ADDRESS >> 12) & 0xfffffUL;
    my_csr &= 0xffffffff0000ffffUL ;
    my_csr |= (ADDRESS << 4);


    printf("%lx \n", my_csr);

	return 0;

}