/*
 * q16: Swap two numbers using a temporary variable.
 */
#include <stdio.h>

int main(void) {
    int a, b, t;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;

    t = a; a = b; b = t;
    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
