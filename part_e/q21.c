/* q21.c - Find GCD of two numbers */
#include <stdio.h>

int main(void) {
    int a, b, t;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) { t = b; b = a % b; a = t; }
    printf("GCD = %d\n", a);
    return 0;
}
