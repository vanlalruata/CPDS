/*
 * q14: Net salary after deductions.
 * Net = gross - (PF + tax).
 */
#include <stdio.h>

int main(void) {
    double gross, pf, tax;
    printf("Enter gross salary, PF, tax: ");
    if (scanf("%lf %lf %lf", &gross, &pf, &tax) != 3) return 1;

    printf("Net salary = %.2f\n", gross - pf - tax);
    return 0;
}
