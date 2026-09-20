#include "tasks.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf(
        "====================================================\n"
        "  Laboratory work 1: Linear algorithms (variant 9)\n"
        "====================================================\n\n"
        "Enter task number (1-%d) or press Enter to run all tasks [ALL]: ",
        TASK_COUNT
    );

    char input[32] = "";
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\r\n")] = '\0';
    }

    char *end;
    const long task = strtol(input, &end, 10);
    int status = 0;

    if (input[0] == '\0') {
        run_all_tasks();
    } else if (*end == '\0' && task >= 1 && task <= TASK_COUNT) {
        run_task((int)task);
    } else {
        printf("Error: invalid task '%s'.\n", input);
        status = 1;
    }

    printf("\nPress Enter to exit...");
    getchar();

    return status;
}
