/**
 * bonus_menu_driven.c - Part D: switch, break, and continue Control
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>

void switch_calculator(void) {
    char op;
    double a, b;
    printf("\n--- Switch Calculator ---\n");
    printf("Enter expression (e.g. 5.5 + 2.3): ");
    if (scanf("%lf %c %lf", &a, &op, &b) != 3) return;

    switch (op) {
        case '+': printf("Result: %.4f\n", a + b); break;
        case '-': printf("Result: %.4f\n", a - b); break;
        case '*': printf("Result: %.4f\n", a * b); break;
        case '/':
            if (b != 0) printf("Result: %.4f\n", a / b);
            else printf("Error: Division by zero is undefined.\n");
            break;
        default: printf("Error: Unknown operator '%c'\n", op); break;
    }
}

void calendar_switch(void) {
    int choice;
    printf("\n--- Calendar Information ---\n");
    printf("1. Day of Week Name\n2. Days in a Month\nEnter sub-choice: ");
    if (scanf("%d", &choice) != 1) return;

    if (choice == 1) {
        int day;
        printf("Enter day number (1=Sunday ... 7=Saturday): ");
        if (scanf("%d", &day) != 1) return;
        switch (day) {
            case 1: printf("Sunday (Weekend)\n"); break;
            case 2: printf("Monday (Weekday)\n"); break;
            case 3: printf("Tuesday (Weekday)\n"); break;
            case 4: printf("Wednesday (Weekday)\n"); break;
            case 5: printf("Thursday (Weekday)\n"); break;
            case 6: printf("Friday (Weekday)\n"); break;
            case 7: printf("Saturday (Weekend)\n"); break;
            default: printf("Invalid day number! Must be 1-7.\n"); break;
        }
    } else if (choice == 2) {
        int month, year;
        printf("Enter month (1-12) and year: ");
        if (scanf("%d %d", &month, &year) != 2) return;
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                printf("Month %d has 31 days.\n", month);
                break;
            case 4: case 6: case 9: case 11:
                printf("Month %d has 30 days.\n", month);
                break;
            case 2: {
                int leap = ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
                printf("February %d has %d days (%s leap year).\n", year, leap ? 29 : 28, leap ? "is" : "not");
                break;
            }
            default:
                printf("Invalid month! Must be 1-12.\n");
                break;
        }
    }
}

void atm_simulator(void) {
    static double balance = 10000.0;
    int choice;
    double amount;

    do {
        printf("\n--- ATM Banking Simulator ---\n");
        printf("1. Check Balance\n2. Deposit\n3. Withdraw\n4. Return to Main Menu\n");
        printf("Enter ATM choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Current Balance: Rs. %.2f\n", balance);
                break;
            case 2:
                printf("Enter deposit amount: Rs. ");
                if (scanf("%lf", &amount) == 1 && amount > 0) {
                    balance += amount;
                    printf("Successfully deposited. New Balance: Rs. %.2f\n", balance);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;
            case 3:
                printf("Enter withdrawal amount: Rs. ");
                if (scanf("%lf", &amount) == 1 && amount > 0) {
                    if (amount <= balance) {
                        balance -= amount;
                        printf("Dispensed Rs. %.2f. New Balance: Rs. %.2f\n", amount, balance);
                    } else {
                        printf("Insufficient funds! Current balance is Rs. %.2f\n", balance);
                    }
                } else {
                    printf("Invalid withdrawal amount.\n");
                }
                break;
            case 4:
                printf("Exiting ATM simulator...\n");
                break;
            default:
                printf("Invalid ATM option!\n");
                break;
        }
    } while (choice != 4);
}

void break_demonstration(void) {
    printf("\n--- Break Demonstration ---\n");
    printf("Summing numbers from user input. Enter 0 or negative number to BREAK early:\n");
    int sum = 0, val, count = 0;
    while (1) {
        printf("Enter number %d: ", count + 1);
        if (scanf("%d", &val) != 1) break;
        if (val <= 0) {
            printf("Break condition met (value = %d). Exiting loop immediately!\n", val);
            break;
        }
        sum += val;
        count++;
    }
    printf("Total sum of %d positive numbers: %d\n", count, sum);
}

void continue_demonstration(void) {
    int limit;
    printf("\n--- Continue Demonstration ---\n");
    printf("Printing numbers up to N, SKIPPING multiples of 3 and 5 using 'continue':\n");
    printf("Enter upper limit N: ");
    if (scanf("%d", &limit) != 1 || limit < 1) return;

    printf("Numbers: ");
    for (int i = 1; i <= limit; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue; // Skip rest of loop body
        }
        printf("%d ", i);
    }
    printf("\n");
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part D: Switch, Break & Continue Hub      \n");
        printf("============================================\n");
        printf("1. Switch Arithmetic Calculator\n");
        printf("2. Calendar Day & Month Info\n");
        printf("3. ATM Simulator (Switch Submenu)\n");
        printf("4. Break Statement Demonstration\n");
        printf("5. Continue Statement Demonstration\n");
        printf("6. Exit\n");
        printf("Enter choice (1-6): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: switch_calculator(); break;
            case 2: calendar_switch(); break;
            case 3: atm_simulator(); break;
            case 4: break_demonstration(); break;
            case 5: continue_demonstration(); break;
            case 6: printf("Exiting Part D Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
