/*
 * q5: Smallest of three numbers (nested if-else).
 */
#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 1;

    if (a <= b) {
        if (a <= c)
            printf("Smallest: %d\n", a);
        else
            printf("Smallest: %d\n", c);
    } else {
        if (b <= c)
            printf("Smallest: %d\n", b);
        else
            printf("Smallest: %d\n", c);
    }
    return 0;
}
