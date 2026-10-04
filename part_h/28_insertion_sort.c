/* q28.c - Insertion sort (ascending).
 * Concept: Treat a[0..i-1] as a sorted hand of cards and insert a[i]
 *          into its correct place by shifting larger elements right.
 * Compile: gcc q28.c -o q28
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, j, key;

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

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        printf("After inserting %d: ", key);
        for (j = 0; j < n; j++) printf("%d ", a[j]);
        printf("\n");
    }

    printf("Sorted (ascending): ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
