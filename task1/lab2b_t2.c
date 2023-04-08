#include <stdio.h>

static inline int multiply(int x, int y) {
    return x * y;
}

int main() {
    int a = 5, b = 7;
    int result = multiply(a, b);
    printf("Product %d\n", result);
    return 0;
}