/*
 * q20: Sum of all odd numbers between two limits.
 * Reads lower and upper limits (inclusive) and sums odds.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read lo, hi      |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | i=lo; sum=0      |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | i<=hi ?          |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * i%2!=0?  print sum
 *  |yes    |
 *  v       /
 * sum+=i  /
 * i++    /
 *  \    /
 *   v  v
 *  (loop) +-------+
 *          | STOP |
 *          +------+
 */
#include <stdio.h>

int main(void) {
    int lo, hi, sum = 0;
    printf("Enter lower and upper limits: ");
    if (scanf("%d %d", &lo, &hi) != 2 || lo > hi) return 1;

    if (lo % 2 == 0) lo++;
    for (int i = lo; i <= hi; i += 2)
        sum += i;

    printf("Sum of odd numbers = %d\n", sum);
    return 0;
}
