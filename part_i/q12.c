/* q12.c - Decrementing a pointer.
 * Concept: p-- moves the pointer back by sizeof(*p) bytes, i.e. to the
 *          previous element of the array.
 * Compile: gcc q12.c -o q12
 */
#include <stdio.h>

#define N 5

int main(void)
{
    int a[N];
    int *p;
    int i;

    printf("Enter %d integers: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    p = &a[N - 1];             /* start at the last element */
    printf("\nStart : p = %p, *p = %d (last element)\n", (void *) p, *p);

    for (i = 1; i < N; i++) {
        p--;                   /* move backward one int */
        printf("p-- (%d) : p = %p, *p = %d\n", i, (void *) p, *p);
    }

    printf("\np now points to a[0]? %s\n", (p == a) ? "yes" : "no");
    printf("Each decrement moved the address back %lu bytes.\n",
           (unsigned long) sizeof(int));

    return 0;
}
