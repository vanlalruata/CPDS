/* part_l/q8.c
 * Demonstrate how writing one union member affects interpretation through
 * another member, and discuss why such reinterpretation must be handled
 * carefully (use an unsigned char view).
 *
 * CAUTION: Reading a union member other than the last one written is
 * undefined behavior in standard C for types that are not "similar".
 * However, inspecting the raw bytes via an unsigned char array is always
 * well-defined. Type punning through unions works on many compilers (esp.
 * GCC) as a common extension, but strictly speaking only the unsigned char
 * view is portable. Always know the actual type stored before interpreting.
 */
#include <stdio.h>

union Value {
    int i;
    unsigned char bytes[sizeof(int)];
};

int main(void) {
    union Value v;
    v.i = 305419896; /* 0x12345678 */
    printf("Stored int: %d (0x%X)\n", v.i, v.i);
    printf("Interpreting shared bytes as unsigned char:\n");
    for (size_t k = 0; k < sizeof(int); k++) {
        printf("  bytes[%zu] = %u (0x%02X)\n", k, v.bytes[k], v.bytes[k]);
    }
    return 0;
}
