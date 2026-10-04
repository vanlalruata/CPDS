/* part_q/q13.c
 * Insert into a linked-list queue (enqueue focused).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;
Node *front = NULL, *rear = NULL;

void insert(int v) {
    Node *n = malloc(sizeof(Node));
    n->data = v; n->next = NULL;
    if (!rear) front = rear = n;
    else { rear->next = n; rear = n; }
    printf("Inserted %d\n", v);
}

int main() {
    insert(5); insert(15); insert(25);
    for (Node *p = front; p; p = p->next) printf("%d ", p->data);
    printf("\n");
    while (front) { Node *t = front; front = front->next; free(t); }
    return 0;
}
