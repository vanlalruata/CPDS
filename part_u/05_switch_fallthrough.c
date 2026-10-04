/* part_u/q5.c — Incorrect switch fall-through (missing break)
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int main(void) {
 *     int c = 2;
 *     switch (c) {
 *         case 1: printf("One\n");
 *         case 2: printf("Two\n");   // BUG: missing break
 *         case 3: printf("Three\n");
 *     }
 *     return 0;
 * }
 *
 * ERROR: Without 'break', case 2 falls through to case 3 printing "Three" too.
 * FIX: Add a break after each case's logic.
 */
#include <stdio.h>
int main(void) {
    int c = 2;
    switch (c) {
        case 1: printf("One\n"); break;
        case 2: printf("Two\n"); break;
        case 3: printf("Three\n"); break;
    }
    return 0;
}
