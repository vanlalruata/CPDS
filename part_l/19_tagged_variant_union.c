/* part_l/q19.c
 * Explain and demonstrate a practical use case for a union:
 * a TYPE-SAFE VARIANT (tagged value) built from an enum + union.
 *
 * This is the canonical, correct way to use unions: a separate enum tells
 * you which union member is currently valid, so you never misinterpret bits.
 */
#include <stdio.h>

typedef enum { T_INT, T_FLOAT, T_CHAR } Type;

typedef struct {
    Type type;
    union {
        int i;
        float f;
        char c;
    } as;
} Variant;

void print_variant(const Variant* v) {
    switch (v->type) {
        case T_INT:   printf("int: %d\n",   v->as.i); break;
        case T_FLOAT: printf("float: %.3f\n", v->as.f); break;
        case T_CHAR:  printf("char: %c\n",  v->as.c); break;
    }
}

int main(void) {
    Variant a = { T_INT,   .as.i = 7 };
    Variant b = { T_FLOAT, .as.f = 9.25f };
    Variant c = { T_CHAR,  .as.c = 'Z' };
    print_variant(&a);
    print_variant(&b);
    print_variant(&c);
    return 0;
}
