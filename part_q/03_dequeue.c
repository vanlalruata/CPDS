/* part_q/q3.c
 * Implement only the dequeue() operation on an array-based queue.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1;

void enqueue(int v) { if (rear < MAX - 1) q[++rear] = v; }

int dequeue() {
    if (rear < front) { printf("Underflow\n"); return -1; }
    return q[front++];
}

int main() {
    enqueue(1); enqueue(2); enqueue(3);
    int v;
    while ((v = dequeue()) != -1) printf("Dequeued %d\n", v);
    dequeue(); /* underflow case */
    return 0;
}
