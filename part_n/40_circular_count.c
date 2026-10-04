/*
 * q40.c -- Circular Linked List: COUNT THE NODES
 *
 * Idea: a do-while loop counts nodes and stops when the traversal returns to
 * the head. A plain 'while (cur != NULL)' loop would never terminate.
 * A recursive helper that carries the head as a sentinel is also shown.
 *
 * Compile: gcc q40.c -o q40
 * Sample input : 5  2 4 6 8 10  ->  Number of nodes = 5
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

/* Iterative count using do-while. */
int countNodes(struct Node *head)
{
    struct Node *cur = head;
    int count = 0;

    if (head == NULL)
        return 0;
    do {
        count++;
        cur = cur->next;
    } while (cur != head);
    return count;
}

/* Recursive helper: 'cur' walks, 'head' is the stop sentinel. */
int countRecursiveHelper(struct Node *cur, struct Node *head)
{
    if (cur->next == head)
        return 1;
    return 1 + countRecursiveHelper(cur->next, head);
}

int countNodesRecursive(struct Node *head)
{
    if (head == NULL)
        return 0;
    return countRecursiveHelper(head, head);
}

/* Sum of nodes -- another example of a bounded circular traversal. */
long sumNodes(struct Node *head)
{
    struct Node *cur = head;
    long sum = 0;

    if (head == NULL)
        return 0;
    do {
        sum += cur->data;
        cur = cur->next;
    } while (cur != head);
    return sum;
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

    printf("\nCircular list: ");
    display(head);

    printf("Number of nodes (iterative) = %d\n", countNodes(head));
    printf("Number of nodes (recursive) = %d\n", countNodesRecursive(head));
    printf("Sum of all nodes            = %ld\n", sumNodes(head));

    freeCircular(head);
    return 0;
}
