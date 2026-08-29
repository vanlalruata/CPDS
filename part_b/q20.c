/*
 * q20: Midpoint of two points.
 * Mx = (x1+x2)/2, My = (y1+y2)/2.
 */
#include <stdio.h>

int main(void) {
    double x1, y1, x2, y2;
    printf("Enter x1 y1 x2 y2: ");
    if (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != 4) return 1;

    printf("Midpoint = (%.4f, %.4f)\n", (x1 + x2) / 2.0, (y1 + y2) / 2.0);
    return 0;
}
