/*
 * q11: Convert kilometres into metres, centimetres and millimetres.
 * 1 km = 1000 m = 100000 cm = 1000000 mm.
 */
#include <stdio.h>

int main(void) {
    double km;
    printf("Enter distance in kilometres: ");
    if (scanf("%lf", &km) != 1 || km < 0) return 1;

    printf("Metres = %.2f\n", km * 1000);
    printf("Centimetres = %.2f\n", km * 100000);
    printf("Millimetres = %.2f\n", km * 1000000);
    return 0;
}
