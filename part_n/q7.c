/*
 * q7.c -- Singly Linked List: SEARCH FOR AN ELEMENT (linear search)
 *
 * Idea: a linked list allows only sequential access, so searching means
 * traversing node by node comparing data with the key. This program reports
 * the first matching position and also every position where the key occurs.
 *
 * Compile: gcc q7.c -o q7
 * Sample input : 6  4 8 15 8 23 42   key 8  ->  found first at position 2
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

/* Returns the 1-based position of the first match, or -1 if absent. */
int search(struct Node *head, int key)
{
    int pos = 1;

    while (head != NULL) {
        if (head->data == key)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

/* Prints all positions holding the key; returns how many were found. */
int searchAll(struct Node *head, int key)
{
    int pos = 1, found = 0;

    while (head != NULL) {
        if (head->data == key) {
            printf("%d ", pos);
            found++;
        }
        head = head->next;
        pos++;
    }
    return found;
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
            freeList(head);
            return 1;
        }
        head = insertEnd(head, value);
    }

    printf("\nList: ");
    display(head);

    printf("Enter element to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    pos = search(head, key);
    if (pos != -1) {
        printf("Element %d FOUND at position %d\n", key, pos);
        printf("All positions of %d: ", key);
        searchAll(head, key);
        printf("\n");
    } else {
        printf("Element %d NOT FOUND in the list\n", key);
    }

    freeList(head);
    return 0;
}
