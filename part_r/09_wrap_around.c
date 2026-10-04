/* part_r/q9.c
 * Demonstrate wrap-around in a circular queue:
 * enqueue/dequeue cross the physical end of the array.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1, count = 0;

void enqueue(int v) {
    if (count == MAX) { printf("Full\n"); return; }
    rear = (rear + 1) % MAX; q[rear] = v; count++;
}
int dequeue() {
    int v = q[front]; front = (front + 1) % MAX; count--; return v;
}

int main() {
    enqueue(1); enqueue(2); enqueue(3); enqueue(4); enqueue(5);
    printf("Dequeued: %d %d\n", dequeue(), dequeue()); /* frees slots 0,1 */
    enqueue(6); /* wraps to index 0 */
    enqueue(7); /* wraps to index 1 */
    printf("rear index = %d (wrapped to start of array)\n", rear);
    for (int i = 0; i < count; i++) printf("%d ", q[(front + i) % MAX]);
    printf("\n");
    return 0;
}
