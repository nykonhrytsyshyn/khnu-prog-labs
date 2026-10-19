#include "matrix.h"
#include "tasks.h"
#include "utils.h"

#include <stdio.h>

void run_task1(void) {
    Matrix a;
    long rows = 0;
    long cols = 0;
    long row_id = 0;
    long col_id = 0;

    puts("\n=== Task 1: delete the column of a chosen element ===\n");

    if (!read_matrix_size("A", &rows, &cols) ||
        !read_matrix("A", a, rows, cols)) {
        return;
    }

    puts("");
    print_matrix("A", a, rows, cols);
    puts("");

    if (!read_long_in_range(
            "Enter the row i of the element A[i][j]: ", 0, rows - 1, &row_id
        ) ||
        !read_long_in_range(
            "Enter the column j of the element A[i][j]: ", 0, cols - 1, &col_id
        )) {
        return;
    }

    printf(
        "\nChosen element: A[%ld][%ld] = %ld\n",
        row_id,
        col_id,
        a[row_id][col_id]
    );

    for (long i = 0; i < rows; ++i) {
        for (long j = col_id; j < cols - 1; ++j) {
            a[i][j] = a[i][j + 1];
        }
    }

    --cols;

    printf("Column %ld is deleted.\n\n", col_id);

    if (cols == 0) {
        puts("No columns are left, the matrix is empty.");
        return;
    }

    print_matrix("A", a, rows, cols);
}
