/* q16.c - Traverse an array using a pointer.
 * Concept: Keep one pointer at the start and one just past the last
 *          element; walk forward while p < end.  The "one past the end"
 *          pointer is legal to form (but not to dereference).
 * Compile: gcc q16.c -o q16
 */
#include <stdio.h>

#define MAX 50

int main(void)
{
    int a[MAX];
    int n, i;
    int *p, *end;
    long sum = 0;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    end = a + n;                       /* one past the last element */

    printf("\nTraversal using a pointer:\n");
    for (p = a; p < end; p++) {
        printf("address %p -> value %d\n", (void *) p, *p);
        sum += *p;
    }

    printf("\nSum computed during traversal = %ld\n", sum);
    return 0;
}
