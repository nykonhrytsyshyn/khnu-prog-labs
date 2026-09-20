#include "tasks.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int status = 0;

    printf(
        "====================================================\n"
        "  Laboratory work 1: Linear algorithms (variant 9)\n"
        "====================================================\n\n"
        "Enter task number (1-4) or press Enter to run all tasks [ALL]: "
    );

    char buffer[32];

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        run_tasks(-1);
    } else {
        buffer[strcspn(buffer, "\r\n")] = '\0';

        if (buffer[0] == '\0') {
            puts("Running all tasks...");
            run_tasks(-1);
        } else {
            char *endptr;
            const long task = strtol(buffer, &endptr, 10);

            if (*endptr != '\0') {
                printf(
                    "Error: Invalid input '%s'. Expected a number from 1 to "
                    "4 or Enter.\n",
                    buffer
                );
                status = 1;
            } else {
                run_tasks((int)task);
            }
        }
    }

    printf("\nPress Enter to exit...");
    getchar();

    return status;
}
