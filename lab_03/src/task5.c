#define MAX_ABS_X 1.0

#define MIN_EPSILON 1e-8
#define MAX_EPSILON 1.0

#define MIN_START_INDEX 0
#define MAX_START_INDEX 1000

#include "tasks.h"
#include "utils.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

static bool read_x(const long k, double *const out_x) {
    while (true) {
        if (!read_double_in_range(
                "Enter x (|x| <= 1): ", -MAX_ABS_X, MAX_ABS_X, out_x
            )) {
            return false;
        }

        if (k != 0 || *out_x != 0.0) {
            return true;
        }

        puts("Error: x must not be 0 when k = 0 (the first term is 1 / x).");
    }
}

void run_task5(void) {
    long k = 0;
    double x = 0.0;
    double epsilon = 0.0;

    puts("\n=== Task 5: sum of a series with a given accuracy ===\n");
    puts("a_n = (-1)^(n-1) * x^(2n-1) / (2n-1), sum over n = k, k+1, ...\n");

    if (!read_long_in_range(
            "Enter the first index k: ", MIN_START_INDEX, MAX_START_INDEX, &k
        )) {
        return;
    }

    if (!read_x(k, &x)) {
        return;
    }

    if (!read_double_in_range(
            "Enter the accuracy epsilon: ", MIN_EPSILON, MAX_EPSILON, &epsilon
        )) {
        return;
    }

    const double x_squared = x * x;
    double sum = 0.0;
    long terms = 0;

    double power = pow(x, 2 * k - 1);      // x^(2n-1)
    double sign = k % 2 == 0 ? -1.0 : 1.0; // (-1)^(n-1)

    for (long n = k;; ++n) {
        const double term = sign * power / (double)(2 * n - 1);

        if (fabs(term) < epsilon) {
            break;
        }

        sum += term;
        sign = -sign;
        power *= x_squared;
        ++terms;
    }

    printf("\nk = %ld, x = %g, epsilon = %g\n", k, x, epsilon);
    printf("Sum of the series: %.6f\n", sum);
    printf("Number of summed terms: %ld\n", terms);

    if (k <= 1) {
        printf(
            "Check, %s: %.6f\n",
            k == 0 ? "arctg(x) + 1/x" : "arctg(x)",
            atan(x) + (k == 0 ? 1.0 / x : 0.0)
        );
    }
}
