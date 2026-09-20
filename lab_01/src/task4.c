#include "tasks.h"
#include "utils.h"

#include <math.h>
#include <stdio.h>

void run_task4(void) {
    double coords[4] = {0.0};

    puts("\n=== Task 4: Area of an axis-aligned rectangle ===\n");

    if (!read_doubles(
            "Enter x1 y1 x2 y2: ",
            4,
            &coords[0],
            &coords[1],
            &coords[2],
            &coords[3]
        )) {
        puts("Invalid input.");
        return;
    }

    const double x1 = coords[0];
    const double y1 = coords[1];
    const double x2 = coords[2];
    const double y2 = coords[3];

    const double width = fabs(x2 - x1);
    const double height = fabs(y2 - y1);
    const double area = width * height;

    if (area == 0.0) {
        puts(
            "Warning: Area is 0.0 (the points form a line segment or a point)."
        );
    }

    printf("\nCorners:\n");
    printf(" - 1st corner: (%.4f, %.4f)\n", x1, y1);
    printf(" - 2nd corner: (%.4f, %.4f)\n", x2, y2);

    printf("\nDimensions:\n");
    printf(" - Width: %.4f\n", width);
    printf(" - Height: %.4f\n", height);

    printf("\nArea: %.4f\n", area);
}
