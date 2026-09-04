/*
 * Program: q21.c
 * Identifies and corrects a memory leak. The buggy version forgets to free
 * the array before returning; the corrected version frees every allocation.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * BUGGY VERSION (do not use):
 *
 *   void buggy(void) {
 *       int *arr = malloc(5 * sizeof(int));
 *       if (arr == NULL) return;
 *       for (int i = 0; i < 5; i++) arr[i] = i;
 *       printf("buggy done\n");
 *       // <-- forgot free(arr); -> memory leak
 *   }
 */

static void correct(void) {
    int *arr = malloc(5 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "malloc failed\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    printf("Sum = %d\n", arr[0] + arr[1] + arr[2] + arr[3] + arr[4]);

    free(arr);
}

int main(void) {
    correct();
    printf("All memory freed correctly.\n");
    return 0;
}