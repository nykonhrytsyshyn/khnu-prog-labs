#include "tasks.h"
#include "utils.h"

#include <stdio.h>

// Table 2.1, variant 4:
//   y = -5x + 2       for x < 0
//   y = x^3 / 0.5     for x >= 0
static double piecewise_function(const double x) {
    if (x < 0.0) {
        return -5.0 * x + 2.0;
    }

    return x * x * x / 0.5;
}

void run_task3(void) {
    double x = 0.0;

    puts("\n=== Task 3: piecewise function (Table 2.1, variant 4) ===\n");
    puts("Formula: y = -5x + 2 for x < 0, y = x^3 / 0.5 for x >= 0");

    if (!read_double("Enter x: ", &x)) {
        puts("Invalid input.");
        return;
    }

    const double y = piecewise_function(x);

    printf("\nx = %.4f\n", x);
    printf("Branch used: %s\n", x < 0.0 ? "y = -5x + 2" : "y = x^3 / 0.5");
    printf("y = %.4f\n", y);
}
