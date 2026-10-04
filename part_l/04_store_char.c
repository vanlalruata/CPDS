/* part_l/q4.c
 * Store a character in a union.
 * Demonstrates storing and reading a char through a union member.
 */
#include <stdio.h>

union U {
    int i;
    float f;
    char c;
};

int main(void) {
    union U u;
    u.c = 'A';
    printf("Stored character: %c\n", u.c);
    return 0;
}
