/*
 * q21: Largest and smallest among N numbers.
 * Reads N then N integers, finds max and min.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read N; read x   |
 * +------------------+
 * | max=min=x;i=1    |
 * +------------------+
 *     |
 *     v
 * +------------------+
 * | i < N ?          |
 * +------------------+
 *   /    \
 * yes/    \no
 *  v       v
 * read x   print max,min
 * if x>max max=x
 * if x<min min=x
 * i++
 *  \       /
 *   v     v
 *  (loop)  +-------+
 *          | STOP |
 *          +------+
 */
#include <stdio.h>

int main(void) {
    int n, x, max, min;
    printf("Enter count N: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("Enter %d numbers:\n", n);
    if (scanf("%d", &x) != 1) return 1;
    max = min = x;
    for (int i = 1; i < n; i++) {
        if (scanf("%d", &x) != 1) return 1;
        if (x > max) max = x;
        if (x < min) min = x;
    }
    printf("Largest = %d, Smallest = %d\n", max, min);
    return 0;
}
