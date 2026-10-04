/* part_t/q17.c — Dynamic Linked List using malloc
 * Operations: insert, delete, search, display, reverse
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *h, int v) {
    struct Node *n = malloc(sizeof(struct Node)); n->data = v; n->next = h; return n;
}
struct Node *del(struct Node *h, int v) {
    struct Node *p = h, *prev = NULL;
    while (p) {
        if (p->data == v) {
            if (!prev) h = p->next; else prev->next = p->next;
            free(p); printf("Deleted.\n"); return h;
        }
        prev = p; p = p->next;
    }
    printf("Not found.\n"); return h;
}
int search(struct Node *h, int v) {
    while (h) { if (h->data == v) return 1; h = h->next; }
    return 0;
}
void display(struct Node *h) { while (h) { printf("%d ", h->data); h = h->next; } printf("\n"); }
struct Node *reverse(struct Node *h) {
    struct Node *p = NULL, *c = h, *n;
    while (c) { n = c->next; c->next = p; p = c; c = n; }
    return p;
}

int main(void) {
    struct Node *h = NULL; int ch, v;
    do {
        printf("\n1.Insert 2.Delete 3.Search 4.Display 5.Reverse 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("val: "); scanf("%d", &v); h = insert(h, v); break;
            case 2: printf("val: "); scanf("%d", &v); h = del(h, v); break;
            case 3: printf("val: "); scanf("%d", &v); printf(search(h, v) ? "Found\n" : "Not found\n"); break;
            case 4: display(h); break;
            case 5: h = reverse(h); printf("Reversed.\n"); break;
        }
    } while (ch != 6);
    while (h) { struct Node *t = h; h = h->next; free(t); }
    return 0;
}
