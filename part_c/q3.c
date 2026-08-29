/*
 * q3: Largest of two numbers (if-else).
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
