/* q35.c - Find the LAST occurrence of an element.
 * Concept: Scan from right to left and stop at the first match found,
 *          which is the last occurrence in left-to-right order.
 * Compile: gcc q35.c -o q35
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, key, last = -1;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to find: ");
    scanf("%d", &key);

    for (i = n - 1; i >= 0; i--) {
        if (a[i] == key) { last = i; break; }
    }

    if (last >= 0)
        printf("Last occurrence of %d is at index %d (position %d).\n",
               key, last, last + 1);
    else
        printf("%d is not present in the array.\n", key);

    return 0;
}
