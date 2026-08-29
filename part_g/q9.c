/* part_g q9: Function to find maximum and return it. */
#include <stdio.h>

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    int x, y;
    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) return 1;
    printf("Maximum = %d\n", maximum(x, y));
    return 0;
}
