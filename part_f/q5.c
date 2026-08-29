/* part_f q5: Function to find square of a number. */
#include <stdio.h>

double square(double n);

double square(double n) {
    return n * n;
}

int main(void) {
    double n;
    printf("Enter a number: ");
    if (scanf("%lf", &n) != 1) return 1;
    printf("Square = %.2f\n", square(n));
    return 0;
}
