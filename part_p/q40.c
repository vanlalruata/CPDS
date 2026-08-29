/*
 * part_p / q40.c
 * Stack Using Linked List - Compare array vs linked-list stacks.
 *
 * COMPARISON:
 *   Array stack  : fixed (or realloc'd) contiguous memory; O(1) access,
 *                  may overflow when full; slightly less per-element
 *                  overhead (no next pointer).
 *   List stack   : grows with malloc; never overflows until memory is
 *                  exhausted; each node carries a pointer (extra space);
 *                  push/pop allocate/free.
 *
 * Demo below builds the SAME sequence with both implementations and
 * prints both results to show identical LIFO behavior.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct { int a[MAX]; int top; } AStack;
typedef struct Node { int data; struct Node *next; } LNode;

void apush(AStack *s, int x) { s->a[++s->top] = x; }
int apop(AStack *s) { return s->a[s->top--]; }
void lpush(LNode **t, int x) { LNode *nn = (LNode*)malloc(sizeof(LNode)); nn->data = x; nn->next = *t; *t = nn; }
int lpop(LNode **t) { LNode *p = *t; int v = p->data; *t = p->next; free(p); return v; }

int main(void) {
    AStack as; as.top = -1;
    LNode *lt = NULL;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) { apush(&as, x); lpush(&lt, x); } }
    printf("Array stack pop:   "); while (as.top != -1) printf("%d ", apop(&as)); printf("\n");
    printf("List  stack pop:   "); while (lt) printf("%d ", lpop(&lt)); printf("\n");
    return 0;
}
