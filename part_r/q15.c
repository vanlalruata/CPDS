/* part_r/q15.c
 * Round-robin scheduling demonstration (quantum-based circular queue).
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct { int pid; int burst; } Proc;
Proc q[MAX];
int front = 0, rear = -1, count = 0;

void add(int id, int b) {
    if (count == MAX) return;
    rear = (rear + 1) % MAX;
    q[rear].pid = id; q[rear].burst = b; count++;
}

void roundRobin(int quantum) {
    while (count) {
        Proc p = q[front];
        int run = (p.burst < quantum) ? p.burst : quantum;
        printf("P%d runs %d (remaining %d)\n", p.pid, run, p.burst - run);
        p.burst -= run;
        front = (front + 1) % MAX;
        if (p.burst > 0) { rear = (rear + 1) % MAX; q[rear] = p; }
        else count--;
    }
}

int main() {
    add(1, 5); add(2, 2); add(3, 7);
    roundRobin(3);
    return 0;
}
