/* q22.c - Find LCM of two numbers */
#include <stdio.h>

int gcd(int a, int b) {
    int t;
    while (b != 0) { t = b; b = a % b; a = t; }
    return a;
}
int main(void) {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("LCM = %d\n", (a * b) / gcd(a, b));
    return 0;
}
