/* q2.c - Menu-driven arithmetic operations
   Repeatedly lets the user choose an operation on two numbers. */
#include <stdio.h>

int main(void) {
    int choice;
    double a, b;
    do {
        printf("\n--- Arithmetic Menu ---\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 5) break;
        printf("Enter two numbers: ");
        scanf("%lf %lf", &a, &b);
        switch (choice) {
            case 1: printf("Sum = %.2f\n", a + b); break;
            case 2: printf("Difference = %.2f\n", a - b); break;
            case 3: printf("Product = %.2f\n", a * b); break;
            case 4:
                if (b == 0) printf("Error: division by zero\n");
                else printf("Quotient = %.2f\n", a / b);
                break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
