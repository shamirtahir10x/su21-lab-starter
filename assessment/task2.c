#include<stdio.h>
int mystrlen(char* str) {
    int i;
    for ( i = 0 ; str[i] != '\0' ; i++){
        
    }
    return i;
}

void main(){

    char array[100];
   
   printf("Enter elements: ");
   scanf("%s", array);

    int number = mystrlen(array);
    int bytes = number * sizeof(char);

    printf("Bytes: %i\n", bytes);

}