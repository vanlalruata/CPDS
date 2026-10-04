/* q30.c - Sort an array in DESCENDING order.
 * Concept: Same exchange sort as ascending, but reverse the comparison
 *          operator so bigger values move to the front.
 * Compile: gcc q30.c -o q30
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, j, temp;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] < a[j]) {        /* '<' gives descending order */
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    printf("Array in descending order: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
