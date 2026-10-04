/* part_f q17: Function to calculate LCM using GCD. */
#include <stdio.h>

int gcd(int a, int b);
long lcm(int a, int b);

int gcd(int a, int b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b != 0) { int t = b; b = a % b; a = t; }
    return a;
}

long lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int g = gcd(a, b);
    long A = a < 0 ? -(long)a : a;
    long B = b < 0 ? -(long)b : b;
    return (A / g) * B;
}

int main(void) {
    int a, b;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1;
    printf("LCM = %ld\n", lcm(a, b));
    return 0;
}
