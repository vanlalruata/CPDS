/* q22: Identify complexity class of several small snippets printed here. */
#include <stdio.h>

static long steps = 0;
static long recursive_calls = 0;

static int linear_sum(int n) {
    int s = 0;
    for (int i = 0; i < n; ++i) { s += i; steps++; }
    return s;
}

static int nested_sum(int n) {
    int s = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) { s++; steps++; }
    return s;
}

static void halving(int n) {
    while (n > 0) { steps++; n /= 2; }
}

static long power_calls(int n) {
    recursive_calls++;
    if (n <= 0) return 1;
    return power_calls(n - 1) + power_calls(n - 1);
}

int main(void) {
    int n = 16;

    steps = 0; (void)linear_sum(n);
    printf("Snippet A (single for):  steps=%ld -> O(n)\n", steps);

    steps = 0; (void)nested_sum(n);
    printf("Snippet B (nested for):  steps=%ld -> O(n^2)\n", steps);

    steps = 0; halving(n);
    printf("Snippet C (n/=2 loop):   steps=%ld -> O(log n)\n", steps);

    steps = 0; halving(1);
    printf("Snippet D (constant):    steps=%ld -> O(1)\n", steps);

    recursive_calls = 0; (void)power_calls(10);
    printf("Snippet E (rec 2-branches): calls=%ld -> O(2^n)\n", recursive_calls);

    printf("\nOther classes: O(n log n) e.g. mergesort, O(n^3) e.g. naive matmul, O(n!) e.g. permute.\n");
    return 0;
}