/* part_r/q19.c
 * Compare simple queue vs circular queue (comment + demo).
 * Simple queue: rear never resets, so it fills up once.
 * Circular queue: rear wraps, reusing freed slots.
 */
#include <stdio.h>
#define MAX 3

int main() {
    /* Simple array queue */
    int sq[MAX], sf = 0, sr = -1;
    sq[++sr] = 1; sq[++sr] = 2; sq[++sr] = 3;
    sf++; sr = -1; /* simulate dequeue reset issue: lost reuse */
    printf("Simple queue after dequeues: rear=%d (cannot reuse without shift)\n", sr);

    /* Circular queue */
    int cq[MAX], cf = 0, cr = -1, cc = 0;
    for (int i = 0; i < MAX; i++) { cr=(cr+1)%MAX; cq[cr]=i+1; cc++; }
    for (int i = 0; i < MAX; i++) { cf=(cf+1)%MAX; cc--; }
    cr=(cr+1)%MAX; cq[cr]=99; cc++; /* reused slot */
    printf("Circular queue reused slot: index=%d value=%d\n", cr, cq[cr]);
    return 0;
}
