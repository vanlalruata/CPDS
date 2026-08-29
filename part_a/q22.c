/*
 * q22: Whether a year is a leap year.
 * Leap if divisible by 4 and (not by 100 or by 400).
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read year        |
 * +------------------+
 *     |
 *     v
 * +-------------------+
 * | (y%4==0 &&        |
 * |  y%100!=0) ||     |
 * |  y%400==0 ?       |
 * +-------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * "Leap"  "Not leap"
 *  \      /
 *   v    v
 * +-------+
 * | STOP  |
 * +-------+
 */
#include <stdio.h>

int main(void) {
    int y;
    printf("Enter a year: ");
    if (scanf("%d", &y) != 1) return 1;

    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        printf("Leap year\n");
    else
        printf("Not a leap year\n");
    return 0;
}
