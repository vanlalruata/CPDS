/* part_g q11: Return multiple results through pointer parameters (min and max). */
#include <stdio.h>

void minMax(int a, int b, int *min, int *max) {
    if (a < b) { *min = a; *max = b; }
    else { *min = b; *max = a; }
}

int main(void) {
    int x = 7, y = 3, mn, mx;
    minMax(x, y, &mn, &mx);
    printf("min = %d, max = %d\n", mn, mx);
    return 0;
}
