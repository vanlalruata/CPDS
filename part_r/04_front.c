/* part_r/q4.c
 * Implement front() for a circular queue.
 */
#include <stdio.h>
#define MAX 4

int q[MAX], front = 0, rear = -1, count = 0;

void enqueue(int v) {
    if (count == MAX) return;
    rear = (rear + 1) % MAX; q[rear] = v; count++;
}

int front_val() {
    if (count == 0) { printf("Empty\n"); return -1; }
    return q[front];
}

int main() {
    enqueue(7); enqueue(8);
    printf("Front = %d\n", front_val());
    return 0;
}
