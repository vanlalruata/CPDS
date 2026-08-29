/*
 * q47.c -- Circular Linked List: FIND THE MINIMUM ELEMENT
 *
 * Idea: initialise the minimum with the head's data and compare against every
 * other node during one bounded round (do-while / while cur != head).
 * The node's position is reported too.
 *
 * Compile: gcc q47.c -o q47
 * Sample input : 6  25 78 12 96 45 33  ->  Minimum = 12 (position 3)
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

/* Returns 1 on success and fills *minOut / *posOut; 0 if the list is empty. */
int findMin(struct Node *head, int *minOut, int *posOut)
{
    struct Node *cur;
    int min, pos = 1, i = 1;

    if (head == NULL)
        return 0;

    min = head->data;
    cur = head->next;
    while (cur != head) {
        i++;
        if (cur->data < min) {
            min = cur->data;
            pos = i;
        }
        cur = cur->next;
    }
    *minOut = min;
    *posOut = pos;
    return 1;
}

/* Minimum and maximum in the same traversal. */
int findMinMax(struct Node *head, int *minOut, int *maxOut)
{
    struct Node *cur;
    int min, max;

    if (head == NULL)
        return 0;

    min = head->data;
    max = head->data;
    cur = head->next;
    while (cur != head) {
        if (cur->data < min)
            min = cur->data;
        if (cur->data > max)
            max = cur->data;
        cur = cur->next;
    }
    *minOut = min;
    *maxOut = max;
    return 1;
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
    int n, i, value, min, max, pos;

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

    printf("\nCircular list: ");
    display(head);

    if (findMin(head, &min, &pos)) {
        printf("Minimum element = %d (at position %d)\n", min, pos);
        findMinMax(head, &min, &max);
        printf("In a single traversal: minimum = %d, maximum = %d, "
               "range = %d\n", min, max, max - min);
    } else {
        printf("List is empty, no minimum exists\n");
    }

    freeCircular(head);
    return 0;
}
