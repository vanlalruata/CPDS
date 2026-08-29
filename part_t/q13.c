/* part_t/q13.c — Student Queue (registration using queue) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct Student {
    int roll;
    char name[50];
};

struct Queue {
    struct Student data[MAX];
    int front, rear;
} q;

void init() { q.front = q.rear = -1; }
int isEmpty() { return q.front == -1; }
void enqueue(int roll, char *name) {
    if (q.rear == MAX - 1) { printf("Queue full.\n"); return; }
    if (isEmpty()) q.front = 0;
    q.rear++;
    q.data[q.rear].roll = roll; strcpy(q.data[q.rear].name, name);
}
void dequeue() {
    if (isEmpty()) { printf("Queue empty.\n"); return; }
    printf("Registered: %d %s\n", q.data[q.front].roll, q.data[q.front].name);
    if (q.front == q.rear) q.front = q.rear = -1;
    else q.front++;
}
void display() {
    if (isEmpty()) { printf("Empty.\n"); return; }
    for (int i = q.front; i <= q.rear; i++) printf("%d %s\n", q.data[i].roll, q.data[i].name);
}

int main(void) {
    int ch, roll; char name[50];
    init();
    do {
        printf("\n1.Register 2.Process 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("roll name: "); scanf("%d %49s", &roll, name); enqueue(roll, name); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 4);
    return 0;
}
