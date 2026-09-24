#include "tasks.h"
#include "utils.h"

#include <stdio.h>

static const char *get_point_location(const double x, const double y) {
    const int x_is_zero = x == 0.0;
    const int y_is_zero = y == 0.0;

    if (x_is_zero && y_is_zero) {
        return "The point is the origin.";
    }

    if (x_is_zero) {
        return "The point lies on the Y axis.";
    }

    if (y_is_zero) {
        return "The point lies on the X axis.";
    }

    return x > 0.0   ? y > 0.0 ? "The point belongs to quadrant I."
                               : "The point belongs to quadrant IV."
           : y > 0.0 ? "The point belongs to quadrant II."
                     : "The point belongs to quadrant III.";
}

void run_task1(void) {
    double x = 0.0;
    double y = 0.0;

    puts("\n=== Task 1: quadrant of a point (x, y) ===\n");

    if (!read_doubles("Enter x, y: ", 2, &x, &y)) {
        puts("Invalid input.");
        return;
    }

    printf("\nPoint: (%.4f, %.4f)\n", x, y);
    puts(get_point_location(x, y));
}
