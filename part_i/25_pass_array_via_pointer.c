/* q25.c - Pass an array to a function using a pointer.
 * Concept: int *p and int a[] are the same in a parameter list.  The
 *          function works on the caller's array, so changes are visible
 *          after it returns.
 * Compile: gcc q25.c -o q25
 */
#include <stdio.h>

#define MAX 50

static void printArray(const int *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", *(p + i));
    printf("\n");
}

/* multiplies every element by a factor - modifies the caller's array */
static void scaleArray(int *p, int n, int factor)
{
    int i;
    for (i = 0; i < n; i++)
        p[i] = p[i] * factor;
}

int main(void)
{
    int a[MAX];
    int n, i, factor;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Enter a multiplying factor: ");
    if (scanf("%d", &factor) != 1) { printf("Invalid input.\n"); return 1; }

    printf("Array before : ");
    printArray(a, n);

    scaleArray(a, n, factor);

    printf("Array after  : ");
    printArray(a, n);

    return 0;
}
