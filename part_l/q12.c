/* part_l/q12.c
 * Demonstrate memory addresses of union members (all same address).
 */
#include <stdio.h>

union U {
    int i;
    float f;
    char c;
};

int main(void) {
    union U u;
    printf("Address of union:       %p\n", (void*)&u);
    printf("Address of u.i:         %p\n", (void*)&u.i);
    printf("Address of u.f:         %p\n", (void*)&u.f);
    printf("Address of u.c:         %p\n", (void*)&u.c);
    return 0;
}
