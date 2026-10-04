/* q12.c - Find duplicate elements in an array.
 * Concept: For each element, look at the elements before it.  If the
 *          same value appeared earlier it is a duplicate; report each
 *          repeated value only once with its total count.
 * Compile: gcc q12.c -o q12
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, j, count, reported, dupKinds = 0;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Duplicate elements:\n");
    for (i = 0; i < n; i++) {
        /* skip values already reported */
        reported = 0;
        for (j = 0; j < i; j++)
            if (a[j] == a[i]) { reported = 1; break; }
        if (reported) continue;

        count = 0;
        for (j = 0; j < n; j++)
            if (a[j] == a[i]) count++;

        if (count > 1) {
            printf("  %d appears %d times\n", a[i], count);
            dupKinds++;
        }
    }

    if (dupKinds == 0)
        printf("  No duplicates found - all elements are unique.\n");

    return 0;
}
