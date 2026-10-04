/*
 * q37.c -- Circular Linked List: DELETE FROM THE END
 *
 * Idea: walk with a 'prev' pointer until cur->next == head (cur is the last
 * node). Then prev->next = head restores the circle and cur is freed.
 * Special case: a single node -> free it and the list becomes NULL.
 *
 * Compile: gcc q37.c -o q37
 * Sample input : 4  10 20 30 40   ->  deleted 40, list = 10 -> 20 -> 30
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

/* Delete the last node; returns the head (NULL if the list becomes empty). */
struct Node *deleteEnd(struct Node *head)
{
    struct Node *cur = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty -- deletion not possible (underflow)\n");
        return NULL;
    }

    if (head->next == head) {              /* only one node */
        printf("Deleted node with value %d (list is now empty)\n", head->data);
        free(head);
        return NULL;
    }

    while (cur->next != head) {            /* cur ends at the last node */
        prev = cur;
        cur = cur->next;
    }

    prev->next = head;                     /* second-last becomes last */
    printf("Deleted node with value %d\n", cur->data);
    free(cur);
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

    printf("How many nodes to delete from the end? ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid input\n");
        freeCircular(head);
        return 1;
    }

    for (i = 0; i < k; i++) {
        head = deleteEnd(head);
        printf("List now: ");
        display(head);
    }

    printf("\nFinal circular list: ");
    display(head);

    freeCircular(head);
    return 0;
}
