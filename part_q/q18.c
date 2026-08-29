/* part_q/q18.c
 * Simulate a customer service desk using a queue.
 * Customers arrive (enqueue) and are served one by one (dequeue).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Cust { int cid; struct Cust *next; } Cust;
Cust *front = NULL, *rear = NULL;

void arrive(int id) {
    Cust *c = malloc(sizeof(Cust));
    c->cid = id; c->next = NULL;
    if (!rear) front = rear = c; else { rear->next = c; rear = c; }
    printf("Customer %d joined the queue.\n", id);
}

void serve() {
    if (!front) { printf("No customers waiting.\n"); return; }
    Cust *t = front; front = front->next;
    printf("Serving customer %d.\n", t->cid);
    free(t);
    if (!front) rear = NULL;
}

int main() {
    int n, id;
    printf("Number of customers? "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &id); arrive(id); }
    printf("-- Serving --\n");
    while (front) serve();
    return 0;
}
