/* q7.c - Second smallest element of an array (distinct values).
 * Concept: Mirror of the second-largest logic; keep smallest and
 *          second smallest while scanning once.
 * Compile: gcc q7.c -o q7
 */
#include <stdio.h>
#include <limits.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i;
    int first = INT_MAX, second = INT_MAX;
    int foundSecond = 0;

    printf("Enter number of elements (2-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 2 || n > MAX) {
        printf("Invalid size (need at least 2).\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        if (a[i] < first) {
            second = first;
            first = a[i];
            if (second != INT_MAX) foundSecond = 1;
        } else if (a[i] > first && (a[i] < second || !foundSecond)) {
            second = a[i];
            foundSecond = 1;
        }
    }

    printf("Smallest element = %d\n", first);
    if (foundSecond)
        printf("Second smallest  = %d\n", second);
    else
        printf("Second smallest does not exist (all elements are equal).\n");

    return 0;
}
