/* part_q/q11.c
 * Menu-driven queue (array based) with all basic operations.
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
    if (isEmpty()) { printf("Empty\n"); return; }
    for (int i = front; i <= rear; i++) printf("%d ", q[i]);
    printf("\n");
}

int main() {
    int ch, v;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Front 4.Rear 5.Display 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Val: "); scanf("%d", &v); enqueue(v); break;
            case 2: v = dequeue(); if (v != -1) printf("Got %d\n", v); break;
            case 3: if (!isEmpty()) printf("Front=%d\n", q[front]); else printf("Empty\n"); break;
            case 4: if (!isEmpty()) printf("Rear=%d\n", q[rear]); else printf("Empty\n"); break;
            case 5: display(); break;
        }
    } while (ch != 6);
    return 0;
}
