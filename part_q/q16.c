/* part_q/q16.c
 * A queue of integers (array based, reusable size).
 */
#include <stdio.h>
#define MAX 100

int q[MAX], front = 0, rear = -1, size;

void enqueue(int v) { if (rear < size - 1) q[++rear] = v; }

int main() {
    printf("Enter queue capacity: "); scanf("%d", &size);
    int n, v;
    printf("How many to enqueue? "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &v); enqueue(v); }
    printf("Integers dequeued: ");
    while (front <= rear) printf("%d ", q[front++]);
    printf("\n");
    return 0;
}
