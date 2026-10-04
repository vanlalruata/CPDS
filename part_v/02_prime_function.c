/* part_v/q2.c — Prime number using function */
#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main(void) {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%d is %s\n", n, isPrime(n) ? "prime" : "not prime");
    return 0;
}
