/*
 * q15: LCM of two numbers.
 * LCM = |a*b| / GCD(a,b).
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read a, b        |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | compute g=GCD    |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | lcm=|a*b|/g      |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | print lcm        |
 * +------------------+
 *     |
 *     v
 * +-------+
 * | STOP  |
 * +-------+
 */
#include <stdio.h>

int main(void) {
    int a, b, ta, tb, g;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;
    ta = a < 0 ? -a : a;
    tb = b < 0 ? -b : b;

    int x = ta, y = tb;
    while (y != 0) {
        int t = x % y;
        x = y;
        y = t;
    }
    g = x;
    printf("LCM = %d\n", (ta / g) * tb);
    return 0;
}
