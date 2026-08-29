/*
 * q45.c -- Circular Linked List: SORT THE LIST
 *
 * Idea: exchange the DATA fields (selection/bubble style) so the circular
 * links never have to be rebuilt. The outer loop stops when i->next == head and
 * the inner loop stops when j == head, which keeps both walks inside one round.
 * Ascending order; O(n^2) time, O(1) extra space.
 *
 * Compile: gcc q45.c -o q45
 * Sample input : 6  50 20 40 10 60 30  ->  10 20 30 40 50 60
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

/* Ascending sort by swapping data fields. */
void sortCircularAscending(struct Node *head)
{
    struct Node *i, *j;
    int tmp;

    if (head == NULL || head->next == head)
        return;                        /* 0 or 1 node is already sorted */

    for (i = head; i->next != head; i = i->next) {
        for (j = i->next; j != head; j = j->next) {
            if (i->data > j->data) {
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

/* Descending sort, same technique with the comparison reversed. */
void sortCircularDescending(struct Node *head)
{
    struct Node *i, *j;
    int tmp;

    if (head == NULL || head->next == head)
        return;

    for (i = head; i->next != head; i = i->next) {
        for (j = i->next; j != head; j = j->next) {
            if (i->data < j->data) {
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
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
            freeCircular(head);
            return 1;
        }
        head = insertEnd(head, value);
    }

    printf("\nOriginal circular list: ");
    display(head);

    sortCircularAscending(head);
    printf("Sorted in ascending order : ");
    display(head);

    sortCircularDescending(head);
    printf("Sorted in descending order: ");
    display(head);

    freeCircular(head);
    return 0;
}
