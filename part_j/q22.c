/* part_j / q22: Implement a simple dynamic list using realloc().
   Supports appending elements until the user enters -1. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} List;

int main(void) {
    List list = { NULL, 0, 0 };
    int val;
    printf("Enter integers (-1 to stop):\n");
    while (scanf("%d", &val) == 1 && val != -1) {
        if (list.size == list.capacity) {
            list.capacity = list.capacity == 0 ? 4 : list.capacity * 2;
            int *tmp = (int *)realloc(list.data, (size_t)list.capacity * sizeof(int));
            if (!tmp) { free(list.data); return 1; }
            list.data = tmp;
        }
        list.data[list.size++] = val;
    }
    printf("List: ");
    for (int i = 0; i < list.size; i++) printf("%d ", list.data[i]);
    printf("\n");
    free(list.data);
    return 0;
}
