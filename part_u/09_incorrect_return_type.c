/* part_u/q9.c — Incorrect return type
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int square(int x) {       // BUG: returns int but should return float division
 *     return x / 2;         // integer division loses fractional part
 * }
 * int main(void) {
 *     printf("%f\n", square(5));  // BUG: expects double, passed int
 *     return 0;
 * }
 *
 * ERROR: Declared return type int, but printf("%f") reads a double; behaviour is UB.
 * FIX: Use float/double return type and floating division.
 */
#include <stdio.h>
double half(int x) { return x / 2.0; }
int main(void) {
    printf("%f\n", half(5));
    return 0;
}
