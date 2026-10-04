/*
 * q6: Area of a triangle using base and height.
 * Area = 0.5 * base * height.
 */
#include <stdio.h>

int main(void) {
    double b, h;
    printf("Enter base and height: ");
    if (scanf("%lf %lf", &b, &h) != 2) return 1;

    printf("Area = %.4f\n", 0.5 * b * h);
    return 0;
}
