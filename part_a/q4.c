/*
 * q4: Even or odd.
 * Reads an integer and checks divisibility by 2.
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
 * +-----------------------------+
 * | n % 2 == 0 ?                |
 * +-----------------------------+
 *   /            \
 * yes/            \no
 *  v               v
 * print "Even"   print "Odd"
 *  \             /
 *   \           /
 *    v         v
 * +-------+  +-------+
 * | STOP  |  | STOP  |
 * +-------+  +-------+
 */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n % 2 == 0)
        printf("Even\n");
    else
        printf("Odd\n");
    return 0;
}
