/* q13.c - Menu for factorial, prime, palindrome, Armstrong number */
#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}
int isPalindrome(int n) {
    int t = n, r = 0;
    while (t) { r = r * 10 + t % 10; t /= 10; }
    return r == n;
}
int isArmstrong(int n) {
    int t = n, s = 0, d;
    while (t) { d = t % 10; s += d * d * d; t /= 10; }
    return s == n;
}
int factorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

int main(void) {
    int choice, n;
    do {
        printf("\n--- Number Programs ---\n");
        printf("1. Factorial\n2. Prime\n3. Palindrome\n4. Armstrong\n5. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 5) break;
        printf("Enter a number: ");
        scanf("%d", &n);
        switch (choice) {
            case 1: printf("Factorial = %d\n", factorial(n)); break;
            case 2: printf("%d is %s\n", n, isPrime(n) ? "PRIME" : "NOT prime"); break;
            case 3: printf("%d is %s\n", n, isPalindrome(n) ? "PALINDROME" : "NOT palindrome"); break;
            case 4: printf("%d is %s\n", n, isArmstrong(n) ? "ARMSTRONG" : "NOT armstrong"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
