/* part_m/q19.c
 * GCD USING EUCLIDEAN ALGORITHM
 *
 * ALGORITHM STEPS:
 * 1. While b != 0: set (a, b) = (b, a % b).
 * 2. When b == 0, a is the GCD.
 *
 * TIME COMPLEXITY: O(log(min(a, b)))  (number of modulo steps)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(void) {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    printf("GCD = %d\n", gcd(x, y));
    return 0;
}
