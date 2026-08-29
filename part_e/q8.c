/* q8.c - Factorial of N */
#include <stdio.h>

int main(void) {
    int n;
    long long f = 1;
    printf("Enter N: ");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) f *= i;
    printf("Factorial = %lld\n", f);
    return 0;
}
