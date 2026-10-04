/*
 * q17: Electricity bill based on slabs.
 * Slabs: 0-100 @1.0/unit, 101-200 @1.5/unit, 201+ @2.0/unit, plus fixed charge 50.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read units       |
 * +------------------+
 *     |
 *     v
 * +-------------------+
 * | units<=100 -> u*1 |
 * | <=200 -> 100+... |
 * | else full slabs  |
 * +-------------------+
 *     |
 *     v
 * +-------------------+
 * | bill = amount+50  |
 * +-------------------+
 *     |
 *     v
 * +-------------------+
 * | print bill        |
 * +-------------------+
 *     |
 *     v
 * +-------+
 * | STOP  |
 * +-------+
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

    bill += 50.0; /* fixed charge */
    printf("Electricity bill: %.2f\n", bill);
    return 0;
}
