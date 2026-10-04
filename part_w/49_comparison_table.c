/* q49: Comparison table: Array vs Linked List vs Stack vs Queue vs Tree. */
#include <stdio.h>

int main(void) {
    printf("+------------------+-----------+----------+----------+----------+-----------+----------------------+\n");
    printf("| Operation        | Array     | LinkedLst| Stack    | Queue    | Tree(BST) | Best use case        |\n");
    printf("+------------------+-----------+----------+----------+----------+-----------+----------------------+\n");
    printf("| Random access    | O(1)      | O(n)     | O(n) top | O(n) end | O(log n)* | Array: indexed data  |\n");
    printf("| Search           | O(n)      | O(n)     | O(n)     | O(n)     | O(log n)* | BST: ordered search  |\n");
    printf("| Insert at front  | O(n)      | O(1)     | O(1) top | O(1)     | O(log n)* | LL: stream/front ops |\n");
    printf("| Insert at end    | O(1) aam. | O(n)     | O(n)     | O(1)     | O(log n)* | Queue: BFS, schedul. |\n");
    printf("| Delete           | O(n)      | O(1) pos | O(1) top | O(1)     | O(log n)* | Stack: undo, DFS     |\n");
    printf("| Memory           | Contigu.  | Scatterd | Array/LL | Array/LL | Nodes+ptrs| Pick per access pat. |\n");
    printf("+------------------+-----------+----------+----------+----------+-----------+----------------------+\n");
    printf("* average for balanced BST; worst case O(n) when skewed.\n");
    printf("aam = amortized for dynamic array (doubling).\n");
    return 0;
}