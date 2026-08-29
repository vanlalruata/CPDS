/*
 * q44.c -- Circular Linked List: CONCATENATE TWO CIRCULAR LISTS
 *
 * Idea: find the last node of each list, then re-wire only two links:
 *      last1->next = head2;      (first list flows into the second)
 *      last2->next = head1;      (the second closes back to the first head)
 * No new nodes are allocated; the result is one circular list.
 *
 * Compile: gcc q44.c -o q44
 * Sample input : 3  1 2 3    2  7 8   ->  1 2 3 7 8 (back to head 1)
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

/* Returns the last node of a circular list (the one pointing to the head). */
struct Node *lastNode(struct Node *head)
{
    struct Node *cur = head;

    if (head == NULL)
        return NULL;
    while (cur->next != head)
        cur = cur->next;
    return cur;
}

/* Concatenate: list1 followed by list2, still circular. */
struct Node *concatenateCircular(struct Node *head1, struct Node *head2)
{
    struct Node *last1, *last2;

    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    last1 = lastNode(head1);
    last2 = lastNode(head2);

    last1->next = head2;               /* join the two chains */
    last2->next = head1;               /* close the big circle */
    return head1;
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

struct Node *readCircular(const char *name, int n)
{
    struct Node *head = NULL;
    int i, value;

    printf("Enter %d integer(s) for list %s: ", n, name);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) {
            printf("Invalid input\n");
            freeCircular(head);
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

    printf("Enter number of nodes in circular list 1: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) {
        printf("Invalid input\n");
        return 1;
    }
    list1 = readCircular("1", n1);

    printf("Enter number of nodes in circular list 2: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) {
        printf("Invalid input\n");
        freeCircular(list1);
        return 1;
    }
    list2 = readCircular("2", n2);

    printf("\nCircular list 1: ");
    display(list1);
    printf("Circular list 2: ");
    display(list2);

    result = concatenateCircular(list1, list2);

    printf("\nConcatenated circular list (%d nodes): ", countNodes(result));
    display(result);

    freeCircular(result);     /* one circle now contains all the nodes */
    return 0;
}
