/*
 * q16: Roots of a quadratic equation.
 * Solves ax^2 + bx + c = 0 using the discriminant.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read a,b,c       |
 * +------------------+
 *     |
 *     v
 * +-------------------+
 * | d = b*b - 4*a*c   |
 * +-------------------+
 *     |
 *     v
 * +-------------------+
 * | d > 0  -> two real|
 * | d == 0-> one real |
 * | d < 0 -> complex  |
 * +-------------------+
 *     |
 *     v
 * +-------+
 * | STOP  |
 * +-------+
 */
#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c;
    printf("Enter coefficients a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    double d = b * b - 4 * a * c;
    if (d > 0) {
        printf("Roots: %.4f and %.4f\n", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
    } else if (d == 0) {
        printf("Root: %.4f\n", -b / (2 * a));
    } else {
        printf("Roots: %.4f + %.4fi and %.4f - %.4fi\n",
               -b / (2 * a), sqrt(-d) / (2 * a), -b / (2 * a), sqrt(-d) / (2 * a));
    }
    return 0;
}
