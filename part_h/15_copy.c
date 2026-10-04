/* q15.c - Copy one array into another array.
 * Concept: Element-by-element assignment b[i] = a[i].  Note that
 *          "b = a" is illegal for arrays in C.
 * Compile: gcc q15.c -o q15
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX], b[MAX];
    int n, i;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
        b[i] = a[i];               /* the actual copy */

    printf("Source array      : ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\nDestination array : ");
    for (i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");

    return 0;
}
