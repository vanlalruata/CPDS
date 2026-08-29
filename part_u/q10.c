/* part_u/q10.c — Missing return statement
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int max(int a, int b) {
 *     if (a > b)
 *         printf("%d\n", a);   // BUG: no return value in non-void function
 * }
 * int main(void) {
 *     max(3, 4);
 *     return 0;
 * }
 *
 * ERROR: Function declared int but control reaches end without returning a value (UB).
 * FIX: Return the result via a return statement.
 */
#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int main(void) {
    printf("max = %d\n", max(3, 4));
    return 0;
}
