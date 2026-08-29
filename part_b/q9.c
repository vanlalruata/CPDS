/*
 * q9: Celsius to Fahrenheit.
 * F = (C * 9/5) + 32.
 */
#include <stdio.h>

int main(void) {
    double c;
    printf("Enter temperature in Celsius: ");
    if (scanf("%lf", &c) != 1) return 1;

    printf("Fahrenheit = %.2f\n", c * 9.0 / 5.0 + 32);
    return 0;
}
