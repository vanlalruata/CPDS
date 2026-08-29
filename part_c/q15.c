/*
 * q15: Triangle equilateral, isosceles or scalene.
 * Classifies by comparing the three sides.
 */
#include <stdio.h>

int main(void) {
    double a, b, c;
    printf("Enter three sides: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    if (a + b > c && b + c > a && a + c > b) {
        if (a == b && b == c)
            printf("Equilateral triangle\n");
        else if (a == b || b == c || a == c)
            printf("Isosceles triangle\n");
        else
            printf("Scalene triangle\n");
    } else
        printf("Not a valid triangle\n");
    return 0;
}
