/* q24.c - Return multiple values from a function using pointers.
 * Concept: Pass one pointer per result.  Here a single call returns the
 *          sum, difference, product, quotient and remainder.
 * Compile: gcc q24.c -o q24
 */
#include <stdio.h>

static void calculate(int a, int b,
                      int *sum, int *diff, int *prod,
                      double *quot, int *rem, int *ok)
{
    *sum  = a + b;
    *diff = a - b;
    *prod = a * b;
    if (b != 0) {
        *quot = (double) a / b;
        *rem  = a % b;
        *ok   = 1;
    } else {
        *quot = 0.0;
        *rem  = 0;
        *ok   = 0;               /* division by zero flag */
    }
}

int main(void)
{
    int a, b, sum, diff, prod, rem, ok;
    double quot;

    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) { printf("Invalid input.\n"); return 1; }

    calculate(a, b, &sum, &diff, &prod, &quot, &rem, &ok);

    printf("Sum        = %d\n", sum);
    printf("Difference = %d\n", diff);
    printf("Product    = %d\n", prod);
    if (ok) {
        printf("Quotient   = %.4f\n", quot);
        printf("Remainder  = %d\n", rem);
    } else {
        printf("Quotient / Remainder : undefined (second number is 0)\n");
    }

    return 0;
}
