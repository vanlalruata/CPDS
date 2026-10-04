/* part_l/q7.c
 * Create a union containing int, float and char.
 * Show that writing one member and reading another reinterprets the bits.
 */
#include <stdio.h>

union Mixed {
    int i;
    float f;
    char c;
};

int main(void) {
    union Mixed m;
    m.i = 1065353216; /* bit pattern of 1.0f */
    printf("As int   : %d\n", m.i);
    printf("As float : %.1f\n", m.f);
    printf("As char  : %c\n", m.c);
    return 0;
}
