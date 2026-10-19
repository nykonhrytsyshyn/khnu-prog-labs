#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

/* Max size of a prompt for user input */
#define PROMPT_SIZE 96

/* Max number of rows and columns of a matrix */
#define MAX_MATRIX_DIM 15

typedef long Matrix[MAX_MATRIX_DIM][MAX_MATRIX_DIM];

bool read_matrix_size(const char *name, long *out_rows, long *out_cols);
void print_matrix(const char *name, Matrix matrix, long rows, long cols);

#endif // MATRIX_H
