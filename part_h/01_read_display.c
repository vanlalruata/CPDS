/* q1.c - Read and display a one-dimensional array.
 * Concept: An array stores several values of the same type in
 *          contiguous memory; elements are accessed as a[0]..a[n-1].
 * Compile: gcc q1.c -o q1
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("The array is:\n");
    for (i = 0; i < n; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}
