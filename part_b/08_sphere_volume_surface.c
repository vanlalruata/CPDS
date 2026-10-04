/*
 * q8: Volume and surface area of a sphere.
 * V = 4/3*pi*r^3, SA = 4*pi*r^2.
 */
#include <stdio.h>
#define PI 3.141592653589793

int main(void) {
    double r;
    printf("Enter radius: ");
    if (scanf("%lf", &r) != 1 || r < 0) return 1;

    printf("Volume = %.4f\n", 4.0 / 3.0 * PI * r * r * r);
    printf("Surface Area = %.4f\n", 4 * PI * r * r);
    return 0;
}
