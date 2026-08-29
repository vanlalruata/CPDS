/* q6.c - Menu-driven unit conversion (km<->mile, C<->F, kg<->pound) */
#include <stdio.h>

int main(void) {
    int choice;
    double v;
    do {
        printf("\n--- Unit Conversion ---\n");
        printf("1. km to mile\n2. mile to km\n3. C to F\n4. F to C\n5. kg to pound\n6. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 6) break;
        printf("Enter value: ");
        scanf("%lf", &v);
        switch (choice) {
            case 1: printf("%.2f km = %.2f mile\n", v, v * 0.621371); break;
            case 2: printf("%.2f mile = %.2f km\n", v, v / 0.621371); break;
            case 3: printf("%.2f C = %.2f F\n", v, v * 9 / 5 + 32); break;
            case 4: printf("%.2f F = %.2f C\n", v, (v - 32) * 5 / 9); break;
            case 5: printf("%.2f kg = %.2f pound\n", v, v * 2.20462); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}
