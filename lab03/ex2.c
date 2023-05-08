// int source[] = {3, 1, 4, 1, 5, 9, 0};
// int dest[10];

// int fun(int x) {
// 	return -x * (x + 1);
// }

// int main() {
//     int k;
//     int sum = 0;
//     for (k = 0; source[k] != 0; k++) {
//         dest[k] = fun(source[k]);
//         sum += dest[k];
//     }
//     return sum;
// }
#include <stdio.h>


int sub (int a, int b) {

return a - b;
}
int compare (int a, int b) {

if (sub(a, b) >= 0)

return 1;

else 

return 0;

}

void main () {

int i;

int num = 5;

int array[10];

for ( i=0; i<10; i=i+1){

array[i] = 0;
}

for ( i=0; i<10; i=i+1){

array[i] = compare(num, i);

printf("%d",array[i]);
}
return;

}


