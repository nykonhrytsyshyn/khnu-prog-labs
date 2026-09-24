#include "tasks.h"
#include "utils.h"

#include <stdio.h>

typedef struct {
    double value;
    const char *formula;
} Result;

static Result calculate_piecewise(const double x) {
    return x < 0.0
               ? (Result){.value = -5.0 * x + 2.0, .formula = "y = -5x + 2"}
               : (Result){.value = 2.0 * x * x * x, .formula = "y = x^3 / 0.5"};
}

void run_task3(void) {
    double x = 0.0;

    puts("\n=== Task 3: piecewise function (Table 2.1, variant 4) ===\n");
    puts("Formula: y = -5x + 2 for x < 0, y = x^3 / 0.5 for x >= 0");

    if (!read_double("Enter x: ", &x)) {
        puts("Invalid input.");
        return;
    }

    const Result result = calculate_piecewise(x);

    printf("\nx = %.4f\n", x);
    printf("Branch used: %s\n", result.formula);
    printf("y = %.4f\n", result.value);
}
