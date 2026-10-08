#include "tasks.h"
#include "utils.h"

#include <stdbool.h>
#include <stdio.h>

#define PROMPT_SIZE 96

int main(void) {
    puts(
        "========================================================\n"
        "  Laboratory work 4: One-dimensional arrays (variant 9)\n"
        "========================================================\n"
    );

    char prompt[PROMPT_SIZE];
    snprintf(
        prompt,
        sizeof(prompt),
        "Enter task number (1-%d) or press Enter to run all tasks [ALL]: ",
        TASK_COUNT
    );

    long task = 0;
    bool provided = false;

    if (!read_optional_long_in_range(prompt, 1, TASK_COUNT, &task, &provided)) {
        return 1;
    }

    if (provided) {
        run_task((int)task);
    } else {
        run_all_tasks();
    }

    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}
