/*
 * part_p / q43.c
 * Stack Using Linked List - Stack of structures.
 * A stack storing Point structures {x, y}; push/pop at the head.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int x, y; } Point;

typedef struct Node { Point p; struct Node *next; } Node;

void push(Node **top, Point p) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->p = p; nn->next = *top; *top = nn;
}
Point pop(Node **top) {
    Point empty = {0, 0};
    if (!*top) { printf("Underflow\n"); return empty; }
    Node *t = *top; Point v = t->p; *top = t->next; free(t); return v;
}

int main(void) {
    Node *top = NULL;
    int n, x, y;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d%d", &x, &y) != 2) break;
        push(&top, (Point){x, y});
    }
    printf("Points (top to bottom): ");
    while (top) { Point p = pop(&top); printf("(%d,%d) ", p.x, p.y); }
    printf("\n");
    return 0;
}
