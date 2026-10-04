/*
 * q24: Valid date (day/month/year).
 * Checks day, month ranges and February limits.
 */
#include <stdio.h>

int is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int main(void) {
    int d, m, y;
    printf("Enter day month year: ");
    if (scanf("%d %d %d", &d, &m, &y) != 3) return 1;

    int valid = 1;
    if (m < 1 || m > 12) valid = 0;
    else {
        int maxd;
        if (m == 2) maxd = is_leap(y) ? 29 : 28;
        else if (m == 4 || m == 6 || m == 9 || m == 11) maxd = 30;
        else maxd = 31;
        if (d < 1 || d > maxd) valid = 0;
    }
    printf(valid ? "Valid date\n" : "Invalid date\n");
    return 0;
}
