/* part_l/q13.c
 * Demonstrate memory addresses of structure members (different addresses).
 */
#include <stdio.h>

struct S {
    int i;
    float f;
    char c;
};

int main(void) {
    struct S s;
    printf("Address of s.i: %p\n", (void*)&s.i);
    printf("Address of s.f: %p\n", (void*)&s.f);
    printf("Address of s.c: %p\n", (void*)&s.c);
    return 0;
}
