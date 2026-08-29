/*
 * q21: Quadrant of a point (x, y).
 * Determines which quadrant or axis the point lies on.
 */
#include <stdio.h>

int main(void) {
    double x, y;
    printf("Enter x and y: ");
    if (scanf("%lf %lf", &x, &y) != 2) return 1;

    if (x == 0 && y == 0)
        printf("Origin\n");
    else if (x == 0)
        printf("Y-axis\n");
    else if (y == 0)
        printf("X-axis\n");
    else if (x > 0 && y > 0)
        printf("Quadrant I\n");
    else if (x < 0 && y > 0)
        printf("Quadrant II\n");
    else if (x < 0 && y < 0)
        printf("Quadrant III\n");
    else
        printf("Quadrant IV\n");
    return 0;
}
