/*
 * q13.c -- Singly Linked List: DELETE THE FIRST NODE
 *
 * Idea: remember the head in a temporary pointer, move head to head->next and
 * free the old node. O(1). Always check for an empty list (underflow) first.
 *
 * Compile: gcc q13.c -o q13
 * Sample input : 4  10 20 30 40   ->  deleted 10, list = 20 -> 30 -> 40 -> NULL
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

struct Node *insertEnd(struct Node *head, int value)
{
    struct Node *node = newNode(value);
    struct Node *cur = head;

    if (head == NULL)
        return node;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = node;
    return head;
}

/* Delete the first node and return the new head. */
struct Node *deleteFirst(struct Node *head)
{
    struct Node *tmp;

    if (head == NULL) {
        printf("List is empty -- deletion not possible (underflow)\n");
        return NULL;
    }

    tmp = head;                    /* node to be removed */
    head = head->next;             /* second node becomes head */
    printf("Deleted node with value %d\n", tmp->data);
    free(tmp);                     /* release memory */
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
    int n, i, value, k;

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

    printf("\nOriginal list: ");
    display(head);

    printf("How many nodes to delete from the beginning? ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    for (i = 0; i < k; i++) {
        head = deleteFirst(head);
        printf("List now: ");
        display(head);
    }

    printf("\nFinal list: ");
    display(head);

    freeList(head);
    return 0;
}
