/* part_l/q18.c
 * Create a union containing a structure.
 * The union can hold a Point struct OR an int, sharing the same space.
 */
#include <stdio.h>

struct Point {
    int x;
    int y;
};

union Holder {
    struct Point p;
    int tag;
};

int main(void) {
    union Holder h;
    h.p.x = 3;
    h.p.y = 4;
    printf("Point: (%d, %d)\n", h.p.x, h.p.y);

    h.tag = 99;  /* reuses the same memory, overwriting the point */
    printf("Tag after overwrite: %d\n", h.tag);
    return 0;
}
