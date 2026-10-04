/* part_q/q20.c
 * Simulate CPU process scheduling using a queue (FIFO ready queue).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Proc { int pid; int burst; struct Proc *next; } Proc;
Proc *front = NULL, *rear = NULL;

void add(int id, int b) {
    Proc *p = malloc(sizeof(Proc));
    p->pid = id; p->burst = b; p->next = NULL;
    if (!rear) front = rear = p; else { rear->next = p; rear = p; }
}

void run() {
    if (!front) { printf("Ready queue empty.\n"); return; }
    Proc *t = front; front = front->next;
    printf("CPU runs process %d for %d units.\n", t->pid, t->burst);
    free(t);
    if (!front) rear = NULL;
}

int main() {
    add(101, 5); add(102, 3); add(103, 8);
    while (front) run();
    return 0;
}
