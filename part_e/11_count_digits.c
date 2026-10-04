/* q11.c - Count digits in a number */
#include <stdio.h>

int main(void) {
    int n, count = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n == 0) count = 1;
    while (n != 0) { count++; n /= 10; }
    printf("Digits = %d\n", count);
    return 0;
}
