/* q18.c - Reverse an array using pointers (no indexing).
 * Concept: Use two pointers, one at the front and one at the back;
 *          swap the pointed-to values and move them towards each other.
 * Compile: gcc q18.c -o q18
 */
#include <stdio.h>

#define MAX 50

int main(void)
{
    int a[MAX];
    int n, i, temp;
    int *left, *right, *p;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", a + i);

    printf("Original: ");
    for (p = a; p < a + n; p++) printf("%d ", *p);
    printf("\n");

    left  = a;
    right = a + n - 1;
    while (left < right) {
        temp   = *left;
        *left  = *right;
        *right = temp;
        left++;
        right--;
    }

    printf("Reversed: ");
    for (p = a; p < a + n; p++) printf("%d ", *p);
    printf("\n");

    return 0;
}
