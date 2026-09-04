/* sprintf and sscanf: format int+float into a string, parse them back. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buf[128];
    int n = 12345;
    double x = 3.14159265;
    int written = sprintf(buf, "n=%d x=%.6f", n, x);
    printf("sprintf wrote %d chars: '%s'\n", written, buf);

    int n2; double x2;
    if (sscanf(buf, "n=%d x=%lf", &n2, &x2) != 2) { perror("sscanf"); return EXIT_FAILURE; }
    printf("Parsed back: n=%d x=%.6f\n", n2, x2);
    return EXIT_SUCCESS;
}