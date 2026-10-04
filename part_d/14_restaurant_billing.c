/* q14.c - Basic restaurant billing system using switch */
#include <stdio.h>

int main(void) {
    int choice, qty;
    float total = 0.0;
    float prices[] = {0, 120.0, 80.0, 150.0, 60.0};
    do {
        printf("\n--- Menu ---\n");
        printf("1. Burger  (120)\n2. Pizza (80)\n3. Pasta  (150)\n4. Coke (60)\n5. Bill & Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice >= 1 && choice <= 4) {
            printf("Enter quantity: ");
            scanf("%d", &qty);
            total += prices[choice] * qty;
        } else if (choice == 5) {
            printf("Total bill = %.2f\n", total);
        } else {
            printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
