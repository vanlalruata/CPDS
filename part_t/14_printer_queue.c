/* part_t/q14.c — Printer Queue (simulate print jobs using a queue) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct Job {
    int id;
    char doc[50];
};

struct Queue {
    struct Job data[MAX];
    int front, rear;
} q;

void init() { q.front = q.rear = -1; }
int isEmpty() { return q.front == -1; }
void addJob(int id, char *doc) {
    if (q.rear == MAX - 1) { printf("Queue full.\n"); return; }
    if (isEmpty()) q.front = 0;
    q.rear++;
    q.data[q.rear].id = id; strcpy(q.data[q.rear].doc, doc);
    printf("Job %d added.\n", id);
}
void printJob() {
    if (isEmpty()) { printf("No jobs.\n"); return; }
    printf("Printing job %d: %s\n", q.data[q.front].id, q.data[q.front].doc);
    if (q.front == q.rear) q.front = q.rear = -1; else q.front++;
}
void display() {
    if (isEmpty()) { printf("Empty.\n"); return; }
    for (int i = q.front; i <= q.rear; i++) printf("%d %s\n", q.data[i].id, q.data[i].doc);
}

int main(void) {
    int ch, id; char doc[50];
    init();
    do {
        printf("\n1.Add Job 2.Print 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("id doc: "); scanf("%d %49s", &id, doc); addJob(id, doc); break;
            case 2: printJob(); break;
            case 3: display(); break;
        }
    } while (ch != 4);
    return 0;
}
