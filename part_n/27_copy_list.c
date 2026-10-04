/*
 * q27.c -- Singly Linked List: COPY (CLONE) A LIST
 *
 * Idea: a deep copy allocates a brand-new node for every node of the original
 * and copies the data. Changing the copy must not affect the original.
 * (A shallow copy would only duplicate the head pointer -- both names would
 *  then refer to the SAME nodes, which is demonstrated in the output.)
 *
 * Compile: gcc q27.c -o q27
 * Sample input : 5  10 20 30 40 50
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

/* Deep copy: new nodes, same order, O(n) using a tail pointer. */
struct Node *copyList(struct Node *head)
{
    struct Node *copyHead = NULL, *copyTail = NULL, *node;

    while (head != NULL) {
        node = newNode(head->data);
        if (copyHead == NULL) {
            copyHead = node;
            copyTail = node;
        } else {
            copyTail->next = node;
            copyTail = node;
        }
        head = head->next;
    }
    return copyHead;
}

/* Recursive deep copy. */
struct Node *copyListRecursive(struct Node *head)
{
    struct Node *node;

    if (head == NULL)
        return NULL;
    node = newNode(head->data);
    node->next = copyListRecursive(head->next);
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
    struct Node *head = NULL, *copy = NULL, *copy2 = NULL;
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

    copy  = copyList(head);
    copy2 = copyListRecursive(head);

    printf("\nOriginal list        : ");
    display(head);
    printf("Copied list (iterative): ");
    display(copy);
    printf("Copied list (recursive): ");
    display(copy2);

    /* Prove the copy is independent: modify the copy only. */
    if (copy != NULL) {
        copy->data = 999;
        printf("\nAfter changing the first node of the COPY to 999:\n");
        printf("Original list: ");
        display(head);
        printf("Copied list  : ");
        display(copy);
        printf("The original is unchanged, so this is a deep copy.\n");
    }

    freeList(head);
    freeList(copy);
    freeList(copy2);
    return 0;
}
