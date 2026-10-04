/* part_t/q22.c — Queue Using Linked List (dynamic nodes) */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int v) {
    struct Node *n = malloc(sizeof(struct Node)); n->data = v; n->next = NULL;
    if (!rear) front = rear = n; else { rear->next = n; rear = n; }
}
int dequeue() {
    if (!front) { printf("Queue underflow.\n"); return -1; }
    struct Node *t = front; int v = t->data; front = front->next;
    if (!front) rear = NULL; free(t); return v;
}
void display() { struct Node *p = front; while (p) { printf("%d ", p->data); p = p->next; } printf("\n"); }

int main(void) {
    int ch, v;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("val: "); scanf("%d", &v); enqueue(v); break;
            case 2: v = dequeue(); if (v != -1) printf("Dequeued %d\n", v); break;
            case 3: display(); break;
        }
    } while (ch != 4);
    while (front) { struct Node *t = front; front = front->next; free(t); }
    return 0;
}
