/* part_t/q20.c — Polynomial Multiplication (two polynomials via linked lists) */
#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff, exp;
    struct Term *next;
};

void append(struct Term **h, int c, int e) {
    struct Term *t = malloc(sizeof(struct Term)); t->coeff = c; t->exp = e; t->next = NULL;
    if (!*h) { *h = t; return; }
    struct Term *p = *h; while (p->next) p = p->next; p->next = t;
}

/* combine like terms for a result list */
void addTerm(struct Term **h, int c, int e) {
    struct Term *p = *h;
    while (p) { if (p->exp == e) { p->coeff += c; return; } p = p->next; }
    append(h, c, e);
}

void display(struct Term *h) {
    if (!h) { printf("0\n"); return; }
    while (h) { printf("%dx^%d", h->coeff, h->exp); if (h->next) printf(" + "); h = h->next; }
    printf("\n");
}

struct Term *multiply(struct Term *a, struct Term *b) {
    struct Term *r = NULL;
    for (struct Term *p = a; p; p = p->next)
        for (struct Term *q = b; q; q = q->next)
            addTerm(&r, p->coeff * q->coeff, p->exp + q->exp);
    return r;
}

int main(void) {
    struct Term *p = NULL, *q = NULL, *r = NULL;
    append(&p, 2, 2); append(&p, 3, 1);          /* 2x^2 + 3x */
    append(&q, 4, 1); append(&q, 5, 0);          /* 4x + 5 */
    printf("P = "); display(p);
    printf("Q = "); display(q);
    r = multiply(p, q);
    printf("P*Q = "); display(r);
    return 0;
}
