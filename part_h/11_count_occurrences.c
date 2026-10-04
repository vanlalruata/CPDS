/* q11.c - Count how many times an element occurs in an array.
 * Concept: Traverse the whole array (do NOT break) and increment a
 *          counter on every match.
 * Compile: gcc q11.c -o q11
 */
#include <stdio.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i, key, count = 0;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to count: ");
    scanf("%d", &key);

    printf("Found at index(es): ");
    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("%d ", i);
            count++;
        }
    }
    if (count == 0) printf("(none)");
    printf("\n%d occurs %d time(s).\n", key, count);

    return 0;
}
