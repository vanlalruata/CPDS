/* q14.c - Reverse an array (in place).
 * Concept: Swap the first with the last, second with second-last, ...
 *          until the two indices meet in the middle.
 * Compile: gcc q14.c -o q14
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, left, right, temp;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Original array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    left = 0;
    right = n - 1;
    while (left < right) {
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }

    printf("Reversed array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
