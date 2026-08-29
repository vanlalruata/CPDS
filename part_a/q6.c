/*
 * q6: Factorial of a number.
 * Reads a non-negative integer and computes n!.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read n; f=1; i=1 |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | i <= n ?         |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * f=f*i    print f
 * i=i+1    |
 *  \      /
 *   v    v
 *  (loop) +-------+
 *         | STOP  |
 *         +-------+
 */
#include <stdio.h>

int main(void) {
    int n;
    unsigned long long f = 1;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    for (int i = 1; i <= n; i++)
        f *= i;

    printf("Factorial of %d = %llu\n", n, f);
    return 0;
}
