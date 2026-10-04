/* part_m/q17.c
 * FIBONACCI USING ITERATION
 *
 * ALGORITHM STEPS:
 * 1. Set a=0, b=1.
 * 2. Repeat n times: print a, then update (a, b) = (b, a+b).
 *
 * TIME COMPLEXITY: O(n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n (number of terms): ");
    scanf("%d", &n);
    long long a = 0, b = 1;
    printf("Fibonacci: ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", a);
        long long t = a + b;
        a = b; b = t;
    }
    printf("\n");
    return 0;
}
