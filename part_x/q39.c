/* strerror and errno: force an error opening a missing file; print errno and strerror(errno). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "missing_xyz_123.txt";
    errno = 0;
    FILE *fp = fopen(name, "r");
    if (!fp) {
        printf("errno=%d message='%s'\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}