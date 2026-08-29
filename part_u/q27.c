/* part_u/q27.c — Stack underflow handling missing
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #define N 3
 * int s[N], top = -1;
 * int pop(void) { return s[top--]; }   // BUG: no underflow check
 * int main(void) {
 *     printf("%d\n", pop());   // pops from empty stack (UB)
 *     return 0;
 * }
 *
 * ERROR: Popping an empty stack (top == -1) yields an invalid index.
 * FIX: Check for underflow; return a sentinel / error indicator.
 */
#include <stdio.h>
#define N 3
int s[N], top = -1;
int pop(void) {
    if (top == -1) { printf("Stack underflow!\n"); return -1; }
    return s[top--];
}
int main(void) {
    printf("pop=%d\n", pop());
    return 0;
}
