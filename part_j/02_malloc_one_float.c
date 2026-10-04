/* part_j / q2: Allocate memory for one float using malloc().
   Demonstrates allocating a single float on the heap. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float *p = (float *)malloc(sizeof(float));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Enter a float: ");
    if (scanf("%f", p) != 1) {
        free(p);
        return 1;
    }
    printf("You entered: %.3f\n", *p);
    free(p);
    return 0;
}
