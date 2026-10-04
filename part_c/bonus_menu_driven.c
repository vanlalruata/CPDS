/**
 * bonus_menu_driven.c - Part C: Conditional Statements (if/else)
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <math.h>

void max_min_three(void) {
    int a, b, c;
    printf("\n--- Max & Min of Three Numbers ---\n");
    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) return;

    int max = a, min = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (b < min) min = b;
    if (c < min) min = c;

    printf("Largest:  %d\n", max);
    printf("Smallest: %d\n", min);
}

void leap_year_check(void) {
    int year;
    printf("\n--- Leap Year Checker ---\n");
    printf("Enter year: ");
    if (scanf("%d", &year) != 1) return;

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        printf("%d is a Leap Year.\n", year);
    } else {
        printf("%d is NOT a Leap Year.\n", year);
    }
}

void char_classifier(void) {
    char ch;
    printf("\n--- Character Classifier ---\n");
    printf("Enter a character: ");
    // Clear buffer and read char
    scanf(" %c", &ch);

    if (ch >= 'A' && ch <= 'Z') {
        printf("'%c' is an UPPERCASE letter.\n", ch);
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            printf("It is also a VOWEL.\n");
        else
            printf("It is a CONSONANT.\n");
    } else if (ch >= 'a' && ch <= 'z') {
        printf("'%c' is a LOWERCASE letter.\n", ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            printf("It is also a VOWEL.\n");
        else
            printf("It is a CONSONANT.\n");
    } else if (ch >= '0' && ch <= '9') {
        printf("'%c' is a DIGIT.\n", ch);
    } else {
        printf("'%c' is a SPECIAL character.\n", ch);
    }
}

void triangle_analysis(void) {
    double a, b, c;
    printf("\n--- Triangle Analysis ---\n");
    printf("Enter 3 side lengths: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return;

    if (a + b > c && a + c > b && b + c > a) {
        printf("Valid Triangle!\n");
        if (a == b && b == c) {
            printf("Type: Equilateral\n");
        } else if (a == b || b == c || a == c) {
            printf("Type: Isosceles\n");
        } else {
            printf("Type: Scalene\n");
        }

        // Check right-angled
        double a2 = a * a, b2 = b * b, c2 = c * c;
        if (fabs(a2 + b2 - c2) < 1e-6 || fabs(a2 + c2 - b2) < 1e-6 || fabs(b2 + c2 - a2) < 1e-6) {
            printf("It is also a RIGHT-ANGLED triangle.\n");
        }
    } else {
        printf("Invalid triangle sides (violation of triangle inequality).\n");
    }
}

void quadratic_solver(void) {
    double a, b, c;
    printf("\n--- Quadratic Equation Solver (ax^2 + bx + c = 0) ---\n");
    printf("Enter coefficients a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3 || a == 0) {
        printf("Coefficient 'a' cannot be zero in a quadratic equation.\n");
        return;
    }

    double disc = b * b - 4 * a * c;
    if (disc > 0) {
        double r1 = (-b + sqrt(disc)) / (2 * a);
        double r2 = (-b - sqrt(disc)) / (2 * a);
        printf("Two Distinct Real Roots:\nRoot 1 = %.4f\nRoot 2 = %.4f\n", r1, r2);
    } else if (disc == 0) {
        double r = -b / (2 * a);
        printf("Two Real and Equal Roots:\nRoot 1 = Root 2 = %.4f\n", r);
    } else {
        double real_part = -b / (2 * a);
        double imag_part = sqrt(-disc) / (2 * a);
        printf("Complex Roots:\nRoot 1 = %.4f + %.4fi\nRoot 2 = %.4f - %.4fi\n",
               real_part, imag_part, real_part, imag_part);
    }
}

void electricity_bill(void) {
    double units, bill = 0;
    printf("\n--- Electricity Bill Calculator ---\n");
    printf("Enter units consumed: ");
    if (scanf("%lf", &units) != 1 || units < 0) return;

    if (units <= 50) {
        bill = units * 1.50;
    } else if (units <= 150) {
        bill = 50 * 1.50 + (units - 50) * 2.50;
    } else if (units <= 250) {
        bill = 50 * 1.50 + 100 * 2.50 + (units - 150) * 4.00;
    } else {
        bill = 50 * 1.50 + 100 * 2.50 + 100 * 4.00 + (units - 250) * 6.00;
    }

    double surcharge = 0.10 * bill;
    double total = bill + surcharge;
    printf("Base Charge:  Rs. %.2f\n", bill);
    printf("Surcharge 10%%: Rs. %.2f\n", surcharge);
    printf("Total Bill:   Rs. %.2f\n", total);
}

void date_validator(void) {
    int d, m, y;
    printf("\n--- Date Validator ---\n");
    printf("Enter day, month, year (DD MM YYYY): ");
    if (scanf("%d %d %d", &d, &m, &y) != 3) return;

    if (y < 1 || m < 1 || m > 12 || d < 1) {
        printf("Date is INVALID!\n");
        return;
    }

    int max_days = 31;
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        max_days = 30;
    } else if (m == 2) {
        int is_leap = ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));
        max_days = is_leap ? 29 : 28;
    }

    if (d <= max_days) {
        printf("Date %02d/%02d/%04d is VALID!\n", d, m, y);
    } else {
        printf("Date %02d/%02d/%04d is INVALID (Month %d has at most %d days)!\n", d, m, y, m, max_days);
    }
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part C: Conditional Logic Showcase        \n");
        printf("============================================\n");
        printf("1. Max & Min of Three Numbers\n");
        printf("2. Leap Year Checker\n");
        printf("3. Character Classification\n");
        printf("4. Triangle Validation & Classification\n");
        printf("5. Quadratic Roots Solver\n");
        printf("6. Electricity Bill Calculation\n");
        printf("7. Date Validator\n");
        printf("8. Exit\n");
        printf("Enter choice (1-8): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: max_min_three(); break;
            case 2: leap_year_check(); break;
            case 3: char_classifier(); break;
            case 4: triangle_analysis(); break;
            case 5: quadratic_solver(); break;
            case 6: electricity_bill(); break;
            case 7: date_validator(); break;
            case 8: printf("Exiting Part C Showcase. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}
