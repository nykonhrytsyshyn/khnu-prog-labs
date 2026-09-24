#include "utils.h"

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool is_buffer_empty(const char *ptr) {
    while (*ptr != '\0') {
        if (!isspace((unsigned char)*ptr)) {
            return false;
        }

        ptr++;
    }

    return true;
}

bool read_double(const char *prompt, double *out_value) {
    return read_doubles(prompt, 1, out_value);
}

bool read_doubles(const char *prompt, const size_t count, ...) {
    if (count == 0) {
        return false;
    }

    if (prompt != NULL) {
        printf("%s", prompt);
    }

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return false;
    }

    buffer[strcspn(buffer, "\r\n")] = '\0';

    va_list args;
    va_start(args, count);

    const char *ptr = buffer;

    for (size_t i = 0; i < count; ++i) {
        double *out = va_arg(args, double *);

        if (out == NULL) {
            va_end(args);
            return false;
        }

        char *endptr;
        errno = 0;
        *out = strtod(ptr, &endptr);

        if (ptr == endptr || errno != 0) {
            va_end(args);

            return false;
        }

        ptr = endptr;
    }

    va_end(args);

    return is_buffer_empty(ptr);
}

bool read_long(const char *prompt, long *out_value) {
    if (out_value == NULL) {
        return false;
    }

    if (prompt != NULL) {
        printf("%s", prompt);
    }

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return false;
    }

    buffer[strcspn(buffer, "\r\n")] = '\0';

    char *endptr;
    errno = 0;
    const long value = strtol(buffer, &endptr, 10);

    if (buffer == endptr || errno != 0) {
        return false;
    }

    *out_value = value;

    return is_buffer_empty(endptr);
}
