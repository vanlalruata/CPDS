/*
 * q22.c -- Singly Linked List: REMOVE DUPLICATES (unsorted list)
 *
 * Idea: for each node 'p' (the first occurrence that is kept), scan the rest
 * of the list with a runner and unlink every later node whose data equals
 * p->data, freeing it. Order of the first occurrences is preserved.
 * Time O(n^2), space O(1).
 *
 * Compile: gcc q22.c -o q22
 * Sample input : 7  10 20 10 30 20 40 10
 *                -> 10 -> 20 -> 30 -> 40 -> NULL   (3 nodes removed)
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

/* Removes duplicates keeping the first occurrence; returns removed count. */
int removeDuplicates(struct Node *head)
{
    struct Node *p, *runner, *dup;
    int removed = 0;

    for (p = head; p != NULL; p = p->next) {
        runner = p;
        while (runner->next != NULL) {
            if (runner->next->data == p->data) {
                dup = runner->next;
                runner->next = dup->next;   /* unlink the duplicate */
                free(dup);                  /* release its memory  */
                removed++;
            } else {
                runner = runner->next;
            }
        }
    }
    return removed;
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
    int n, i, value, removed;

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

    printf("\nOriginal list (%d nodes): ", countNodes(head));
    display(head);

    removed = removeDuplicates(head);

    printf("Duplicate nodes removed = %d\n", removed);
    printf("List after removing duplicates (%d nodes): ", countNodes(head));
    display(head);

    freeList(head);
    return 0;
}
