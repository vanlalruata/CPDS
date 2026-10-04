/*
 * q18: Electricity bill using slab rates (if-else ladder).
 * 0-100 @1.0, 101-200 @1.5, 201+ @2.0, plus fixed 50.
 */
#include <stdio.h>

int main(void) {
    int u;
    double bill;
    printf("Enter units consumed: ");
    if (scanf("%d", &u) != 1 || u < 0) return 1;

    if (u <= 100)
        bill = u * 1.0;
    else if (u <= 200)
        bill = 100 * 1.0 + (u - 100) * 1.5;
    else
        bill = 100 * 1.0 + 100 * 1.5 + (u - 200) * 2.0;

    printf("Electricity bill: %.2f\n", bill + 50.0);
    return 0;
}
