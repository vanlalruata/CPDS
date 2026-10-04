/*
 * q16: Triangle acute, right or obtuse (using sides squared).
 * Compares a^2+b^2 with c^2 (largest side c).
 */
#include <stdio.h>

int main(void) {
    double a, b, c, x, y, z;
    printf("Enter three sides: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    x = a; y = b; z = c;
    if (y > x) { double t = x; x = y; y = t; }
    if (z > x) { double t = x; x = z; z = t; }
    if (y > z) { double t = z; z = y; y = t; }

    if (z + y > x) {
        double s = y * y + z * z;
        if (x * x == s)
            printf("Right triangle\n");
        else if (x * x < s)
            printf("Acute triangle\n");
        else
            printf("Obtuse triangle\n");
    } else
        printf("Not a valid triangle\n");
    return 0;
}
