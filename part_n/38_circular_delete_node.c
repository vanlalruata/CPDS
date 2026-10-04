/*
 * q38.c -- Circular Linked List: DELETE A SPECIFIED NODE (by value)
 *
 * Idea: search the circle with a do-while loop, keeping a 'prev' pointer.
 * Three cases:
 *   1. single node holding the key -> free it, list becomes empty;
 *   2. the key is in the head node -> update the LAST node's next and the head;
 *   3. any other node             -> prev->next = cur->next; free(cur).
 *
 * Compile: gcc q38.c -o q38
 * Sample input : 5  10 20 30 40 50   delete 30
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

/* Delete the first node whose data == key; returns the new head. */
struct Node *deleteByValue(struct Node *head, int key)
{
    struct Node *cur, *prev = NULL, *last;

    if (head == NULL) {
        printf("List is empty -- deletion not possible\n");
        return NULL;
    }

    /* case 1: single node */
    if (head->next == head) {
        if (head->data == key) {
            printf("Deleted %d (list is now empty)\n", key);
            free(head);
            return NULL;
        }
        printf("Value %d not found\n", key);
        return head;
    }

    /* case 2: key in the head node */
    if (head->data == key) {
        last = head;
        while (last->next != head)
            last = last->next;
        cur = head;
        last->next = head->next;
        head = head->next;
        printf("Deleted head node with value %d\n", key);
        free(cur);
        return head;
    }

    /* case 3: search the rest of the circle */
    prev = head;
    cur = head->next;
    while (cur != head) {
        if (cur->data == key) {
            prev->next = cur->next;
            printf("Deleted node with value %d\n", key);
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    }

    printf("Value %d not found in the list\n", key);
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
    int n, i, value, key, k;

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

    printf("How many values to delete? ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid input\n");
        freeCircular(head);
        return 1;
    }

    for (i = 0; i < k; i++) {
        printf("Enter value to delete: ");
        if (scanf("%d", &key) != 1) {
            printf("Invalid input\n");
            freeCircular(head);
            return 1;
        }
        head = deleteByValue(head, key);
        printf("List now: ");
        display(head);
    }

    printf("\nFinal circular list: ");
    display(head);

    freeCircular(head);
    return 0;
}
