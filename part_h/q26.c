/* q26.c - Bubble sort (ascending) with pass-by-pass display.
 * Concept: Repeatedly compare adjacent pairs and swap when out of
 *          order; after pass i the largest i elements are in place.
 *          Best case O(n) with the "swapped" flag, worst case O(n^2).
 * Compile: gcc q26.c -o q26
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, j, temp, swapped;

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
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        printf("After pass %d: ", i + 1);
        for (j = 0; j < n; j++) printf("%d ", a[j]);
        printf("\n");
        if (!swapped) break;          /* already sorted */
    }

    printf("Sorted (ascending): ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
