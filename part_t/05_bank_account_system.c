/* part_t/q5.c — Bank Account System
 * Concepts: structures and functions
 * Operations: Create, Deposit, Withdraw, Display balance, Search
 */
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Account {
    int accno;
    char name[50];
    float balance;
};

void create(struct Account *a, int *n) {
    printf("accno, name, initial deposit: ");
    scanf("%d %49s %f", &a[*n].accno, a[*n].name, &a[*n].balance);
    (*n)++;
}

int find(struct Account *a, int n, int accno) {
    for (int i = 0; i < n; i++) if (a[i].accno == accno) return i;
    return -1;
}

void deposit(struct Account *a, int n, int accno, float amt) {
    int i = find(a, n, accno);
    if (i < 0) printf("Not found.\n");
    else { a[i].balance += amt; printf("Deposited.\n"); }
}

void withdraw(struct Account *a, int n, int accno, float amt) {
    int i = find(a, n, accno);
    if (i < 0) printf("Not found.\n");
    else if (a[i].balance < amt) printf("Insufficient.\n");
    else { a[i].balance -= amt; printf("Withdrawn.\n"); }
}

void displayBalance(struct Account *a, int n, int accno) {
    int i = find(a, n, accno);
    if (i < 0) printf("Not found.\n");
    else printf("Balance of %s: %.2f\n", a[i].name, a[i].balance);
}

int main(void) {
    struct Account a[MAX]; int n = 0, ch, accno; float amt;
    do {
        printf("\n1.Create 2.Deposit 3.Withdraw 4.Balance 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(a, &n); break;
            case 2: printf("accno, amount: "); scanf("%d %f", &accno, &amt); deposit(a, n, accno, amt); break;
            case 3: printf("accno, amount: "); scanf("%d %f", &accno, &amt); withdraw(a, n, accno, amt); break;
            case 4: printf("accno: "); scanf("%d", &accno); displayBalance(a, n, accno); break;
        }
    } while (ch != 5);
    return 0;
}
