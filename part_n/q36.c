/*
 * q36.c -- Circular Linked List: DELETE FROM THE BEGINNING
 *
 * Idea: the head node is removed, so the LAST node must be re-pointed to the
 * second node which becomes the new head:
 *      find last;  last->next = head->next;  free(head);  head = last->next;
 * Special case: only one node -> free it and the list becomes empty (NULL).
 *
 * Compile: gcc q36.c -o q36
 * Sample input : 4  10 20 30 40   ->  deleted 10, list = 20 -> 30 -> 40
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

/* Delete the first node; returns the new head. */
struct Node *deleteBeginning(struct Node *head)
{
    struct Node *last, *tmp;

    if (head == NULL) {
        printf("List is empty -- deletion not possible (underflow)\n");
        return NULL;
    }

    if (head->next == head) {              /* only one node */
        printf("Deleted node with value %d (list is now empty)\n", head->data);
        free(head);
        return NULL;
    }

    last = head;
    while (last->next != head)             /* find the last node */
        last = last->next;

    tmp = head;
    last->next = head->next;               /* skip the old head */
    head = head->next;                     /* new head */
    printf("Deleted node with value %d\n", tmp->data);
    free(tmp);
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

    printf("How many nodes to delete from the beginning? ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid input\n");
        freeCircular(head);
        return 1;
    }

    for (i = 0; i < k; i++) {
        head = deleteBeginning(head);
        printf("List now: ");
        display(head);
    }

    printf("\nFinal circular list: ");
    display(head);

    freeCircular(head);
    return 0;
}
