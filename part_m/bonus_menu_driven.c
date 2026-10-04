/**
 * bonus_menu_driven.c - Part M: Algorithm Analysis & Complexity Workbench
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>

void compare_searches(void) {
    int n = 100;
    int arr[100];
    for (int i = 0; i < n; i++) arr[i] = (i + 1) * 2;

    int key;
    printf("\n--- Linear Search O(N) vs Binary Search O(log N) ---\n");
    printf("Array has %d sorted elements (2, 4, 6, ..., 200).\n", n);
    printf("Enter target value to search: ");
    if (scanf("%d", &key) != 1) return;

    // Linear search step count
    int linear_steps = 0, linear_idx = -1;
    for (int i = 0; i < n; i++) {
        linear_steps++;
        if (arr[i] == key) {
            linear_idx = i;
            break;
        }
    }

    // Binary search step count
    int binary_steps = 0, binary_idx = -1;
    int low = 0, high = n - 1;
    while (low <= high) {
        binary_steps++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            binary_idx = mid;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("\nSearch Results for Key %d:\n", key);
    if (linear_idx != -1) printf("Status: Found at index %d (Binary found at %d)\n", linear_idx, binary_idx);
    else printf("Status: Not Found\n");
    printf("Linear Search Comparisons: %d  (Time Complexity: O(N))\n", linear_steps);
    printf("Binary Search Comparisons: %d  (Time Complexity: O(log2 N))\n", binary_steps);
}

void compare_sorts(void) {
    int n = 10;
    int original[10] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    int arr1[10], arr2[10];
    for (int i = 0; i < n; i++) { arr1[i] = original[i]; arr2[i] = original[i]; }

    printf("\n--- Bubble Sort vs Insertion Sort Operation Counter ---\n");
    printf("Input: ");
    for (int i = 0; i < n; i++) printf("%d ", original[i]);
    printf("\n");

    // Bubble Sort comparisons & swaps
    int bubble_comps = 0, bubble_swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bubble_comps++;
            if (arr1[j] > arr1[j + 1]) {
                bubble_swaps++;
                int t = arr1[j]; arr1[j] = arr1[j + 1]; arr1[j + 1] = t;
            }
        }
    }

    // Insertion Sort comparisons & shifts
    int insert_comps = 0, insert_shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = arr2[i];
        int j = i - 1;
        while (j >= 0) {
            insert_comps++;
            if (arr2[j] > key) {
                insert_shifts++;
                arr2[j + 1] = arr2[j];
                j--;
            } else {
                break;
            }
        }
        arr2[j + 1] = key;
    }

    printf("\nBubble Sort:    %d comparisons, %d swaps (Worst/Avg O(N^2))\n", bubble_comps, bubble_swaps);
    printf("Insertion Sort: %d comparisons, %d shifts (Worst/Avg O(N^2))\n", insert_comps, insert_shifts);
}

int recursive_call_count = 0;
unsigned long long fact_recursive(int n) {
    recursive_call_count++;
    if (n <= 1) return 1;
    return n * fact_recursive(n - 1);
}

void compare_factorial(void) {
    int n;
    printf("\n--- Iterative vs Recursive Factorial (Stack Space Analysis) ---\n");
    printf("Enter n (0-20): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) return;

    // Iterative
    unsigned long long fact_iter = 1;
    int iter_loops = 0;
    for (int i = 1; i <= n; i++) {
        iter_loops++;
        fact_iter *= i;
    }

    // Recursive
    recursive_call_count = 0;
    unsigned long long fact_rec = fact_recursive(n);

    printf("Factorial of %d = %llu (Recursive verified: %llu)\n", n, fact_iter, fact_rec);
    printf("Iterative: %d loop cycles | Space Complexity: O(1)\n", iter_loops);
    printf("Recursive: %d call frames | Space Complexity: O(N) call stack frames\n", recursive_call_count);
}

void complexity_growth_table(void) {
    printf("\n--- Asymptotic Growth Rates Demonstration Table ---\n");
    printf("%-6s | %-8s | %-12s | %-12s | %-12s\n", "N", "O(log2 N)", "O(N)", "O(N log2 N)", "O(N^2)");
    printf("------------------------------------------------------------------\n");
    int sizes[] = {8, 16, 32, 64, 128, 256, 512, 1024};
    int num_sizes = (int)(sizeof(sizes) / sizeof(sizes[0]));
    for (int idx = 0; idx < num_sizes; idx++) {
        int n = sizes[idx];
        int log_n = 0;
        int temp = n;
        while (temp > 1) { log_n++; temp /= 2; }
        long long n_log_n = (long long)n * log_n;
        long long n_sq = (long long)n * n;
        printf("%-6d | %-8d | %-12d | %-12lld | %-12lld\n", n, log_n, n, n_log_n, n_sq);
    }
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part M: Algorithm Complexity Analysis Hub \n");
        printf("============================================\n");
        printf("1. Compare Search Complexities (Linear vs Binary)\n");
        printf("2. Compare Sorting Complexities (Bubble vs Insertion)\n");
        printf("3. Iterative vs Recursive Factorial (Space Analysis)\n");
        printf("4. Asymptotic Growth Rates Reference Table\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: compare_searches(); break;
            case 2: compare_sorts(); break;
            case 3: compare_factorial(); break;
            case 4: complexity_growth_table(); break;
            case 5: printf("Exiting Part M Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
