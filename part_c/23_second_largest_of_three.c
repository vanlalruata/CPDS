/*
 * q23: Second-largest among three numbers.
 * Finds the middle value (neither largest nor smallest).
 */
#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 1;

    int second;
    if ((a >= b && a <= c) || (a <= b && a >= c))
        second = a;
    else if ((b >= a && b <= c) || (b <= a && b >= c))
        second = b;
    else
        second = c;

    printf("Second-largest: %d\n", second);
    return 0;
}
