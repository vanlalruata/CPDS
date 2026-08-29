/* part_k / q4: Define a structure for a product. */
#include <stdio.h>

typedef struct {
    int id;
    char name[40];
    float price;
    int quantity;
} Product;

int main(void) {
    Product p = { 1, "Pen", 2.5f, 100 };
    printf("%d %s %.2f x %d\n", p.id, p.name, p.price, p.quantity);
    return 0;
}
