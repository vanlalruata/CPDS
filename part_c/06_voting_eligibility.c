/*
 * q6: Eligible to vote based on age (>=18).
 */
#include <stdio.h>

int main(void) {
    int age;
    printf("Enter age: ");
    if (scanf("%d", &age) != 1) return 1;

    if (age >= 18)
        printf("Eligible to vote\n");
    else
        printf("Not eligible to vote\n");
    return 0;
}
