/*
 * q13: Generate Fibonacci series.
 * Prints the first N Fibonacci numbers.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read N; a=0;b=1  |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | count < N ?      |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * print a   print series
 * c=a+b     |
 * a=b      /
 * b=c     /
 * count++/
 *  \    /
 *   v  v
 *  (loop) +-------+
 *          | STOP |
 *          +------+
 */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter number of terms: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    long a = 0, b = 1;
    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++) {
        printf("%ld ", a);
        long c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}
