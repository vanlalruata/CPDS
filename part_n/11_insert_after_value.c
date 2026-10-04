/*
 * q11.c -- Singly Linked List: INSERT AFTER A SPECIFIED VALUE
 *
 * Idea: search for the node whose data equals the key. Once found, link the
 * new node behind it:
 *      node->next = key_node->next;   key_node->next = node;
 * If the key does not exist, report an error and leave the list unchanged.
 *
 * Compile: gcc q11.c -o q11
 * Sample input : 4  10 20 30 40   insert 25 after 20
 *                -> 10 -> 20 -> 25 -> 30 -> 40 -> NULL
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

/* Insert 'value' immediately after the first node containing 'key'. */
struct Node *insertAfterValue(struct Node *head, int key, int value)
{
    struct Node *cur = head, *node;

    while (cur != NULL && cur->data != key)
        cur = cur->next;

    if (cur == NULL) {
        printf("Key %d not found -- insertion not performed\n", key);
        return head;
    }

    node = newNode(value);
    node->next = cur->next;
    cur->next = node;
    printf("Inserted %d after %d\n", value, key);
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
    int n, i, value, key;

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

    printf("\nOriginal list: ");
    display(head);

    printf("Enter the existing value after which to insert: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }
    printf("Enter the new value to insert: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    head = insertAfterValue(head, key, value);

    printf("\nUpdated list: ");
    display(head);

    freeList(head);
    return 0;
}
