/* part_f q16: Function to calculate GCD (Euclidean algorithm). */
#include <stdio.h>

int gcd(int a, int b);

int gcd(int a, int b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(void) {
    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;
    printf("GCD = %d\n", gcd(a, b));
    return 0;
}
