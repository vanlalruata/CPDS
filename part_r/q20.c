/* part_r/q20.c
 * Time complexity of queue operations.
 * enqueue, dequeue, front, rear, isEmpty, isFull are all O(1)
 * because we use index arithmetic, not shifting.
 */
#include <stdio.h>
#define MAX 4

int q[MAX], front = 0, rear = -1, count = 0;

void enqueue(int v) { /* O(1) */ rear=(rear+1)%MAX; q[rear]=v; count++; }
int dequeue() { /* O(1) */ int v=q[front]; front=(front+1)%MAX; count--; return v; }

int main() {
    for (int i = 0; i < 1000; i++) enqueue(i % MAX);
    while (count) dequeue();
    printf("All operations run in O(1) constant time.\n");
    printf("enqueue/dequeue/front/rear/isEmpty/isFull = O(1)\n");
    printf("display = O(n), space = O(n)\n");
    return 0;
}
