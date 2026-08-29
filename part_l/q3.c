/* part_l/q3.c
 * Store a float in a union.
 * Demonstrates storing and reading a float through a union member.
 */
#include <stdio.h>

union U {
    int i;
    float f;
    char c;
};

int main(void) {
    union U u;
    u.f = 3.14159f;
    printf("Stored float: %.5f\n", u.f);
    return 0;
}
