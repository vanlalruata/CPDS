/**
 * bonus_menu_driven.c - Part I: Pointers Deep-Dive Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>

void pointer_basics(void) {
    int val = 42;
    int *ptr = &val;
    int **dptr = &ptr;

    printf("\n--- Pointer Dereferencing & Double Pointers ---\n");
    printf("val value:            %d\n", val);
    printf("val address (&val):   %p\n", (void *)&val);
    printf("ptr value (holds &val):%p\n", (void *)ptr);
    printf("dereferenced *ptr:    %d\n", *ptr);
    printf("dptr value (holds &ptr):%p\n", (void *)dptr);
    printf("dereferenced **dptr:  %d\n", **dptr);

    **dptr = 100;
    printf("After **dptr = 100, val is now: %d\n", val);
}

void pointer_arithmetic(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("\n--- Pointer Arithmetic & Array Traversal ---\n");
    printf("Base address (arr): %p\n", (void *)arr);
    for (int i = 0; i < 5; i++) {
        printf("*(p + %d) = %2d  | Address: %p | Offset: %td bytes\n",
               i, *(p + i), (void *)(p + i), (char *)(p + i) - (char *)arr);
    }
}

// Function pointer operations
int add_op(int a, int b) { return a + b; }
int mul_op(int a, int b) { return a * b; }
int max_op(int a, int b) { return (a > b) ? a : b; }

void function_pointers_demo(void) {
    int (*operation)(int, int);
    int a, b, choice;
    printf("\n--- Function Pointers ---\n");
    printf("Enter two numbers: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    printf("Select operation:\n1. Add\n2. Multiply\n3. Maximum\nEnter choice: ");
    if (scanf("%d", &choice) != 1) return;

    if (choice == 1) operation = add_op;
    else if (choice == 2) operation = mul_op;
    else if (choice == 3) operation = max_op;
    else { printf("Invalid choice!\n"); return; }

    int result = operation(a, b);
    printf("Invoked function via pointer! Result: %d\n", result);
}

typedef struct {
    char title[32];
    float price;
} Book;

void pointer_to_struct_demo(void) {
    Book my_book = {"Data Structures in C", 450.0f};
    Book *bptr = &my_book;

    printf("\n--- Pointer to Structure (Arrow Operator '->') ---\n");
    printf("Book Title (via (*bptr).title): %s\n", (*bptr).title);
    printf("Book Price (via bptr->price):   Rs. %.2f\n", bptr->price);

    bptr->price = 499.0f;
    printf("Updated price via pointer:      Rs. %.2f\n", my_book.price);
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part I: Complete Pointers Architecture    \n");
        printf("============================================\n");
        printf("1. Pointer Basics & Double Pointer (**ptr)\n");
        printf("2. Pointer Arithmetic & Memory Offsets\n");
        printf("3. Function Pointers\n");
        printf("4. Pointer to Structure (Arrow Operator)\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: pointer_basics(); break;
            case 2: pointer_arithmetic(); break;
            case 3: function_pointers_demo(); break;
            case 4: pointer_to_struct_demo(); break;
            case 5: printf("Exiting Part I Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
