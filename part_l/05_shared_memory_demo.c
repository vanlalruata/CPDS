/* part_l/q5.c
 * Demonstrate that union members share memory.
 * We write an int (0x12345678 on little-endian) and read back the bytes.
 * Because all members overlap, the unsigned char view reveals the raw bytes.
 */
#include <stdio.h>

union U {
    int i;
    unsigned char b[sizeof(int)];
};

int main(void) {
    union U u;
    u.i = 0x12345678;
    printf("Integer value: 0x%X\n", u.i);
    printf("Bytes in memory (little-endian layout):\n");
    for (size_t k = 0; k < sizeof(int); k++) {
        printf("  byte[%zu] = 0x%02X\n", k, u.b[k]);
    }
    return 0;
}
