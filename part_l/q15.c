/* part_l/q15.c
 * Use a union in a menu-driven program (store int or float based on choice).
 */
#include <stdio.h>

union Num {
    int i;
    float f;
};

int main(void) {
    union Num n;
    int choice;
    printf("Store (1) int or (2) float? ");
    if (scanf("%d", &choice) != 1) return 1;

    if (choice == 1) {
        printf("Enter an integer: ");
        scanf("%d", &n.i);
        printf("You entered integer: %d\n", n.i);
    } else if (choice == 2) {
        printf("Enter a float: ");
        scanf("%f", &n.f);
        printf("You entered float: %.3f\n", n.f);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
