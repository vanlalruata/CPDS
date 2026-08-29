/*
 * part_o / q21.c
 * Doubly Linked List - Find the middle node.
 * Reads n values and prints the middle element using the
 * slow/fast pointer technique.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL, *tail = NULL, *slow = NULL;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int v; if (scanf("%d", &v) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = v; nn->prev = tail; nn->next = NULL;
        if (!head) { head = nn; slow = nn; }
        else tail->next = nn;
        tail = nn;
        cnt++;
        if (cnt % 2 == 0) slow = slow->next;
    }
    if (slow) printf("Middle = %d\n", slow->data);
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
