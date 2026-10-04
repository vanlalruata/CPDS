/*
 * q31.c -- Circular Linked List: CREATION
 *
 * In a circular singly linked list the last node points back to the first node
 * instead of NULL, so there is no NULL 'next' anywhere and traversal must be
 * stopped explicitly when the head is reached again.
 *
 * Idea: append each value at the end; after every insertion the new last node
 * is made to point to the head, keeping the circle intact.
 *
 * Compile: gcc q31.c -o q31
 * Sample input : 4  10 20 30 40
 * Sample output: 10 -> 20 -> 30 -> 40 -> (back to head 10)
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *newNode(int value)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    p->data = value;
    p->next = NULL;
    return p;
}

/* Insert at the end of a circular list; returns the head. */
struct Node *insertEnd(struct Node *head, int value)
{
    struct Node *node = newNode(value);
    struct Node *cur;

    if (head == NULL) {
        node->next = node;             /* single node points to itself */
        return node;
    }

    cur = head;
    while (cur->next != head)          /* stop at the last node */
        cur = cur->next;

    cur->next = node;
    node->next = head;                 /* close the circle */
    return head;
}

void display(struct Node *head)
{
    struct Node *cur = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d -> ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("(back to head %d)\n", head->data);
}

/* Verify the structure really is circular. */
void checkStructure(struct Node *head)
{
    struct Node *cur = head;
    int count = 0;

    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    do {
        count++;
        cur = cur->next;
    } while (cur != head);

    printf("Nodes = %d\n", count);
    printf("Head node value = %d\n", head->data);

    cur = head;
    while (cur->next != head)
        cur = cur->next;
    printf("Last node value = %d, and last->next points to %d (the head)\n",
           cur->data, cur->next->data);
}

void freeCircular(struct Node *head)
{
    struct Node *cur, *tmp;

    if (head == NULL)
        return;
    cur = head->next;
    while (cur != head) {              /* free everything except the head */
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(head);
}

int main(void)
{
    struct Node *head = NULL;
    int n, i, value;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter %d integer(s): ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) {
            printf("Invalid input\n");
            freeCircular(head);
            return 1;
        }
        head = insertEnd(head, value);
    }

    printf("\nCircular linked list created:\n");
    display(head);

    printf("\nStructure check:\n");
    checkStructure(head);

    freeCircular(head);
    return 0;
}
