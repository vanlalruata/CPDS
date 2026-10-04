/* part_r/q17.c
 * Josephus problem using a circular queue / circular elimination.
 * N people, every k-th is eliminated; print elimination order.
 */
#include <stdio.h>
#define MAX 100

int q[MAX], front = 0, rear = -1, count = 0;

void enqueue(int v) { rear = (rear+1)%MAX; q[rear] = v; count++; }
int dequeue() { int v = q[front]; front = (front+1)%MAX; count--; return v; }

int main() {
    int n, k;
    printf("N and K: "); scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) enqueue(i);
    printf("Elimination order: ");
    while (count > 1) {
        for (int i = 1; i < k; i++) enqueue(dequeue());
        printf("%d ", dequeue());
    }
    printf("\nSurvivor: %d\n", dequeue());
    return 0;
}
