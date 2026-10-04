/* q13.c - Remove duplicate elements from an array.
 * Concept: Copy an element into the result only if it is not already
 *          present there.  The first occurrence order is preserved.
 * Compile: gcc q13.c -o q13
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX], b[MAX];
    int n, m = 0, i, j, exists;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        exists = 0;
        for (j = 0; j < m; j++)
            if (b[j] == a[i]) { exists = 1; break; }
        if (!exists)
            b[m++] = a[i];
    }

    printf("Original array (%d elements) : ", n);
    for (i = 0; i < n; i++) printf("%d ", a[i]);

    printf("\nAfter removing duplicates (%d): ", m);
    for (i = 0; i < m; i++) printf("%d ", b[i]);
    printf("\n");

    return 0;
}
