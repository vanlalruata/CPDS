/* q33.c - Pointer to a structure.
 * Concept: A structure variable has an address like any other object.
 *          struct Book *p = &b;  then (*p).member accesses a field.
 * Compile: gcc q33.c -o q33
 */
#include <stdio.h>

struct Book {
    int   id;
    char  title[50];
    float price;
};

int main(void)
{
    struct Book b;
    struct Book *p;

    p = &b;                       /* pointer to the structure */

    printf("Enter book id: ");
    scanf("%d", &b.id);
    printf("Enter book title (one word): ");
    scanf("%49s", b.title);
    printf("Enter price: ");
    scanf("%f", &b.price);

    printf("\n--- using the structure variable ---\n");
    printf("Id = %d, Title = %s, Price = %.2f\n", b.id, b.title, b.price);

    printf("\n--- using the pointer with (*p).member ---\n");
    printf("Id = %d, Title = %s, Price = %.2f\n",
           (*p).id, (*p).title, (*p).price);

    printf("\nAddress of structure : %p\n", (void *) p);
    printf("Size of structure    : %lu bytes\n",
           (unsigned long) sizeof(struct Book));

    (*p).price = (*p).price * 1.10f;   /* 10%% increase through pointer */
    printf("Price after 10%% increase (via pointer): %.2f\n", b.price);

    return 0;
}
