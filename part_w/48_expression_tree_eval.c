/* q48: Expression tree for ((3+5)*2); evaluated with postorder. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char op;        /* '+','*', etc. 0 if leaf */
    int  value;     /* used when op==0 */
    struct Node *left, *right;
};

static struct Node *leaf(int v) {
    struct Node *n = malloc(sizeof *n);
    n->op = 0; n->value = v; n->left = n->right = NULL; return n;
}
static struct Node *node(char op, struct Node *l, struct Node *r) {
    struct Node *n = malloc(sizeof *n);
    n->op = op; n->value = 0; n->left = l; n->right = r; return n;
}
static int eval(struct Node *r) {
    if (!r->op) return r->value;
    int a = eval(r->left), b = eval(r->right);
    switch (r->op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}
static void postfix(struct Node *r) {
    if (!r) return;
    postfix(r->left); postfix(r->right);
    if (r->op) printf("%c ", r->op); else printf("%d ", r->value);
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    /* ((3+5)*2) */
    struct Node *three = leaf(3);
    struct Node *five  = leaf(5);
    struct Node *two   = leaf(2);
    struct Node *plus  = node('+', three, five);
    struct Node *root  = node('*', plus, two);

    printf("Postfix: "); postfix(root); printf("\n");
    printf("((3+5)*2) = %d\n", eval(root));
    free_tree(root);
    return 0;
}