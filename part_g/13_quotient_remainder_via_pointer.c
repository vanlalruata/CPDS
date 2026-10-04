/* part_g q13: Calculate quotient and remainder using pointer parameters. */
#include <stdio.h>

void divRem(int a, int b, int *q, int *r) {
    *q = a / b;
    *r = a % b;
}

int main(void) {
    int a, b, q, r;
    printf("Enter dividend and divisor: ");
    if (scanf("%d %d", &a, &b) != 2 || b == 0) return 1;
    divRem(a, b, &q, &r);
    printf("Quotient = %d, Remainder = %d\n", q, r);
    return 0;
}
