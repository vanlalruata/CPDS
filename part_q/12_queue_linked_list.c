/* part_q/q12.c
 * Implement a queue using a linked list.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int v) {
    Node *n = malloc(sizeof(Node));
    n->data = v; n->next = NULL;
    if (!rear) front = rear = n;
    else { rear->next = n; rear = n; }
}

int dequeue() {
    if (!front) { printf("Underflow\n"); return -1; }
    int v = front->data;
    Node *t = front; front = front->next;
    if (!front) rear = NULL;
    free(t);
    return v;
}

void display() {
    if (!front) { printf("Empty\n"); return; }
    for (Node *p = front; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}

int main() {
    enqueue(1); enqueue(2); enqueue(3);
    display();
    printf("Dequeued %d\n", dequeue());
    display();
    while (front) dequeue();
    return 0;
}
