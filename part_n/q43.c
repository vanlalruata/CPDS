/*
 * q43.c -- Circular Linked List: SPLIT INTO TWO HALVES
 *
 * Idea: find the middle with slow/fast pointers (bounded by the head), then
 * close each half into its own circular list:
 *      head1 = head;            slow->next = head1;
 *      head2 = slow->next(old); last->next  = head2;
 * If the number of nodes is odd, the first half gets the extra node.
 *
 * Compile: gcc q43.c -o q43
 * Sample input : 6  1 2 3 4 5 6  ->  half1 = 1 2 3, half2 = 4 5 6
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

int countNodes(struct Node *head)
{
    struct Node *cur = head;
    int c = 0;

    if (head == NULL)
        return 0;
    do {
        c++;
        cur = cur->next;
    } while (cur != head);
    return c;
}

/* Splits one circular list into two circular lists. */
void splitCircular(struct Node *head, struct Node **head1, struct Node **head2)
{
    struct Node *slow = head, *fast = head;

    if (head == NULL) {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }
    if (head->next == head) {          /* only one node */
        *head1 = head;
        *head2 = NULL;
        return;
    }

    /* slow ends at the last node of the first half */
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next->next == head)      /* even count: push fast to the last node */
        fast = fast->next;

    *head1 = head;
    *head2 = slow->next;

    slow->next = *head1;               /* close the first half */
    fast->next = *head2;               /* close the second half */
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
    struct Node *head = NULL, *head1 = NULL, *head2 = NULL;
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

    printf("\nOriginal circular list (%d nodes): ", countNodes(head));
    display(head);

    splitCircular(head, &head1, &head2);

    printf("\nFirst half  (%d nodes): ", countNodes(head1));
    display(head1);
    printf("Second half (%d nodes): ", countNodes(head2));
    display(head2);

    printf("\nBoth halves are independent circular lists.\n");

    freeCircular(head1);
    freeCircular(head2);
    return 0;
}
