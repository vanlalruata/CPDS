/*
 * Program: q25.c
 * Builds a dynamic integer list by reallocating in a loop. The list starts
 * as NULL and grows as the user inputs numbers; input ends when the user
 * enters the sentinel value 0. Prints all values and frees the list.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *list = NULL;
    int size = 0;
    int capacity = 0;
    const int sentinel = 0;

    printf("Enter integers (0 to stop):\n");
    for (;;) {
        int value;
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(list);
            return 1;
        }
        if (value == sentinel) break;

        if (size == capacity) {
            capacity = (capacity == 0) ? 4 : capacity * 2;
            int *tmp = realloc(list, (size_t)capacity * sizeof(int));
            if (tmp == NULL) {
                fprintf(stderr, "realloc failed\n");
                free(list);
                return 1;
            }
            list = tmp;
        }
        list[size++] = value;
    }

    printf("\nList contents (%d items):\n", size);
    for (int i = 0; i < size; i++) {
        printf("list[%d] = %d\n", i, list[i]);
    }

    free(list);
    list = NULL;
    return 0;
}