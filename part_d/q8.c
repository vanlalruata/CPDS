/* q8.c - Menu-driven temperature conversion (C-F, F-C, C-K) */
#include <stdio.h>

int main(void) {
    int choice;
    double t;
    do {
        printf("\n--- Temperature Conversion ---\n");
        printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Celsius to Kelvin\n4. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                printf("Enter Celsius: ");
                scanf("%lf", &t);
                printf("Fahrenheit = %.2f\n", t * 9 / 5 + 32);
                break;
            case 2:
                printf("Enter Fahrenheit: ");
                scanf("%lf", &t);
                printf("Celsius = %.2f\n", (t - 32) * 5 / 9);
                break;
            case 3:
                printf("Enter Celsius: ");
                scanf("%lf", &t);
                printf("Kelvin = %.2f\n", t + 273.15);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
