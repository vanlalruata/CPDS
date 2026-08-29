/* part_l/q14.c
 * Program showing the memory-saving property of unions (sizeof comparison).
 * If we had 1000 records, a union design uses far less memory than a struct.
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
    const long n = 1000;
    printf("One struct = %zu bytes, %ld structs = %ld bytes\n",
           sizeof(struct S), n, (long)(sizeof(struct S) * n));
    printf("One union  = %zu bytes, %ld unions  = %ld bytes\n",
           sizeof(union U), n, (long)(sizeof(union U) * n));
    return 0;
}
