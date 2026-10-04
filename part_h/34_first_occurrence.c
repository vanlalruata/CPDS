/* q34.c - Find the FIRST occurrence of an element.
 * Concept: Scan from left to right and stop at the very first match.
 * Compile: gcc q34.c -o q34
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, key, first = -1;

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

    for (i = 0; i < n; i++) {
        if (a[i] == key) { first = i; break; }
    }

    if (first >= 0)
        printf("First occurrence of %d is at index %d (position %d).\n",
               key, first, first + 1);
    else
        printf("%d is not present in the array.\n", key);

    return 0;
}
