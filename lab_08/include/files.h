#ifndef FILES_H
#define FILES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define COPY_BUFFER_SIZE 1024
#define TEMP_SUFFIX ".tmp"

bool read_file_name(char *name, size_t size);
FILE *open_output_file(const char *mode, char *name, size_t size);

void print_stream(FILE *file);
bool print_file(const char *name);

bool prepend_line(const char *name, const char *line);

#endif // FILES_H
