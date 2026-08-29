/* q22.c - Rotate an array LEFT by k positions.
 * Concept: New position of element i is (i + n - k) % n; equivalently
 *          b[i] = a[(i + k) % n].  k is reduced modulo n first.
 * Compile: gcc q22.c -o q22
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

    printf("Enter k (number of left rotations, k >= 0): ");
    if (scanf("%d", &k) != 1 || k < 0) { printf("Invalid k.\n"); return 1; }

    k = k % n;                       /* rotating n times = no change */

    for (i = 0; i < n; i++)
        b[i] = a[(i + k) % n];

    printf("Original            : ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\nLeft rotated by %-4d: ", k);
    for (i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");

    return 0;
}
