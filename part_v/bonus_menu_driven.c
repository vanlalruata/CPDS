/**
 * bonus_menu_driven.c - Part V: High-Value Exam & Advanced Memory Practical Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exam_dynamic_stats(void) {
    int n;
    printf("\n--- Exam Problem: Dynamic Array Sum, Average, Max, Min ---\n");
    printf("Enter number of scores to allocate dynamically: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) return;

    double *scores = (double *)malloc(n * sizeof(double));
    if (!scores) {
        printf("Out of heap memory!\n");
        return;
    }

    printf("Enter %d scores: ", n);
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &scores[i]);
        sum += scores[i];
    }

    double max = scores[0], min = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] > max) max = scores[i];
        if (scores[i] < min) min = scores[i];
    }

    printf("Statistics:\n");
    printf("  Sum:     %.2f\n", sum);
    printf("  Average: %.2f\n", sum / n);
    printf("  Max:     %.2f\n", max);
    printf("  Min:     %.2f\n", min);

    free(scores);
    scores = NULL;
}

void exam_string_array_dma(void) {
    int count;
    printf("\n--- Exam Problem: Dynamic Array of Strings ---\n");
    printf("Enter number of strings to store: ");
    if (scanf("%d", &count) != 1 || count < 1 || count > 20) return;

    char **names = (char **)malloc(count * sizeof(char *));
    if (!names) return;

    char buffer[128];
    for (int i = 0; i < count; i++) {
        printf("Enter string %d: ", i + 1);
        scanf(" %127s", buffer);
        names[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(names[i], buffer);
    }

    printf("\nDynamically Stored Strings:\n");
    for (int i = 0; i < count; i++) {
        printf("  [%d] %s (length %zu, allocated at %p)\n",
               i + 1, names[i], strlen(names[i]), (void *)names[i]);
    }

    // Free individual strings, then array of pointers
    for (int i = 0; i < count; i++) free(names[i]);
    free(names);
    names = NULL;
    printf("All dynamic string memory successfully freed.\n");
}

void exam_dynamic_matrix_addition(void) {
    int r, c;
    printf("\n--- Exam Problem: Dynamic Matrix Addition ---\n");
    printf("Enter rows and columns: ");
    if (scanf("%d %d", &r, &c) != 2 || r < 1 || c < 1 || r > 20 || c > 20) return;

    int **A = (int **)malloc(r * sizeof(int *));
    int **B = (int **)malloc(r * sizeof(int *));
    int **C = (int **)malloc(r * sizeof(int *));

    for (int i = 0; i < r; i++) {
        A[i] = (int *)malloc(c * sizeof(int));
        B[i] = (int *)malloc(c * sizeof(int));
        C[i] = (int *)malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) {
            A[i][j] = i + j;
            B[i][j] = (i + 1) * (j + 1);
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Matrix A + Matrix B = Matrix C (%d x %d):\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A); free(B); free(C);
    printf("Matrices freed cleanly without leaks.\n");
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part V: Exam High-Value DMA Problem Hub   \n");
        printf("============================================\n");
        printf("1. Dynamic Array Numerical Statistics\n");
        printf("2. Dynamic Array of Strings (char **)\n");
        printf("3. Dynamic Matrix Addition (DMA 2D Array)\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: exam_dynamic_stats(); break;
            case 2: exam_string_array_dma(); break;
            case 3: exam_dynamic_matrix_addition(); break;
            case 4: printf("Exiting Part V Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
