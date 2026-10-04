/* q20.c - Sum of positive numbers; terminate on negative input using break */
#include <stdio.h>

int main(void) {
    int n, sum = 0;
    while (1) {
        printf("Enter a number: ");
        if (scanf("%d", &n) != 1) break;
        if (n < 0) break;
        sum += n;
    }
    printf("Sum of positive numbers = %d\n", sum);
    return 0;
}
