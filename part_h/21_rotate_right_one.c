/* q21.c - Rotate an array RIGHT by one position.
 * Concept: Save the last element, shift everything one place right
 *          (loop backwards!), then place the saved value at index 0.
 *          {1,2,3,4} -> {4,1,2,3}
 * Compile: gcc q21.c -o q21
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, last;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Before rotation: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    last = a[n - 1];
    for (i = n - 1; i > 0; i--)
        a[i] = a[i - 1];
    a[0] = last;

    printf("After right rotation by 1: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
