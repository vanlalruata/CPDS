/* part_r/q10.c
 * Why a circular queue is better than a simple array queue.
 * A simple array queue loses free space at the front after dequeue;
 * a circular queue reuses it, so it never reports "full" until truly full.
 */
#include <stdio.h>
#define MAX 5

/* Simple array queue */
int sq[MAX], sf = 0, sr = -1;
/* Circular queue */
int cq[MAX], cf = 0, cr = -1, cc = 0;

int main() {
    /* Fill and drain a simple queue */
    for (int i = 1; i <= MAX; i++) sq[++sr] = i;
    for (int i = 0; i < MAX; i++) sf++;
    printf("Simple queue: after enqueue+dequeue all %d, can it add more? ", MAX);
    printf(sr == MAX - 1 ? "NO (rear stuck at end)\n" : "YES\n");

    /* Circular queue handles it */
    for (int i = 1; i <= MAX; i++) { cr = (cr+1)%MAX; cq[cr] = i; cc++; }
    for (int i = 0; i < MAX; i++) { cf = (cf+1)%MAX; cc--; }
    printf("Circular queue: after same ops, can it add more? ");
    cr = (cr+1)%MAX; cq[cr] = 99; cc++;
    printf("YES (slot reused, added 99 at index %d)\n", cr);
    return 0;
}
