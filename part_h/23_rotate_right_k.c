/* q23.c - Rotate an array RIGHT by k positions.
 * Concept: b[(i + k) % n] = a[i].  Right rotation by k is the same as
 *          left rotation by (n - k).
 * Compile: gcc q23.c -o q23
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX], b[MAX];
    int n, k, i;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter k (number of right rotations, k >= 0): ");
    if (scanf("%d", &k) != 1 || k < 0) { printf("Invalid k.\n"); return 1; }

    k = k % n;

    for (i = 0; i < n; i++)
        b[(i + k) % n] = a[i];

    printf("Original             : ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\nRight rotated by %-4d: ", k);
    for (i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");

    return 0;
}
