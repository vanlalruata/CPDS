/* part_u/q22.c — Incorrect structure member access
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * struct Point { int x, y; };
 * int main(void) {
 *     struct Point p;
 *     p->x = 5;          // BUG: p is a struct, not a pointer; use p.x
 *     printf("%d\n", p.x);
 *     return 0;
 * }
 *
 * ERROR: '->' is for pointers; for a struct variable use the '.' operator.
 * FIX: Assign with p.x = 5;
 */
#include <stdio.h>
struct Point { int x, y; };
int main(void) {
    struct Point p;
    p.x = 5;
    printf("%d\n", p.x);
    return 0;
}
