#include "tasks.h"
#include "utils.h"

#include <math.h>
#include <stdio.h>

static double triangle_angle_gamma_deg(
    const double a,
    const double b,
    const double c
) {
    const double cos_gamma = (a * a + b * b - c * c) / (2.0 * a * b);
    const double gamma_rad = acos(cos_gamma);

    return gamma_rad * 180.0 / PI;
}

static double triangle_bisector_gamma(
    const double a,
    const double b,
    const double c
) {
    const double cos_gamma = (a * a + b * b - c * c) / (2.0 * a * b);
    const double gamma_rad = acos(cos_gamma);

    return 2.0 * a * b * cos(gamma_rad / 2.0) / (a + b);
}

void run_task1(void) {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    puts("\n=== Task 1: triangle - angle gamma and bisector w ===\n");

    if (!read_doubles("Enter sides a, b, c: ", 3, &a, &b, &c)) {
        puts("Invalid input.");
        return;
    }

    printf("\na = %.4f, b = %.4f, c = %.4f\n", a, b, c);
    printf("Angle gamma: %.4f deg\n", triangle_angle_gamma_deg(a, b, c));
    printf("Bisector w_g: %.4f\n", triangle_bisector_gamma(a, b, c));
}
