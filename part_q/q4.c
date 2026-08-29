/* part_q/q4.c
 * Implement front() to peek at the first element of a queue.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1;

void enqueue(int v) { if (rear < MAX - 1) q[++rear] = v; }

int front_val() {
    if (rear < front) { printf("Queue empty\n"); return -1; }
    return q[front];
}

int main() {
    enqueue(11); enqueue(22);
    printf("Front element = %d\n", front_val());
    return 0;
}
