/*
 * q7: Whether a number is prime.
 * Reads an integer and checks for primality.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read n           |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | n<2 ? -> not prime
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | i=2; i*i<=n ?    |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * n%i==0? yes -> print "Not prime"
 *  |no
 *  v
 * i++
 *  \    /
 *   v  v
 * print "Prime"
 *  +-------+
 *  | STOP  |
 *  +-------+
 */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n < 2) {
        printf("Not prime\n");
        return 0;
    }
    int prime = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            prime = 0;
            break;
        }
    }
    printf(prime ? "Prime\n" : "Not prime\n");
    return 0;
}
