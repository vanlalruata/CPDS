/* part_j / q1: Allocate memory for one integer using malloc().
   Reads an integer, stores it in dynamically allocated memory, prints it, frees it. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = (int *)malloc(sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Enter an integer: ");
    if (scanf("%d", p) != 1) {
        free(p);
        return 1;
    }
    printf("You entered: %d\n", *p);
    free(p);
    return 0;
}
