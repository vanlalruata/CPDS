/*
 * q24.c -- Singly Linked List: MERGE TWO SORTED LISTS
 *
 * Idea: compare the front nodes of both lists and always pick the smaller one,
 * linking it into the result. No new nodes are allocated -- existing nodes are
 * relinked, so the merge runs in O(m+n) time with O(1) extra memory.
 * When one list is exhausted, attach the remainder of the other.
 *
 * Compile: gcc q24.c -o q24
 * Sample input : 3  1 3 5    3  2 4 6   ->  1 2 3 4 5 6
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

/* Insertion sort (relinking) so the inputs are guaranteed sorted. */
struct Node *sortList(struct Node *head)
{
    struct Node *sorted = NULL, *cur = head, *next, *scan;

    while (cur != NULL) {
        next = cur->next;
        if (sorted == NULL || cur->data <= sorted->data) {
            cur->next = sorted;
            sorted = cur;
        } else {
            scan = sorted;
            while (scan->next != NULL && scan->next->data < cur->data)
                scan = scan->next;
            cur->next = scan->next;
            scan->next = cur;
        }
        cur = next;
    }
    return sorted;
}

/* Merge two ascending lists into one ascending list (iterative). */
struct Node *mergeSorted(struct Node *a, struct Node *b)
{
    struct Node dummy;          /* dummy head simplifies the code */
    struct Node *tail = &dummy;

    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a != NULL) ? a : b;    /* attach the leftovers */
    return dummy.next;
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

/* Reads a list of n integers from stdin. */
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
    struct Node *list1 = NULL, *list2 = NULL, *merged;
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

    /* make sure both lists are sorted before merging */
    list1 = sortList(list1);
    list2 = sortList(list2);

    printf("\nSorted list 1: ");
    display(list1);
    printf("Sorted list 2: ");
    display(list2);

    merged = mergeSorted(list1, list2);

    printf("\nMerged sorted list: ");
    display(merged);

    freeList(merged);      /* all nodes of both lists now belong to 'merged' */
    return 0;
}
