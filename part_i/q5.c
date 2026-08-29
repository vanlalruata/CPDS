/* q5.c - Pointers to int, float, char and double.
 * Concept: A pointer's type tells the compiler how to interpret the
 *          bytes at the address and how far pointer arithmetic moves.
 *          Each type needs its own matching pointer type.
 * Compile: gcc q5.c -o q5
 */
#include <stdio.h>

int main(void)
{
    int    i;
    float  f;
    char   c;
    double d;

    int    *pi = &i;
    float  *pf = &f;
    char   *pc = &c;
    double *pd = &d;

    printf("Enter an integer: ");
    scanf("%d", &i);
    printf("Enter a float: ");
    scanf("%f", &f);
    printf("Enter a character: ");
    scanf(" %c", &c);
    printf("Enter a double: ");
    scanf("%lf", &d);

    printf("\n%-10s %-12s %-22s %s\n", "Type", "Value", "Address", "Value via pointer");
    printf("%-10s %-12d %-22p %d\n",   "int",    i, (void *) pi, *pi);
    printf("%-10s %-12.4f %-22p %.4f\n","float", f, (void *) pf, *pf);
    printf("%-10s %-12c %-22p %c\n",   "char",   c, (void *) pc, *pc);
    printf("%-10s %-12.6f %-22p %.6f\n","double",d, (void *) pd, *pd);

    return 0;
}
