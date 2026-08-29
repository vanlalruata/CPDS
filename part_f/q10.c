/* part_f q10: Function to check prime. Returns 1 if prime, 0 otherwise. */
#include <stdio.h>

int isPrime(int n);

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;
    if (isPrime(n))
        printf("%d is Prime\n", n);
    else
        printf("%d is not Prime\n", n);
    return 0;
}
