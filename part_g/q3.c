/* part_g q3: Function with arguments and no return value. */
#include <stdio.h>

void printProduct(int a, int b) {
    printf("Product of %d and %d = %d\n", a, b, a * b);
}

int main(void) {
    int x, y;
    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) return 1;
    printProduct(x, y);
    return 0;
}
