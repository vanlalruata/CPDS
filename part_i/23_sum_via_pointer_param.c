/* q23.c - Sum of array elements using a pointer parameter.
 * Concept: An array argument decays to a pointer, so the function
 *          receives the address of the first element and needs the
 *          length separately.
 * Compile: gcc q23.c -o q23
 */
#include <stdio.h>

#define MAX 50

static long sumArray(const int *p, int n)
{
    long sum = 0;
    const int *end = p + n;
    for (; p < end; p++)
        sum += *p;
    return sum;
}

int main(void)
{
    int a[MAX];
    int n, i;
    long total;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", a + i);

    total = sumArray(a, n);

    printf("Sum     = %ld\n", total);
    printf("Average = %.4f\n", (double) total / n);

    return 0;
}
