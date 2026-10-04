/* part_k / q35: Create a structure suitable for a linked-list node. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main(void) {
    Node *head = NULL, *second = NULL;
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    if (!head || !second) return 1;
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = NULL;
    printf("Linked list: %d -> %d -> NULL\n", head->data, second->data);
    free(second);
    free(head);
    return 0;
}
