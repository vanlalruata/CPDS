/*
 * q25: Evaluate a mathematical expression with int and float.
 * Evaluates (a + b * c) / d - e using mixed types.
 */
#include <stdio.h>

int main(void) {
    int a, b, c, d;
    double e;
    printf("Enter a b c d (int) and e (double): ");
    if (scanf("%d %d %d %d %lf", &a, &b, &c, &d, &e) != 5) return 1;

    double result = (double)(a + b * c) / d - e;
    printf("Result of (a + b*c)/d - e = %.4f\n", result);
    return 0;
}
