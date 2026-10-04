/* q12.c - Sum of digits */
#include <stdio.h>

int main(void) {
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 0) n = -n;
    while (n > 0) { sum += n % 10; n /= 10; }
    printf("Sum of digits = %d\n", sum);
    return 0;
}
