/* q9.c - Several pointers pointing to the same variable.
 * Concept: Any number of pointers may hold the same address; a change
 *          made through one of them is visible through all of them.
 * Compile: gcc q9.c -o q9
 */
#include <stdio.h>

int main(void)
{
    int x;
    int *p1, *p2, *p3;

    printf("Enter an integer: ");
    if (scanf("%d", &x) != 1) { printf("Invalid input.\n"); return 1; }

    p1 = &x;
    p2 = &x;
    p3 = p1;                  /* copy of the same address */

    printf("\nAddresses: &x=%p  p1=%p  p2=%p  p3=%p\n",
           (void *) &x, (void *) p1, (void *) p2, (void *) p3);
    printf("Values   : x=%d  *p1=%d  *p2=%d  *p3=%d\n", x, *p1, *p2, *p3);

    *p2 = x + 100;            /* change through p2 */
    printf("\nAfter *p2 = x + 100:\n");
    printf("x=%d  *p1=%d  *p2=%d  *p3=%d  (all changed together)\n",
           x, *p1, *p2, *p3);

    printf("\nDo all three pointers compare equal? %s\n",
           (p1 == p2 && p2 == p3) ? "yes" : "no");

    return 0;
}
