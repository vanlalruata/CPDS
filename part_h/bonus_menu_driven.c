/**
 * bonus_menu_driven.c - Part H: Complete Array Operations Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>

#define MAX_SIZE 100

void display_array(const int arr[], int n) {
    printf("Array [%d]: ", n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insert_element(int arr[], int *n) {
    if (*n >= MAX_SIZE) {
        printf("Array is full!\n");
        return;
    }
    int pos, val;
    printf("Enter position (0 to %d) and value: ", *n);
    if (scanf("%d %d", &pos, &val) != 2 || pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
    printf("Element inserted successfully.\n");
    display_array(arr, *n);
}

void delete_element(int arr[], int *n) {
    if (*n <= 0) {
        printf("Array is empty!\n");
        return;
    }
    int pos;
    printf("Enter index to delete (0 to %d): ", *n - 1);
    if (scanf("%d", &pos) != 1 || pos < 0 || pos >= *n) {
        printf("Invalid index!\n");
        return;
    }
    int val = arr[pos];
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Deleted %d from index %d.\n", val, pos);
    display_array(arr, *n);
}

void search_ops(const int arr[], int n) {
    int key;
    printf("Enter value to search: ");
    if (scanf("%d", &key) != 1) return;

    // Linear search
    int found = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) { found = i; break; }
    }
    if (found != -1) printf("Found %d at index %d (Linear Search).\n", key, found);
    else printf("Element %d not found.\n", key);
}

void sort_ops(int arr[], int n) {
    int choice;
    printf("\n--- Sorting Algorithms ---\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nEnter choice: ");
    if (scanf("%d", &choice) != 1) return;

    if (choice == 1) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
                }
            }
        }
        printf("Bubble sorted: ");
    } else if (choice == 2) {
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) min_idx = j;
            }
            int t = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = t;
        }
        printf("Selection sorted: ");
    } else if (choice == 3) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        printf("Insertion sorted: ");
    }
    display_array(arr, n);
}

void matrix_multiplication(void) {
    int r1, c1, r2, c2;
    printf("\n--- Matrix Multiplication ---\n");
    printf("Enter rows and cols for Matrix A: ");
    if (scanf("%d %d", &r1, &c1) != 2 || r1 < 1 || c1 < 1 || r1 > 10 || c1 > 10) return;
    printf("Enter rows and cols for Matrix B: ");
    if (scanf("%d %d", &r2, &c2) != 2 || r2 < 1 || c2 < 1 || r2 > 10 || c2 > 10) return;

    if (c1 != r2) {
        printf("Matrix multiplication not possible! Columns of A must equal Rows of B.\n");
        return;
    }

    int A[10][10], B[10][10], C[10][10] = {0};
    printf("Enter elements of Matrix A (%d x %d):\n", r1, c1);
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B (%d x %d):\n", r2, c2);
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++) scanf("%d", &B[i][j]);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Product Matrix C (%d x %d):\n", r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) printf("%5d ", C[i][j]);
        printf("\n");
    }
}

int main(void) {
    int arr[MAX_SIZE] = {45, 12, 89, 34, 7, 23, 67};
    int n = 7;
    int choice;

    do {
        printf("\n============================================\n");
        printf("  Part H: Master Array Operations Hub       \n");
        printf("============================================\n");
        printf("Current "); display_array(arr, n);
        printf("1. Insert Element at Position\n");
        printf("2. Delete Element at Position\n");
        printf("3. Search for an Element\n");
        printf("4. Sort Array (Bubble/Selection/Insertion)\n");
        printf("5. Matrix Multiplication (2D Array Demo)\n");
        printf("6. Exit\n");
        printf("Enter choice (1-6): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: insert_element(arr, &n); break;
            case 2: delete_element(arr, &n); break;
            case 3: search_ops(arr, n); break;
            case 4: sort_ops(arr, n); break;
            case 5: matrix_multiplication(); break;
            case 6: printf("Exiting Part H Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
