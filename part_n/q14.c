/*
 * q14.c -- Singly Linked List: DELETE THE LAST NODE
 *
 * Idea: two cases.
 *   1. only one node  -> free it and the list becomes empty;
 *   2. otherwise walk with a 'prev' pointer until cur->next == NULL, then set
 *      prev->next = NULL and free(cur).
 *
 * Compile: gcc q14.c -o q14
 * Sample input : 4  10 20 30 40   ->  deleted 40, list = 10 -> 20 -> 30 -> NULL
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

/* Delete the last node; returns the new head. */
struct Node *deleteLast(struct Node *head)
{
    struct Node *cur = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty -- deletion not possible (underflow)\n");
        return NULL;
    }

    if (head->next == NULL) {          /* single node */
        printf("Deleted node with value %d\n", head->data);
        free(head);
        return NULL;
    }

    while (cur->next != NULL) {        /* stop at the last node */
        prev = cur;
        cur = cur->next;
    }

    prev->next = NULL;                 /* second-last becomes the last */
    printf("Deleted node with value %d\n", cur->data);
    free(cur);
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

    printf("How many nodes to delete from the end? ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    for (i = 0; i < k; i++) {
        head = deleteLast(head);
        printf("List now: ");
        display(head);
    }

    printf("\nFinal list: ");
    display(head);

    freeList(head);
    return 0;
}
