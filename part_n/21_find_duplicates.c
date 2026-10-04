/*
 * q21.c -- Singly Linked List: FIND DUPLICATE VALUES
 *
 * Idea: for every node, scan the remaining part of the list. If the same value
 * appears later AND it was not already reported, print it as a duplicate.
 * To avoid printing a value twice, we only report from its FIRST occurrence
 * (checked by scanning the part of the list before the current node).
 * Time O(n^2), space O(1) -- no extra list/hash needed.
 *
 * Compile: gcc q21.c -o q21
 * Sample input : 7  10 20 10 30 20 40 10
 *                -> 10 (3 times), 20 (2 times)
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

/* How many times does 'value' appear starting from node 'from'? */
int countFrom(struct Node *from, int value)
{
    int c = 0;
    while (from != NULL) {
        if (from->data == value)
            c++;
        from = from->next;
    }
    return c;
}

/* Is 'value' present in the list segment [head, stop)? */
int seenBefore(struct Node *head, struct Node *stop, int value)
{
    while (head != stop && head != NULL) {
        if (head->data == value)
            return 1;
        head = head->next;
    }
    return 0;
}

/* Prints all duplicated values with their frequency; returns how many. */
int findDuplicates(struct Node *head)
{
    struct Node *cur;
    int distinctDup = 0, times;

    for (cur = head; cur != NULL; cur = cur->next) {
        if (seenBefore(head, cur, cur->data))
            continue;                     /* already reported earlier */
        times = countFrom(cur, cur->data);
        if (times > 1) {
            printf("  %d occurs %d times\n", cur->data, times);
            distinctDup++;
        }
    }
    return distinctDup;
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
    int n, i, value, dup;

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

    printf("Duplicate values found:\n");
    dup = findDuplicates(head);
    if (dup == 0)
        printf("  none -- all values are unique\n");
    else
        printf("Total distinct duplicated values = %d\n", dup);

    freeList(head);
    return 0;
}
