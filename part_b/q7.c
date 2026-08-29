/*
 * q7: Area of a triangle using Heron's formula.
 * s = (a+b+c)/2 ; Area = sqrt(s(s-a)(s-b)(s-c)).
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c, s;
    printf("Enter sides a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    s = (a + b + c) / 2.0;
    printf("Area = %.4f\n", sqrt(s * (s - a) * (s - b) * (s - c)));
    return 0;
}
