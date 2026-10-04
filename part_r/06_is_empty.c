/* part_r/q6.c
 * Implement isEmpty() for a circular queue.
 */
#include <stdio.h>
#define MAX 4

int front = 0, rear = -1, count = 0;

int isEmpty() { return count == 0; }

int main() {
    printf("isEmpty = %d\n", isEmpty());
    count = 1;
    printf("isEmpty after add = %d\n", isEmpty());
    return 0;
}
