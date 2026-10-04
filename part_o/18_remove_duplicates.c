/*
 * part_o / q18.c
 * Doubly Linked List - Remove duplicates.
 * Reads n values and removes nodes whose value already appeared
 * earlier (keeps first occurrence of each value).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* removeDups(Node *head) {
    Node *i = head;
    while (i) {
        Node *j = i->next;
        while (j) {
            Node *nxt = j->next;
            if (j->data == i->data) {
                if (j->prev) j->prev->next = j->next;
                if (j->next) j->next->prev = j->prev;
                free(j);
            }
            j = nxt;
        }
        i = i->next;
    }
    return head;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int v; if (scanf("%d", &v) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = v; nn->prev = tail; nn->next = NULL;
        if (!head) head = nn; else tail->next = nn;
        tail = nn;
    }
    head = removeDups(head);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
