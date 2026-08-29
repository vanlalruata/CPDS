/* q20.c - Print all prime numbers between two limits */
#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter two limits: ");
    scanf("%d %d", &a, &b);
    printf("Primes: ");
    for (int n = a; n <= b; n++) {
        int isPrime = 1;
        if (n < 2) continue;
        for (int i = 2; i * i <= n; i++) if (n % i == 0) { isPrime = 0; break; }
        if (isPrime) printf("%d ", n);
    }
    printf("\n");
    return 0;
}
