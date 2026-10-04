/* part_t/q18.c — Sorted Linked List (ascending order after each insert) */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insertSorted(struct Node *h, int v) {
    struct Node *n = malloc(sizeof(struct Node)); n->data = v;
    if (!h || v < h->data) { n->next = h; return n; }
    struct Node *p = h;
    while (p->next && p->next->data < v) p = p->next;
    n->next = p->next; p->next = n;
    return h;
}

void display(struct Node *h) { while (h) { printf("%d ", h->data); h = h->next; } printf("\n"); }

int main(void) {
    struct Node *h = NULL; int ch, v;
    do {
        printf("\n1.Insert 2.Display 3.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("val: "); scanf("%d", &v); h = insertSorted(h, v); }
        else if (ch == 2) display(h);
    } while (ch != 3);
    while (h) { struct Node *t = h; h = h->next; free(t); }
    return 0;
}
