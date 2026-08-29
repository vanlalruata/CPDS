/*
 * q5: Area and circumference of a circle.
 * Area = pi*r^2, Circumference = 2*pi*r.
 */
#include <stdio.h>
#define PI 3.141592653589793

int main(void) {
    double r;
    printf("Enter radius: ");
    if (scanf("%lf", &r) != 1 || r < 0) return 1;

    printf("Area = %.4f\n", PI * r * r);
    printf("Circumference = %.4f\n", 2 * PI * r);
    return 0;
}
