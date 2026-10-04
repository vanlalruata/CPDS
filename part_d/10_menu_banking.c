/* q10.c - Menu-driven banking program (deposit/withdraw/balance) */
#include <stdio.h>

int main(void) {
    int choice;
    double balance = 0.0, amt;
    do {
        printf("\n--- Banking ---\n");
        printf("1. Deposit\n2. Withdraw\n3. Balance\n4. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amt);
                balance += amt;
                printf("Deposited\n");
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amt);
                if (amt > balance) printf("Insufficient balance\n");
                else { balance -= amt; printf("Withdrawn\n"); }
                break;
            case 3:
                printf("Balance = %.2f\n", balance);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
