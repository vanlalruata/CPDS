/*
 * q35.c -- Circular Linked List: INSERT AT A SPECIFIED POSITION
 *
 * Idea: positions are 1-based, valid range 1..count+1.
 *   - position 1        -> insert at the beginning (head and last both change);
 *   - position count+1  -> insert at the end;
 *   - otherwise         -> stop at node (pos-1) and splice the node in.
 *
 * Compile: gcc q35.c -o q35
 * Sample input : 4  10 20 30 40   value 25 position 3
 *                -> 10 -> 20 -> 25 -> 30 -> 40 -> (head 10)
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

int countNodes(struct Node *head)
{
    struct Node *cur = head;
    int c = 0;

    if (head == NULL)
        return 0;
    do {
        c++;
        cur = cur->next;
    } while (cur != head);
    return c;
}

/* Insert 'value' at 1-based position 'pos'; returns the (possibly new) head. */
struct Node *insertAtPosition(struct Node *head, int value, int pos)
{
    struct Node *node, *prev, *last;
    int i, count = countNodes(head);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position! Valid range is 1 to %d\n", count + 1);
        return head;
    }

    if (head == NULL) {                     /* empty list */
        node = newNode(value);
        node->next = node;
        return node;
    }

    if (pos == 1) {                         /* new head */
        node = newNode(value);
        last = head;
        while (last->next != head)
            last = last->next;
        node->next = head;
        last->next = node;
        return node;
    }

    prev = head;
    for (i = 1; i < pos - 1; i++)           /* reach node (pos-1) */
        prev = prev->next;

    node = newNode(value);
    node->next = prev->next;
    prev->next = node;
    return head;
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
            freeCircular(head);
            return 1;
        }
        head = insertEnd(head, value);
    }

    printf("\nOriginal circular list: ");
    display(head);

    printf("Enter value to insert: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input\n");
        freeCircular(head);
        return 1;
    }
    printf("Enter position (1 to %d): ", countNodes(head) + 1);
    if (scanf("%d", &pos) != 1) {
        printf("Invalid input\n");
        freeCircular(head);
        return 1;
    }

    head = insertAtPosition(head, value, pos);

    printf("\nList after insertion: ");
    display(head);

    freeCircular(head);
    return 0;
}
