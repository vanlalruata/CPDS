/* part_f q15: Function to calculate sum of digits. */
#include <stdio.h>

int sumOfDigits(int n);

int sumOfDigits(int n) {
    int s = 0;
    n = n < 0 ? -n : n;
    while (n != 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main(void) {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Sum of digits = %d\n", sumOfDigits(n));
    return 0;
}
