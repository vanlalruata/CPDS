/* part_t/q15.c — CPU Scheduling (round-robin using circular queue) */
#include <stdio.h>

#define MAX 10

struct Process {
    int id, bt, rt; /* burst time, remaining time */
};

int main(void) {
    struct Process p[MAX];
    int n, tq, done = 0, time = 0, i;
    printf("Number of processes: "); scanf("%d", &n);
    for (i = 0; i < n; i++) { p[i].id = i + 1; printf("Burst time p%d: ", i + 1); scanf("%d", &p[i].bt); p[i].rt = p[i].bt; }
    printf("Time quantum: "); scanf("%d", &tq);
    printf("Execution order:\n");
    while (done < n) {
        for (i = 0; i < n; i++) {
            if (p[i].rt > 0) {
                int run = (p[i].rt < tq) ? p[i].rt : tq;
                printf("P%d runs %d units (time %d-%d)\n", p[i].id, run, time, time + run);
                time += run; p[i].rt -= run;
                if (p[i].rt == 0) done++;
            }
        }
    }
    printf("Total time: %d\n", time);
    return 0;
}
