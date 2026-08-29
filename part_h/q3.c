/* q3.c - Average (arithmetic mean) of array elements.
 * Concept: average = sum / n.  Cast to double so the division is not
 *          truncated by integer arithmetic.
 * Compile: gcc q3.c -o q3
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i;
    long sum = 0;
    double avg;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    avg = (double) sum / n;

    printf("Sum     = %ld\n", sum);
    printf("Average = %.4f\n", avg);
    return 0;
}
