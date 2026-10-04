/* q32.c - Dynamically allocate an ARRAY with malloc, use it and free it.
 * Concept: malloc(n * sizeof(int)) creates an n-element block that can
 *          be used exactly like an array (p[i] or *(p + i)).  The size
 *          is decided at run time.
 * Compile: gcc q32.c -o q32
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p;
    int n, i;
    long sum = 0;

    printf("How many integers do you want to store? ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid size.\n");
        return 1;
    }

    p = (int *) malloc((size_t) n * sizeof(int));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Allocated %lu bytes at %p\n",
           (unsigned long) ((size_t) n * sizeof(int)), (void *) p);

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", p + i);
        sum += p[i];
    }

    printf("Elements : ");
    for (i = 0; i < n; i++) printf("%d ", *(p + i));
    printf("\nSum      = %ld\n", sum);
    printf("Average  = %.4f\n", (double) sum / n);

    free(p);                       /* every malloc needs one free */
    p = NULL;
    printf("Dynamic array freed.\n");

    return 0;
}
