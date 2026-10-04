/*
 * q1.c -- Singly Linked List: CREATION (build from input, insert at end)
 *
 * Idea: read n, then n integers; append each value at the end of the list so
 * that the list order matches the input order.
 * Key points: malloc() for each node, walk to the last node to append,
 *             free() every node before exiting.
 *
 * Compile: gcc q1.c -o q1
 * Sample input : 5  10 20 30 40 50
 * Sample output: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Allocate and initialise one node. */
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

/* Insert at the end; returns the head of the list. */
struct Node *insertEnd(struct Node *head, int value)
{
    struct Node *node = newNode(value);
    struct Node *cur;

    if (head == NULL)
        return node;                 /* first node becomes the head */

    cur = head;
    while (cur->next != NULL)        /* walk to the last node */
        cur = cur->next;
    cur->next = node;
    return head;
}

void display(struct Node *head)
{
    struct Node *cur;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    for (cur = head; cur != NULL; cur = cur->next)
        printf("%d -> ", cur->data);
    printf("NULL\n");
}

void freeList(struct Node *head)
{
    struct Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
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
            freeList(head);
            return 1;
        }
        head = insertEnd(head, value);
    }

    printf("\nLinked list created (in input order):\n");
    display(head);

    freeList(head);                  /* release all nodes */
    return 0;
}
