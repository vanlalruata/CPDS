/*
 * q24: Convert binary to decimal.
 * Reads a binary number (as an integer) and converts to decimal.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read bin; dec=0  |
 * | p=1              |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | bin>0 ?          |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * d=bin%10 print dec
 * dec+=d*p   |
 * p*=2      /
 * bin/=10  /
 *  \      /
 *   v    v
 *  (loop) +-------+
 *          | STOP |
 *          +------+
 */
#include <stdio.h>

int main(void) {
    long bin;
    int dec = 0, p = 1;
    printf("Enter a binary number: ");
    if (scanf("%ld", &bin) != 1 || bin < 0) return 1;

    long t = bin;
    while (t > 0) {
        int d = t % 10;
        dec += d * p;
        p *= 2;
        t /= 10;
    }
    printf("Decimal: %d\n", dec);
    return 0;
}
