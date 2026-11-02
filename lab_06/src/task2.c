#include "tasks.h"
#include "utils.h"

#include <math.h>
#include <stdio.h>

#define BASE_ARGUMENT 6
#define BASE_VALUE 3.0
#define DIVISOR 3.0
#define MAX_ARGUMENT 500

static double f(const long x) {
    if (x == BASE_ARGUMENT) {
        return BASE_VALUE;
    }

    return f(x - 1) / DIVISOR;
}

void run_task2(void) {
    long x = 0;

    puts("\n=== Task 2: recursive function ===\n");
    puts("f(x) = 3 for x = 6,  f(x) = f(x - 1) / 3 for x > 6\n");

    if (!read_long_in_range(
            "Enter a natural x (x >= 6): ", BASE_ARGUMENT, MAX_ARGUMENT, &x
        )) {
        return;
    }

    printf("\nf(%ld) = %.10g\n", x, f(x));

    // f(x) = 3 / 3^(x - 6) = 3^(7 - x)
    printf("Check, 3^(7 - x): %.10g\n", pow(BASE_VALUE, 7 - x));
}
