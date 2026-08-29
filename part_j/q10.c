/* part_j / q10: Search a dynamically allocated array for a value. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, key, found = 0;
    printf("Enter size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr) return 1;
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter value to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Found at index %d\n", i);
            found = 1;
        }
    }
    if (!found) printf("Value not found\n");
    free(arr);
    return 0;
}
