#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

/* Max size of a prompt for user input */
#define PROMPT_SIZE 96

/* Max number of rows and columns of a matrix */
#define MAX_MATRIX_DIM 15

/* Max absolute value of a matrix element */
#define MAX_ELEMENT_ABS 1000L

/* Elements of a randomly filled matrix are from -RANDOM_ABS to RANDOM_ABS */
#define RANDOM_ABS 50

typedef long Matrix[MAX_MATRIX_DIM][MAX_MATRIX_DIM];

bool read_matrix_size(const char *name, long *out_rows, long *out_cols);
bool read_matrix(const char *name, Matrix matrix, long rows, long cols);
void print_matrix(const char *name, Matrix matrix, long rows, long cols);

#endif // MATRIX_H
