/**
 * bonus_menu_driven.c - Part J: Dynamic Memory Allocation (DMA) Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>

void malloc_vs_calloc_demo(void) {
    int n = 5;
    printf("\n--- malloc() vs calloc() Memory Initialization ---\n");

    int *m_arr = (int *)malloc(n * sizeof(int));
    int *c_arr = (int *)calloc(n, sizeof(int));

    if (!m_arr || !c_arr) {
        printf("Memory allocation failed!\n");
        free(m_arr);
        free(c_arr);
        return;
    }

    printf("calloc() allocated %d ints (guaranteed zero-initialized):\n", n);
    for (int i = 0; i < n; i++) printf("%d ", c_arr[i]);
    printf("\n");

    printf("malloc() allocated %d ints (allocates raw uninitialized memory bytes):\n", n);
    printf("Initializing malloc array with sequential numbers: ");
    for (int i = 0; i < n; i++) {
        m_arr[i] = (i + 1) * 10;
        printf("%d ", m_arr[i]);
    }
    printf("\n");

    free(m_arr);
    free(c_arr);
    printf("Both memory blocks safely freed.\n");
}

void realloc_resizable_array(void) {
    printf("\n--- realloc() Resizable Dynamic Array ---\n");
    int capacity = 2, count = 0;
    int *arr = (int *)malloc(capacity * sizeof(int));
    if (!arr) return;

    printf("Initial capacity: %d. Enter positive integers to append (enter -1 to stop):\n", capacity);
    int val;
    while (1) {
        printf("Enter integer: ");
        if (scanf("%d", &val) != 1 || val == -1) break;

        if (count == capacity) {
            capacity *= 2;
            int *temp = (int *)realloc(arr, capacity * sizeof(int));
            if (!temp) {
                printf("realloc failed! Retaining original data.\n");
                break;
            }
            arr = temp;
            printf("[realloc] Capacity doubled to %d!\n", capacity);
        }
        arr[count++] = val;
    }

    printf("Dynamic array contents (%d elements, %d capacity): ", count, capacity);
    for (int i = 0; i < count; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    arr = NULL;
    printf("Dynamic array freed and pointer set to NULL.\n");
}

void dynamic_2d_matrix(void) {
    int rows, cols;
    printf("\n--- Dynamic 2D Matrix (Array of Pointers) ---\n");
    printf("Enter rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows < 1 || cols < 1 || rows > 50 || cols > 50) return;

    // Allocate array of row pointers
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (!matrix) return;

    // Allocate each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i + 1) * 10 + (j + 1);
        }
    }

    printf("Allocated dynamic matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free matrix rows, then row pointers
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
    printf("Dynamic matrix successfully and completely deallocated.\n");
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part J: Dynamic Memory Allocation Lab     \n");
        printf("============================================\n");
        printf("1. malloc() vs calloc() Initialization\n");
        printf("2. Resizable Dynamic Array with realloc()\n");
        printf("3. Dynamic 2D Matrix (Double Pointer Allocation)\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: malloc_vs_calloc_demo(); break;
            case 2: realloc_resizable_array(); break;
            case 3: dynamic_2d_matrix(); break;
            case 4: printf("Exiting Part J Lab. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
