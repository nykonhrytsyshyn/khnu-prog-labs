#include "matrix.h"
#include "tasks.h"

#include <stdio.h>

void run_task2(void) {
    Matrix a;
    long rows = 0;
    long cols = 0;

    puts("\n=== Task 2: mean of the elements and the smaller ones ===\n");

    if (!read_matrix_size("A", &rows, &cols) ||
        !read_matrix("A", a, rows, cols)) {
        return;
    }

    long sum = 0;

    for (long i = 0; i < rows; ++i) {
        for (long j = 0; j < cols; ++j) {
            sum += a[i][j];
        }
    }

    const double mean = (double)sum / (double)(rows * cols);
    int smaller_count = 0;

    for (long i = 0; i < rows; ++i) {
        for (long j = 0; j < cols; ++j) {
            if ((double)a[i][j] < mean) {
                ++smaller_count;
            }
        }
    }

    puts("");
    print_matrix("A", a, rows, cols);
    printf("\nArithmetic mean: %.4f\n", mean);
    printf("Number of elements smaller than the mean: %d\n", smaller_count);
}
