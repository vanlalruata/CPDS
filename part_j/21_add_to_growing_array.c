/* part_j / q21: Add elements to a dynamically growing array (realloc per add). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    int *arr = NULL;
    printf("How many elements to add? ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;
    for (i = 0; i < n; i++) {
        int val;
        printf("Element %d: ", i);
        scanf("%d", &val);
        int *tmp = (int *)realloc(arr, (size_t)(i + 1) * sizeof(int));
        if (!tmp) { free(arr); return 1; }
        arr = tmp;
        arr[i] = val;
    }
    printf("Final array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
