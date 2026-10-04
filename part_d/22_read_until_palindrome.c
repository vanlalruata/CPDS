/* q22.c - Continuously accept numbers until user enters a palindrome */
#include <stdio.h>

int isPalindrome(int n) {
    int t = n, r = 0;
    while (t) { r = r * 10 + t % 10; t /= 10; }
    return r == n;
}
int main(void) {
    int n;
    while (1) {
        printf("Enter a number: ");
        if (scanf("%d", &n) != 1) break;
        if (isPalindrome(n)) { printf("%d is a palindrome. Stopping.\n", n); break; }
        printf("%d is not a palindrome. Try again.\n", n);
    }
    return 0;
}
