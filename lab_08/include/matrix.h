#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

#define MAX_MATRIX_DIM 15
#define MAX_ELEMENT_ABS 1000L
#define RANDOM_ABS 50

typedef long Matrix[MAX_MATRIX_DIM][MAX_MATRIX_DIM];

bool read_matrix_size(const char *name, long *out_rows, long *out_cols);
bool read_matrix(const char *name, Matrix matrix, long rows, long cols);
void print_matrix(const char *name, Matrix matrix, long rows, long cols);

bool write_matrix_file(const char *name, Matrix matrix, long rows, long cols);
bool read_matrix_file(const char *name, Matrix matrix, long rows, long cols);

#endif // MATRIX_H
