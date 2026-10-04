/* part_k / q29: Create a product inventory system. */
#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    char name[40];
    int quantity;
    float price;
} Product;

int main(void) {
    Product p[MAX];
    int n = 0, i, key, choice, found;
    while (1) {
        printf("\n1.Add 2.Display 3.Search 4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            if (n >= MAX) { printf("Full.\n"); continue; }
            printf("id name quantity price: ");
            scanf("%d %39s %d %f", &p[n].id, p[n].name, &p[n].quantity, &p[n].price);
            n++;
        } else if (choice == 2) {
            for (i = 0; i < n; i++) printf("%d %s qty=%d price=%.2f\n", p[i].id, p[i].name, p[i].quantity, p[i].price);
        } else if (choice == 3) {
            found = 0;
            printf("Enter id: ");
            scanf("%d", &key);
            for (i = 0; i < n; i++)
                if (p[i].id == key) { printf("%d %s qty=%d price=%.2f\n", p[i].id, p[i].name, p[i].quantity, p[i].price); found = 1; }
            if (!found) printf("Not found.\n");
        } else if (choice == 4) {
            break;
        }
    }
    return 0;
}
