/* q15.c - Check palindrome number */
#include <stdio.h>

int main(void) {
    int n, t, rev = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    t = n;
    while (t != 0) { rev = rev * 10 + t % 10; t /= 10; }
    if (rev == n) printf("%d is a palindrome\n", n);
    else printf("%d is not a palindrome\n", n);
    return 0;
}
