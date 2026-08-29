/* q7.c - Menu-driven area calculator (circle, rectangle, triangle) */
#include <stdio.h>

int main(void) {
    int choice;
    double a, b;
    do {
        printf("\n--- Area Calculator ---\n");
        printf("1. Circle\n2. Rectangle\n3. Triangle\n4. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                printf("Enter radius: ");
                scanf("%lf", &a);
                printf("Area = %.2f\n", 3.14159 * a * a);
                break;
            case 2:
                printf("Enter length and breadth: ");
                scanf("%lf %lf", &a, &b);
                printf("Area = %.2f\n", a * b);
                break;
            case 3:
                printf("Enter base and height: ");
                scanf("%lf %lf", &a, &b);
                printf("Area = %.2f\n", 0.5 * a * b);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
