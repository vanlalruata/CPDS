/* part_k / q21: Create a structure containing another structure. */
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point topLeft;
    Point bottomRight;
} Rectangle;

int main(void) {
    Rectangle r = { {0, 10}, {10, 0} };
    printf("TopLeft=(%d,%d) BottomRight=(%d,%d)\n",
           r.topLeft.x, r.topLeft.y, r.bottomRight.x, r.bottomRight.y);
    return 0;
}
