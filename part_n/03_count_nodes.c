/*
 * q3.c -- Singly Linked List: COUNT THE NUMBER OF NODES
 *
 * Idea: walk from head to NULL and increment a counter (O(n) time, O(1) space).
 * A recursive version is also given: count(head) = 1 + count(head->next).
 *
 * Compile: gcc q3.c -o q3
 * Sample input : 5  11 22 33 44 55   ->  Number of nodes = 5
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

/* Iterative node count. */
int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *cur = head;

    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

/* Recursive node count. */
int countNodesRecursive(struct Node *head)
{
    if (head == NULL)
        return 0;
    return 1 + countNodesRecursive(head->next);
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

    printf("\nList: ");
    display(head);

    printf("Number of nodes (iterative) = %d\n", countNodes(head));
    printf("Number of nodes (recursive) = %d\n", countNodesRecursive(head));

    freeList(head);
    return 0;
}
