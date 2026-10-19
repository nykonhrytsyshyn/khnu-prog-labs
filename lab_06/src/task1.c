#include "matrix.h"
#include "tasks.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

#define RANDOM_MIN 1
#define RANDOM_MAX 50

static void fill_random(
    long a[][MAX_MATRIX_DIM],
    const long rows,
    const long cols
) {
    for (long i = 0; i < rows; ++i) {
        for (long j = 0; j < cols; ++j) {
            const int r = rand(); // NOLINT(*-msc50-cpp)
            a[i][j] = r % (RANDOM_MAX - RANDOM_MIN + 1) + RANDOM_MIN;
        }
    }
}

static long find_min(
    long a[][MAX_MATRIX_DIM],
    const long rows,
    const long cols
) {
    long min = a[0][0];

    for (long i = 0; i < rows; ++i) {
        for (long j = 0; j < cols; ++j) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
    }

    return min;
}

void run_task1(void) {
    Matrix a;
    long rows = 0;
    long cols = 0;

    puts("\n=== Task 1: minimum element of a random array ===\n");

    if (!read_matrix_size("the array", &rows, &cols)) {
        return;
    }

    fill_random(a, rows, cols);

    puts("");
    print_matrix("A", a, rows, cols);
    printf("\nMinimum element: %ld\n", find_min(a, rows, cols));
}
