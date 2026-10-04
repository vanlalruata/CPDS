/*
 * q12: Convert seconds into hours, minutes and seconds.
 * Splits total seconds into H:M:S.
 */
#include <stdio.h>

int main(void) {
    int total;
    printf("Enter total seconds: ");
    if (scanf("%d", &total) != 1 || total < 0) return 1;

    int h = total / 3600;
    int m = (total % 3600) / 60;
    int s = total % 60;
    printf("%d seconds = %d hours, %d minutes, %d seconds\n", total, h, m, s);
    return 0;
}
