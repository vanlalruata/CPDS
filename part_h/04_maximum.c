/* q4.c - Find the maximum element of an array.
 * Concept: Assume the first element is the maximum, then compare with
 *          every remaining element and update when a bigger one is found.
 * Compile: gcc q4.c -o q4
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, max, pos;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[0];
    pos = 0;
    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            pos = i;
        }
    }

    printf("Maximum element = %d (at index %d)\n", max, pos);
    return 0;
}
