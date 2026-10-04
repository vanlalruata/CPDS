/*
 * q19: Income tax based on slabs.
 * <=250000 nil; <=500000 5%; <=1000000 20%; else 30%.
 */
#include <stdio.h>

int main(void) {
    double inc, tax;
    printf("Enter annual income: ");
    if (scanf("%lf", &inc) != 1 || inc < 0) return 1;

    if (inc <= 250000)
        tax = 0;
    else if (inc <= 500000)
        tax = (inc - 250000) * 0.05;
    else if (inc <= 1000000)
        tax = 250000 * 0.05 + (inc - 500000) * 0.20;
    else
        tax = 250000 * 0.05 + 500000 * 0.20 + (inc - 1000000) * 0.30;

    printf("Income tax = %.2f\n", tax);
    return 0;
}
