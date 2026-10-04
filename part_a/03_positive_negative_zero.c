/*
 * q3: Positive, negative, or zero.
 * Reads a number and classifies it.
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
 * | n > 0 ?          |
 * +------------------+
 *   /    \    (no)
 * yes     v
 *  |   +------------------+
 *  |   | n < 0 ?          |
 *  |   +------------------+
 *  |     /    \    (no)
 *  |    yes    v
 *  |     |   print "Zero"
 *  |     v
 *  |  print "Negative"
 *  |     |
 *  v     v
 * print "Positive"
 *  \    /
 *   v  v
 * +-------+
 * | STOP  |
 * +-------+
 */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n > 0)
        printf("Positive\n");
    else if (n < 0)
        printf("Negative\n");
    else
        printf("Zero\n");
    return 0;
}
