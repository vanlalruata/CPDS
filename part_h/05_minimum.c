/* q5.c - Find the minimum element of an array.
 * Concept: Same single-pass idea as maximum, but keep the smaller value.
 * Compile: gcc q5.c -o q5
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, min, pos;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    min = a[0];
    pos = 0;
    for (i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            pos = i;
        }
    }

    printf("Minimum element = %d (at index %d)\n", min, pos);
    return 0;
}
