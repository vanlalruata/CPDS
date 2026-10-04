/* q13.c - Product of digits */
#include <stdio.h>

int main(void) {
    int n, prod = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n == 0) { printf("Product of digits = 0\n"); return 0; }
    if (n < 0) n = -n;
    while (n > 0) { prod *= n % 10; n /= 10; }
    printf("Product of digits = %d\n", prod);
    return 0;
}
