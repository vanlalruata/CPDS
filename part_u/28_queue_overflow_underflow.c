/* part_u/q28.c — Queue overflow/underflow handling missing
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #define N 3
 * int q[N], f = 0, r = -1;
 * void enq(int v) { q[++r] = v; }          // BUG: no overflow check
 * int deq(void) { return q[f++]; }         // BUG: no underflow check
 * int main(void) {
 *     deq();                               // underflow
 *     enq(1); enq(2); enq(3); enq(4);      // overflow
 *     return 0;
 * }
 *
 * ERROR: Enqueue/dequeue lack bounds checks, causing overflow/underflow (UB).
 * FIX: Guard enqueue with r < N-1 and dequeue with f <= r.
 */
#include <stdio.h>
#define N 3
int q[N], f = 0, r = -1;
void enq(int v) {
    if (r == N - 1) { printf("Queue overflow!\n"); return; }
    q[++r] = v;
}
int deq(void) {
    if (f > r) { printf("Queue underflow!\n"); return -1; }
    return q[f++];
}
int main(void) {
    printf("deq=%d\n", deq());
    enq(1); enq(2); enq(3); enq(4);
    return 0;
}
