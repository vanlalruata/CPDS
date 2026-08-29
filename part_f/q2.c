/* part_f q2: Function to subtract two numbers. */
#include <stdio.h>

double subtract(double a, double b);

double subtract(double a, double b) {
    return a - b;
}

int main(void) {
    double x, y;
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &x, &y) != 2) return 1;
    printf("Difference = %.2f\n", subtract(x, y));
    return 0;
}
