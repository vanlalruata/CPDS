/* q13.c - Demonstrate p + n (pointer plus integer).
 * Concept: p + n points n elements ahead: address + n * sizeof(*p).
 *          *(p + n) is exactly the same as p[n].
 * Compile: gcc q13.c -o q13
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

    p = a;

    printf("\np      = %p, *p        = %d\n", (void *) p, *p);
    printf("p + %-2d = %p, *(p + %d) = %d\n", k, (void *) (p + k), k, *(p + k));
    printf("a[%d]  = %d  <-- same value as *(p + %d)\n", k, a[k], k);
    printf("\nByte difference = %ld = %d * sizeof(int)\n",
           (long) ((char *) (p + k) - (char *) p), k);

    return 0;
}
