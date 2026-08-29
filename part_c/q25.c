/*
 * q25: Given date falls in a leap year.
 * Reads a date and reports whether its year is a leap year.
 */
#include <stdio.h>

int main(void) {
    int d, m, y;
    printf("Enter day month year: ");
    if (scanf("%d %d %d", &d, &m, &y) != 3) return 1;

    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        printf("The year %d is a leap year\n", y);
    else
        printf("The year %d is not a leap year\n", y);
    return 0;
}
