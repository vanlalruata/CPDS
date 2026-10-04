/*
 * q5.c -- Singly Linked List: MAXIMUM NODE VALUE
 *
 * Idea: assume the first node holds the maximum, then traverse the rest and
 * update the maximum whenever a larger value is found. Its position is also
 * reported. Never initialise max with 0 -- that fails for all-negative lists.
 *
 * Compile: gcc q5.c -o q5
 * Sample input : 5  -4 -9 -1 -7 -3   ->  Maximum = -1 (position 3)
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

/*
 * Finds the maximum value.
 * Returns 1 on success and stores the value in *maxOut and its 1-based
 * position in *posOut; returns 0 if the list is empty.
 */
int findMax(struct Node *head, int *maxOut, int *posOut)
{
    struct Node *cur;
    int max, pos = 1, i = 1;

    if (head == NULL)
        return 0;

    max = head->data;                        /* start with the first node */
    for (cur = head->next; cur != NULL; cur = cur->next) {
        i++;
        if (cur->data > max) {
            max = cur->data;
            pos = i;
        }
    }
    *maxOut = max;
    *posOut = pos;
    return 1;
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
    int n, i, value, max, pos;

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

    if (findMax(head, &max, &pos))
        printf("Maximum value = %d (found at position %d)\n", max, pos);
    else
        printf("List is empty, no maximum exists\n");

    freeList(head);
    return 0;
}
