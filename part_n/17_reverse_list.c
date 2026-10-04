/*
 * q17.c -- Singly Linked List: REVERSE THE LIST
 *
 * Idea (iterative, three pointers): walk the list once and flip every link.
 *      prev = NULL; cur = head;
 *      while (cur) { next = cur->next; cur->next = prev; prev = cur; cur = next; }
 *      head = prev;
 * Time O(n), extra space O(1). A recursive version is also included.
 *
 * Compile: gcc q17.c -o q17
 * Sample input : 5  10 20 30 40 50  ->  50 -> 40 -> 30 -> 20 -> 10 -> NULL
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

/* Iterative reversal using three pointers. */
struct Node *reverseIterative(struct Node *head)
{
    struct Node *prev = NULL, *cur = head, *next = NULL;

    while (cur != NULL) {
        next = cur->next;      /* remember the rest of the list */
        cur->next = prev;      /* flip the current link         */
        prev = cur;            /* advance prev                  */
        cur = next;            /* advance cur                   */
    }
    return prev;               /* prev is the new head          */
}

/* Recursive reversal. */
struct Node *reverseRecursive(struct Node *head)
{
    struct Node *rest;

    if (head == NULL || head->next == NULL)
        return head;                       /* base case */

    rest = reverseRecursive(head->next);   /* reverse the tail */
    head->next->next = head;               /* put head after it */
    head->next = NULL;
    return rest;
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

    printf("\nOriginal list : ");
    display(head);

    head = reverseIterative(head);
    printf("Reversed (iterative): ");
    display(head);

    head = reverseRecursive(head);
    printf("Reversed again (recursive) -- back to original: ");
    display(head);

    freeList(head);
    return 0;
}
