/*
 * q26.c -- Singly Linked List: COMPARE TWO LISTS (length and content)
 *
 * Idea: walk both lists together. They are equal only if the data matches at
 * every step AND both end at the same time. The program reports the lengths,
 * whether the contents are identical, and the first position that differs.
 *
 * Compile: gcc q26.c -o q26
 * Sample input : 3  1 2 3    3  1 2 3   ->  lists are EQUAL
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

/* Returns 1 if identical (same length and same data), else 0. */
int areEqual(struct Node *a, struct Node *b)
{
    while (a != NULL && b != NULL) {
        if (a->data != b->data)
            return 0;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);       /* both must finish together */
}

/* Recursive comparison (same logic). */
int areEqualRecursive(struct Node *a, struct Node *b)
{
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return 0;
    if (a->data != b->data)
        return 0;
    return areEqualRecursive(a->next, b->next);
}

/* First 1-based position where they differ, or 0 if no such position. */
int firstDifference(struct Node *a, struct Node *b)
{
    int pos = 1;

    while (a != NULL && b != NULL) {
        if (a->data != b->data)
            return pos;
        a = a->next;
        b = b->next;
        pos++;
    }
    if (a != NULL || b != NULL)
        return pos;                        /* one list is longer */
    return 0;
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
    struct Node *list1 = NULL, *list2 = NULL;
    int n1, n2, len1, len2, diff;

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

    len1 = countNodes(list1);
    len2 = countNodes(list2);
    printf("\nLength of list 1 = %d, length of list 2 = %d\n", len1, len2);
    if (len1 == len2)
        printf("Lengths are equal\n");
    else
        printf("Lengths differ (list %s is longer)\n", (len1 > len2) ? "1" : "2");

    if (areEqual(list1, list2)) {
        printf("Result: the two lists are EQUAL (identical content)\n");
    } else {
        diff = firstDifference(list1, list2);
        printf("Result: the two lists are NOT EQUAL "
               "(first mismatch at position %d)\n", diff);
    }
    printf("Recursive check agrees: %s\n",
           areEqualRecursive(list1, list2) ? "EQUAL" : "NOT EQUAL");

    freeList(list1);
    freeList(list2);
    return 0;
}
