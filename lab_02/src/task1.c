#include "tasks.h"
#include "utils.h"

#include <stdio.h>

void run_task1(void) {
    double x = 0.0;
    double y = 0.0;

    puts("\n=== Task 1: quadrant of a point (x, y) ===\n");

    if (!read_doubles("Enter x, y: ", 2, &x, &y)) {
        puts("Invalid input.");
        return;
    }

    printf("\nPoint: (%.4f, %.4f)\n", x, y);

    if (x == 0.0 && y == 0.0) {
        puts("The point is the origin.");
    } else if (x == 0.0) {
        puts("The point lies on the Y axis.");
    } else if (y == 0.0) {
        puts("The point lies on the X axis.");
    } else if (x > 0.0 && y > 0.0) {
        puts("The point belongs to quadrant I.");
    } else if (x < 0.0 && y > 0.0) {
        puts("The point belongs to quadrant II.");
    } else if (x < 0.0 && y < 0.0) {
        puts("The point belongs to quadrant III.");
    } else {
        puts("The point belongs to quadrant IV.");
    }
}
