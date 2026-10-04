/*
 * q12.c -- Singly Linked List: INSERT BEFORE A SPECIFIED VALUE
 *
 * Idea: a singly linked list cannot move backwards, so we keep a 'prev'
 * pointer while searching for the key.
 *   - if the key is in the head node, insert at the beginning;
 *   - otherwise: node->next = prev->next;  prev->next = node;
 *
 * Compile: gcc q12.c -o q12
 * Sample input : 4  10 20 30 40   insert 15 before 20
 *                -> 10 -> 15 -> 20 -> 30 -> 40 -> NULL
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

/* Insert 'value' just before the first node containing 'key'. */
struct Node *insertBeforeValue(struct Node *head, int key, int value)
{
    struct Node *cur = head, *prev = NULL, *node;

    if (head == NULL) {
        printf("List is empty -- insertion not performed\n");
        return head;
    }

    if (head->data == key) {              /* key is the first node */
        node = newNode(value);
        node->next = head;
        printf("Inserted %d before %d (at the beginning)\n", value, key);
        return node;
    }

    while (cur != NULL && cur->data != key) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Key %d not found -- insertion not performed\n", key);
        return head;
    }

    node = newNode(value);
    node->next = prev->next;              /* == cur */
    prev->next = node;
    printf("Inserted %d before %d\n", value, key);
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

    printf("Enter the existing value before which to insert: ");
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

    head = insertBeforeValue(head, key, value);

    printf("\nUpdated list: ");
    display(head);

    freeList(head);
    return 0;
}
