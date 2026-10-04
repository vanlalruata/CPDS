/* q27.c - Selection sort (ascending).
 * Concept: In pass i, find the index of the smallest element in
 *          a[i..n-1] and swap it with a[i].  Exactly n-1 swaps.
 * Compile: gcc q27.c -o q27
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, j, minIdx, temp;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Unsorted: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[minIdx])
                minIdx = j;

        if (minIdx != i) {
            temp = a[i];
            a[i] = a[minIdx];
            a[minIdx] = temp;
        }

        printf("After pass %d: ", i + 1);
        for (j = 0; j < n; j++) printf("%d ", a[j]);
        printf("\n");
    }

    printf("Sorted (ascending): ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
