/* part_t/q11.c — Polynomial Representation via linked list
 * Concepts: nodes with coeff + exp; creation, display, addition
 * Display style: 5x^3 + 4x^2 + 2x + 7
 */
#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff, exp;
    struct Term *next;
};

struct Term *createTerm(int c, int e) {
    struct Term *t = malloc(sizeof(struct Term));
    t->coeff = c; t->exp = e; t->next = NULL; return t;
}

void append(struct Term **h, int c, int e) {
    if (c == 0) return;
    struct Term *t = createTerm(c, e);
    if (!*h) { *h = t; return; }
    struct Term *p = *h; while (p->next) p = p->next; p->next = t;
}

void display(struct Term *h) {
    if (!h) { printf("0\n"); return; }
    int first = 1;
    while (h) {
        if (!first && h->coeff > 0) printf(" + ");
        if (h->coeff < 0) printf(" - ");
        if (h->exp == 0) printf("%d", h->coeff < 0 ? -h->coeff : h->coeff);
        else if (h->exp == 1) printf("%dx", h->coeff < 0 ? -h->coeff : h->coeff);
        else printf("%dx^%d", h->coeff < 0 ? -h->coeff : h->coeff, h->exp);
        first = 0; h = h->next;
    }
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
    append(&p, 5, 3); append(&p, 4, 2); append(&p, 2, 1); append(&p, 7, 0);
    append(&q, 3, 2); append(&q, 6, 1); append(&q, 1, 0);
    printf("P = "); display(p);
    printf("Q = "); display(q);
    r = add(p, q);
    printf("P+Q = "); display(r);
    return 0;
}
