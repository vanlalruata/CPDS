/* part_k / q28: Create a bank account management system. */
#include <stdio.h>

#define MAX 100

typedef struct {
    int accountNo;
    char holder[40];
    float balance;
} Account;

int main(void) {
    Account a[MAX];
    int n = 0, i, key, choice, found;
    while (1) {
        printf("\n1.Add 2.Display 3.Search 4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            if (n >= MAX) { printf("Full.\n"); continue; }
            printf("accno holder balance: ");
            scanf("%d %39s %f", &a[n].accountNo, a[n].holder, &a[n].balance);
            n++;
        } else if (choice == 2) {
            for (i = 0; i < n; i++) printf("%d %s %.2f\n", a[i].accountNo, a[i].holder, a[i].balance);
        } else if (choice == 3) {
            found = 0;
            printf("Enter account no: ");
            scanf("%d", &key);
            for (i = 0; i < n; i++)
                if (a[i].accountNo == key) { printf("%d %s %.2f\n", a[i].accountNo, a[i].holder, a[i].balance); found = 1; }
            if (!found) printf("Not found.\n");
        } else if (choice == 4) {
            break;
        }
    }
    return 0;
}
