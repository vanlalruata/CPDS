/* part_q/q8.c
 * Display the contents of an array-based queue.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1;

void enqueue(int v) { if (rear < MAX - 1) q[++rear] = v; }

void display() {
    if (rear < front) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) printf("%d ", q[i]);
    printf("\n");
}

int main() {
    enqueue(1); enqueue(2); enqueue(3);
    display();
    return 0;
}
