/* q17.c - Common elements (intersection) of two arrays.
 * Concept: For every element of A check whether it exists in B.
 *          A small "already printed" check avoids repeating values.
 * Compile: gcc q17.c -o q17
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX], b[MAX], common[MAX];
    int n1, n2, i, j, cnt = 0, exists;

    printf("Enter size of first array (1-%d): ", MAX);
    if (scanf("%d", &n1) != 1 || n1 < 1 || n1 > MAX) { printf("Invalid size.\n"); return 1; }
    printf("Enter %d elements of A: ", n1);
    for (i = 0; i < n1; i++) scanf("%d", &a[i]);

    printf("Enter size of second array (1-%d): ", MAX);
    if (scanf("%d", &n2) != 1 || n2 < 1 || n2 > MAX) { printf("Invalid size.\n"); return 1; }
    printf("Enter %d elements of B: ", n2);
    for (i = 0; i < n2; i++) scanf("%d", &b[i]);

    for (i = 0; i < n1; i++) {
        /* is a[i] present in B ? */
        exists = 0;
        for (j = 0; j < n2; j++)
            if (b[j] == a[i]) { exists = 1; break; }
        if (!exists) continue;

        /* already collected ? */
        exists = 0;
        for (j = 0; j < cnt; j++)
            if (common[j] == a[i]) { exists = 1; break; }
        if (!exists) common[cnt++] = a[i];
    }

    printf("Common elements (%d): ", cnt);
    if (cnt == 0) printf("none");
    for (i = 0; i < cnt; i++) printf("%d ", common[i]);
    printf("\n");

    return 0;
}
