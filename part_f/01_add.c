/* part_f q1: Function to add two numbers.
   Demonstrates a function with a return value and two parameters. */
#include <stdio.h>

double add(double a, double b);

double add(double a, double b) {
    return a + b;
}

int main(void) {
    double x, y;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &x, &y) != 2) return 1;
    printf("Sum = %.2f\n", add(x, y));
    return 0;
}
