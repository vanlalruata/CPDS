/*
 * q15: Percentage and grade from marks in five subjects.
 * Percentage = total/5; grade by thresholds.
 */
#include <stdio.h>

int main(void) {
    double m1, m2, m3, m4, m5;
    printf("Enter marks of 5 subjects: ");
    if (scanf("%lf %lf %lf %lf %lf", &m1, &m2, &m3, &m4, &m5) != 5) return 1;

    double total = m1 + m2 + m3 + m4 + m5;
    double pct = total / 5.0;
    char g = (pct >= 90) ? 'A' : (pct >= 80) ? 'B' : (pct >= 70) ? 'C' : (pct >= 60) ? 'D' : 'F';
    printf("Percentage = %.2f, Grade = %c\n", pct, g);
    return 0;
}
