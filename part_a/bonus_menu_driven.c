/**
 * bonus_menu_driven.c - Part A: Flowchart and Basic C Programming
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>

void check_largest(void) {
    int a, b, c;
    printf("\n--- Find Largest Number ---\n");
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Invalid input.\n");
        return;
    }
    int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    printf("The largest of %d, %d, and %d is: %d\n", a, b, c, max);
}

void check_number_properties(void) {
    int n;
    printf("\n--- Number Properties ---\n");
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return;
    }
    printf("%d is %s\n", n, (n % 2 == 0) ? "Even" : "Odd");
    if (n > 0) printf("%d is Positive\n", n);
    else if (n < 0) printf("%d is Negative\n", n);
    else printf("%d is Zero\n", n);
}

void check_prime(void) {
    int n, is_prime = 1;
    printf("\n--- Prime Number Check ---\n");
    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Please enter a valid positive integer.\n");
        return;
    }
    if (n <= 1) is_prime = 0;
    else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }
    if (is_prime) printf("%d is a Prime number.\n", n);
    else printf("%d is NOT a Prime number.\n", n);
}

void factorial_fibonacci(void) {
    int choice, n;
    printf("\n--- Factorial & Fibonacci ---\n");
    printf("1. Factorial\n2. Fibonacci Series\nEnter sub-choice: ");
    if (scanf("%d", &choice) != 1) return;

    if (choice == 1) {
        printf("Enter a non-negative integer (0-20): ");
        if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
            printf("Invalid input for factorial.\n");
            return;
        }
        unsigned long long fact = 1;
        for (int i = 1; i <= n; i++) fact *= i;
        printf("Factorial of %d = %llu\n", n, fact);
    } else if (choice == 2) {
        printf("Enter number of terms (1-50): ");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("Invalid number of terms.\n");
            return;
        }
        long long first = 0, second = 1, next;
        printf("Fibonacci Series (%d terms): ", n);
        for (int i = 1; i <= n; i++) {
            printf("%lld ", first);
            next = first + second;
            first = second;
            second = next;
        }
        printf("\n");
    }
}

void reverse_palindrome(void) {
    int n, temp, rev = 0, rem;
    printf("\n--- Reverse & Palindrome ---\n");
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return;
    temp = n;
    while (temp != 0) {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }
    printf("Reversed number: %d\n", rev);
    if (n == rev && n >= 0)
        printf("%d is a Palindrome.\n", n);
    else
        printf("%d is NOT a Palindrome.\n", n);
}

void gcd_lcm(void) {
    int a, b, temp_a, temp_b;
    printf("\n--- GCD and LCM ---\n");
    printf("Enter two positive integers: ");
    if (scanf("%d %d", &a, &b) != 2 || a <= 0 || b <= 0) {
        printf("Please enter positive integers.\n");
        return;
    }
    temp_a = a;
    temp_b = b;
    while (temp_b != 0) {
        int rem = temp_a % temp_b;
        temp_a = temp_b;
        temp_b = rem;
    }
    int gcd = temp_a;
    long long lcm = ((long long)a * b) / gcd;
    printf("GCD(%d, %d) = %d\n", a, b, gcd);
    printf("LCM(%d, %d) = %lld\n", a, b, lcm);
}

void decimal_binary(void) {
    int n, binary[32], count = 0;
    printf("\n--- Decimal to Binary Converter ---\n");
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Please enter a non-negative integer.\n");
        return;
    }
    if (n == 0) {
        printf("Binary equivalent: 0\n");
        return;
    }
    int temp = n;
    while (temp > 0) {
        binary[count++] = temp % 2;
        temp /= 2;
    }
    printf("Binary equivalent of %d: ", n);
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main(void) {
    int choice;
    do {
        printf("\n==========================================\n");
        printf("  Part A: Basic C Programming Workbench   \n");
        printf("==========================================\n");
        printf("1. Find Largest of 3 Numbers\n");
        printf("2. Check Even/Odd & Positive/Negative\n");
        printf("3. Prime Number Check\n");
        printf("4. Factorial & Fibonacci Series\n");
        printf("5. Reverse Number & Palindrome Check\n");
        printf("6. Compute GCD and LCM\n");
        printf("7. Decimal to Binary Conversion\n");
        printf("8. Exit\n");
        printf("Enter your choice (1-8): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: check_largest(); break;
            case 2: check_number_properties(); break;
            case 3: check_prime(); break;
            case 4: factorial_fibonacci(); break;
            case 5: reverse_palindrome(); break;
            case 6: gcd_lcm(); break;
            case 7: decimal_binary(); break;
            case 8: printf("Exiting Part A Workbench. Goodbye!\n"); break;
            default: printf("Invalid choice! Select 1-8.\n");
        }
    } while (choice != 8);

    return 0;
}
