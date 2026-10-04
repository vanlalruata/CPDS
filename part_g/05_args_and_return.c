/* part_g q5: Function with arguments and a return value. */
#include <stdio.h>

int multiply(int a, int b) {
    return a * b;
}

int main(void) {
    int x, y;
    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) return 1;
    printf("Result = %d\n", multiply(x, y));
    return 0;
}
