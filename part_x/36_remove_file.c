/* remove: delete a file using remove() and report success/failure. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "junk.txt";
    FILE *fp = fopen(name, "w");
    if (fp) { fputs("to be removed\n", fp); fclose(fp); }
    if (remove(name) == 0) printf("Removed %s\n", name);
    else { perror("remove"); return EXIT_FAILURE; }
    return EXIT_SUCCESS;
}