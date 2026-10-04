/* part_t/q19.c — Polynomial Addition (two polynomials via linked lists) */
#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff, exp;
    struct Term *next;
};

void append(struct Term **h, int c, int e) {
    if (c == 0) return;
    struct Term *t = malloc(sizeof(struct Term)); t->coeff = c; t->exp = e; t->next = NULL;
    if (!*h) { *h = t; return; }
    struct Term *p = *h; while (p->next) p = p->next; p->next = t;
}

void display(struct Term *h) {
    if (!h) { printf("0\n"); return; }
    while (h) { printf("%dx^%d", h->coeff, h->exp); if (h->next) printf(" + "); h = h->next; }
    printf("\n");
}

struct Term *add(struct Term *a, struct Term *b) {
    struct Term *r = NULL;
    while (a && b) {
        if (a->exp == b->exp) { append(&r, a->coeff + b->coeff, a->exp); a = a->next; b = b->next; }
        else if (a->exp > b->exp) { append(&r, a->coeff, a->exp); a = a->next; }
        else { append(&r, b->coeff, b->exp); b = b->next; }
    }
    while (a) { append(&r, a->coeff, a->exp); a = a->next; }
    while (b) { append(&r, b->coeff, b->exp); b = b->next; }
    return r;
}

int main(void) {
    struct Term *p = NULL, *q = NULL, *r = NULL;
    append(&p, 4, 3); append(&p, 3, 1); append(&p, 5, 0);
    append(&q, 2, 3); append(&q, 1, 2); append(&q, 2, 0);
    printf("P = "); display(p);
    printf("Q = "); display(q);
    r = add(p, q);
    printf("P+Q = "); display(r);
    return 0;
}
