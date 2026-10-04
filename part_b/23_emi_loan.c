/*
 * q23: EMI for a loan.
 * EMI = P*r*(1+r)^n / ((1+r)^n - 1), r = monthly rate.
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double p, annual, n;
    printf("Enter principal, annual rate%%, tenure(months): ");
    if (scanf("%lf %lf %lf", &p, &annual, &n) != 3) return 1;

    double r = annual / (12.0 * 100.0);
    double emi;
    if (r == 0)
        emi = p / n;
    else {
        double f = pow(1 + r, n);
        emi = p * r * f / (f - 1);
    }
    printf("EMI = %.2f\n", emi);
    return 0;
}
