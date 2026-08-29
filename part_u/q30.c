/* part_u/q30.c — Determine the output of pointers and arrays
 *
 * Program below is CORRECT. Comment shows expected output with reasoning.
 */
#include <stdio.h>

int main(void) {
    int a[3] = {10, 20, 30};
    int *p = a;
    printf("%d %d %d\n", *p, *(p + 1), *(a + 2));
    p++;
    printf("%d\n", *p);
    printf("%d\n", *(a + 2));
    return 0;
}

/* EXPECTED OUTPUT:
 * 10 20 30
 * 20
 * 30
 *
 * Reason: p points to a[0]; *(p+1) is a[1]; *(a+2) is a[2]=30.
 * p++ moves p to a[1], so *p prints 20. The array a is unchanged, so
 * *(a+2) still prints 30.
 */
