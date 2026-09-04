/* Logger: append timestamped messages to app.log using time/localtime/strftime. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "app.log";
    const char *msg  = argc > 2 ? argv[2] : "Application event";

    FILE *fp = fopen(name, "a");
    if (!fp) { perror(name); return EXIT_FAILURE; }

    time_t now = time(NULL);
    struct tm tm_buf;
    if (!localtime_s(&tm_buf, &now)) {
        char ts[32];
        strftime(ts, sizeof ts, "%Y-%m-%d %H:%M:%S", &tm_buf);
        fprintf(fp, "[%s] %s\n", ts, msg);
    } else {
        fprintf(fp, "[%ld] %s\n", (long)now, msg);
    }
    fclose(fp);
    printf("Logged to %s\n", name);
    return EXIT_SUCCESS;
}