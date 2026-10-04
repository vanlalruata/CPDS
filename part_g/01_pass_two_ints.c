/* part_g q1: Passing two integers to a function and using them. */
#include <stdio.h>

void printSum(int a, int b) {
    printf("You passed %d and %d, their sum is %d\n", a, b, a + b);
}

int main(void) {
    int x, y;
    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) return 1;
    printSum(x, y);
    return 0;
}
