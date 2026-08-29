/*
 * q11: Count number of digits in an integer.
 * Reads an integer and counts its digits.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read n; c=0;t=n  |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | t != 0 ?         |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * t/=10     if n==0 print 1 else print c
 * c++       |
 *  \       /
 *   v     v
 *  (loop)  +-------+
 *          | STOP  |
 *          +-------+
 */
#include <stdio.h>

int main(void) {
    int n, c = 0, t;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;
    t = n;

    if (t == 0)
        c = 1;
    else {
        while (t != 0) {
            t /= 10;
            c++;
        }
    }
    printf("Number of digits in %d = %d\n", n, c);
    return 0;
}
