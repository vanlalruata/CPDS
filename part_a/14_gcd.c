/*
 * q14: GCD of two numbers.
 * Uses Euclid's algorithm to find the greatest common divisor.
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
 * | b != 0 ?         |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * t=a%b     print a (GCD)
 * a=b      |
 * b=t      /
 *  \      /
 *   v    v
 *  (loop) +-------+
 *          | STOP |
 *          +------+
 */
#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;

    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    printf("GCD = %d\n", a);
    return 0;
}
