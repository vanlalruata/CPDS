/*
 * part_o / q25.c
 * Undo / Redo using a doubly linked list.
 * Each action is an integer id. Menu: 1=do x (add action),
 * 2=undo (move to prev), 3=redo (move to next), 4=show.
 * Doing a new action after undo discards the redo branch.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int action;
    struct Node *prev, *next;
} Node;

int main(void) {
    Node *cur = NULL;
    int ch, x;
    while (scanf("%d", &ch) == 1 && ch != 0) {
        if (ch == 1) {
            if (scanf("%d", &x) != 1) continue;
            Node *nn = (Node*)malloc(sizeof(Node));
            nn->action = x; nn->prev = cur; nn->next = NULL;
            if (cur) {
                Node *t = cur->next;
                while (t) { Node *nxt = t->next; free(t); t = nxt; }
                cur->next = nn;
            }
            cur = nn;
            printf("Did %d\n", x);
        } else if (ch == 2) {
            if (cur && cur->prev) { cur = cur->prev; printf("Undo to %d\n", cur->action); }
            else printf("Nothing to undo\n");
        } else if (ch == 3) {
            if (cur && cur->next) { cur = cur->next; printf("Redo to %d\n", cur->action); }
            else printf("Nothing to redo\n");
        } else if (ch == 4) {
            if (cur) printf("Current action: %d\n", cur->action); else printf("No action\n");
        }
    }
    return 0;
}
