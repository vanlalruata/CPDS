/* part_t/q29.c — Linked List-Based Polynomial Calculator
 * Create, Display, Add, Evaluate a polynomial.
 */
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
float eval(struct Term *h, float x) {
    float s = 0; while (h) { float t = 1; for (int i = 0; i < h->exp; i++) t *= x; s += h->coeff * t; h = h->next; } return s;
}

int main(void) {
    struct Term *p = NULL, *q = NULL, *r = NULL; int n, c, e; float x;
    printf("Number of terms in P: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { printf("coeff exp: "); scanf("%d %d", &c, &e); append(&p, c, e); }
    printf("Number of terms in Q: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { printf("coeff exp: "); scanf("%d %d", &c, &e); append(&q, c, e); }
    r = add(p, q);
    printf("P = "); display(p);
    printf("Q = "); display(q);
    printf("P+Q = "); display(r);
    printf("Evaluate P at x=2: "); scanf("%f", &x); printf("= %.2f\n", eval(p, x));
    return 0;
}
