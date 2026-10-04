/* q16.c - Check Armstrong number (3-digit classic definition) */
#include <stdio.h>

int main(void) {
    int n, t, sum = 0, d;
    printf("Enter a number: ");
    scanf("%d", &n);
    t = n;
    while (t != 0) { d = t % 10; sum += d * d * d; t /= 10; }
    if (sum == n) printf("%d is an Armstrong number\n", n);
    else printf("%d is not an Armstrong number\n", n);
    return 0;
}
