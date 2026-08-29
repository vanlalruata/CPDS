/*
 * part_p / q41.c
 * Stack Using Linked List - Two stacks using linked lists.
 * Two independent singly-linked-list stacks, each push/pop at head.
 * Reads pairs: 'which' (1 or 2) and value to push, then -1 to stop.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

void push(Node **t, int x) { Node *nn = (Node*)malloc(sizeof(Node)); nn->data = x; nn->next = *t; *t = nn; }
int pop(Node **t) { if (!*t) return -1; Node *p = *t; int v = p->data; *t = p->next; free(p); return v; }

int main(void) {
    Node *s1 = NULL, *s2 = NULL;
    int which, x;
    while (scanf("%d", &which) == 1 && which != 0) {
        if (scanf("%d", &x) != 1) break;
        if (which == 1) push(&s1, x); else push(&s2, x);
    }
    printf("Stack1 top->bottom: ");
    for (Node *c = s1; c; c = c->next) printf("%d ", c->data);
    printf("\nStack2 top->bottom: ");
    for (Node *c = s2; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (s1) { Node *t = s1->next; free(s1); s1 = t; }
    while (s2) { Node *t = s2->next; free(s2); s2 = t; }
    return 0;
}
