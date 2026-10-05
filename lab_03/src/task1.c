#include "tasks.h"
#include "utils.h"

#include <stdio.h>

void run_task1(void) {
    double a = 0.0;
    double b = 0.0;
    long n = 0;

    puts("\n=== Task 1: tabulation of y = x(5 + x) on [a; b] ===\n");

    if (!read_interval(
            "Enter the interval start a: ", "Enter the interval end b: ", &a, &b
        )) {
        return;
    }

    if (!read_long_in_range(
            "Enter the number of steps N: ", 1, MAX_STEPS, &n
        )) {
        return;
    }

    const double h = (b - a) / (double)n;

    printf("\nh = (b - a) / N = %.6g\n\n", h);
    puts("   i |            x |             y");
    puts("-----+--------------+--------------");

    for (long i = 0; i <= n; ++i) {
        const double x = a + (double)i * h;
        const double y = x * (5.0 + x);

        printf("%4ld | %12.4f | %13.4f\n", i, x, y);
    }
}
