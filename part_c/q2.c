/*
 * q2: Even or odd (if-else).
 */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n % 2 == 0)
        printf("Even\n");
    else
        printf("Odd\n");
    return 0;
}
