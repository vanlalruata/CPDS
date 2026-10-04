/*
 * q41.c -- Circular Linked List: REVERSE THE LIST
 *
 * Idea: the same three-pointer technique as a singly linked list, but the loop
 * is bounded by the head and the circle has to be closed again at the end:
 *      prev = last node (so the new last points back correctly)
 *      flip every link while walking one full round
 *      new head = old last node;  old head->next = new head... i.e.
 *      head->next = prev is handled by making the original head the last node.
 *
 * Compile: gcc q41.c -o q41
 * Sample input : 5  10 20 30 40 50  ->  50 -> 40 -> 30 -> 20 -> 10 -> (head 50)
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
    struct Node *last;

    if (head == NULL) {
        node->next = node;
        return node;
    }
    last = head;
    while (last->next != head)
        last = last->next;
    last->next = node;
    node->next = head;
    return head;
}

/* Reverse the circular list; returns the new head (the old last node). */
struct Node *reverseCircular(struct Node *head)
{
    struct Node *prev, *cur, *next;

    if (head == NULL || head->next == head)
        return head;                   /* 0 or 1 node: nothing to do */

    prev = head;
    while (prev->next != head)         /* prev = last node */
        prev = prev->next;

    cur = head;
    do {
        next = cur->next;              /* remember the following node */
        cur->next = prev;              /* reverse this link           */
        prev = cur;
        cur = next;
    } while (cur != head);

    return prev;                       /* prev is the old last node = new head */
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

/* Confirms that the reversed list is still circular. */
void verifyCircular(struct Node *head)
{
    struct Node *last = head;

    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    while (last->next != head)
        last = last->next;
    printf("Verified: last node %d points back to the head %d\n",
           last->data, head->data);
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

    printf("\nOriginal circular list: ");
    display(head);

    head = reverseCircular(head);

    printf("Reversed circular list: ");
    display(head);
    verifyCircular(head);

    head = reverseCircular(head);
    printf("Reversed once more (back to the original): ");
    display(head);

    freeCircular(head);
    return 0;
}
