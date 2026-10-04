/* q20.c - Rotate an array LEFT by one position.
 * Concept: Save a[0], shift every element one place left, then put the
 *          saved value at the last index.  {1,2,3,4} -> {2,3,4,1}
 * Compile: gcc q20.c -o q20
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, first;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Before rotation: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    first = a[0];
    for (i = 0; i < n - 1; i++)
        a[i] = a[i + 1];
    a[n - 1] = first;

    printf("After left rotation by 1: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
