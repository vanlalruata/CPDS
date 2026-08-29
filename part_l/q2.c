/* part_l/q2.c
 * Store an integer in a union.
 * Demonstrates declaring a union and storing an integer value.
 */
#include <stdio.h>

union U {
    int i;
    float f;
    char c;
};

int main(void) {
    union U u;
    u.i = 12345;
    printf("Stored integer: %d\n", u.i);
    return 0;
}
