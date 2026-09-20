#include "tasks.h"
#include "utils.h"

#include <math.h>
#include <stdio.h>

static double evaluate(const double a, const double b, const double x) {
    const double e1 = cbrt(fabs(a * x + b - 3.0));
    const double e2 = cbrt(fabs(b * x - b + 4.0));
    const double e3 = exp(-b * x / (a + 3.0));

    return (e1 * e1 + fabs(e2) + e3) / sqrt(fabs(e1 * e3)) - 1.0 / 3.0;
}

void run_task2(void) {
    double a = 0.0;
    double b = 0.0;
    double x = 0.0;

    puts(
        "\n=== Task 2: function F(E1, E2, E3) ===\n\n"
        "Formulas:\n"
        " - E1 = cbrt(|a*x + b - 3|)\n"
        " - E2 = cbrt(|b*x - b + 4|)\n"
        " - E3 = exp(-b*x / (a + 3))\n"
        " - F  = (E1^2 + |E2| + E3) / sqrt(|E1 * E3|) - 1/3\n"
    );

    if (!read_doubles("Enter a, b, x: ", 3, &a, &b, &x)) {
        puts("Invalid input.");
        return;
    }

    if (a == -3.0) {
        puts("Error: 'a = -3' leads to division by zero in E3.");
        return;
    }

    if (a * x + b - 3.0 == 0.0) {
        puts("Error: E1 is 0, leading to division by zero in F.");
        return;
    }

    printf("\na = %.4f, b = %.4f, x = %.4f\n", a, b, x);
    printf("F = %.4f\n", evaluate(a, b, x));
}
