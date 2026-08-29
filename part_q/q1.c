/* part_q/q1.c
 * Implement a queue using an array.
 * Demonstrates enqueue, dequeue and display through a simple menu.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1;

int isFull()  { return rear == MAX - 1; }
int isEmpty() { return rear < front; }

void enqueue(int v) {
    if (isFull()) { printf("Overflow!\n"); return; }
    q[++rear] = v;
}

int dequeue() {
    if (isEmpty()) { printf("Underflow!\n"); return -1; }
    return q[front++];
}

void display() {
    if (isEmpty()) { printf("Queue empty\n"); return; }
    for (int i = front; i <= rear; i++) printf("%d ", q[i]);
    printf("\n");
}

int main() {
    int ch, v;
    do {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("Value: "); scanf("%d", &v); enqueue(v); }
        else if (ch == 2) { v = dequeue(); if (v != -1) printf("Dequeued %d\n", v); }
        else if (ch == 3) display();
    } while (ch != 4);
    return 0;
}
