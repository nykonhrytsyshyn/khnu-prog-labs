#include "tasks.h"
#include "utils.h"

#include <math.h>
#include <stdio.h>

static double horner_evaluate(
    const double *coefficients,
    const int degree,
    const double x
) {
    double result = coefficients[0];

    for (int i = 1; i <= degree; ++i) {
        result = result * x + coefficients[i];
    }

    return result;
}

static double evaluate(const double x) {
    const double coefficients[] = {-3.7, 0.0, 0.0, 4.1, 0.0, -2.1, 1.2};
    const int degree = 6;
    const double u = 1.0 + sqrt(x);

    return horner_evaluate(coefficients, degree, u);
}

void run_task3(void) {
    double x = 0.0;

    puts(
        "\n=== Task 3: Horner's method ===\n\n"
        "Formula: c = -3.7*(1 + sqrt(x))^6 + 4.1*(1 + sqrt(x))^3 - 2.1*(1 + "
        "sqrt(x)) + 1.2\n"
    );

    if (!read_double("Enter x: ", &x)) {
        puts("Invalid input.");
        return;
    }

    if (x < 0.0) {
        puts("x must be >= 0 - skipping.");
        return;
    }

    printf("\nx = %.4f\n", x);
    printf("c = %.4f\n", evaluate(x));
}
