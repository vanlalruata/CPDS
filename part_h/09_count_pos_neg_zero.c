/* q9.c - Count positive, negative and zero elements.
 * Concept: A simple three-way classification using if / else if / else.
 * Compile: gcc q9.c -o q9
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i;
    int pos = 0, neg = 0, zero = 0;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > 0)      pos++;
        else if (a[i] < 0) neg++;
        else               zero++;
    }

    printf("Positive elements = %d\n", pos);
    printf("Negative elements = %d\n", neg);
    printf("Zero elements     = %d\n", zero);
    return 0;
}
