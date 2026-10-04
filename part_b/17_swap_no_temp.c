/*
 * q17: Swap two numbers without using a third variable.
 * Uses arithmetic swap (a=a+b; b=a-b; a=a-b).
 */
#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;

    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
