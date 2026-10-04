/*
 * q4: Largest of three numbers (nested if-else).
 */
#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 1;

    if (a >= b) {
        if (a >= c)
            printf("Largest: %d\n", a);
        else
            printf("Largest: %d\n", c);
    } else {
        if (b >= c)
            printf("Largest: %d\n", b);
        else
            printf("Largest: %d\n", c);
    }
    return 0;
}
