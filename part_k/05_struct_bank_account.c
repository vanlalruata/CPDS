/* part_k / q5: Define a structure for a bank account. */
#include <stdio.h>

typedef struct {
    int accountNo;
    char holder[40];
    float balance;
} Account;

int main(void) {
    Account a = { 1001, "Carol", 5000.0f };
    printf("%d %s %.2f\n", a.accountNo, a.holder, a.balance);
    return 0;
}
