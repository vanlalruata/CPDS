/* q16.c - Merge two arrays into a third array.
 * Concept: Copy all elements of A then all elements of B into C.
 *          Size of C = n1 + n2.
 * Compile: gcc q16.c -o q16
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX], b[MAX], c[2 * MAX];
    int n1, n2, i, k = 0;

    printf("Enter size of first array (1-%d): ", MAX);
    if (scanf("%d", &n1) != 1 || n1 < 1 || n1 > MAX) { printf("Invalid size.\n"); return 1; }
    printf("Enter %d elements of first array: ", n1);
    for (i = 0; i < n1; i++) scanf("%d", &a[i]);

    printf("Enter size of second array (1-%d): ", MAX);
    if (scanf("%d", &n2) != 1 || n2 < 1 || n2 > MAX) { printf("Invalid size.\n"); return 1; }
    printf("Enter %d elements of second array: ", n2);
    for (i = 0; i < n2; i++) scanf("%d", &b[i]);

    for (i = 0; i < n1; i++) c[k++] = a[i];
    for (i = 0; i < n2; i++) c[k++] = b[i];

    printf("Merged array (%d elements): ", k);
    for (i = 0; i < k; i++) printf("%d ", c[i]);
    printf("\n");

    return 0;
}
