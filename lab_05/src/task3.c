#include "matrix.h"
#include "tasks.h"
#include "utils.h"

#include <stdio.h>

void run_task3(void) {
    Matrix a;
    Matrix b;
    Matrix c;

    long a_rows = 0;
    long a_cols = 0;
    long b_cols = 0;

    puts("\n=== Task 3: product of matrices C = A x B ===\n");

    if (!read_matrix_size("A", &a_rows, &a_cols) ||
        !read_matrix("A", a, a_rows, a_cols)) {
        return;
    }

    const long b_rows = a_cols;

    printf("\nB must have %ld rows (the number of columns of A).\n", b_rows);

    if (!read_long_in_range(
            "Enter the number of columns of B: ", 1, MAX_MATRIX_DIM, &b_cols
        ) ||
        !read_matrix("B", b, b_rows, b_cols)) {
        return;
    }

    for (long i = 0; i < a_rows; ++i) {
        for (long j = 0; j < b_cols; ++j) {
            c[i][j] = 0;

            for (long k = 0; k < a_cols; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    puts("");
    print_matrix("A", a, a_rows, a_cols);
    puts("");
    print_matrix("B", b, b_rows, b_cols);
    puts("");
    print_matrix("C", c, a_rows, b_cols);
}
