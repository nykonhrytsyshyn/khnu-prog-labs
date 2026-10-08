#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_ARRAY_SIZE 100
#define MAX_ELEMENT_ABS 1000000L

bool read_double(const char *prompt, double *out_value);
bool read_doubles(const char *prompt, size_t count, ...);
bool read_long(const char *prompt, long *out_value);
bool read_longs(const char *prompt, size_t count, ...);

bool read_long_in_range(
    const char *prompt,
    long min,
    long max,
    long *out_value
);
bool read_optional_long_in_range(
    const char *prompt,
    long min,
    long max,
    long *out_value,
    bool *out_provided
);

bool read_sequence(const char *name, long *array, long *out_count);
void print_sequence(const char *name, const long *array, long count);

bool confirm(const char *prompt, bool default_answer);

#endif // UTILS_H
