/* part_f q13: Function to reverse a number. */
#include <stdio.h>

long reverseNumber(long n);

long reverseNumber(long n) {
    long rev = 0;
    while (n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int main(void) {
    long n;
    printf("Enter a number: ");
    if (scanf("%ld", &n) != 1) return 1;
    printf("Reversed = %ld\n", reverseNumber(n));
    return 0;
}
