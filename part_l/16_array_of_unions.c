/* part_l/q16.c
 * Create an array of unions.
 * Each element can independently hold an int or a float at different times.
 */
#include <stdio.h>

#define N 3

union Cell {
    int i;
    float f;
};

int main(void) {
    union Cell arr[N];

    arr[0].i = 10;
    arr[1].f = 2.5f;
    arr[2].i = 42;

    printf("Element 0 (int):  %d\n", arr[0].i);
    printf("Element 1 (float): %.2f\n", arr[1].f);
    printf("Element 2 (int):  %d\n", arr[2].i);
    return 0;
}
