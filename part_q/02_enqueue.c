/* part_q/q2.c
 * Implement only the enqueue() operation on an array-based queue.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1, count = 0;

void enqueue(int v) {
    if (rear == MAX - 1) { printf("Overflow: cannot enqueue %d\n", v); return; }
    q[++rear] = v;
    count++;
    printf("Enqueued %d (size=%d)\n", v, count);
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    enqueue(40); enqueue(50); enqueue(60); /* overflow case */
    return 0;
}
