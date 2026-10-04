/**
 * bonus_menu_driven.c - Part G: Argument Passing Techniques in C
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>

// Pass by value
void try_modify_value(int a) {
    a = a + 100;
    printf("[Inside Function] Value modified locally to: %d\n", a);
}

// Pass by pointer (reference simulation)
void swap_by_pointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Returning multiple values via pointers
void compute_stats(int a, int b, int *sum, int *diff, int *prod, double *quot) {
    *sum = a + b;
    *diff = a - b;
    *prod = a * b;
    *quot = (b != 0) ? ((double)a / b) : 0.0;
}

// Passing 1D array to function
void modify_array(int arr[], int n, int multiplier) {
    for (int i = 0; i < n; i++) {
        arr[i] *= multiplier;
    }
}

// Passing struct by value vs pointer
typedef struct {
    int id;
    char name[32];
    float marks;
} Student;

void display_student_by_val(Student s) {
    printf("[Pass by Value] ID: %d, Name: %s, Marks: %.2f\n", s.id, s.name, s.marks);
}

void award_grace_marks(Student *s, float grace) {
    s->marks += grace;
    printf("[Pass by Pointer] Added %.2f grace marks. New Marks: %.2f\n", grace, s->marks);
}

void demo_value_vs_pointer(void) {
    int x = 50;
    printf("\n--- Pass by Value vs Pass by Pointer ---\n");
    printf("Original x: %d\n", x);
    try_modify_value(x);
    printf("After try_modify_value (pass by value), x in main is still: %d\n", x);

    int y = 99;
    printf("\nSwapping x (%d) and y (%d) using pointers...\n", x, y);
    swap_by_pointer(&x, &y);
    printf("After swap_by_pointer: x = %d, y = %d\n", x, y);
}

void demo_multiple_returns(void) {
    int a, b;
    printf("\n--- Return Multiple Values Via Output Pointers ---\n");
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    int sum, diff, prod;
    double quot;
    compute_stats(a, b, &sum, &diff, &prod, &quot);

    printf("Results returned via pointers:\n");
    printf("Sum:        %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product:    %d\n", prod);
    printf("Quotient:   %.4f\n", quot);
}

void demo_array_passing(void) {
    int n, arr[20], factor;
    printf("\n--- Passing Arrays to Functions ---\n");
    printf("Enter number of elements (1-20): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 20) return;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter multiplier factor: ");
    if (scanf("%d", &factor) != 1) return;

    modify_array(arr, n, factor);
    printf("Modified array in caller (arrays decay to pointers): ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void demo_struct_passing(void) {
    Student st = {101, "Alice", 84.5f};
    printf("\n--- Passing Structures ---\n");
    display_student_by_val(st);
    award_grace_marks(&st, 5.0f);
    display_student_by_val(st);
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part G: Parameter Passing Techniques Hub  \n");
        printf("============================================\n");
        printf("1. Pass by Value vs Pass by Pointer\n");
        printf("2. Return Multiple Values via Pointers\n");
        printf("3. Pass Array to Function (Pointer Decay)\n");
        printf("4. Pass Structure by Value vs Pointer\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: demo_value_vs_pointer(); break;
            case 2: demo_multiple_returns(); break;
            case 3: demo_array_passing(); break;
            case 4: demo_struct_passing(); break;
            case 5: printf("Exiting Part G Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
