/*
 * part_p / q38.c
 * Stack Using Linked List - Browser history with two stacks.
 * backStack holds visited pages; forwardStack holds pages to redo.
 * Visiting a new page clears forwardStack. Menu:
 * 1=visit x 2=back 3=forward 4=show current.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int page; struct Node *next; } Node;

void push(Node **top, int x) { Node *nn = (Node*)malloc(sizeof(Node)); nn->page = x; nn->next = *top; *top = nn; }
int pop(Node **top) { if (!*top) return -1; Node *t = *top; int v = t->page; *top = t->next; free(t); return v; }
int peek(Node *top) { return top ? top->page : -1; }

int main(void) {
    Node *back = NULL, *fwd = NULL;
    int cur = -1, ch, x;
    while (scanf("%d", &ch) == 1 && ch != 0) {
        if (ch == 1) {
            if (scanf("%d", &x) != 1) continue;
            if (cur != -1) push(&back, cur);
            while (fwd) { Node *t = fwd->next; free(fwd); fwd = t; } /* clear forward */
            cur = x; printf("Visited %d\n", x);
        } else if (ch == 2) {
            if (back) { push(&fwd, cur); cur = pop(&back); printf("Back to %d\n", cur); }
            else printf("No back history\n");
        } else if (ch == 3) {
            if (fwd) { push(&back, cur); cur = pop(&fwd); printf("Forward to %d\n", cur); }
            else printf("No forward history\n");
        } else if (ch == 4) printf("Current: %d\n", cur);
    }
    while (back) { Node *t = back->next; free(back); back = t; }
    while (fwd) { Node *t = fwd->next; free(fwd); fwd = t; }
    return 0;
}
