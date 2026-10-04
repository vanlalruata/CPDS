/*
 * q8: Reverse an integer.
 * Reads an integer and prints its reverse.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read n; rev=0    |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | n != 0 ?         |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * d=n%10    print rev
 * rev=rev*10+d
 * n=n/10
 *  \       /
 *   v     v
 *  (loop)  +-------+
 *          | STOP  |
 *          +-------+
 */
#include <stdio.h>

int main(void) {
    int n, rev = 0, orig;
    printf("Enter an integer: ");
    if (scanf("%d", &orig) != 1) return 1;
    n = orig < 0 ? -orig : orig;

    while (n != 0) {
        int d = n % 10;
        rev = rev * 10 + d;
        n /= 10;
    }
    printf("Reverse of %d is %d\n", orig, orig < 0 ? -rev : rev);
    return 0;
}
