/* part_r/q14.c
 * Round-based CPU scheduling using a circular queue of processes.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef struct { int pid; int remaining; } Proc;
Proc q[MAX];
int front = 0, rear = -1, count = 0;

void add(int id, int b) {
    if (count == MAX) return;
    rear = (rear + 1) % MAX;
    q[rear].pid = id; q[rear].remaining = b; count++;
}

void schedule(int quantum) {
    while (count) {
        Proc p = q[front];
        int run = p.remaining < quantum ? p.remaining : quantum;
        printf("Process %d runs for %d\n", p.pid, run);
        p.remaining -= run;
        front = (front + 1) % MAX;
        if (p.remaining > 0) { rear = (rear + 1) % MAX; q[rear] = p; }
        else count--;
    }
}

int main() {
    add(1, 6); add(2, 4); add(3, 3);
    schedule(2);
    return 0;
}
