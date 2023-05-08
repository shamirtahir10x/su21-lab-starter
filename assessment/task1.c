#include<stdio.h>

void swap(int *x, int *y) {
    // Add code here
    int temp;
    temp = *x;
    *x = *y;
    *y = temp; 
}

void main(){

    int a = 5,b = 11;

    swap(&a,&b);

    printf("a: %d\n", a);
    printf("b: %d\n", b);

}