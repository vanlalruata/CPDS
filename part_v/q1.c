/* part_v/q1.c — Factorial using function */
#include <stdio.h>

long factorial(int n) {
    long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

int main(void) {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Factorial of %d = %ld\n", n, factorial(n));
    return 0;
}
