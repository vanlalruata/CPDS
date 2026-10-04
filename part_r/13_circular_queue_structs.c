/* part_r/q13.c
 * Circular queue of structures (sensor readings).
 */
#include <stdio.h>
#define MAX 3

typedef struct { int id; int value; } Reading;
Reading q[MAX];
int front = 0, rear = -1, count = 0;

void enqueue(Reading r) {
    if (count == MAX) { printf("Full\n"); return; }
    rear = (rear + 1) % MAX; q[rear] = r; count++;
}

void display() {
    if (count == 0) { printf("Empty\n"); return; }
    for (int i = 0; i < count; i++) {
        Reading r = q[(front + i) % MAX];
        printf("[id=%d val=%d] ", r.id, r.value);
    }
    printf("\n");
}

int main() {
    Reading r;
    for (int i = 0; i < MAX; i++) {
        printf("id value: "); scanf("%d %d", &r.id, &r.value);
        enqueue(r);
    }
    display();
    return 0;
}
