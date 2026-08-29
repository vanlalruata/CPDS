/* q6.c - Second largest element of an array (distinct values).
 * Concept: Track the largest and the second largest in one pass.
 *          Duplicates of the largest are skipped so that for
 *          {5,5,3} the second largest is 3.
 * Compile: gcc q6.c -o q6
 */
#include <stdio.h>
#include <limits.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i;
    int first = INT_MIN, second = INT_MIN;
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
        if (a[i] > first) {
            second = first;
            first = a[i];
            if (second != INT_MIN) foundSecond = 1;
        } else if (a[i] < first && (a[i] > second || !foundSecond)) {
            second = a[i];
            foundSecond = 1;
        }
    }

    printf("Largest element = %d\n", first);
    if (foundSecond)
        printf("Second largest  = %d\n", second);
    else
        printf("Second largest does not exist (all elements are equal).\n");

    return 0;
}
