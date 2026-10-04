/*
 * q20: Employee bonus based on salary and years of service.
 * >5 years 10% bonus; 3-5 years 7%; else 5%.
 */
#include <stdio.h>

int main(void) {
    double sal, bonus;
    int yrs;
    printf("Enter salary and years of service: ");
    if (scanf("%lf %d", &sal, &yrs) != 2) return 1;

    if (yrs > 5)
        bonus = sal * 0.10;
    else if (yrs >= 3)
        bonus = sal * 0.07;
    else
        bonus = sal * 0.05;

    printf("Bonus = %.2f\n", bonus);
    return 0;
}
