/*
 * q1: Addition, subtraction, multiplication and division of two integers.
 * Reads two integers and prints all four operations.
 */
#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;

    printf("Sum = %d\n", a + b);
    printf("Difference = %d\n", a - b);
    printf("Product = %d\n", a * b);
    if (b != 0)
        printf("Quotient = %.4f\n", (double)a / b);
    else
        printf("Quotient: division by zero\n");
    return 0;
}
