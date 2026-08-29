/* part_l/q11.c
 * Compare structure and union using the same members (print sizes/behavior).
 */
#include <stdio.h>

struct S {
    int i;
    float f;
    char c;
};

union U {
    int i;
    float f;
    char c;
};

int main(void) {
    struct S s;
    union U u;

    s.i = 10; s.f = 2.5f; s.c = 'X';
    u.i = 10; u.f = 2.5f; u.c = 'X';

    printf("struct can hold all values at once:\n");
    printf("  i=%d f=%.2f c=%c\n", s.i, s.f, s.c);

    printf("union holds only the LAST written member:\n");
    printf("  i=%d f=%.2f c=%c\n", u.i, u.f, u.c);

    printf("sizeof(struct)=%zu  sizeof(union)=%zu\n", sizeof(s), sizeof(u));
    return 0;
}
