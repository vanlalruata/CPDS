/*
 * q9: Whether a number is a palindrome.
 * A number equal to its reverse is a palindrome.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read n; rev=0;t=n|
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | t != 0 ?         |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * d=t%10    rev==n? -> print "Palindrome"
 * rev=rev*10+d          else "Not palindrome"
 * t=t/10
 *  \       /
 *   v     v
 *  (loop)  +-------+
 *          | STOP  |
 *          +-------+
 */
#include <stdio.h>

int main(void) {
    int n, t, rev = 0;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;
    t = n;

    while (t != 0) {
        rev = rev * 10 + (t % 10);
        t /= 10;
    }
    printf(rev == n ? "Palindrome\n" : "Not palindrome\n");
    return 0;
}
