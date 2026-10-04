/* part_r/q12.c
 * Implement a circular queue using a linked list.
 * The last node links back to the first, with a single pointer 'rear'.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;
Node *rear = NULL;
int count = 0;
#define MAX 5

void enqueue(int v) {
    if (count == MAX) { printf("Overflow\n"); return; }
    Node *n = malloc(sizeof(Node));
    n->data = v;
    if (!rear) { n->next = n; rear = n; }
    else { n->next = rear->next; rear->next = n; rear = n; }
    count++;
}

int dequeue() {
    if (!rear) { printf("Underflow\n"); return -1; }
    Node *f = rear->next;
    int v = f->data;
    if (f == rear) rear = NULL;
    else rear->next = f->next;
    free(f); count--;
    return v;
}

void display() {
    if (!rear) { printf("Empty\n"); return; }
    Node *p = rear->next;
    do { printf("%d ", p->data); p = p->next; } while (p != rear->next);
    printf("\n");
}

int main() {
    enqueue(1); enqueue(2); enqueue(3);
    display();
    printf("Dequeued %d\n", dequeue());
    display();
    while (rear) dequeue();
    return 0;
}
