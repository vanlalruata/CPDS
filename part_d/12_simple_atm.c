/* q12.c - Simple ATM menu using switch */
#include <stdio.h>

int main(void) {
    int choice, pin = 1234, entered;
    double balance = 1000.0, amt;
    printf("Enter PIN: ");
    scanf("%d", &entered);
    if (entered != pin) { printf("Incorrect PIN\n"); return 1; }
    do {
        printf("\n--- ATM ---\n");
        printf("1. Check Balance\n2. Withdraw\n3. Deposit\n4. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: printf("Balance = %.2f\n", balance); break;
            case 2:
                printf("Enter amount: ");
                scanf("%lf", &amt);
                if (amt > balance) printf("Insufficient funds\n");
                else { balance -= amt; printf("Please collect cash\n"); }
                break;
            case 3:
                printf("Enter amount: ");
                scanf("%lf", &amt);
                balance += amt;
                printf("Deposit successful\n");
                break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
