#ifndef LAB02_UTILS_H
#define LAB02_UTILS_H

#include <stdbool.h>
#include <stddef.h>

bool read_double(const char *prompt, double *out_value);
bool read_doubles(const char *prompt, size_t count, ...);
bool read_long(const char *prompt, long *out_value);

#endif // LAB02_UTILS_H
