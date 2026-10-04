/* part_r/q18.c
 * Producer-consumer style buffering (simple simulated version).
 * Producer enqueues items up to capacity; consumer dequeues them.
 */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1, count = 0;

void produce(int v) {
    if (count == MAX) { printf("Buffer full, drop %d\n", v); return; }
    rear = (rear + 1) % MAX; q[rear] = v; count++;
    printf("Produced %d (buffer=%d)\n", v, count);
}
void consume() {
    if (count == 0) { printf("Buffer empty\n"); return; }
    int v = q[front]; front = (front + 1) % MAX; count--;
    printf("Consumed %d (buffer=%d)\n", v, count);
}

int main() {
    produce(1); produce(2); produce(3);
    consume(); consume();
    produce(4); produce(5); produce(6); produce(7); /* one dropped */
    while (count) consume();
    return 0;
}
