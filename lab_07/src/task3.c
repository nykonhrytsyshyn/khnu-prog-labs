#define NON_ASCII_BIT 0x80

#include "tasks.h"
#include "utils.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    const char *start;
    size_t bytes;
    size_t length;
} Word;

static bool is_word_char(const unsigned char c) {
    return isalnum(c) || c >= NON_ASCII_BIT;
}

static bool next_word(const char **const position, Word *const out_word) {
    const char *p = *position;

    while (*p != '\0' && !is_word_char((unsigned char)*p)) {
        ++p;
    }

    const char *const start = p;

    while (*p != '\0' && is_word_char((unsigned char)*p)) {
        ++p;
    }

    *position = p;

    if (p == start) {
        return false;
    }

    out_word->start = start;
    out_word->bytes = (size_t)(p - start);
    out_word->length = text_length(start, out_word->bytes);

    return true;
}

static void print_word(const char *const title, const Word word) {
    printf(
        "%s: \"%.*s\", length %zu\n",
        title,
        (int)word.bytes,
        word.start,
        word.length
    );
}

void run_task3(void) {
    char text[MAX_LINE_SIZE];

    puts("\n=== Task 3: the shortest and the longest word ===\n");

    if (!read_text_line("Enter the text: ", text, sizeof(text))) {
        return;
    }

    const char *position = text;
    Word word;
    Word shortest = {0};
    Word longest = {0};
    long count = 0;

    while (next_word(&position, &word)) {
        if (count == 0 || word.length < shortest.length) {
            shortest = word;
        }

        if (count == 0 || word.length > longest.length) {
            longest = word;
        }

        ++count;
    }

    puts("");

    if (count == 0) {
        puts("There are no words in the text.");
        return;
    }

    print_word("Shortest word", shortest);
    print_word("Longest word", longest);
    printf("Number of words: %ld\n", count);
}
