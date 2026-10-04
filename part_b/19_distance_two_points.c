/*
 * q19: Distance between two points.
 * d = sqrt((x2-x1)^2 + (y2-y1)^2).
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double x1, y1, x2, y2;
    printf("Enter x1 y1 x2 y2: ");
    if (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != 4) return 1;

    printf("Distance = %.4f\n", sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
    return 0;
}
