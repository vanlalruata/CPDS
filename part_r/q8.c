/* part_r/q8.c
 * Display a circular queue in logical order.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1, count = 0;

void enqueue(int v) {
    if (count == MAX) return;
    rear = (rear + 1) % MAX; q[rear] = v; count++;
}

void display() {
    if (count == 0) { printf("Empty\n"); return; }
    for (int i = 0; i < count; i++)
        printf("%d ", q[(front + i) % MAX]);
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); enqueue(40);
    display();
    return 0;
}
