/* part_f q20: Function to check perfect number (sum of proper divisors equals number). */
#include <stdio.h>

int isPerfect(int n);

int isPerfect(int n) {
    if (n < 1) return 0;
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0) sum += i;
    return sum == n;
}

int main(void) {
    int n;
    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1) return 1;
    if (isPerfect(n))
        printf("%d is a Perfect number\n", n);
    else
        printf("%d is not a Perfect number\n", n);
    return 0;
}
