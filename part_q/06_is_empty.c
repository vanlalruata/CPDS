/* part_q/q6.c
 * Implement isEmpty() for an array-based queue.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1;

int isEmpty() { return rear < front; }

int main() {
    printf("isEmpty (before) = %d\n", isEmpty());
    q[++rear] = 5;
    printf("isEmpty (after enqueue) = %d\n", isEmpty());
    return 0;
}
