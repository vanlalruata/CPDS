/*
 * q22: Discount and final price.
 * final = price * (1 - discount%/100).
 */
#include <stdio.h>

int main(void) {
    double price, disc;
    printf("Enter price and discount percent: ");
    if (scanf("%lf %lf", &price, &disc) != 2) return 1;

    double off = price * disc / 100.0;
    printf("Discount = %.2f, Final price = %.2f\n", off, price - off);
    return 0;
}
