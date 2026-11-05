#define WORD_DELIMITERS ":;- "

#include "tasks.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>

void run_task2(void) {
    char text[MAX_LINE_SIZE];
    char work[MAX_LINE_SIZE];

    puts(
        "\n=== Task 2: words separated by \":\", \";\", \"-\" and a space ===\n"
    );

    if (!read_text_line("Enter the text: ", text, sizeof(text))) {
        return;
    }

    snprintf(work, sizeof(work), "%s", text);
    puts("\nWords:");

    long count = 0;

    for (const char *word = strtok(work, WORD_DELIMITERS); word != NULL;
         word = strtok(NULL, WORD_DELIMITERS)) {
        ++count;
        printf("%ld) %s\n", count, word);
    }

    if (count == 0) {
        puts("(none)");
    }

    printf("\nNumber of words: %ld\n", count);
}
