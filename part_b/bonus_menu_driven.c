/**
 * bonus_menu_driven.c - Part B: Integer and Real Operations
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <math.h>

void arithmetic_ops(void) {
    double a, b;
    printf("\n--- Arithmetic Operations ---\n");
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) return;
    printf("Sum:            %.4f\n", a + b);
    printf("Difference:     %.4f\n", a - b);
    printf("Product:        %.4f\n", a * b);
    if (b != 0) printf("Division:       %.4f\n", a / b);
    else printf("Division:       Undefined (divide by zero)\n");
}

void interest_calc(void) {
    double p, r, t;
    printf("\n--- Interest Calculator ---\n");
    printf("Enter Principal, Annual Rate (%%), and Time (years): ");
    if (scanf("%lf %lf %lf", &p, &r, &t) != 3 || p < 0 || r < 0 || t < 0) {
        printf("Invalid input values.\n");
        return;
    }
    double si = (p * r * t) / 100.0;
    double ci = p * pow((1.0 + r / 100.0), t) - p;
    printf("Simple Interest:   %.2f (Total: %.2f)\n", si, p + si);
    printf("Compound Interest: %.2f (Total: %.2f)\n", ci, p + ci);
}

void geometry_calc(void) {
    int choice;
    printf("\n--- Geometry Calculations ---\n");
    printf("1. Circle Area & Circumference\n2. Triangle Heron's Formula\n3. Sphere Volume & Surface Area\nEnter choice: ");
    if (scanf("%d", &choice) != 1) return;

    if (choice == 1) {
        double r;
        printf("Enter radius: ");
        if (scanf("%lf", &r) == 1 && r >= 0) {
            printf("Area:          %.4f\n", 3.141592653589793 * r * r);
            printf("Circumference: %.4f\n", 2.0 * 3.141592653589793 * r);
        }
    } else if (choice == 2) {
        double a, b, c;
        printf("Enter 3 sides of triangle: ");
        if (scanf("%lf %lf %lf", &a, &b, &c) == 3 && a + b > c && a + c > b && b + c > a) {
            double s = (a + b + c) / 2.0;
            double area = sqrt(s * (s - a) * (s - b) * (s - c));
            printf("Triangle Area: %.4f\n", area);
        } else {
            printf("Invalid triangle sides.\n");
        }
    } else if (choice == 3) {
        double r;
        printf("Enter sphere radius: ");
        if (scanf("%lf", &r) == 1 && r >= 0) {
            double vol = (4.0 / 3.0) * 3.141592653589793 * r * r * r;
            double sa = 4.0 * 3.141592653589793 * r * r;
            printf("Volume:       %.4f\n", vol);
            printf("Surface Area: %.4f\n", sa);
        }
    }
}

void temperature_conversion(void) {
    int choice;
    double temp;
    printf("\n--- Temperature Conversion ---\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\nEnter choice: ");
    if (scanf("%d", &choice) != 1) return;

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        if (scanf("%lf", &temp) == 1) {
            double f = (temp * 9.0 / 5.0) + 32.0;
            printf("%.2f C = %.2f F\n", temp, f);
        }
    } else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        if (scanf("%lf", &temp) == 1) {
            double c = (temp - 32.0) * 5.0 / 9.0;
            printf("%.2f F = %.2f C\n", temp, c);
        }
    }
}

void coordinate_geometry(void) {
    double x1, y1, x2, y2;
    printf("\n--- Distance & Midpoint ---\n");
    printf("Enter Point 1 (x1 y1): ");
    if (scanf("%lf %lf", &x1, &y1) != 2) return;
    printf("Enter Point 2 (x2 y2): ");
    if (scanf("%lf %lf", &x2, &y2) != 2) return;

    double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double mid_x = (x1 + x2) / 2.0;
    double mid_y = (y1 + y2) / 2.0;

    printf("Distance: %.4f\n", dist);
    printf("Midpoint: (%.4f, %.4f)\n", mid_x, mid_y);
}

void salary_calc(void) {
    double basic;
    printf("\n--- Salary Calculator ---\n");
    printf("Enter Basic Salary: ");
    if (scanf("%lf", &basic) != 1 || basic < 0) return;

    double da = 0.40 * basic;
    double hra = 0.20 * basic;
    double gross = basic + da + hra;
    double pf = 0.12 * basic;
    double net = gross - pf;

    printf("Basic: %.2f | DA (40%%): %.2f | HRA (20%%): %.2f\n", basic, da, hra);
    printf("Gross Salary: %.2f\n", gross);
    printf("PF Deduction (12%%): %.2f\n", pf);
    printf("Net Salary:   %.2f\n", net);
}

void swap_demo(void) {
    int a, b;
    printf("\n--- Value Swapping Demonstration ---\n");
    printf("Enter two integers a and b: ");
    if (scanf("%d %d", &a, &b) != 2) return;

    printf("Original: a = %d, b = %d\n", a, b);

    // Using temp
    int temp = a;
    int x = b;
    int y = temp;
    printf("Swapped with temporary variable:   x = %d, y = %d\n", x, y);

    // Without temp (arithmetic)
    int p = a, q = b;
    p = p + q;
    q = p - q;
    p = p - q;
    printf("Swapped without temporary variable: a = %d, b = %d\n", p, q);
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part B: Integer & Real Operations Hub    \n");
        printf("============================================\n");
        printf("1. Arithmetic Operations\n");
        printf("2. Simple & Compound Interest\n");
        printf("3. Geometry (Circle, Triangle, Sphere)\n");
        printf("4. Temperature Conversion (C <-> F)\n");
        printf("5. Distance & Midpoint Between Points\n");
        printf("6. Salary Calculator (DA, HRA, PF, Net)\n");
        printf("7. Swap Demonstration (With & Without Temp)\n");
        printf("8. Exit\n");
        printf("Enter choice (1-8): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: arithmetic_ops(); break;
            case 2: interest_calc(); break;
            case 3: geometry_calc(); break;
            case 4: temperature_conversion(); break;
            case 5: coordinate_geometry(); break;
            case 6: salary_calc(); break;
            case 7: swap_demo(); break;
            case 8: printf("Exiting Part B Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}
