/* part_f q14: Function to check palindrome number. */
#include <stdio.h>

int isPalindrome(int n);

int isPalindrome(int n) {
    int orig = n, rev = 0;
    while (n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return (orig == rev);
}

int main(void) {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) return 1;
    if (isPalindrome(n))
        printf("%d is a Palindrome\n", n);
    else
        printf("%d is not a Palindrome\n", n);
    return 0;
}
