/* part_f q6: Function to find cube of a number. */
#include <stdio.h>

double cube(double n);

double cube(double n) {
    return n * n * n;
}

int main(void) {
    double n;
    printf("Enter a number: ");
    if (scanf("%lf", &n) != 1) return 1;
    printf("Cube = %.2f\n", cube(n));
    return 0;
}
