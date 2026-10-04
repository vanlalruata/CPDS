/*
 * q17: Roots of quadratic handling all cases (real/equal/complex).
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c;
    printf("Enter coefficients a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    double d = b * b - 4 * a * c;
    if (d > 0)
        printf("Real and distinct: %.4f, %.4f\n", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
    else if (d == 0)
        printf("Real and equal: %.4f\n", -b / (2 * a));
    else
        printf("Complex: %.4f + %.4fi, %.4f - %.4fi\n",
               -b / (2 * a), sqrt(-d) / (2 * a), -b / (2 * a), sqrt(-d) / (2 * a));
    return 0;
}
