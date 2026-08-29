/* part_q/q7.c
 * Implement isFull() for an array-based queue.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1;

int isFull() { return rear == MAX - 1; }

int main() {
    printf("isFull (before) = %d\n", isFull());
    for (int i = 0; i < MAX; i++) q[++rear] = i;
    printf("isFull (after fill) = %d\n", isFull());
    return 0;
}
