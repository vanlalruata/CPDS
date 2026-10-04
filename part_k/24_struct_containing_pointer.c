/* part_k / q24: Create a structure containing a pointer (char *name).
   Name is allocated dynamically and freed at the end. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roll;
    char *name;
} Student;

int main(void) {
    Student s;
    char buffer[40];
    printf("Enter roll and name: ");
    if (scanf("%d %39s", &s.roll, buffer) != 2) return 1;
    s.name = (char *)malloc(strlen(buffer) + 1);
    if (!s.name) return 1;
    strcpy(s.name, buffer);
    printf("Roll=%d Name=%s\n", s.roll, s.name);
    free(s.name);
    return 0;
}
