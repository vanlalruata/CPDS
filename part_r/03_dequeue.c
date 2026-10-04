/* part_r/q3.c
 * Implement dequeue() for a circular queue.
 */
#include <stdio.h>
#define MAX 4

int q[MAX], front = 0, rear = -1, count = 0;

void enqueue(int v) {
    if (count == MAX) return;
    rear = (rear + 1) % MAX; q[rear] = v; count++;
}

int dequeue() {
    if (count == 0) { printf("Underflow\n"); return -1; }
    int v = q[front];
    front = (front + 1) % MAX; count--;
    return v;
}

int main() {
    enqueue(1); enqueue(2);
    printf("Dequeued %d\n", dequeue());
    printf("Dequeued %d\n", dequeue());
    printf("Dequeued %d\n", dequeue()); /* underflow */
    return 0;
}
