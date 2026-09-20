#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>

bool read_double(const char *prompt, double *out_value);
bool read_doubles(const char *prompt, size_t count, ...);

#endif // UTILS_H

#ifndef PI
#define PI 3.14159265358979323846
#endif // PI
