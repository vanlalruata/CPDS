/* part_q/q9.c
 * Handle overflow in a queue (enqueue beyond capacity).
 */
#include <stdio.h>
#define MAX 3

int q[MAX], front = 0, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) {
        printf("OVERFLOW: queue full, cannot add %d\n", v);
        return;
    }
    q[++rear] = v;
    printf("Enqueued %d\n", v);
}

int main() {
    enqueue(1); enqueue(2); enqueue(3);
    enqueue(4); /* triggers overflow */
    return 0;
}
