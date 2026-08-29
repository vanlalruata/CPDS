/*
 * q8.c -- Singly Linked List: INSERT AT THE BEGINNING
 *
 * Idea: make the new node point to the current head and then treat the new
 * node as the head. This is an O(1) operation -- no traversal is needed.
 *      newNode->next = head;   head = newNode;
 *
 * Compile: gcc q8.c -o q8
 * Sample input : 3  20 30 40   then 10  ->  10 -> 20 -> 30 -> 40 -> NULL
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

/* Insert at front: O(1). Returns the new head. */
struct Node *insertBeginning(struct Node *head, int value)
{
    struct Node *node = newNode(value);
    node->next = head;
    return node;
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
        head = insertEnd(head, value);
    }

    printf("\nOriginal list: ");
    display(head);

    printf("How many elements to insert at the beginning? ");
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
        head = insertBeginning(head, value);
        printf("After inserting %d at beginning: ", value);
        display(head);
    }

    printf("\nFinal list: ");
    display(head);

    freeList(head);
    return 0;
}
