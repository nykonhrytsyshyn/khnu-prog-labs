#include "files.h"
#include "tasks.h"
#include "utils.h"

#include <ctype.h>
#include <stdio.h>

#define ALPHABET_SIZE 26

static size_t sort_letters(const char *const text, char *const out) {
    size_t counts[ALPHABET_SIZE][2] = {{0}};

    for (const char *p = text; *p != '\0'; ++p) {
        const unsigned char c = (unsigned char)*p;

        if (isupper(c)) {
            ++counts[c - 'A'][0];
        } else if (islower(c)) {
            ++counts[c - 'a'][1];
        }
    }

    size_t length = 0;

    for (int k = 0; k < ALPHABET_SIZE; ++k) {
        for (size_t i = 0; i < counts[k][0]; ++i) {
            out[length++] = (char)('A' + k);
        }

        for (size_t i = 0; i < counts[k][1]; ++i) {
            out[length++] = (char)('a' + k);
        }
    }

    out[length] = '\0';

    return length;
}

void run_task1(void) {
    char name[MAX_LINE_SIZE];
    char text[MAX_LINE_SIZE];
    char sorted[MAX_LINE_SIZE];

    puts(
        "\n=== Task 1: a sentence and its letters in alphabetical order ===\n"
    );

    FILE *const file = open_output_file("w+", name, sizeof(name));

    if (file == NULL) {
        return;
    }

    if (!read_text_line("Enter the sentence: ", text, sizeof(text))) {
        fclose(file);
        return;
    }

    const size_t count = sort_letters(text, sorted);

    if (fprintf(file, "%s\n%s\n", text, sorted) < 0 || fflush(file) != 0) {
        printf("Error: cannot write to \"%s\".\n", name);
        fclose(file);
        return;
    }

    rewind(file);

    printf("\nThe file \"%s\" contains:\n", name);
    print_stream(file);
    printf("\nNumber of letters: %zu\n", count);

    fclose(file);
}
