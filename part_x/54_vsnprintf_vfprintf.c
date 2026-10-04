/* vsnprintf / vfprintf: format into a buffer via va_list and call with multiple args. */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static void logfmt(char *buf, size_t cap, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, cap, fmt, ap);
    va_end(ap);
}

int main(void) {
    char buf[128];
    logfmt(buf, sizeof buf, "name=%s age=%d pi=%.4f", "Alice", 30, 3.14159);
    fprintf(stdout, "%s\n", buf);
    return EXIT_SUCCESS;
}