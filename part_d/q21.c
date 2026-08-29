/* q21.c - Continuously accept numbers until a prime number is entered */
#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}
int main(void) {
    int n;
    while (1) {
        printf("Enter a number: ");
        if (scanf("%d", &n) != 1) break;
        if (isPrime(n)) { printf("%d is prime. Stopping.\n", n); break; }
        printf("%d is not prime. Try again.\n", n);
    }
    return 0;
}
