/*
 * q39.c -- Circular Linked List: SEARCH AN ELEMENT
 *
 * Idea: the traversal must be bounded by the head, otherwise the search would
 * loop forever when the key is absent:
 *      cur = head;
 *      do { if (cur->data == key) found; cur = cur->next; } while (cur != head);
 *
 * Compile: gcc q39.c -o q39
 * Sample input : 5  11 22 33 44 55   key 33  ->  found at position 3
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

/* Returns the 1-based position of the first match, or -1 if absent. */
int search(struct Node *head, int key)
{
    struct Node *cur = head;
    int pos = 1;

    if (head == NULL)
        return -1;

    do {
        if (cur->data == key)
            return pos;
        cur = cur->next;
        pos++;
    } while (cur != head);              /* stop after one full round */

    return -1;
}

/* Prints every position of the key; returns the number of matches. */
int searchAll(struct Node *head, int key)
{
    struct Node *cur = head;
    int pos = 1, found = 0;

    if (head == NULL)
        return 0;
    do {
        if (cur->data == key) {
            printf("%d ", pos);
            found++;
        }
        cur = cur->next;
        pos++;
    } while (cur != head);
    return found;
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
    int n, i, value, key, pos;

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

    printf("\nCircular list: ");
    display(head);

    printf("Enter element to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input\n");
        freeCircular(head);
        return 1;
    }

    pos = search(head, key);
    if (pos != -1) {
        printf("Element %d FOUND at position %d\n", key, pos);
        printf("All positions of %d: ", key);
        searchAll(head, key);
        printf("\n");
    } else {
        printf("Element %d NOT FOUND in the circular list\n", key);
    }

    freeCircular(head);
    return 0;
}
