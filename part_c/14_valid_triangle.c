/*
 * q14: Three sides form a valid triangle.
 * Valid if sum of any two sides > third.
 */
#include <stdio.h>

int main(void) {
    double a, b, c;
    printf("Enter three sides: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    if (a + b > c && b + c > a && a + c > b)
        printf("Valid triangle\n");
    else
        printf("Not a valid triangle\n");
    return 0;
}
