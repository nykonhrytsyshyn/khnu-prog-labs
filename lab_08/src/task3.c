#include "files.h"
#include "tasks.h"
#include "utils.h"

#include <stdio.h>

void run_task3(void) {
    char name[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];

    puts("\n=== Task 3: add a line to the beginning of a file ===\n");
    puts("A file that does not exist is created.\n");

    if (!read_file_name(name, sizeof(name)) ||
        !read_text_line("Enter the line S: ", line, sizeof(line))) {
        return;
    }

    if (!prepend_line(name, line)) {
        return;
    }

    printf("\nThe file \"%s\" now contains:\n", name);
    print_file(name);
}
