/**
 * bonus_menu_driven.c - Part L: Unions in C
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <string.h>

// Simple Union
union DataHolder {
    int i;
    float f;
    char str[20];
};

// Tagged Variant Record
typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_STRING } ValueType;

typedef struct {
    ValueType type;
    union {
        int i_val;
        float f_val;
        char str_val[32];
    } value;
} Variant;

void shared_memory_demo(void) {
    union DataHolder data;
    printf("\n--- Union Shared Memory Overwrite Demonstration ---\n");
    printf("sizeof(union DataHolder): %zu bytes\n", sizeof(union DataHolder));

    data.i = 100;
    printf("Assigned data.i = 100\n");
    printf("data.i: %d | data.f: %f (corrupted/reinterpreted)\n", data.i, data.f);

    data.f = 220.5f;
    printf("\nAssigned data.f = 220.5\n");
    printf("data.f: %f | data.i: %d (corrupted)\n", data.f, data.i);

    strcpy(data.str, "C Programming");
    printf("\nAssigned data.str = \"C Programming\"\n");
    printf("data.str: %s | data.i: %d | data.f: %f\n", data.str, data.i, data.f);
    printf("Takeaway: All union members share the exact same starting memory address!\n");
}

void struct_vs_union_sizeof(void) {
    struct StructVersion {
        int id;
        double salary;
        char code[16];
    };

    union UnionVersion {
        int id;
        double salary;
        char code[16];
    };

    printf("\n--- Struct vs Union Memory Footprint ---\n");
    printf("Members: int id (4 bytes), double salary (8 bytes), char code[16] (16 bytes)\n");
    printf("sizeof(struct StructVersion): %zu bytes (Sum of member sizes + padding)\n", sizeof(struct StructVersion));
    printf("sizeof(union UnionVersion):   %zu bytes (Max of member sizes + alignment)\n", sizeof(union UnionVersion));
    printf("Ratio: Union saves %zu bytes per instance!\n",
           sizeof(struct StructVersion) - sizeof(union UnionVersion));
}

void tagged_variant_demo(void) {
    Variant items[3];

    // Item 1: Integer
    items[0].type = TYPE_INT;
    items[0].value.i_val = 42;

    // Item 2: Float
    items[1].type = TYPE_FLOAT;
    items[1].value.f_val = 3.14159f;

    // Item 3: String
    items[2].type = TYPE_STRING;
    strcpy(items[2].value.str_val, "Data Structures");

    printf("\n--- Tagged Union (Variant Pattern) ---\n");
    for (int i = 0; i < 3; i++) {
        printf("Item %d: ", i + 1);
        switch (items[i].type) {
            case TYPE_INT:
                printf("[INTEGER] %d\n", items[i].value.i_val);
                break;
            case TYPE_FLOAT:
                printf("[FLOAT]   %.4f\n", items[i].value.f_val);
                break;
            case TYPE_STRING:
                printf("[STRING]  %s\n", items[i].value.str_val);
                break;
        }
    }
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part L: C Unions & Memory Sharing Hub     \n");
        printf("============================================\n");
        printf("1. Union Shared Memory Overwrite Demo\n");
        printf("2. Struct vs Union sizeof Comparison\n");
        printf("3. Tagged Union (Variant Record Pattern)\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: shared_memory_demo(); break;
            case 2: struct_vs_union_sizeof(); break;
            case 3: tagged_variant_demo(); break;
            case 4: printf("Exiting Part L Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
