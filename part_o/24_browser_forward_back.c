/*
 * part_o / q24.c
 * Browser history - forward/back navigation using a doubly linked
 * list. Menu: 1=visit page (int id), 2=back, 3=forward, 4=show current.
 * Back/forward move along the list; visiting a new page truncates
 * the forward branch.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int page;
    struct Node *prev, *next;
} Node;

int main(void) {
    Node *cur = NULL;
    int ch, p;
    while (scanf("%d", &ch) == 1 && ch != 0) {
        if (ch == 1) {
            if (scanf("%d", &p) != 1) continue;
            Node *nn = (Node*)malloc(sizeof(Node));
            nn->page = p; nn->prev = cur; nn->next = NULL;
            if (cur) {
                Node *t = cur->next;
                while (t) { Node *nxt = t->next; free(t); t = nxt; }
                cur->next = nn;
            }
            cur = nn;
            printf("Visited %d\n", p);
        } else if (ch == 2) {
            if (cur && cur->prev) { cur = cur->prev; printf("Back to %d\n", cur->page); }
            else printf("No back history\n");
        } else if (ch == 3) {
            if (cur && cur->next) { cur = cur->next; printf("Forward to %d\n", cur->page); }
            else printf("No forward history\n");
        } else if (ch == 4) {
            if (cur) printf("Current: %d\n", cur->page); else printf("None\n");
        }
    }
    return 0;
}
