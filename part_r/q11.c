/* part_r/q11.c
 * Menu-driven circular queue (array based).
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1, count = 0;

int isFull()  { return count == MAX; }
int isEmpty() { return count == 0; }

void enqueue(int v) {
    if (isFull()) { printf("Overflow\n"); return; }
    rear = (rear + 1) % MAX; q[rear] = v; count++;
}
int dequeue() {
    if (isEmpty()) { printf("Underflow\n"); return -1; }
    int v = q[front]; front = (front + 1) % MAX; count--; return v;
}
void display() {
    if (isEmpty()) { printf("Empty\n"); return; }
    for (int i = 0; i < count; i++) printf("%d ", q[(front+i)%MAX]);
    printf("\n");
}

int main() {
    int ch, v;
    do {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("Val: "); scanf("%d", &v); enqueue(v); }
        else if (ch == 2) { v = dequeue(); if (v != -1) printf("Got %d\n", v); }
        else if (ch == 3) display();
    } while (ch != 4);
    return 0;
}
