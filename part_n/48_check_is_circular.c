/*
 * q48.c -- CHECK WHETHER A GIVEN LINKED LIST IS CIRCULAR
 *
 * Three possibilities for a list built with 'next' pointers:
 *   a) linear            -- some node's next is NULL;
 *   b) fully circular    -- the last node points back to the HEAD;
 *   c) loop but not circular -- the last node points to a middle node
 *                               (this is a cycle, yet not a circular list).
 *
 * Idea: Floyd's slow/fast algorithm detects any loop in O(n)/O(1). If a loop
 * exists, the first node of the loop is computed: the list is truly CIRCULAR
 * only when that node is the head.
 *
 * The program lets you choose the structure so all three cases can be tested.
 *
 * Compile: gcc q48.c -o q48
 * Sample input : 5  1 2 3 4 5   then 1  ->  the list IS circular
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

/* Builds a plain (linear) list. */
struct Node *insertEndLinear(struct Node *head, int value)
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

/* Floyd's cycle detection: returns the meeting node or NULL. */
struct Node *detectLoop(struct Node *head)
{
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}

/* First node of the loop (assumes a loop exists). */
struct Node *loopStart(struct Node *head, struct Node *meet)
{
    struct Node *p = head, *q = meet;

    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}

/* 1 if the list is a proper circular list, 0 otherwise. */
int isCircular(struct Node *head)
{
    struct Node *meet;

    if (head == NULL)
        return 1;                       /* empty list: circular by convention */
    meet = detectLoop(head);
    if (meet == NULL)
        return 0;                       /* linear */
    return (loopStart(head, meet) == head);
}

/* Safe print for a list that may contain a loop. */
void displaySafe(struct Node *head, int limit)
{
    struct Node *cur = head;
    int i = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (cur != NULL && i < limit) {
        printf("%d -> ", cur->data);
        cur = cur->next;
        i++;
    }
    if (cur == NULL)
        printf("NULL\n");
    else
        printf("... (the traversal repeats)\n");
}

/* Removes any loop so the nodes can be freed with a simple walk. */
void breakLoop(struct Node *head)
{
    struct Node *meet = detectLoop(head);
    struct Node *start, *p;

    if (meet == NULL)
        return;
    start = loopStart(head, meet);
    p = start;
    while (p->next != start)
        p = p->next;
    p->next = NULL;
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
    struct Node *head = NULL, *cur, *last = NULL, *target = NULL, *meet;
    int n, i, value, choice;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input (need at least 1 node)\n");
        return 1;
    }

    printf("Enter %d integer(s): ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) {
            printf("Invalid input\n");
            freeList(head);
            return 1;
        }
        head = insertEndLinear(head, value);
    }

    printf("\nMake the last node point to which position?\n");
    printf("  0 = NULL (linear list)\n");
    printf("  1 = the head  (proper circular list)\n");
    printf("  2..%d = a middle node (loop but not circular)\n", n);
    printf("Your choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    for (cur = head, i = 1; cur != NULL; cur = cur->next, i++) {
        if (i == choice)
            target = cur;
        if (cur->next == NULL)
            last = cur;
    }

    if (choice >= 1 && choice <= n && target != NULL) {
        last->next = target;
        printf("last->next now points to node %d (value %d)\n",
               choice, target->data);
    } else {
        printf("last->next stays NULL\n");
    }

    printf("\nList (safe print): ");
    displaySafe(head, n + 5);

    meet = detectLoop(head);
    printf("\nLoop present? %s\n", (meet != NULL) ? "YES" : "NO");
    if (meet != NULL)
        printf("Loop begins at the node with value %d\n",
               loopStart(head, meet)->data);

    if (isCircular(head))
        printf("RESULT: the given linked list IS CIRCULAR\n");
    else if (meet != NULL)
        printf("RESULT: the list is NOT circular -- it only contains a loop\n");
    else
        printf("RESULT: the list is NOT circular -- it is linear (ends at NULL)\n");

    breakLoop(head);
    freeList(head);
    return 0;
}
