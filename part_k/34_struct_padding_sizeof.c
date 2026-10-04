/* part_k / q34: Demonstrate structure padding using sizeof().
   A struct may be larger than the sum of its members due to alignment. */
#include <stdio.h>

typedef struct {
    char c;     /* 1 byte */
    int i;      /* 4 bytes (padding added after c) */
    char d;     /* 1 byte (+ padding to align to 4) */
} Padded;

typedef struct {
    int i;      /* 4 bytes */
    char c;     /* 1 byte */
    char d;     /* 1 byte */
} PackedLike;

int main(void) {
    printf("sizeof(char)=%zu\n", sizeof(char));
    printf("sizeof(int)=%zu\n", sizeof(int));
    printf("Sum of members of Padded = %zu\n", sizeof(char) + sizeof(int) + sizeof(char));
    printf("sizeof(Padded struct) = %zu (extra padding)\n", sizeof(Padded));
    printf("sizeof(PackedLike struct) = %zu\n", sizeof(PackedLike));
    return 0;
}
