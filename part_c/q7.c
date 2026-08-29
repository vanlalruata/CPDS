/*
 * q7: Passed or failed (>=40).
 */
#include <stdio.h>

int main(void) {
    int m;
    printf("Enter marks: ");
    if (scanf("%d", &m) != 1) return 1;

    if (m >= 40)
        printf("Passed\n");
    else
        printf("Failed\n");
    return 0;
}
