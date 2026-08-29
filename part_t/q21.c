/* part_t/q21.c — Stack Using Linked List (dynamic nodes) */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **top, int v) {
    struct Node *n = malloc(sizeof(struct Node)); n->data = v; n->next = *top; *top = n;
}
int pop(struct Node **top) {
    if (!*top) { printf("Stack underflow.\n"); return -1; }
    struct Node *t = *top; int v = t->data; *top = t->next; free(t); return v;
}
void display(struct Node *top) { while (top) { printf("%d ", top->data); top = top->next; } printf("\n"); }

int main(void) {
    struct Node *top = NULL; int ch, v;
    do {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("val: "); scanf("%d", &v); push(&top, v); break;
            case 2: v = pop(&top); if (v != -1) printf("Popped %d\n", v); break;
            case 3: display(top); break;
        }
    } while (ch != 4);
    while (top) { struct Node *t = top; top = top->next; free(t); }
    return 0;
}
