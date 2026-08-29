/* q7.c - Sum of all odd numbers up to N */
#include <stdio.h>

int main(void) {
    int n, sum = 0;
    printf("Enter N: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 2) sum += i;
    printf("Sum of odds = %d\n", sum);
    return 0;
}
