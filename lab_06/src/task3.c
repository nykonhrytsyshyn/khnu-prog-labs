#include "tasks.h"
#include "utils.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

typedef enum {
    CALC_OK,
    CALC_BAD_LOG_ARGUMENT,
    CALC_BAD_SQRT_ARGUMENT,
    CALC_ZERO_DENOMINATOR,
    CALC_NOT_FINITE
} CalcStatus;

static bool read_input(
    double *const x,
    double *const y,
    double *const a,
    double *const b,
    double *const j
) {
    return read_double_in_range(
               "Enter x: ", -MAX_INPUT_ABS, MAX_INPUT_ABS, x
           ) &&
           read_double_in_range(
               "Enter y: ", -MAX_INPUT_ABS, MAX_INPUT_ABS, y
           ) &&
           read_double_in_range(
               "Enter a: ", -MAX_INPUT_ABS, MAX_INPUT_ABS, a
           ) &&
           read_double_in_range(
               "Enter b: ", -MAX_INPUT_ABS, MAX_INPUT_ABS, b
           ) &&
           read_double_in_range("Enter j: ", -MAX_INPUT_ABS, MAX_INPUT_ABS, j);
}

static CalcStatus calculate_z(
    const double x,
    const double y,
    const double a,
    const double b,
    const double j,
    double *const out_z
) {
    if (y == 0.0 || x / y <= 0.0) {
        return CALC_BAD_LOG_ARGUMENT;
    }

    const double radicand = a * x * x + b;

    if (radicand < 0.0) {
        return CALC_BAD_SQRT_ARGUMENT;
    }

    const double denominator = exp(-x / y) * sin(x * x + y);

    if (denominator == 0.0) {
        return CALC_ZERO_DENOMINATOR;
    }

    const double z = (log(x / y) + sqrt(radicand) + j) / denominator;

    if (!isfinite(z)) {
        return CALC_NOT_FINITE;
    }

    *out_z = z;

    return CALC_OK;
}

static void print_error(const CalcStatus status) {
    switch (status) {
        case CALC_BAD_LOG_ARGUMENT:
            puts(
                "Error: x / y must be positive (y != 0), ln(x / y) is "
                "undefined."
            );
            break;
        case CALC_BAD_SQRT_ARGUMENT:
            puts(
                "Error: a * x^2 + b must not be negative under the square root."
            );
            break;
        case CALC_ZERO_DENOMINATOR:
            puts("Error: the denominator e^(-x / y) * sin(x^2 + y) is zero.");
            break;
        case CALC_NOT_FINITE:
            puts("Error: the result is too large to be represented.");
            break;
        case CALC_OK: break;
    }
}

static void print_result(
    const double x,
    const double y,
    const double a,
    const double b,
    const double j,
    const double z
) {
    printf("\nx = %g, y = %g, a = %g, b = %g, j = %g\n", x, y, a, b, j);
    printf("Z = %.10g\n", z);
}

void run_task3(void) {
    double x = 0.0;
    double y = 0.0;
    double a = 0.0;
    double b = 0.0;
    double j = 0.0;
    double z = 0.0;

    puts("\n=== Task 3: value of a function at a point ===\n");
    puts("        ln(x / y) + sqrt(a * x^2 + b) + j");
    puts("Z = -------------------------------------");
    puts("          e^(-x / y) * sin(x^2 + y)\n");

    while (true) {
        if (!read_input(&x, &y, &a, &b, &j)) {
            return;
        }

        const CalcStatus status = calculate_z(x, y, a, b, j, &z);

        if (status == CALC_OK) {
            break;
        }

        print_error(status);
        puts("Please enter the values again.\n");
    }

    print_result(x, y, a, b, j, z);
}
