/* q19.c - Difference of two arrays: elements present in A but not in B.
 * Concept: Set difference A - B.  Keep an element of A only when a
 *          search of B fails.
 * Compile: gcc q19.c -o q19
 */
#include <stdio.h>

#define MAX 100

static int contains(const int u[], int m, int v)
{
    int i;
    for (i = 0; i < m; i++)
        if (u[i] == v) return 1;
    return 0;
}

int main(void)
{
    int a[MAX], b[MAX], d[MAX];
    int n1, n2, i, m = 0;

    printf("Enter size of array A (1-%d): ", MAX);
    if (scanf("%d", &n1) != 1 || n1 < 1 || n1 > MAX) { printf("Invalid size.\n"); return 1; }
    printf("Enter %d elements of A: ", n1);
    for (i = 0; i < n1; i++) scanf("%d", &a[i]);

    printf("Enter size of array B (1-%d): ", MAX);
    if (scanf("%d", &n2) != 1 || n2 < 1 || n2 > MAX) { printf("Invalid size.\n"); return 1; }
    printf("Enter %d elements of B: ", n2);
    for (i = 0; i < n2; i++) scanf("%d", &b[i]);

    for (i = 0; i < n1; i++)
        if (!contains(b, n2, a[i]) && !contains(d, m, a[i]))
            d[m++] = a[i];

    printf("A - B (%d elements): ", m);
    if (m == 0) printf("none");
    for (i = 0; i < m; i++) printf("%d ", d[i]);
    printf("\n");

    return 0;
}
