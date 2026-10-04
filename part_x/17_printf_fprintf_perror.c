/* Demonstrate printf, fprintf(stderr,...), and perror. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("stdout via printf: %d %s\n", 42, "answer");
    fprintf(stdout, "stdout via fprintf: pi=%.4f\n", 3.14159);
    fprintf(stderr, "stderr via fprintf: this is an informational note\n");

    FILE *fp = fopen("does_not_exist_xyz.txt", "r");
    if (!fp) perror("fopen does_not_exist_xyz.txt");
    else fclose(fp);

    return EXIT_SUCCESS;
}