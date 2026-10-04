/*
 * q23: Convert decimal to binary.
 * Reads a non-negative integer and prints its binary form.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read n; store*   |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | n>0? push n%2;n/=|
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | pop & print bits |
 * +------------------+
 *     |
 *     v
 * +-------+
 * | STOP  |
 * +-------+
 * (*uses array, then prints reversed)
 */
#include <stdio.h>

int main(void) {
    int n, bits[64], c = 0;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;

    if (n == 0) {
        printf("Binary: 0\n");
        return 0;
    }
    int t = n;
    while (t > 0) {
        bits[c++] = t % 2;
        t /= 2;
    }
    printf("Binary: ");
    for (int i = c - 1; i >= 0; i--)
        printf("%d", bits[i]);
    printf("\n");
    return 0;
}
