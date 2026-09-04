/* snprintf: safely format into a fixed-size buffer without overflow. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buf[16];
    int ret = snprintf(buf, sizeof buf, "Pi=%.8f", 3.14159265358979);
    if (ret < 0) { perror("snprintf"); return EXIT_FAILURE; }
    printf("Return value (what would be written): %d\n", ret);
    printf("Buffer content (truncated to %zu): '%s'\n", sizeof buf, buf);
    return EXIT_SUCCESS;
}