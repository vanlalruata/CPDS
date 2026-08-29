/* part_l/q20.c
 * Compare memory usage of equivalent structure and union designs.
 * Design A: store BOTH an int and a float (struct) at all times.
 * Design B: store EITHER an int or a float (union) at a time.
 */
#include <stdio.h>

struct Both {
    int i;
    float f;
};

union Either {
    int i;
    float f;
};

int main(void) {
    long count = 1000000;
    printf("Struct design  : %zu bytes/record -> %ld bytes total\n",
           sizeof(struct Both), (long)(sizeof(struct Both) * count));
    printf("Union design   : %zu bytes/record -> %ld bytes total\n",
           sizeof(union Either), (long)(sizeof(union Either) * count));
    return 0;
}
