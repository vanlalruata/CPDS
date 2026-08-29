/*
 * q9: Leap year (nested if-else).
 */
#include <stdio.h>

int main(void) {
    int y;
    printf("Enter a year: ");
    if (scanf("%d", &y) != 1) return 1;

    if (y % 4 == 0) {
        if (y % 100 == 0) {
            if (y % 400 == 0)
                printf("Leap year\n");
            else
                printf("Not a leap year\n");
        } else
            printf("Leap year\n");
    } else
        printf("Not a leap year\n");
    return 0;
}
