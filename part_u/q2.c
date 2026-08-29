/* part_u/q2.c — Incorrect scanf() statement (missing &)
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int main(void) {
 *     int x;
 *     printf("Enter x: ");
 *     scanf("%d", x);   // BUG: missing &, passes value instead of address
 *     printf("%d\n", x);
 *     return 0;
 * }
 *
 * ERROR: scanf needs the address of the variable; passing x (an int) is UB.
 * FIX: Use &x so scanf writes to the variable's address.
 */
#include <stdio.h>
int main(void) {
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("%d\n", x);
    return 0;
}
