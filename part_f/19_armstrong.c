/* part_f q19: Function to check Armstrong number (sum of cubes of digits equals number). */
#include <stdio.h>

int isArmstrong(int n);

int isArmstrong(int n) {
    int orig = n, sum = 0;
    n = n < 0 ? -n : n;
    while (n != 0) {
        int d = n % 10;
        sum += d * d * d;
        n /= 10;
    }
    return (orig < 0 ? -orig : orig) == sum;
}

int main(void) {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) return 1;
    if (isArmstrong(n))
        printf("%d is an Armstrong number\n", n);
    else
        printf("%d is not an Armstrong number\n", n);
    return 0;
}
