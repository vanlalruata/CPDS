/* part_j / q35: Create the first node of a linked list using malloc(). */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main(void) {
    Node *head = (Node *)malloc(sizeof(Node));
    if (!head) return 1;
    head->data = 100;
    head->next = NULL;
    printf("First node created: data=%d, next=%p\n", head->data, (void *)head->next);
    free(head);
    return 0;
}
