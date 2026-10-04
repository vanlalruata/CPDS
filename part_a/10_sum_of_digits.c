/*
 * q10: Sum of digits of a number.
 * Reads an integer and sums its digits.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read n; sum=0    |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | n != 0 ?         |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * sum+=n%10 print sum
 * n/=10     |
 *  \       /
 *   v     v
 *  (loop)  +-------+
 *          | STOP  |
 *          +-------+
 */
#include <stdio.h>

int main(void) {
    int n, sum = 0, t;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;
    t = n < 0 ? -n : n;

    while (t != 0) {
        sum += t % 10;
        t /= 10;
    }
    printf("Sum of digits of %d = %d\n", n, sum);
    return 0;
}
