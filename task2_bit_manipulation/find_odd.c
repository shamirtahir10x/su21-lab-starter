#include <stdio.h>

int find_odd_occuring(int arr[],int n) {
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int arr[] = {12, 12, 14, 90, 14, 14, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int odds = find_odd_occuring(arr,n);

    printf("Odd Numbers : %d\n", odds);
    return 0;
}