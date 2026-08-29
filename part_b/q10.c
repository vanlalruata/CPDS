/*
 * q10: Fahrenheit to Celsius.
 * C = (F - 32) * 5/9.
 */
#include <stdio.h>

int main(void) {
    double f;
    printf("Enter temperature in Fahrenheit: ");
    if (scanf("%lf", &f) != 1) return 1;

    printf("Celsius = %.2f\n", (f - 32) * 5.0 / 9.0);
    return 0;
}
