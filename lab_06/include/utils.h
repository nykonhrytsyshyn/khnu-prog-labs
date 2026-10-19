#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>

// Max absolute value of a real number accepted from the keyboard
#define MAX_INPUT_ABS 1e6

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
bool read_double_in_range(
    const char *prompt,
    double min,
    double max,
    double *out_value
);

bool confirm(const char *prompt, bool default_answer);

#endif // UTILS_H
