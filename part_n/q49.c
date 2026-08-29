/*
 * q49.c -- CONVERT A SINGLY LINKED LIST INTO A CIRCULAR LINKED LIST
 *
 * Idea: only one link has to change. Walk to the last node (the one whose next
 * is NULL) and make it point to the head:
 *      last->next = head;
 * The reverse conversion (circular -> linear) is also shown: find the node
 * whose next is the head and set that next to NULL.
 *
 * Compile: gcc q49.c -o q49
 * Sample input : 5  10 20 30 40 50
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

/* Build a normal (NULL terminated) singly linked list. */
struct Node *insertEndLinear(struct Node *head, int value)
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

/* Singly -> circular: link the last node back to the head. */
struct Node *toCircular(struct Node *head)
{
    struct Node *cur = head;

    if (head == NULL)
        return NULL;
    while (cur->next != NULL)          /* find the last node */
        cur = cur->next;
    cur->next = head;                  /* close the circle */
    printf("Converted: node %d (last) now points to the head %d\n",
           cur->data, head->data);
    return head;
}

/* Circular -> singly: cut the link that closes the circle. */
struct Node *toLinear(struct Node *head)
{
    struct Node *cur = head;

    if (head == NULL)
        return NULL;
    while (cur->next != head)
        cur = cur->next;
    cur->next = NULL;
    printf("Converted back: node %d now points to NULL\n", cur->data);
    return head;
}

void displayLinear(struct Node *head)
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

void displayCircular(struct Node *head)
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

int countCircular(struct Node *head)
{
    struct Node *cur = head;
    int c = 0;

    if (head == NULL)
        return 0;
    do {
        c++;
        cur = cur->next;
    } while (cur != head);
    return c;
}

void freeLinear(struct Node *head)
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
            freeLinear(head);
            return 1;
        }
        head = insertEndLinear(head, value);
    }

    printf("\nSingly linked list: ");
    displayLinear(head);

    printf("\nConverting to a circular linked list...\n");
    head = toCircular(head);

    printf("Circular linked list: ");
    displayCircular(head);
    printf("Nodes counted by circular traversal = %d\n", countCircular(head));

    printf("\nConverting the circular list back to a singly linked list...\n");
    head = toLinear(head);
    printf("Singly linked list again: ");
    displayLinear(head);

    freeLinear(head);          /* safe: the list is linear again */
    return 0;
}
