/* part_f q12: Function to calculate power (x raised to y). */
#include <stdio.h>

double power(double base, int exp);

double power(double base, int exp) {
    double r = 1;
    int neg = (exp < 0);
    if (neg) exp = -exp;
    for (int i = 0; i < exp; i++) r *= base;
    return neg ? 1 / r : r;
}

int main(void) {
    double b;
    int e;
    printf("Enter base and exponent: ");
    if (scanf("%lf %d", &b, &e) != 2) return 1;
    printf("Result = %.4f\n", power(b, e));
    return 0;
}
