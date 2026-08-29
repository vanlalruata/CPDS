/*
 * q6.c -- Singly Linked List: MINIMUM NODE VALUE
 *
 * Idea: initialise the minimum with the first node's data and traverse the
 * remaining nodes, replacing the minimum whenever a smaller value appears.
 *
 * Compile: gcc q6.c -o q6
 * Sample input : 6  45 12 78 3 99 21   ->  Minimum = 3 (position 4)
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

/* Returns 1 and fills *minOut / *posOut, or 0 for an empty list. */
int findMin(struct Node *head, int *minOut, int *posOut)
{
    struct Node *cur;
    int min, pos = 1, i = 1;

    if (head == NULL)
        return 0;

    min = head->data;
    for (cur = head->next; cur != NULL; cur = cur->next) {
        i++;
        if (cur->data < min) {
            min = cur->data;
            pos = i;
        }
    }
    *minOut = min;
    *posOut = pos;
    return 1;
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
    int n, i, value, min, pos;

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

    printf("\nList: ");
    display(head);

    if (findMin(head, &min, &pos))
        printf("Minimum value = %d (found at position %d)\n", min, pos);
    else
        printf("List is empty, no minimum exists\n");

    freeList(head);
    return 0;
}
