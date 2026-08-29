/* part_f q3: Function to multiply two numbers. */
#include <stdio.h>

double multiply(double a, double b);

double multiply(double a, double b) {
    return a * b;
}

int main(void) {
    double x, y;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &x, &y) != 2) return 1;
    printf("Product = %.2f\n", multiply(x, y));
    return 0;
}
