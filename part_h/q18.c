/* q18.c - Union of two arrays (all distinct elements of A and B).
 * Concept: Insert every element of A and B into a result array, but
 *          only if it is not already present there.
 * Compile: gcc q18.c -o q18
 */
#include <stdio.h>

#define MAX 100

/* helper: is value v already in array u[0..m-1] ? */
static int contains(const int u[], int m, int v)
{
    int i;
    for (i = 0; i < m; i++)
        if (u[i] == v) return 1;
    return 0;
}

int main(void)
{
    int a[MAX], b[MAX], u[2 * MAX];
    int n1, n2, i, m = 0;

    printf("Enter size of first array (1-%d): ", MAX);
    if (scanf("%d", &n1) != 1 || n1 < 1 || n1 > MAX) { printf("Invalid size.\n"); return 1; }
    printf("Enter %d elements of A: ", n1);
    for (i = 0; i < n1; i++) scanf("%d", &a[i]);

    printf("Enter size of second array (1-%d): ", MAX);
    if (scanf("%d", &n2) != 1 || n2 < 1 || n2 > MAX) { printf("Invalid size.\n"); return 1; }
    printf("Enter %d elements of B: ", n2);
    for (i = 0; i < n2; i++) scanf("%d", &b[i]);

    for (i = 0; i < n1; i++)
        if (!contains(u, m, a[i])) u[m++] = a[i];
    for (i = 0; i < n2; i++)
        if (!contains(u, m, b[i])) u[m++] = b[i];

    printf("Union (%d elements): ", m);
    for (i = 0; i < m; i++) printf("%d ", u[i]);
    printf("\n");

    return 0;
}
