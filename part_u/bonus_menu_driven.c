/**
 * bonus_menu_driven.c - Part U: C Debugging & Common Pitfalls Showcase
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>

void off_by_one_demo(void) {
    printf("\n--- Pitfall 1: Off-By-One Array Bound Errors ---\n");
    printf("BUGGY CODE:    int arr[5]; for(int i=0; i<=5; i++) arr[i] = i;\n");
    printf("EXPLANATION:   Valid indices for arr[5] are 0 to 4. Accessing arr[5] causes undefined behavior / buffer overflow.\n");
    printf("CORRECTED FIX: for(int i = 0; i < 5; i++) arr[i] = i;\n");
    int arr[5];
    for (int i = 0; i < 5; i++) arr[i] = (i + 1) * 10;
    printf("Safe output:   ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");
}

void dangling_pointer_demo(void) {
    printf("\n--- Pitfall 2: Dangling Pointers & Use-After-Free ---\n");
    printf("BUGGY CODE:\n  int *p = malloc(sizeof(int));\n  free(p);\n  *p = 50; // DANGEROUS USE-AFTER-FREE!\n");
    printf("EXPLANATION:   free(p) releases the memory back to the OS heap, but 'p' still holds the old address.\n");
    printf("CORRECTED FIX: Always set pointers to NULL immediately after freeing: free(p); p = NULL;\n");

    int *p = (int *)malloc(sizeof(int));
    if (p) {
        *p = 100;
        printf("Safely used:   *p = %d\n", *p);
        free(p);
        p = NULL; // Defended against dangling pointer
        printf("Safe defense:  p set to %p (NULL). Subsequent dereference checks can now prevent crashes!\n", (void *)p);
    }
}

void memory_leak_demo(void) {
    printf("\n--- Pitfall 3: Memory Leaks ---\n");
    printf("BUGGY CODE:\n  while(1) { int *p = malloc(1024); } // Never freed!\n");
    printf("EXPLANATION:   Losing the only pointer reference to allocated heap memory makes it impossible to reclaim.\n");
    printf("CORRECTED FIX: Ensure every malloc()/calloc() has a matching free() before pointer reassignment or exit.\n");
}

void uninitialized_variable_demo(void) {
    printf("\n--- Pitfall 4: Uninitialized Variables ---\n");
    printf("BUGGY CODE:\n  int total; total += 10; // total starts with garbage value!\n");
    printf("EXPLANATION:   Automatic (local stack) variables in C do not default to 0.\n");
    printf("CORRECTED FIX: Always initialize variables at declaration: int total = 0;\n");
    int total = 0;
    total += 10;
    printf("Safe output:   total initialized to 0, total += 10 gives: %d\n", total);
}

void operator_precedence_demo(void) {
    printf("\n--- Pitfall 5: Pointer Precedence (*p++ vs (*p)++) ---\n");
    int val = 10;
    int *p = &val;
    printf("Initial: val = %d\n", val);
    printf("(*p)++ increments the VALUE pointed to: ");
    (*p)++;
    printf("val is now %d\n", val);
    printf("*p++ increments the POINTER address itself, NOT the value!\n");
    printf("Takeaway: Parentheses are critical when combining dereference and post-increment.\n");
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part U: C Debugging & Antipatterns Lab    \n");
        printf("============================================\n");
        printf("1. Off-By-One Array Bound Errors\n");
        printf("2. Dangling Pointers & Use-After-Free\n");
        printf("3. Memory Leaks & Resource Management\n");
        printf("4. Uninitialized Variables & Garbage Values\n");
        printf("5. Pointer Operator Precedence (*p++ vs (*p)++)\n");
        printf("6. Exit\n");
        printf("Enter choice (1-6): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: off_by_one_demo(); break;
            case 2: dangling_pointer_demo(); break;
            case 3: memory_leak_demo(); break;
            case 4: uninitialized_variable_demo(); break;
            case 5: operator_precedence_demo(); break;
            case 6: printf("Exiting Part U Lab. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
