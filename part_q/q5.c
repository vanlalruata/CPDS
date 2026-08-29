/* part_q/q5.c
 * Implement rear() to peek at the last element of a queue.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1;

void enqueue(int v) { if (rear < MAX - 1) q[++rear] = v; }

int rear_val() {
    if (rear < front) { printf("Queue empty\n"); return -1; }
    return q[rear];
}

int main() {
    enqueue(11); enqueue(22); enqueue(33);
    printf("Rear element = %d\n", rear_val());
    return 0;
}
