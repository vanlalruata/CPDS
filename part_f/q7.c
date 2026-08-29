/* part_f q7: Function to find maximum of two numbers. */
#include <stdio.h>

int max2(int a, int b);

int max2(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;
    printf("Maximum = %d\n", max2(a, b));
    return 0;
}
