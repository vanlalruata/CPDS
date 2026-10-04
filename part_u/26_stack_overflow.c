/* part_u/q26.c — Stack overflow handling missing
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #define N 3
 * int s[N], top = -1;
 * void push(int v) { s[++top] = v; }   // BUG: no overflow check
 * int main(void) {
 *     push(1); push(2); push(3); push(4);   // overflow, writes s[3]
 *     return 0;
 * }
 *
 * ERROR: Pushing without checking top < N-1 corrupts memory on overflow.
 * FIX: Check for overflow before pushing; report and refuse.
 */
#include <stdio.h>
#define N 3
int s[N], top = -1;
void push(int v) {
    if (top == N - 1) { printf("Stack overflow!\n"); return; }
    s[++top] = v;
}
int main(void) {
    push(1); push(2); push(3); push(4);
    return 0;
}
