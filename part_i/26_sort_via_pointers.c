/* q26.c - Sort an array using pointers (bubble sort with pointers).
 * Concept: Instead of indices, compare *(p) with *(p + 1) and swap the
 *          pointed-to values.  The array is sorted in place.
 * Compile: gcc q26.c -o q26
 */
#include <stdio.h>

#define MAX 50

static void sortAsc(int *a, int n)
{
    int *p, *last, temp, swapped;
    for (last = a + n - 1; last > a; last--) {
        swapped = 0;
        for (p = a; p < last; p++) {
            if (*p > *(p + 1)) {
                temp = *p;
                *p = *(p + 1);
                *(p + 1) = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

static void show(const int *a, int n)
{
    const int *p;
    for (p = a; p < a + n; p++) printf("%d ", *p);
    printf("\n");
}

int main(void)
{
    int a[MAX];
    int n, i;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", a + i);

    printf("Before sorting: ");
    show(a, n);

    sortAsc(a, n);

    printf("After sorting : ");
    show(a, n);

    return 0;
}
