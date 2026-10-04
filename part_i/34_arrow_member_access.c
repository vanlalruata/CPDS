/* q34.c - Access structure members using the arrow operator ->
 * Concept: p->member is a shorthand for (*p).member and is the usual
 *          way to work with a pointer to a structure.
 * Compile: gcc q34.c -o q34
 */
#include <stdio.h>

struct Student {
    int   roll;
    char  name[50];
    float marks;
};

static void printStudent(const struct Student *s)
{
    printf("Roll  : %d\n", s->roll);
    printf("Name  : %s\n", s->name);
    printf("Marks : %.2f\n", s->marks);
}

int main(void)
{
    struct Student st;
    struct Student *p = &st;

    printf("Enter roll number: ");
    scanf("%d", &p->roll);            /* &(p->roll) */
    printf("Enter name (one word): ");
    scanf("%49s", p->name);
    printf("Enter marks: ");
    scanf("%f", &p->marks);

    printf("\nStudent details read through the arrow operator:\n");
    printStudent(p);

    p->marks += 5.0f;                 /* modify through -> */
    printf("\nAfter adding 5 grace marks: %.2f\n", st.marks);
    printf("Grade: %s\n", st.marks >= 40.0f ? "PASS" : "FAIL");

    return 0;
}
