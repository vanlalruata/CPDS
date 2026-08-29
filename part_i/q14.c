/* q14.c - Demonstrate p - n (pointer minus integer).
 * Concept: p - n points n elements before p.  Starting from the end of
 *          an array we can walk backwards with *(p - n).
 * Compile: gcc q14.c -o q14
 */
#include <stdio.h>

#define MAX 20

int main(void)
{
    int a[MAX];
    int n, k, i;
    int *p;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Enter offset k (0 to %d): ", n - 1);
    if (scanf("%d", &k) != 1 || k < 0 || k >= n) { printf("Invalid offset.\n"); return 1; }

    p = &a[n - 1];                     /* pointer to the last element */

    printf("\np      = %p, *p        = %d  (last element)\n", (void *) p, *p);
    printf("p - %-2d = %p, *(p - %d) = %d\n", k, (void *) (p - k), k, *(p - k));
    printf("a[%d]  = %d  <-- same value\n", n - 1 - k, a[n - 1 - k]);

    printf("\nWalking backwards using p - i:\n");
    for (i = 0; i < n; i++)
        printf("*(p - %d) = %d\n", i, *(p - i));

    return 0;
}
