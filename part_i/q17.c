/* q17.c - Print an array WITHOUT using the [] indexing operator.
 * Concept: a[i] is defined as *(a + i).  Using only * and pointer
 *          arithmetic gives the same result.
 * Compile: gcc q17.c -o q17
 */
#include <stdio.h>

#define MAX 50

int main(void)
{
    int a[MAX];
    int n, i;
    int *p;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", a + i);            /* &a[i] written as a + i */

    printf("\nUsing *(a + i):   ");
    for (i = 0; i < n; i++)
        printf("%d ", *(a + i));

    printf("\nUsing *p, p++ :   ");
    for (p = a; p < a + n; p++)
        printf("%d ", *p);

    printf("\nUsing *(p - k) backwards: ");
    p = a + n - 1;
    for (i = 0; i < n; i++)
        printf("%d ", *(p - i));
    printf("\n");

    return 0;
}
