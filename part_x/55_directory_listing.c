/* Directory listing using opendir/readdir/closedir (POSIX dirent.h). */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    const char *path = argc > 1 ? argv[1] : ".";
    DIR *d = opendir(path);
    if (!d) { perror(path); return EXIT_FAILURE; }
    struct dirent *e;
    long n = 0;
    while ((e = readdir(d)) != NULL) {
        printf("%s\n", e->d_name);
        n++;
    }
    closedir(d);
    printf("--- %ld entries in %s ---\n", n, path);
    return EXIT_SUCCESS;
}