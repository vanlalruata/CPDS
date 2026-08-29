/*
 * q34.c -- Circular Linked List: INSERT AT THE END
 *
 * Idea: reach the last node (the node whose next is the head), attach the new
 * node there and make the new node point back to the head:
 *      last->next = node;   node->next = head;
 * The head does NOT change (unless the list was empty).
 *
 * Compile: gcc q34.c -o q34
 * Sample input : 3  10 20 30   insert 40  ->  10 -> 20 -> 30 -> 40 -> (head 10)
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

/* Insert at the end of a circular list; returns the head. */
struct Node *insertEnd(struct Node *head, int value)
{
    struct Node *node = newNode(value);
    struct Node *last;

    if (head == NULL) {
        node->next = node;             /* first node: points to itself */
        return node;
    }

    last = head;
    while (last->next != head)         /* find the last node */
        last = last->next;

    last->next = node;                 /* append */
    node->next = head;                 /* keep the list circular */
    return head;
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
            freeCircular(head);
            return 1;
        }
        head = insertEnd(head, value);
    }

    printf("\nOriginal circular list: ");
    display(head);

    printf("How many elements to insert at the end? ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid input\n");
        freeCircular(head);
        return 1;
    }

    for (i = 0; i < k; i++) {
        printf("Enter value %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input\n");
            freeCircular(head);
            return 1;
        }
        head = insertEnd(head, value);
        printf("After inserting %d at end: ", value);
        display(head);
    }

    printf("\nFinal circular list (%d nodes): ", countNodes(head));
    display(head);

    freeCircular(head);
    return 0;
}
