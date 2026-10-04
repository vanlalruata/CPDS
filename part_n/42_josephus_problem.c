/*
 * q42.c -- Circular Linked List: JOSEPHUS PROBLEM
 *
 * Problem: n people numbered 1..n stand in a circle. Counting starts at person
 * 1; every k-th person is eliminated. The counting continues around the circle
 * until only one person remains -- that person survives.
 *
 * Idea: a circular linked list models the circle perfectly. Walk (k-1) steps to
 * reach the person just before the victim, unlink the victim and free it.
 * Repeat until only one node is left.
 *
 * Compile: gcc q42.c -o q42
 * Sample input : n = 7, k = 3  ->  eliminated 3 6 2 7 5 1, survivor = 4
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;                 /* person number */
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
        printf("Circle is empty\n");
        return;
    }
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("\n");
}

/*
 * Solves the Josephus problem.
 * Returns the surviving person's number; every node is freed on the way.
 */
int josephus(struct Node *head, int k)
{
    struct Node *prev, *victim;
    int i, survivor;

    if (head == NULL)
        return -1;

    prev = head;
    while (prev->next != head)        /* prev must trail the counting start */
        prev = prev->next;

    while (prev->next != prev) {      /* more than one person left */
        for (i = 1; i < k; i++)       /* count k-1 steps */
            prev = prev->next;

        victim = prev->next;          /* the k-th person */
        prev->next = victim->next;    /* remove from the circle */
        printf("Eliminated person %d\n", victim->data);
        free(victim);
    }

    survivor = prev->data;
    free(prev);                       /* free the last remaining node */
    return survivor;
}

/* Recurrence check: J(1)=0, J(n) = (J(n-1)+k) % n, answer = J(n)+1. */
int josephusFormula(int n, int k)
{
    int i, r = 0;
    for (i = 2; i <= n; i++)
        r = (r + k) % i;
    return r + 1;
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
    int n, k, i, survivor;

    printf("Enter number of people (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input (n must be positive)\n");
        return 1;
    }

    printf("Enter the counting step (k): ");
    if (scanf("%d", &k) != 1 || k <= 0) {
        printf("Invalid input (k must be positive)\n");
        return 1;
    }

    for (i = 1; i <= n; i++)          /* people numbered 1..n */
        head = insertEnd(head, i);

    printf("\nPeople in the circle: ");
    display(head);
    printf("Every %d-th person is eliminated.\n\n", k);

    survivor = josephus(head, k);     /* frees all nodes internally */

    printf("\nThe survivor is person number %d\n", survivor);
    printf("Verification using the recurrence formula: %d\n",
           josephusFormula(n, k));

    return 0;
}
