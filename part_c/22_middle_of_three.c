/*
 * q22: Middle number among three numbers.
 * Finds the value that is neither the max nor the min.
 */
#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 1;

    int mid;
    if ((a >= b && a <= c) || (a <= b && a >= c))
        mid = a;
    else if ((b >= a && b <= c) || (b <= a && b >= c))
        mid = b;
    else
        mid = c;

    printf("Middle number: %d\n", mid);
    return 0;
}
