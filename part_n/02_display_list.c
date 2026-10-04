/*
 * q2.c -- Singly Linked List: DISPLAY / TRAVERSAL
 *
 * Idea: traversal means starting at head and following the 'next' links
 * until NULL. Here the same list is shown three ways:
 *   1. arrow form,  2. position-wise table,  3. recursive traversal.
 *
 * Compile: gcc q2.c -o q2
 * Sample input : 4  7 3 9 1
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

/* 1. Simple arrow display (iterative). */
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

/* 2. Display with position numbers and node addresses. */
void displayDetailed(struct Node *head)
{
    struct Node *cur = head;
    int pos = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("%-10s %-10s %s\n", "Position", "Data", "Next");
    while (cur != NULL) {
        printf("%-10d %-10d %s\n", pos, cur->data,
               (cur->next != NULL) ? "points to next node" : "NULL (last node)");
        cur = cur->next;
        pos++;
    }
}

/* 3. Recursive traversal. */
void displayRecursive(struct Node *cur)
{
    if (cur == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", cur->data);
    displayRecursive(cur->next);
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

    printf("\n1) Arrow form:\n");
    display(head);

    printf("\n2) Position-wise details:\n");
    displayDetailed(head);

    printf("\n3) Recursive traversal:\n");
    displayRecursive(head);

    freeList(head);
    return 0;
}
