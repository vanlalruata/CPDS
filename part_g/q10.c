/* part_g q10: Function returning whether a number is prime (1=prime,0=not). */
#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main(void) {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("%d is %sprime\n", n, isPrime(n) ? "" : "not ");
    return 0;
}
