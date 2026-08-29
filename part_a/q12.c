/*
 * q12: Calculate x^n.
 * Reads base x and exponent n and computes x^n.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read x,n; r=1;i=0|
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | i < n ?          |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * r=r*x    print r
 * i++      |
 *  \      /
 *   v    v
 *  (loop)  +-------+
 *          | STOP  |
 *          +-------+
 */
#include <stdio.h>

int main(void) {
    double x;
    int n;
    double r = 1.0;
    printf("Enter base x and non-negative exponent n: ");
    if (scanf("%lf %d", &x, &n) != 2 || n < 0) return 1;

    for (int i = 0; i < n; i++)
        r *= x;

    printf("%.2f^%d = %.6f\n", x, n, r);
    return 0;
}
