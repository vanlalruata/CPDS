/* q24.c - Insert an element at a specified position in an array.
 * Concept: Shift elements from the end down to the target position one
 *          place to the right to create a hole, then store the value.
 *          Position is taken as 1-based (1 .. n+1).
 * Compile: gcc q24.c -o q24
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, pos, value;

    printf("Enter number of elements (1-%d): ", MAX - 1);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX - 1) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position (1 to %d): ", n + 1);
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > n + 1) {
        printf("Invalid position.\n");
        return 1;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    for (i = n; i >= pos; i--)        /* shift right */
        a[i] = a[i - 1];
    a[pos - 1] = value;
    n++;

    printf("Array after insertion (%d elements): ", n);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
