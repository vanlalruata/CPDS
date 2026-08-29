/*
 * q2: Largest of three numbers.
 * Reads three integers and prints the largest.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +-------------------+
 * | read a, b, c      |
 * +-------------------+
 *     |
 *     v
 * +----------------------------+
 * | if a>=b && a>=c -> max=a   |
 * | else if b>=c -> max=b      |
 * | else max=c                 |
 * +----------------------------+
 *     |
 *     v
 * +-------------------+
 * | print max         |
 * +-------------------+
 *     |
 *     v
 * +-------+
 * | STOP  |
 * +-------+
 */
#include <stdio.h>

int main(void) {
    int a, b, c, max;
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 1;

    if (a >= b && a >= c)
        max = a;
    else if (b >= c)
        max = b;
    else
        max = c;

    printf("Largest: %d\n", max);
    return 0;
}
