/*
 * q1: Largest of two numbers.
 * Reads two integers and prints the larger one.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read a, b        |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | a > b ?          |
 * +------------------+
 *   /      \
 * yes/      \no
 *  /          \
 * v            v
 * print a    print b
 *  \          /
 *   \        /
 *    v      v
 *  +-------+
 *  | STOP  |
 *  +-------+
 */
#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;

    if (a > b)
        printf("Largest: %d\n", a);
    else
        printf("Largest: %d\n", b);
    return 0;
}
