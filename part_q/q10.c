/* part_q/q10.c
 * Handle underflow in a queue (dequeue from empty queue).
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1;

int dequeue() {
    if (rear < front) {
        printf("UNDERFLOW: queue empty\n");
        return -1;
    }
    return q[front++];
}

int main() {
    dequeue(); /* underflow on empty queue */
    q[++rear] = 7;
    printf("Dequeued %d\n", dequeue());
    dequeue(); /* underflow again */
    return 0;
}
