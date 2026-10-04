/* part_q/q19.c
 * Simulate printer scheduling using a queue (FIFO job queue).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Job { int jobid; int pages; struct Job *next; } Job;
Job *front = NULL, *rear = NULL;

void submit(int id, int p) {
    Job *j = malloc(sizeof(Job));
    j->jobid = id; j->pages = p; j->next = NULL;
    if (!rear) front = rear = j; else { rear->next = j; rear = j; }
}

void print() {
    if (!front) { printf("No jobs.\n"); return; }
    Job *t = front; front = front->next;
    printf("Printing job %d (%d pages)...\n", t->jobid, t->pages);
    free(t);
    if (!front) rear = NULL;
}

int main() {
    submit(1, 3); submit(2, 10); submit(3, 1);
    while (front) print();
    return 0;
}
