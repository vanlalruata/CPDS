/*
 * q23.c -- Singly Linked List: SORT THE LIST
 *
 * Two classic techniques are demonstrated:
 *   1. Bubble sort by SWAPPING DATA  -- simplest, O(n^2), links untouched.
 *   2. Insertion sort by RELINKING NODES -- builds a new sorted chain by
 *      moving nodes, which is what a real linked-list sort does.
 * The list is sorted in ascending order.
 *
 * Compile: gcc q23.c -o q23
 * Sample input : 6  40 10 50 20 60 30  ->  10 20 30 40 50 60
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

/* 1. Bubble sort exchanging only the data fields. */
void bubbleSortData(struct Node *head)
{
    struct Node *i, *j;
    int tmp;

    for (i = head; i != NULL && i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

/* 2. Insertion sort that relinks nodes into a new sorted list. */
struct Node *insertionSortNodes(struct Node *head)
{
    struct Node *sorted = NULL, *cur = head, *next, *scan;

    while (cur != NULL) {
        next = cur->next;                     /* save the rest */

        if (sorted == NULL || cur->data <= sorted->data) {
            cur->next = sorted;               /* insert at front */
            sorted = cur;
        } else {
            scan = sorted;
            while (scan->next != NULL && scan->next->data < cur->data)
                scan = scan->next;
            cur->next = scan->next;           /* splice in place */
            scan->next = cur;
        }
        cur = next;
    }
    return sorted;
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
    struct Node *head = NULL, *copy = NULL, *cur;
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

    /* make a second copy so both algorithms can be shown on the same data */
    for (cur = head; cur != NULL; cur = cur->next)
        copy = insertEnd(copy, cur->data);

    printf("\nOriginal list: ");
    display(head);

    bubbleSortData(head);
    printf("Sorted by bubble sort (data swap)      : ");
    display(head);

    copy = insertionSortNodes(copy);
    printf("Sorted by insertion sort (node relink) : ");
    display(copy);

    freeList(head);
    freeList(copy);
    return 0;
}
