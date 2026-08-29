/* part_j / q20: Build a dynamically resizable integer array (loop, realloc to grow). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int cap = 2, count = 0, i, val;
    int *arr = (int *)malloc((size_t)cap * sizeof(int));
    if (!arr) return 1;
    printf("Enter integers (enter -1 to stop):\n");
    while (scanf("%d", &val) == 1 && val != -1) {
        if (count == cap) {
            cap *= 2;
            int *tmp = (int *)realloc(arr, (size_t)cap * sizeof(int));
            if (!tmp) { free(arr); return 1; }
            arr = tmp;
            printf("(resized capacity to %d)\n", cap);
        }
        arr[count++] = val;
    }
    printf("You entered %d values: ", count);
    for (i = 0; i < count; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
