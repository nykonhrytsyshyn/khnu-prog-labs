#include "files.h"
#include "matrix.h"
#include "tasks.h"
#include "utils.h"

#include <stdio.h>

static long print_negatives(
    FILE *const file,
    Matrix matrix,
    const long rows,
    const long cols
) {
    long count = 0;

    for (long i = 0; i < rows; ++i) {
        for (long j = 0; j < cols; ++j) {
            if (matrix[i][j] < 0) {
                printf("A[%ld][%ld] = %ld\n", i, j, matrix[i][j]);
                fprintf(file, "%ld, %ld: %ld\n", i, j, matrix[i][j]);
                ++count;
            }
        }
    }

    return count;
}

void run_task2(void) {
    Matrix a;
    Matrix b;
    long rows = 0;
    long cols = 0;
    char name[MAX_LINE_SIZE];

    puts("\n=== Task 2: negative elements of a matrix in a file ===\n");

    if (!read_matrix_size("the matrix", &rows, &cols) ||
        !read_matrix("A", a, rows, cols)) {
        return;
    }

    FILE *const created = open_output_file("w", name, sizeof(name));

    if (created == NULL) {
        return;
    }

    fclose(created);

    if (!write_matrix_file(name, a, rows, cols) ||
        !read_matrix_file(name, b, rows, cols)) {
        printf("Error: cannot write or read the file \"%s\".\n", name);
        return;
    }

    printf("\nThe matrix is written to \"%s\" and read back:\n", name);
    print_matrix("A", b, rows, cols);

    FILE *const file = fopen(name, "a");

    if (file == NULL) {
        printf("Error: cannot open \"%s\" for appending.\n", name);
        return;
    }

    puts("\nNegative elements, A[row][column] = value:");
    fputs("\nNegative elements (row, column: value):\n", file);

    const long count = print_negatives(file, b, rows, cols);

    if (count == 0) {
        puts("none");
        fputs("none\n", file);
    }

    if (fclose(file) != 0) {
        printf("Error: cannot write to \"%s\".\n", name);
        return;
    }

    printf("\nNegative elements: %ld (they are added to the file)\n", count);
}
