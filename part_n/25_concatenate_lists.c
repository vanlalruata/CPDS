/*
 * q25.c -- Singly Linked List: CONCATENATE TWO LISTS
 *
 * Idea: append list2 to the end of list1 by walking to the last node of list1
 * and setting last->next = head2. No new nodes are created, so the operation is
 * O(n1) and the two lists become one; head2 must not be freed separately.
 *
 * Compile: gcc q25.c -o q25
 * Sample input : 3  1 2 3    2  8 9   ->  1 -> 2 -> 3 -> 8 -> 9 -> NULL
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

/* Concatenation: head1 followed by head2. Returns the combined head. */
struct Node *concatenate(struct Node *head1, struct Node *head2)
{
    struct Node *cur;

    if (head1 == NULL)
        return head2;          /* nothing before, second list is the answer */
    if (head2 == NULL)
        return head1;

    cur = head1;
    while (cur->next != NULL)  /* find the last node of the first list */
        cur = cur->next;
    cur->next = head2;         /* join */
    return head1;
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

struct Node *readList(const char *name, int n)
{
    struct Node *head = NULL;
    int i, value;

    printf("Enter %d integer(s) for list %s: ", n, name);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) {
            printf("Invalid input\n");
            freeList(head);
            exit(EXIT_FAILURE);
        }
        head = insertEnd(head, value);
    }
    return head;
}

int main(void)
{
    struct Node *list1 = NULL, *list2 = NULL, *result;
    int n1, n2;

    printf("Enter number of nodes in list 1: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) {
        printf("Invalid input\n");
        return 1;
    }
    list1 = readList("1", n1);

    printf("Enter number of nodes in list 2: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) {
        printf("Invalid input\n");
        freeList(list1);
        return 1;
    }
    list2 = readList("2", n2);

    printf("\nList 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    result = concatenate(list1, list2);

    printf("\nConcatenated list (%d nodes): ", countNodes(result));
    display(result);

    freeList(result);          /* one free walk covers both original lists */
    return 0;
}
