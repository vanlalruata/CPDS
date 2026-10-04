/* q11.c - Incrementing a pointer.
 * Concept: p++ does not add 1 byte; it advances the pointer by
 *          sizeof(*p) bytes so that it points to the next element.
 * Compile: gcc q11.c -o q11
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

    p = a;                     /* points to a[0] */
    printf("\nStart : p = %p, *p = %d\n", (void *) p, *p);

    for (i = 1; i < N; i++) {
        p++;                   /* move forward one int */
        printf("p++ (%d) : p = %p, *p = %d\n", i, (void *) p, *p);
    }

    printf("\nEach increment moved the address by sizeof(int) = %lu bytes.\n",
           (unsigned long) sizeof(int));

    return 0;
}
