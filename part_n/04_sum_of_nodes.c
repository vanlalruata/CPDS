/*
 * q4.c -- Singly Linked List: SUM OF ALL NODES
 *
 * Idea: traverse the list once, adding every node's data to an accumulator.
 * The average is also printed to show use of the count together with the sum.
 *
 * Compile: gcc q4.c -o q4
 * Sample input : 5  10 20 30 40 50   ->  Sum = 150, Average = 30.00
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

/* Iterative sum of the data fields. */
long sumList(struct Node *head)
{
    long sum = 0;
    struct Node *cur = head;

    while (cur != NULL) {
        sum += cur->data;
        cur = cur->next;
    }
    return sum;
}

/* Recursive sum. */
long sumListRecursive(struct Node *head)
{
    if (head == NULL)
        return 0;
    return head->data + sumListRecursive(head->next);
}

int countNodes(struct Node *head)
{
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->next;
    }
    return c;
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
    int n, i, value, count;
    long sum;

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

    sum = sumList(head);
    count = countNodes(head);

    printf("Sum of all nodes (iterative) = %ld\n", sum);
    printf("Sum of all nodes (recursive) = %ld\n", sumListRecursive(head));
    if (count > 0)
        printf("Average value = %.2f\n", (double)sum / count);

    freeList(head);
    return 0;
}
