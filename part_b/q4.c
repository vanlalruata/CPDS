/*
 * q4: Compound interest.
 * A = P * (1 + R/100)^T ; CI = A - P.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double p, r, t;
    printf("Enter principal, rate%%, time: ");
    if (scanf("%lf %lf %lf", &p, &r, &t) != 3) return 1;

    double a = p * pow(1 + r / 100.0, t);
    printf("Compound Interest = %.2f\n", a - p);
    return 0;
}
