/* part_g q12: Calculate sum and average using pointer parameters. */
#include <stdio.h>

void sumAvg(int a, int b, int *sum, double *avg) {
    *sum = a + b;
    *avg = (double)(*sum) / 2;
}

int main(void) {
    int x, y, s; double a;
    printf("Enter two integers: ");
    if (scanf("%d %d", &x, &y) != 2) return 1;
    sumAvg(x, y, &s, &a);
    printf("Sum = %d, Average = %.2f\n", s, a);
    return 0;
}
