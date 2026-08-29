/* q27.c - Reverse an array using pointers inside a function.
 * Concept: The function receives only the base address, yet it can
 *          rearrange the caller's data because pointers give access to
 *          the same memory.
 * Compile: gcc q27.c -o q27
 */
#include <stdio.h>

#define MAX 50

static void reverseArray(int *a, int n)
{
    int *left  = a;
    int *right = a + n - 1;
    int temp;
    while (left < right) {
        temp   = *left;
        *left  = *right;
        *right = temp;
        left++;
        right--;
    }
}

static void show(const int *a, int n)
{
    int i;
    for (i = 0; i < n; i++) printf("%d ", *(a + i));
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

    printf("Original: ");
    show(a, n);

    reverseArray(a, n);

    printf("Reversed: ");
    show(a, n);

    return 0;
}
