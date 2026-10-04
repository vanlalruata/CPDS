/*
 * q5: Sum of first N natural numbers.
 * Reads N and computes 1+2+...+N.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read N; sum=0;i=1|
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | i <= N ?         |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * sum=sum+i  print sum
 * i=i+1      |
 *  \        /
 *   v      v
 *   (loop)  +-------+
 *           | STOP  |
 *           +-------+
 */
#include <stdio.h>

int main(void) {
    int n, sum = 0;
    printf("Enter N: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    for (int i = 1; i <= n; i++)
        sum += i;

    printf("Sum of first %d natural numbers: %d\n", n, sum);
    return 0;
}
