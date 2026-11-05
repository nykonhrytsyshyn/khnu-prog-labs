#define REPLACED_SYMBOLS "+-*"

#include "tasks.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>

static long replace_symbols(char *const text) {
    long count = 0;

    for (char *p = text; *p != '\0'; ++p) {
        if (strchr(REPLACED_SYMBOLS, *p) != NULL) {
            *p = ' ';
            ++count;
        }
    }

    return count;
}

void run_task1(void) {
    char text[MAX_LINE_SIZE];

    puts(
        "\n=== Task 1: replace the symbols \"+\", \"-\", \"*\" with spaces "
        "===\n"
    );

    if (!read_text_line("Enter the line: ", text, sizeof(text))) {
        return;
    }

    const long count = replace_symbols(text);

    printf("\nResult: \"%s\"\n", text);
    printf("Replaced symbols: %ld\n", count);
}
