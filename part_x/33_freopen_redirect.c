/* freopen: redirect stdout to log.txt, printf, then redirect back to console. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "log.txt";
    if (!freopen(name, "w", stdout)) { perror("freopen log.txt"); return EXIT_FAILURE; }
    printf("This goes to %s\n", name);
    fflush(stdout);

    if (!freopen("CON", "w", stdout)) {
        if (!freopen("/dev/tty", "w", stdout)) {
            fprintf(stderr, "Could not restore stdout.\n");
        }
    }
    printf("Back to console.\n");
    return EXIT_SUCCESS;
}