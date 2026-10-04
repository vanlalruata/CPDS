/* part_r/q1.c
 * Implement a circular queue using an array.
 * front/rear wrap around using modulo arithmetic.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1, count = 0;

int isFull()  { return count == MAX; }
int isEmpty() { return count == 0; }

void enqueue(int v) {
    if (isFull()) { printf("Overflow\n"); return; }
    rear = (rear + 1) % MAX;
    q[rear] = v; count++;
}

int dequeue() {
    if (isEmpty()) { printf("Underflow\n"); return -1; }
    int v = q[front];
    front = (front + 1) % MAX; count--;
    return v;
}

void display() {
    if (isEmpty()) { printf("Empty\n"); return; }
    for (int i = 0; i < count; i++)
        printf("%d ", q[(front + i) % MAX]);
    printf("\n");
}

int main() {
    enqueue(1); enqueue(2); enqueue(3);
    display();
    printf("Dequeued %d\n", dequeue());
    enqueue(4); enqueue(5);
    display();
    return 0;
}
