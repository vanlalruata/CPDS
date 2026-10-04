/* q10.c - Linear (sequential) search for an element in an array.
 * Concept: Compare the key with each element until it is found.
 *          Works on unsorted data; time complexity O(n).
 * Compile: gcc q10.c -o q10
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, key, found = -1;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            found = i;
            break;                 /* stop at the first match */
        }
    }

    if (found != -1)
        printf("%d found at index %d (position %d).\n", key, found, found + 1);
    else
        printf("%d is not present in the array.\n", key);

    return 0;
}
