#include "tasks.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf(
        "====================================================\n"
        "  Laboratory work 2: Branched algorithms (variant 9)\n"
        "====================================================\n\n"
        "Enter task number (1-%d) or press Enter to run all tasks [ALL]: ",
        TASK_COUNT
    );

    long task;
    int status = 0;

    if (!read_long("", &task)) {
        run_all_tasks();
    } else if (task >= 1 && task <= TASK_COUNT) {
        run_task((int)task);
    } else {
        printf("Error: invalid task '%ld'.\n", task);
        status = 1;
    }

    printf("\nPress Enter to exit...");
    getchar();

    return status;
}
