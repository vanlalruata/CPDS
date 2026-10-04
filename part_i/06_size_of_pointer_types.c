/* q6.c - Size of different pointer types.
 * Concept: All object pointers on a given platform normally have the
 *          same size (they all hold an address), even though the sizes
 *          of the types they point to differ.
 * Compile: gcc q6.c -o q6
 */
#include <stdio.h>

int main(void)
{
    int    *pi;
    float  *pf;
    char   *pc;
    double *pd;
    long   *pl;
    void   *pv;
    int   **ppi;
    char dummy;

    printf("Press Enter after reading (input is consumed to keep the\n");
    printf("program interactive). Type any character then Enter: ");
    if (scanf(" %c", &dummy) != 1) dummy = '-';

    printf("\nYou typed '%c'.\n\n", dummy);

    printf("%-22s %s\n", "Pointer type", "sizeof (bytes)");
    printf("%-22s %lu\n", "int *",    (unsigned long) sizeof(pi));
    printf("%-22s %lu\n", "float *",  (unsigned long) sizeof(pf));
    printf("%-22s %lu\n", "char *",   (unsigned long) sizeof(pc));
    printf("%-22s %lu\n", "double *", (unsigned long) sizeof(pd));
    printf("%-22s %lu\n", "long *",   (unsigned long) sizeof(pl));
    printf("%-22s %lu\n", "void *",   (unsigned long) sizeof(pv));
    printf("%-22s %lu\n", "int **",   (unsigned long) sizeof(ppi));

    printf("\nFor comparison, sizes of the pointed-to types:\n");
    printf("%-22s %lu\n", "int",    (unsigned long) sizeof(int));
    printf("%-22s %lu\n", "float",  (unsigned long) sizeof(float));
    printf("%-22s %lu\n", "char",   (unsigned long) sizeof(char));
    printf("%-22s %lu\n", "double", (unsigned long) sizeof(double));
    printf("%-22s %lu\n", "long",   (unsigned long) sizeof(long));

    return 0;
}
