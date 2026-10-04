/*
 * q28.c -- Singly Linked List: CHECK WHETHER THE LIST IS A PALINDROME
 *
 * Idea (O(n) time, O(1) extra space):
 *   1. find the middle with slow/fast pointers;
 *   2. reverse the second half;
 *   3. compare the first half with the reversed second half;
 *   4. reverse the second half again to restore the original list.
 * A simple stack/array method is also shown for comparison.
 *
 * Compile: gcc q28.c -o q28
 * Sample input : 5  1 2 3 2 1  ->  the list IS a palindrome
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

int countNodes(struct Node *head)
{
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->next;
    }
    return c;
}

struct Node *reverse(struct Node *head)
{
    struct Node *prev = NULL, *cur = head, *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

/* Method 1: middle + reverse second half. Restores the list before returning. */
int isPalindromeReverseHalf(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    struct Node *secondHalf, *p1, *p2;
    int result = 1;

    if (head == NULL || head->next == NULL)
        return 1;                       /* 0 or 1 node is a palindrome */

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;              /* slow ends at the first middle */
        fast = fast->next->next;
    }

    secondHalf = reverse(slow->next);   /* reverse the second half */
    slow->next = NULL;                  /* temporarily split the list */

    p1 = head;
    p2 = secondHalf;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data != p2->data) {
            result = 0;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    slow->next = reverse(secondHalf);   /* restore the original list */
    return result;
}

/* Method 2: copy values into an array and compare the two ends. */
int isPalindromeArray(struct Node *head)
{
    int n = countNodes(head);
    int *arr, i, j, ok = 1;
    struct Node *cur = head;

    if (n <= 1)
        return 1;

    arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++, cur = cur->next)
        arr[i] = cur->data;

    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (arr[i] != arr[j]) {
            ok = 0;
            break;
        }
    }
    free(arr);
    return ok;
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
            freeList(head);
            return 1;
        }
        head = insertEnd(head, value);
    }

    printf("\nList: ");
    display(head);

    if (isPalindromeReverseHalf(head))
        printf("Result: the list IS a palindrome\n");
    else
        printf("Result: the list is NOT a palindrome\n");

    printf("Verification with the array method: %s\n",
           isPalindromeArray(head) ? "palindrome" : "not a palindrome");

    printf("List after checking (must be unchanged): ");
    display(head);

    freeList(head);
    return 0;
}
