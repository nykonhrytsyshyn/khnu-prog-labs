#include "matrix.h"

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool read_matrix_size(
    const char *const name,
    long *const out_rows,
    long *const out_cols
) {
    char prompt[PROMPT_SIZE];

    snprintf(prompt, sizeof(prompt), "Enter the number of rows of %s: ", name);

    if (!read_long_in_range(prompt, 1, MAX_MATRIX_DIM, out_rows)) {
        return false;
    }

    snprintf(
        prompt, sizeof(prompt), "Enter the number of columns of %s: ", name
    );

    return read_long_in_range(prompt, 1, MAX_MATRIX_DIM, out_cols);
}

bool read_matrix(
    const char *const name,
    Matrix matrix,
    const long rows,
    const long cols
) {
    char prompt[PROMPT_SIZE];

    snprintf(
        prompt, sizeof(prompt), "Fill %s with random numbers? (Y/n): ", name
    );

    const bool random_fill = confirm(prompt, true);

    if (feof(stdin)) {
        return false;
    }

    for (long i = 0; i < rows; ++i) {
        for (long j = 0; j < cols; ++j) {
            if (random_fill) {
                const int r = rand(); // NOLINT(*-msc50-cpp)
                matrix[i][j] = r % (2 * RANDOM_ABS + 1) - RANDOM_ABS;
                continue;
            }

            snprintf(prompt, sizeof(prompt), "%s[%ld][%ld] = ", name, i, j);

            if (!read_long_in_range(
                    prompt, -MAX_ELEMENT_ABS, MAX_ELEMENT_ABS, &matrix[i][j]
                )) {
                return false;
            }
        }
    }

    return true;
}

void print_matrix(
    const char *const name,
    Matrix matrix,
    const long rows,
    const long cols
) {
    char text[32];
    size_t width = 1;

    for (long i = 0; i < rows; ++i) {
        for (long j = 0; j < cols; ++j) {
            snprintf(text, sizeof(text), "%ld", matrix[i][j]);

            if (strlen(text) > width) {
                width = strlen(text);
            }
        }
    }

    printf("%s (%ld x %ld) =\n", name, rows, cols);

    for (long i = 0; i < rows; ++i) {
        for (long j = 0; j < cols; ++j) {
            printf(j == 0 ? "%*ld" : " %*ld", (int)width, matrix[i][j]);
        }

        puts("");
    }
}
