/**
 * bonus_menu_driven.c - Part E: Loops and Patterns Showcase
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <math.h>

void number_theory_suite(void) {
    int n;
    printf("\n--- Number Theory Inspector ---\n");
    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n < 1) return;

    // Armstrong check
    int temp = n, digits = 0;
    while (temp > 0) { digits++; temp /= 10; }
    temp = n;
    int armstrong_sum = 0;
    while (temp > 0) {
        int d = temp % 10;
        int p = 1;
        for (int i = 0; i < digits; i++) p *= d;
        armstrong_sum += p;
        temp /= 10;
    }
    printf("Armstrong Check: %s (Sum of digits^%d = %d)\n",
           (armstrong_sum == n) ? "YES" : "NO", digits, armstrong_sum);

    // Perfect number check
    int proper_div_sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) proper_div_sum += i;
    }
    printf("Perfect Check:   %s (Sum of proper divisors = %d)\n",
           (proper_div_sum == n) ? "YES" : "NO", proper_div_sum);

    // Strong number check (sum of factorials of digits)
    temp = n;
    int strong_sum = 0;
    while (temp > 0) {
        int d = temp % 10;
        int fact = 1;
        for (int i = 1; i <= d; i++) fact *= i;
        strong_sum += fact;
        temp /= 10;
    }
    printf("Strong Check:    %s (Sum of digit factorials = %d)\n",
           (strong_sum == n) ? "YES" : "NO", strong_sum);
}

void primes_in_range(void) {
    int low, high, count = 0;
    printf("\n--- Prime Numbers in Range ---\n");
    printf("Enter lower and upper limits: ");
    if (scanf("%d %d", &low, &high) != 2 || low > high) return;

    printf("Primes between %d and %d: ", low, high);
    for (int i = low; i <= high; i++) {
        if (i < 2) continue;
        int prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) { prime = 0; break; }
        }
        if (prime) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal primes found: %d\n", count);
}

void pattern_generator(void) {
    int choice, rows;
    printf("\n--- Pattern Generator ---\n");
    printf("1. Star Pyramid\n2. Right Triangle Star\n3. Inverted Triangle\n4. Floyd's Number Triangle\nEnter choice: ");
    if (scanf("%d", &choice) != 1) return;

    printf("Enter number of rows (1-15): ");
    if (scanf("%d", &rows) != 1 || rows < 1 || rows > 15) return;

    switch (choice) {
        case 1:
            for (int i = 1; i <= rows; i++) {
                for (int s = 1; s <= rows - i; s++) printf(" ");
                for (int j = 1; j <= 2 * i - 1; j++) printf("*");
                printf("\n");
            }
            break;
        case 2:
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= i; j++) printf("* ");
                printf("\n");
            }
            break;
        case 3:
            for (int i = rows; i >= 1; i--) {
                for (int j = 1; j <= i; j++) printf("* ");
                printf("\n");
            }
            break;
        case 4: {
            int num = 1;
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("%-3d ", num++);
                }
                printf("\n");
            }
            break;
        }
        default: printf("Invalid pattern selection.\n"); break;
    }
}

void multiplication_tables(void) {
    int n, limit;
    printf("\n--- Multiplication Table ---\n");
    printf("Enter table number and limit: ");
    if (scanf("%d %d", &n, &limit) != 2 || limit < 1) return;

    for (int i = 1; i <= limit; i++) {
        printf("%2d x %2d = %4d\n", n, i, n * i);
    }
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part E: Iteration & Loop Mastery Hub      \n");
        printf("============================================\n");
        printf("1. Number Theory (Armstrong, Strong, Perfect)\n");
        printf("2. Prime Numbers in Given Range\n");
        printf("3. Pattern Generator (Pyramids, Triangles)\n");
        printf("4. Multiplication Tables\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: number_theory_suite(); break;
            case 2: primes_in_range(); break;
            case 3: pattern_generator(); break;
            case 4: multiplication_tables(); break;
            case 5: printf("Exiting Part E Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
