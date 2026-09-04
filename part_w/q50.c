/* q50: Menu-driven data-structure advisor. */
#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[64];
    int choice;
    printf("Pick the problem type:\n");
    printf(" 1) Frequent insertions at both ends\n");
    printf(" 2) Need LIFO (last in, first out)\n");
    printf(" 3) Need FIFO (first in, first out)\n");
    printf(" 4) Need ordered dynamic data with O(log n) search\n");
    printf(" 5) Hierarchical / parent-child data\n");
    printf("Choice: ");
    if (scanf("%d", &choice) != 1) return 0;

    switch (choice) {
        case 1:
            printf("Recommendation: Doubly Linked List (or deque).\n");
            printf("Reason: O(1) insert/delete at both ends; no shifting.\n");
            break;
        case 2:
            printf("Recommendation: Stack.\n");
            printf("Reason: LIFO semantics; push/pop are O(1). Use for DFS, undo.\n");
            break;
        case 3:
            printf("Recommendation: Queue (or circular buffer).\n");
            printf("Reason: FIFO semantics; enqueue/dequeue are O(1). Use for BFS.\n");
            break;
        case 4:
            printf("Recommendation: Balanced BST (e.g., AVL/Red-Black) or B-Tree.\n");
            printf("Reason: maintains sorted order with O(log n) search/insert/delete.\n");
            break;
        case 5:
            printf("Recommendation: Tree (general or k-ary).\n");
            printf("Reason: explicit parent-child edges; supports hierarchical queries.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
    (void)buf;
    return 0;
}