/* q5.c - Number of days in a given month (accounts for leap February) */
#include <stdio.h>

int main(void) {
    int month, year, days;
    printf("Enter month and year: ");
    scanf("%d %d", &month, &year);
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31; break;
        case 4: case 6: case 9: case 11:
            days = 30; break;
        case 2:
            days = ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
            break;
        default:
            printf("Invalid month\n");
            return 1;
    }
    printf("Days = %d\n", days);
    return 0;
}
