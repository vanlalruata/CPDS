/* q18.c - Check strong number (sum of factorial of digits) */
#include <stdio.h>

int fact(int x) {
    int f = 1;
    for (int i = 2; i <= x; i++) f *= i;
    return f;
}
int main(void) {
    int n, t, sum = 0, d;
    printf("Enter a number: ");
    scanf("%d", &n);
    t = n;
    while (t != 0) { d = t % 10; sum += fact(d); t /= 10; }
    if (sum == n) printf("%d is a strong number\n", n);
    else printf("%d is not a strong number\n", n);
    return 0;
}
