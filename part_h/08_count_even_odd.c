/* q8.c - Count even and odd elements of an array.
 * Concept: n % 2 == 0 means even.  For negative numbers in C the
 *          remainder may be -1, so compare with != 0 for odd.
 * Compile: gcc q8.c -o q8
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, even = 0, odd = 0;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Even elements: ");
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0) { printf("%d ", a[i]); even++; }
    printf("\nOdd  elements: ");
    for (i = 0; i < n; i++)
        if (a[i] % 2 != 0) { printf("%d ", a[i]); odd++; }
    printf("\n");

    printf("Count of even = %d\n", even);
    printf("Count of odd  = %d\n", odd);
    return 0;
}
