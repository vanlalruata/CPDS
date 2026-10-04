/* q25.c - Delete an element from a specified position in an array.
 * Concept: Overwrite the deleted slot by shifting all later elements
 *          one place to the left and decreasing the logical size.
 *          Position is 1-based.
 * Compile: gcc q25.c -o q25
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, pos, removed;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position to delete (1 to %d): ", n);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > n) {
        printf("Invalid position.\n");
        return 1;
    }

    removed = a[pos - 1];
    for (i = pos - 1; i < n - 1; i++)  /* shift left */
        a[i] = a[i + 1];
    n--;

    printf("Deleted element %d.\n", removed);
    printf("Array after deletion (%d elements): ", n);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    if (n == 0) printf("(empty)");
    printf("\n");

    return 0;
}
