/*
 * part_o / q15.c
 * Doubly Linked List - Find minimum element.
 * Reads n values and prints the minimum value.
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    Node *head = NULL, *tail = NULL, *minNode = NULL;
    for (int i = 0; i < n; i++) {
        int v; if (scanf("%d", &v) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = v; nn->prev = tail; nn->next = NULL;
        if (!head) { head = nn; minNode = nn; }
        else tail->next = nn;
        tail = nn;
        if (nn->data < minNode->data) minNode = nn;
    }
    if (minNode) printf("Minimum = %d\n", minNode->data);
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
