/* part_r/q5.c
 * Implement rear() for a circular queue.
 */
#include <stdio.h>
#define MAX 4

int q[MAX], front = 0, rear = -1, count = 0;

void enqueue(int v) {
    if (count == MAX) return;
    rear = (rear + 1) % MAX; q[rear] = v; count++;
}

int rear_val() {
    if (count == 0) { printf("Empty\n"); return -1; }
    return q[rear];
}

int main() {
    enqueue(7); enqueue(8); enqueue(9);
    printf("Rear = %d\n", rear_val());
    return 0;
}
