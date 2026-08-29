/* part_r/q7.c
 * Implement isFull() for a circular queue.
 */
#include <stdio.h>
#define MAX 3

int count = 0;

int isFull() { return count == MAX; }

int main() {
    printf("isFull = %d\n", isFull());
    count = MAX;
    printf("isFull after fill = %d\n", isFull());
    return 0;
}
