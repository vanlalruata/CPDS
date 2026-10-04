/*
 * q13: Gross salary from basic salary and allowances.
 * Gross = basic + HRA + DA.
 */
#include <stdio.h>

int main(void) {
    double basic, hra, da;
    printf("Enter basic, HRA, DA: ");
    if (scanf("%lf %lf %lf", &basic, &hra, &da) != 3) return 1;

    printf("Gross salary = %.2f\n", basic + hra + da);
    return 0;
}
