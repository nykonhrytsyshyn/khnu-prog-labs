#include "tasks.h"
#include "utils.h"

#include <math.h>
#include <stdio.h>

void run_task4(void) {
    double a = 0.0;
    double b = 0.0;
    double lower = 0.0;
    double upper = 0.0;
    long n = 0;

    puts("\n=== Task 4: tabulation of y = arctg(x) on [a; b] ===\n");

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

    if (!read_interval(
            "Enter the lower bound of y: ",
            "Enter the upper bound of y: ",
            &lower,
            &upper
        )) {
        return;
    }

    const double h = (b - a) / (double)n;
    double sum = 0.0;
    long count = 0;

    printf("\nh = (b - a) / N = %.6g\n\n", h);
    puts("   i |            x |        y");
    puts("-----+--------------+---------");

    for (long i = 0; i <= n; ++i) {
        const double x = a + (double)i * h;
        const double y = atan(x);

        printf("%4ld | %12.4f | %8.4f\n", i, x, y);

        if (y > lower && y < upper) {
            sum += y;
            ++count;
        }
    }

    puts("");

    if (count == 0) {
        printf("No values of y satisfy %g < y < %g.\n", lower, upper);
        return;
    }

    printf(
        "Arithmetic mean of y with %g < y < %g: %.4f (%ld values)\n",
        lower,
        upper,
        sum / (double)count,
        count
    );
}
