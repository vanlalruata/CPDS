/*
 * q15.c -- Singly Linked List: DELETE THE NODE AT A SPECIFIED POSITION
 *
 * Idea: positions are 1-based and must lie in 1..count.
 *   - position 1: head = head->next and free the old head;
 *   - otherwise: stop at node (pos-1), let del = prev->next, then
 *     prev->next = del->next; free(del);
 *
 * Compile: gcc q15.c -o q15
 * Sample input : 5  10 20 30 40 50   position 3
 *                -> 10 -> 20 -> 40 -> 50 -> NULL
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

int countNodes(struct Node *head)
{
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->next;
    }
    return c;
}

/* Delete the node at 1-based position pos; returns the new head. */
struct Node *deleteAtPosition(struct Node *head, int pos)
{
    struct Node *del, *prev;
    int i, count = countNodes(head);

    if (head == NULL) {
        printf("List is empty -- deletion not possible\n");
        return NULL;
    }
    if (pos < 1 || pos > count) {
        printf("Invalid position! Valid range is 1 to %d\n", count);
        return head;
    }

    if (pos == 1) {                     /* delete the first node */
        del = head;
        head = head->next;
        printf("Deleted %d from position 1\n", del->data);
        free(del);
        return head;
    }

    prev = head;
    for (i = 1; i < pos - 1; i++)       /* reach node (pos-1) */
        prev = prev->next;

    del = prev->next;                   /* node to delete */
    prev->next = del->next;             /* unlink it */
    printf("Deleted %d from position %d\n", del->data, pos);
    free(del);
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
    int n, i, value, pos;

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

    printf("Enter position to delete (1 to %d): ", countNodes(head));
    if (scanf("%d", &pos) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    head = deleteAtPosition(head, pos);

    printf("\nList after deletion: ");
    display(head);

    freeList(head);
    return 0;
}
