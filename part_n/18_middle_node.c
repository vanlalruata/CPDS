/*
 * q18.c -- Singly Linked List: FIND THE MIDDLE NODE (slow / fast pointers)
 *
 * Idea (Floyd / tortoise-hare): move 'slow' one step and 'fast' two steps per
 * iteration. When fast reaches the end, slow is at the middle. Only ONE
 * traversal is needed (no counting pass).
 * For an even number of nodes this reports the second middle element
 * (e.g. 1 2 3 4 -> 3); the first middle is also shown for comparison.
 *
 * Compile: gcc q18.c -o q18
 * Sample input : 5  10 20 30 40 50  ->  Middle = 30
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

/* Second middle for even length (1 2 3 4 -> 3). */
struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;             /* 1 step  */
        fast = fast->next->next;       /* 2 steps */
    }
    return slow;
}

/* First middle for even length (1 2 3 4 -> 2). */
struct Node *findMiddleFirst(struct Node *head)
{
    struct Node *slow = head, *fast = head;

    if (head == NULL)
        return NULL;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    struct Node *head = NULL, *mid;
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

    printf("\nList: ");
    display(head);
    printf("Total nodes = %d\n", countNodes(head));

    mid = findMiddle(head);
    if (mid == NULL) {
        printf("List is empty -- no middle node\n");
    } else {
        printf("Middle node (slow/fast pointers) = %d\n", mid->data);
        mid = findMiddleFirst(head);
        printf("First middle (for even length lists) = %d\n", mid->data);
    }

    freeList(head);
    return 0;
}
