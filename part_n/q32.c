/*
 * q32.c -- Circular Linked List: DISPLAY (stop when the head is reached)
 *
 * Idea: a 'while (cur != NULL)' loop would never end here, because no node has
 * a NULL next pointer. The correct pattern is a do-while loop:
 *      cur = head;
 *      do { print cur->data; cur = cur->next; } while (cur != head);
 * The program also prints two full rounds to show the wrap-around behaviour.
 *
 * Compile: gcc q32.c -o q32
 * Sample input : 4  5 10 15 20
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
    struct Node *cur;

    if (head == NULL) {
        node->next = node;
        return node;
    }
    cur = head;
    while (cur->next != head)
        cur = cur->next;
    cur->next = node;
    node->next = head;
    return head;
}

/* Standard circular display: one complete round using do-while. */
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

/* Display with position numbers. */
void displayWithPositions(struct Node *head)
{
    struct Node *cur = head;
    int pos = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("Position %d : %d\n", pos++, cur->data);
        cur = cur->next;
    } while (cur != head);
}

/* Traverse 'rounds' complete cycles to demonstrate the wrap-around. */
void displayRounds(struct Node *head, int rounds)
{
    struct Node *cur = head;
    int r;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    for (r = 0; r < rounds; r++) {
        do {
            printf("%d ", cur->data);
            cur = cur->next;
        } while (cur != head);
        printf("| ");
    }
    printf("\n");
}

/* Display starting from any node (a circular list has no fixed start). */
void displayFrom(struct Node *start)
{
    struct Node *cur = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d -> ", cur->data);
        cur = cur->next;
    } while (cur != start);
    printf("(back to %d)\n", start->data);
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
    int n, i, value;

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

    printf("\n1) One round starting from the head:\n");
    display(head);

    printf("\n2) Position-wise display:\n");
    displayWithPositions(head);

    printf("\n3) Two complete rounds (shows the wrap-around):\n");
    displayRounds(head, 2);

    if (head != NULL && head->next != head) {
        printf("\n4) Same list displayed starting from the second node:\n");
        displayFrom(head->next);
    }

    freeCircular(head);
    return 0;
}
