/* part_f q4: Function to divide two numbers (with zero check). */
#include <stdio.h>

double divide(double a, double b);

double divide(double a, double b) {
    return b != 0 ? a / b : 0;
}

int main(void) {
    double x, y;
    printf("Enter dividend and divisor: ");
    if (scanf("%lf %lf", &x, &y) != 2) return 1;
    if (y == 0) {
        printf("Error: division by zero\n");
        return 1;
    }
    printf("Quotient = %.2f\n", divide(x, y));
    return 0;
}
