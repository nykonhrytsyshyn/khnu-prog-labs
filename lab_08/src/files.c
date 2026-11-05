#include "files.h"

#include "utils.h"

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool read_file_name(char *const name, const size_t size) {
    while (true) {
        if (!read_text_line("Enter the file name: ", name, size)) {
            return false;
        }

        if (name[0] != '\0') {
            return true;
        }

        puts("Error: the file name must not be empty.");
    }
}

FILE *open_output_file(
    const char *const mode,
    char *const name,
    const size_t size
) {
    while (true) {
        if (!read_file_name(name, size)) {
            return NULL;
        }

        FILE *const existing = fopen(name, "r");

        if (existing != NULL) {
            fclose(existing);

            if (!confirm(
                    "The file exists and will be overwritten. Continue? "
                    "(y/N): ",
                    false
                )) {
                if (feof(stdin)) {
                    return NULL;
                }

                continue;
            }
        }

        FILE *const file = fopen(name, mode);

        if (file != NULL) {
            return file;
        }

        printf("Error: cannot open \"%s\": %s.\n", name, strerror(errno));
    }
}

void print_stream(FILE *const file) {
    char line[MAX_LINE_SIZE];

    while (fgets(line, sizeof(line), file) != NULL) {
        fputs(line, stdout);
    }
}

bool print_file(const char *const name) {
    FILE *const file = fopen(name, "r");

    if (file == NULL) {
        printf("Error: cannot open \"%s\": %s.\n", name, strerror(errno));
        return false;
    }

    print_stream(file);
    fclose(file);

    return true;
}

static bool copy_stream(FILE *const from, FILE *const to) {
    char buffer[COPY_BUFFER_SIZE];
    size_t count;

    while ((count = fread(buffer, 1, sizeof(buffer), from)) > 0) {
        if (fwrite(buffer, 1, count, to) != count) {
            return false;
        }
    }

    return !ferror(from);
}

static bool replace_file(
    const char *const temp_name,
    const char *const name,
    const bool existed
) {
    if (existed && remove(name) != 0) {
        printf("Error: cannot replace \"%s\": %s.\n", name, strerror(errno));
        remove(temp_name);
        return false;
    }

    if (rename(temp_name, name) != 0) {
        printf(
            "Error: cannot rename \"%s\" to \"%s\": %s.\n",
            temp_name,
            name,
            strerror(errno)
        );
        return false;
    }

    return true;
}

bool prepend_line(const char *const name, const char *const line) {
    char temp_name[MAX_LINE_SIZE + sizeof(TEMP_SUFFIX)];

    snprintf(temp_name, sizeof(temp_name), "%s%s", name, TEMP_SUFFIX);

    FILE *const source = fopen(name, "r");
    const bool existed = source != NULL;

    if (!existed && errno != ENOENT) {
        printf("Error: cannot open \"%s\": %s.\n", name, strerror(errno));
        return false;
    }

    FILE *const temp = fopen(temp_name, "w");

    if (temp == NULL) {
        printf(
            "Error: cannot create \"%s\": %s.\n", temp_name, strerror(errno)
        );

        if (existed) {
            fclose(source);
        }

        return false;
    }

    bool ok = fputs(line, temp) >= 0 && fputc('\n', temp) != EOF;

    if (existed) {
        ok = ok && copy_stream(source, temp);
        fclose(source);
    }

    if (fclose(temp) != 0) {
        ok = false;
    }

    if (!ok) {
        printf("Error: cannot write \"%s\".\n", temp_name);
        remove(temp_name);
        return false;
    }

    return replace_file(temp_name, name, existed);
}
