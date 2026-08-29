/*
 * q33.c -- Circular Linked List: INSERT AT THE BEGINNING
 *
 * Idea: the new node must become the head, but the LAST node has to be updated
 * as well so that it points to the new head:
 *      find last;  node->next = head;  last->next = node;  head = node;
 * If the list is empty, the node simply points to itself.
 *
 * Compile: gcc q33.c -o q33
 * Sample input : 3  20 30 40   insert 10  ->  10 -> 20 -> 30 -> 40 -> (head 10)
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
    struct Node *cur;

    if (head == NULL) {
        node->next = node;
        return node;
    }
    cur = head;
    while (cur->next != head)
        cur = cur->next;
    cur->next = node;
    node->next = head;
    return head;
}

/* Insert at the front of a circular list; returns the NEW head. */
struct Node *insertBeginning(struct Node *head, int value)
{
    struct Node *node = newNode(value);
    struct Node *last;

    if (head == NULL) {
        node->next = node;
        return node;
    }

    last = head;
    while (last->next != head)        /* locate the last node */
        last = last->next;

    node->next = head;                /* new node points to the old head */
    last->next = node;                /* last node points to the new head */
    return node;                      /* new head */
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

void freeCircular(struct Node *head)
{
    struct Node *cur, *tmp;

    if (head == NULL)
        return;
    cur = head->next;
    while (cur != head) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(head);
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
            freeCircular(head);
            return 1;
        }
        head = insertEnd(head, value);
    }

    printf("\nOriginal circular list: ");
    display(head);

    printf("How many elements to insert at the beginning? ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid input\n");
        freeCircular(head);
        return 1;
    }

    for (i = 0; i < k; i++) {
        printf("Enter value %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input\n");
            freeCircular(head);
            return 1;
        }
        head = insertBeginning(head, value);
        printf("After inserting %d at beginning: ", value);
        display(head);
    }

    printf("\nFinal circular list: ");
    display(head);

    freeCircular(head);
    return 0;
}
