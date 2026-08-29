/* part_u/q8.c — Function prototype mismatch
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int add(int a, int b);          // BUG: prototype says 2 args
 * int main(void) {
 *     printf("%d\n", add(1, 2, 3)); // call passes 3 args
 *     return 0;
 * }
 * int add(int a, int b, int c) { return a + b + c; }
 *
 * ERROR: Prototype (2 args) conflicts with definition/call (3 args): mismatch.
 * FIX: Make the prototype match the definition (3 args).
 */
#include <stdio.h>
int add(int a, int b, int c);
int main(void) {
    printf("%d\n", add(1, 2, 3));
    return 0;
}
int add(int a, int b, int c) { return a + b + c; }
