/*
 * q9.c -- Singly Linked List: INSERT AT THE END (append)
 *
 * Idea: if the list is empty the new node becomes the head; otherwise walk to
 * the node whose next is NULL and attach the new node there.  O(n) with a
 * single head pointer, O(1) if a tail pointer is maintained (also shown).
 *
 * Compile: gcc q9.c -o q9
 * Sample input : 3  10 20 30   then 40  ->  10 -> 20 -> 30 -> 40 -> NULL
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

/* Insert at end using only the head pointer (O(n)). */
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

/* Insert at end in O(1) when a tail pointer is kept up to date. */
void insertEndWithTail(struct Node **head, struct Node **tail, int value)
{
    struct Node *node = newNode(value);

    if (*head == NULL) {
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
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
    struct Node *head = NULL, *tail = NULL;
    int n, i, value, k;

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
        insertEndWithTail(&head, &tail, value);   /* O(1) build */
    }

    printf("\nOriginal list: ");
    display(head);

    printf("How many elements to insert at the end? ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    for (i = 0; i < k; i++) {
        printf("Enter value %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input\n");
            freeList(head);
            return 1;
        }
        head = insertEnd(head, value);            /* O(n) version */
        printf("After inserting %d at end: ", value);
        display(head);
    }

    printf("\nFinal list: ");
    display(head);

    freeList(head);
    return 0;
}
