/* part_r/q16.c
 * Simulate a circular buffer (fixed-size ring) using a circular queue.
 */
#include <stdio.h>
#define SIZE 5

int buf[SIZE], head = 0, tail = -1, count = 0;

void put(int v) {
    if (count == SIZE) { /* overwrite oldest (typical ring behaviour) */
        head = (head + 1) % SIZE; count--;
    }
    tail = (tail + 1) % SIZE; buf[tail] = v; count++;
}

void dump() {
    for (int i = 0; i < count; i++) printf("%d ", buf[(head + i) % SIZE]);
    printf("\n");
}

int main() {
    put(1); put(2); put(3); put(4); put(5);
    dump();
    put(6); /* overwrites 1 */
    dump();
    return 0;
}
