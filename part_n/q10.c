/*
 * q10.c -- Singly Linked List: INSERT AT A SPECIFIED POSITION
 *
 * Idea: positions are 1-based. Position 1 means insert at the front.
 * Otherwise stop at the (pos-1)-th node and splice the new node in:
 *      node->next = prev->next;   prev->next = node;
 * Valid positions are 1 .. count+1 (count+1 appends at the end).
 *
 * Compile: gcc q10.c -o q10
 * Sample input : 4  10 20 30 40   value 25 position 3
 *                -> 10 -> 20 -> 25 -> 30 -> 40 -> NULL
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

/* Insert value at 1-based position pos. Returns the new head. */
struct Node *insertAtPosition(struct Node *head, int value, int pos)
{
    struct Node *node, *prev;
    int i;
    int count = countNodes(head);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position! Valid range is 1 to %d\n", count + 1);
        return head;
    }

    if (pos == 1) {                    /* insert at beginning */
        node = newNode(value);
        node->next = head;
        return node;
    }

    prev = head;
    for (i = 1; i < pos - 1; i++)      /* stop at node (pos-1) */
        prev = prev->next;

    node = newNode(value);
    node->next = prev->next;
    prev->next = node;
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

    printf("Enter value to insert: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }
    printf("Enter position (1 to %d): ", countNodes(head) + 1);
    if (scanf("%d", &pos) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    head = insertAtPosition(head, value, pos);

    printf("\nList after insertion: ");
    display(head);

    freeList(head);
    return 0;
}
