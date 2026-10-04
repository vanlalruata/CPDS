/* part_t/q28.c — Menu-Driven Data Structure Program
 * 1.Array 2.Stack 3.Queue 4.Linked List 5.Tree 6.Exit
 * Demonstrates selected operations per chosen structure.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int arr[MAX], acount = 0;
int stack[MAX], stop = -1;
int queue[MAX], qf = -1, qr = -1;

/* very small linked list + BST hooks for demo */
struct N { int d; struct N *l, *r; } *ll = NULL, *tree = NULL;
struct N *mk(int d) { struct N *n = malloc(sizeof(struct N)); n->d = d; n->l = n->r = NULL; return n; }
struct N *llIns(struct N *h, int v) { struct N *n = mk(v); n->r = h; return n; }
void llDisp(struct N *h) { while (h) { printf("%d ", h->d); h = h->r; } printf("\n"); }
struct N *bstIns(struct N *r, int v) { if (!r) return mk(v); if (v < r->d) r->l = bstIns(r->l, v); else r->r = bstIns(r->r, v); return r; }
void ino(struct N *r) { if (r) { ino(r->l); printf("%d ", r->d); ino(r->r); } }

int main(void) {
    int ch, sub, v;
    do {
        printf("\n1.Array 2.Stack 3.Queue 4.LinkedList 5.Tree 6.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf(" 1.Add 2.Display: "); scanf("%d", &sub);
            if (sub == 1 && acount < MAX) { printf("val: "); scanf("%d", &v); arr[acount++] = v; }
            else if (sub == 2) { for (int i = 0; i < acount; i++) printf("%d ", arr[i]); printf("\n"); }
        } else if (ch == 2) {
            printf(" 1.Push 2.Pop: "); scanf("%d", &sub);
            if (sub == 1 && stop < MAX - 1) { printf("val: "); scanf("%d", &v); stack[++stop] = v; }
            else if (sub == 2 && stop >= 0) printf("Popped %d\n", stack[stop--]);
        } else if (ch == 3) {
            printf(" 1.Enqueue 2.Dequeue: "); scanf("%d", &sub);
            if (sub == 1) { if (qf == -1) qf = 0; printf("val: "); scanf("%d", &v); queue[++qr] = v; }
            else if (sub == 2 && qf >= 0) { printf("Deq %d\n", queue[qf++]); if (qf > qr) qf = qr = -1; }
        } else if (ch == 4) {
            printf(" 1.Insert 2.Display: "); scanf("%d", &sub);
            if (sub == 1) { printf("val: "); scanf("%d", &v); ll = llIns(ll, v); }
            else if (sub == 2) llDisp(ll);
        } else if (ch == 5) {
            printf(" 1.Insert 2.Inorder: "); scanf("%d", &sub);
            if (sub == 1) { printf("val: "); scanf("%d", &v); tree = bstIns(tree, v); }
            else if (sub == 2) { ino(tree); printf("\n"); }
        }
    } while (ch != 6);
    return 0;
}
