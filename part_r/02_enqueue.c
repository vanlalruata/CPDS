/* part_r/q2.c
 * Implement enqueue() for a circular queue.
 */
#include <stdio.h>
#define MAX 4

int q[MAX], front = 0, rear = -1, count = 0;

void enqueue(int v) {
    if (count == MAX) { printf("Overflow\n"); return; }
    rear = (rear + 1) % MAX;
    q[rear] = v; count++;
    printf("Enqueued %d\n", v);
}

int main() {
    enqueue(1); enqueue(2); enqueue(3); enqueue(4);
    enqueue(5); /* overflow */
    return 0;
}
