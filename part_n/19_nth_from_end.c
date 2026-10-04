/*
 * q19.c -- Singly Linked List: FIND THE Nth NODE FROM THE END (two pointers)
 *
 * Idea: advance 'fast' by N nodes first. Then move 'fast' and 'slow' together
 * one step at a time. When fast becomes NULL, slow points to the Nth node from
 * the end. Single pass, O(n) time, O(1) space.
 *
 * Compile: gcc q19.c -o q19
 * Sample input : 6  10 20 30 40 50 60   n = 2  ->  2nd from end = 50
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

/* Returns the Nth node from the end, or NULL if it does not exist. */
struct Node *nthFromEnd(struct Node *head, int nth)
{
    struct Node *slow = head, *fast = head;
    int i;

    if (head == NULL || nth <= 0)
        return NULL;

    for (i = 0; i < nth; i++) {        /* give fast a head start of nth nodes */
        if (fast == NULL)
            return NULL;               /* list shorter than nth */
        fast = fast->next;
    }

    while (fast != NULL) {             /* move both together */
        slow = slow->next;
        fast = fast->next;
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
    struct Node *head = NULL, *res;
    int n, i, value, nth, total;

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

    total = countNodes(head);
    printf("\nList: ");
    display(head);

    printf("Enter N (1 to %d): ", total);
    if (scanf("%d", &nth) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    res = nthFromEnd(head, nth);
    if (res != NULL)
        printf("The %d-th node from the end is %d "
               "(same as position %d from the start)\n",
               nth, res->data, total - nth + 1);
    else
        printf("Node does not exist -- N must be between 1 and %d\n", total);

    freeList(head);
    return 0;
}
