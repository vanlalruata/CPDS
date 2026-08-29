/* part_l/q6.c
 * Compare sizeof(struct) and sizeof(union) with same members.
 * struct: total size >= sum of member sizes (with padding).
 * union:  size == size of the largest member (members overlap).
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
    printf("sizeof(struct S) = %zu bytes\n", sizeof(struct S));
    printf("sizeof(union  U) = %zu bytes\n", sizeof(union U));
    return 0;
}
