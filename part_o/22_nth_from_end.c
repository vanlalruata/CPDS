/*
 * part_o / q22.c
 * Doubly Linked List - Nth node from the end.
 * Reads n values, then k; prints the k-th node from the end
 * (1-based). Uses a difference of two pointers.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

int main(void) {
    int n, k;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int v; if (scanf("%d", &v) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = v; nn->prev = tail; nn->next = NULL;
        if (!head) head = nn; else tail->next = nn;
        tail = nn;
    }
    if (scanf("%d", &k) != 1) return 0;
    Node *first = head;
    for (int i = 0; i < k && first; i++) first = first->next;
    if (!first) { printf("Invalid k\n"); }
    else {
        Node *second = head;
        while (first) { first = first->next; second = second->next; }
        printf("%dth node from end = %d\n", k, second->data);
    }
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
