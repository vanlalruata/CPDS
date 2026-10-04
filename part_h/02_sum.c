/* q2.c - Sum of all elements of an array.
 * Concept: Accumulate values in a running total while traversing the array.
 * Compile: gcc q2.c -o q2
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i;
    long sum = 0;          /* long protects against overflow of many ints */

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("Sum of %d elements = %ld\n", n, sum);
    return 0;
}
