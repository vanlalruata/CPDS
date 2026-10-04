/* part_j / q14: Demonstrate calloc() initialization (values start at 0). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 5, i;
    int *arr = (int *)calloc((size_t)n, sizeof(int));
    if (!arr) return 1;
    printf("calloc initializes to zero:\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
    return 0;
}
