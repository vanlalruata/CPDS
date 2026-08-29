/* q15.c - Difference between two pointers into the same array.
 * Concept: Subtracting two pointers of the same type yields the number
 *          of ELEMENTS between them, of type ptrdiff_t (<stddef.h>),
 *          printed with the %td conversion.
 * Compile: gcc q15.c -o q15
 */
#include <stdio.h>
#include <stddef.h>

#define MAX 20

int main(void)
{
    int a[MAX];
    int n, i, j, k;
    int *p1, *p2;
    ptrdiff_t diff;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (k = 0; k < n; k++) scanf("%d", &a[k]);

    printf("Enter two indices i and j (0 to %d): ", n - 1);
    if (scanf("%d %d", &i, &j) != 2 || i < 0 || i >= n || j < 0 || j >= n) {
        printf("Invalid indices.\n");
        return 1;
    }

    p1 = &a[i];
    p2 = &a[j];
    diff = p2 - p1;

    printf("\np1 = &a[%d] = %p, *p1 = %d\n", i, (void *) p1, *p1);
    printf("p2 = &a[%d] = %p, *p2 = %d\n", j, (void *) p2, *p2);
    printf("p2 - p1 = %ld element(s)   (type is ptrdiff_t)\n", (long) diff);
    printf("Byte distance = %ld bytes\n", (long) ((char *) p2 - (char *) p1));
    printf("Number of elements between them (inclusive count) = %ld\n",
           (long) ((diff >= 0 ? diff : -diff) + 1));

    return 0;
}
