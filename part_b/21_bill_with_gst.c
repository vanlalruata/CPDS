/*
 * q21: Total bill including GST.
 * Total = price * (1 + gst%/100).
 */
#include <stdio.h>

int main(void) {
    double price, gst;
    printf("Enter price and GST percent: ");
    if (scanf("%lf %lf", &price, &gst) != 2) return 1;

    printf("Total bill (incl. GST) = %.2f\n", price * (1 + gst / 100.0));
    return 0;
}
