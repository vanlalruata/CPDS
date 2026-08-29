/* part_q/q15.c
 * Queue implemented with dynamically allocated nodes (linked list).
 * Memory is freed at the end.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;
Node *front = NULL, *rear = NULL;

void enqueue(int v) {
    Node *n = malloc(sizeof(Node));
    n->data = v; n->next = NULL;
    if (!rear) front = rear = n;
    else { rear->next = n; rear = n; }
}

int dequeue() {
    if (!front) return -1;
    int v = front->data;
    Node *t = front; front = front->next;
    free(t);
    return v;
}

int main() {
    int n, v;
    printf("How many values? "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &v); enqueue(v); }
    printf("Dequeued in order: ");
    while (front) printf("%d ", dequeue());
    printf("\n");
    return 0;
}
