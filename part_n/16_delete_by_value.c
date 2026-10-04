/*
 * q16.c -- Singly Linked List: DELETE A NODE CONTAINING A SPECIFIED VALUE
 *
 * Idea: search with a 'prev' pointer.
 *   deleteByValue()    -- removes only the FIRST occurrence of the key;
 *   deleteAllByValue() -- removes EVERY occurrence of the key.
 * Both free the removed nodes.
 *
 * Compile: gcc q16.c -o q16
 * Sample input : 6  10 25 30 25 40 25   key 25
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

/* Delete the first node whose data == key. */
struct Node *deleteByValue(struct Node *head, int key)
{
    struct Node *cur = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty -- deletion not possible\n");
        return NULL;
    }

    while (cur != NULL && cur->data != key) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Value %d not found in the list\n", key);
        return head;
    }

    if (prev == NULL)                 /* the key is in the head node */
        head = cur->next;
    else
        prev->next = cur->next;

    printf("Deleted first occurrence of %d\n", key);
    free(cur);
    return head;
}

/* Delete every node whose data == key; returns the new head and
   reports how many nodes were removed through *removed. */
struct Node *deleteAllByValue(struct Node *head, int key, int *removed)
{
    struct Node *cur = head, *prev = NULL, *tmp;
    *removed = 0;

    while (cur != NULL) {
        if (cur->data == key) {
            tmp = cur;
            if (prev == NULL) {
                head = cur->next;
                cur = head;
            } else {
                prev->next = cur->next;
                cur = cur->next;
            }
            free(tmp);
            (*removed)++;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
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
    int n, i, value, key, removed;

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

    printf("Enter value to delete: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    head = deleteByValue(head, key);
    printf("After deleting the first occurrence: ");
    display(head);

    head = deleteAllByValue(head, key, &removed);
    printf("After deleting all remaining occurrences (%d removed): ", removed);
    display(head);

    freeList(head);
    return 0;
}
