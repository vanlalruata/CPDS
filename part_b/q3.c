/*
 * q3: Simple interest.
 * SI = P * R * T / 100.
 */
#include <stdio.h>

int main(void) {
    double p, r, t;
    printf("Enter principal, rate%%, time: ");
    if (scanf("%lf %lf %lf", &p, &r, &t) != 3) return 1;

    printf("Simple Interest = %.2f\n", p * r * t / 100.0);
    return 0;
}
