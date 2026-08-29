/*
 * q46.c -- Circular Linked List: FIND THE MAXIMUM ELEMENT
 *
 * Idea: start with the head's data as the current maximum and traverse exactly
 * one round with a do-while loop, updating the maximum (and its position)
 * whenever a larger value is met.
 *
 * Compile: gcc q46.c -o q46
 * Sample input : 6  25 78 12 96 45 33  ->  Maximum = 96 (position 4)
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

/* Returns 1 on success and fills *maxOut / *posOut; 0 if the list is empty. */
int findMax(struct Node *head, int *maxOut, int *posOut)
{
    struct Node *cur;
    int max, pos = 1, i = 1;

    if (head == NULL)
        return 0;

    max = head->data;
    cur = head->next;
    while (cur != head) {              /* one full round */
        i++;
        if (cur->data > max) {
            max = cur->data;
            pos = i;
        }
        cur = cur->next;
    }
    *maxOut = max;
    *posOut = pos;
    return 1;
}

/* Second largest distinct value; returns 0 if it does not exist. */
int findSecondMax(struct Node *head, int *secondOut)
{
    struct Node *cur;
    int max, second, haveSecond = 0;

    if (head == NULL || head->next == head)
        return 0;

    max = head->data;
    second = 0;
    cur = head->next;
    while (cur != head) {
        if (cur->data > max) {
            second = max;
            haveSecond = 1;
            max = cur->data;
        } else if (cur->data != max && (!haveSecond || cur->data > second)) {
            second = cur->data;
            haveSecond = 1;
        }
        cur = cur->next;
    }
    if (!haveSecond)
        return 0;
    *secondOut = second;
    return 1;
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
    int n, i, value, max, pos, second;

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

    if (findMax(head, &max, &pos)) {
        printf("Maximum element = %d (at position %d)\n", max, pos);
        if (findSecondMax(head, &second))
            printf("Second largest distinct element = %d\n", second);
        else
            printf("No second largest element (all values are equal)\n");
    } else {
        printf("List is empty, no maximum exists\n");
    }

    freeCircular(head);
    return 0;
}
