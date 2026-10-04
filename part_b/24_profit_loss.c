/*
 * q24: Profit/loss and profit/loss percentage.
 * Compares cost price and selling price.
 */
#include <stdio.h>

int main(void) {
    double cp, sp;
    printf("Enter cost price and selling price: ");
    if (scanf("%lf %lf", &cp, &sp) != 2 || cp <= 0) return 1;

    if (sp > cp)
        printf("Profit = %.2f (%.2f%%)\n", sp - cp, (sp - cp) / cp * 100);
    else if (sp < cp)
        printf("Loss = %.2f (%.2f%%)\n", cp - sp, (cp - sp) / cp * 100);
    else
        printf("No profit, no loss\n");
    return 0;
}
