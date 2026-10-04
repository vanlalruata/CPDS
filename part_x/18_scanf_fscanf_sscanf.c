/* Demonstrate scanf (stdin), fscanf (file), sscanf (string). */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp) { fclose(fp); return; }
    fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("100 hello 3.14\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    ensure_sample(name);

    const char *str = "200 world 2.71";

    int i1; char s1[32]; double d1;
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    if (fscanf(fp, "%d %31s %lf", &i1, s1, &d1) != 3) { perror("fscanf"); fclose(fp); return EXIT_FAILURE; }
    fclose(fp);
    printf("fscanf -> %d %s %.3f\n", i1, s1, d1);

    int i2; char s2[32]; double d2;
    if (sscanf(str, "%d %31s %lf", &i2, s2, &d2) != 3) { perror("sscanf"); return EXIT_FAILURE; }
    printf("sscanf -> %d %s %.3f\n", i2, s2, d2);

    printf("Enter: int string float (e.g. 7 foo 1.5): ");
    int i3; char s3[32]; double d3;
    if (scanf("%d %31s %lf", &i3, s3, &d3) == 3)
        printf("scanf -> %d %s %.3f\n", i3, s3, d3);
    return EXIT_SUCCESS;
}