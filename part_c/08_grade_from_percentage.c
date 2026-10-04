/*
 * q8: Grade based on percentage (nested if-else).
 */
#include <stdio.h>

int main(void) {
    double p;
    printf("Enter percentage: ");
    if (scanf("%lf", &p) != 1) return 1;

    if (p >= 90)
        printf("Grade A\n");
    else if (p >= 80)
        printf("Grade B\n");
    else if (p >= 70)
        printf("Grade C\n");
    else if (p >= 60)
        printf("Grade D\n");
    else
        printf("Grade F\n");
    return 0;
}
