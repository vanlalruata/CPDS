/*
 * part_p / q33.c
 * Stack Using Linked List - Sort a stack (linked-list based).
 * Pops the list into an array, sorts the array, then rebuilds the
 * stack. (A purely pointer-based insertion sort is also valid.)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

void push(Node **top, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->next = *top; *top = nn;
}

int main(void) {
    Node *top = NULL;
    int n, x;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&top, x); }
    int k = 0;
    for (Node *c = top; c; c = c->next) arr[k++] = c->data;
    /* selection sort */
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++)
            if (arr[i] > arr[j]) { int t = arr[i]; arr[i] = arr[j]; arr[j] = t; }
    /* rebuild stack from sorted array */
    while (top) { Node *t = top->next; free(top); top = t; }
    for (int i = 0; i < k; i++) push(&top, arr[i]);
    printf("Sorted: ");
    for (Node *c = top; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    free(arr);
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
