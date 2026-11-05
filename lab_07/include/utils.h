#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_LINE_SIZE 256

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

bool read_text_line(const char *prompt, char *buffer, size_t size);
size_t text_length(const char *text, size_t bytes);

bool confirm(const char *prompt, bool default_answer);

#endif // UTILS_H
