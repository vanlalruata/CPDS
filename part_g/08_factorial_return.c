/* part_g q8: Function to calculate factorial and return the result. */
#include <stdio.h>

long factorial(int n) {
    long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

int main(void) {
    int n;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;
    printf("Factorial = %ld\n", factorial(n));
    return 0;
}
