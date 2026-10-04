/* part_q/q14.c
 * Delete from a linked-list queue (dequeue focused).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;
Node *front = NULL, *rear = NULL;

void insert(int v) {
    Node *n = malloc(sizeof(Node));
    n->data = v; n->next = NULL;
    if (!rear) front = rear = n; else { rear->next = n; rear = n; }
}

int delete() {
    if (!front) { printf("Underflow\n"); return -1; }
    int v = front->data;
    Node *t = front; front = front->next;
    if (!front) rear = NULL;
    free(t);
    return v;
}

int main() {
    insert(10); insert(20); insert(30);
    printf("Deleted %d\n", delete());
    printf("Deleted %d\n", delete());
    while (front) { Node *t = front; front = front->next; free(t); }
    return 0;
}
