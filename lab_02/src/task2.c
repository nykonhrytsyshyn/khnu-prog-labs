#include "tasks.h"
#include "utils.h"

#include <stdio.h>

enum {
    PRESCHOOLER_MAX_AGE = 6,
    SCHOOLBOY_MAX_AGE = 17,
    WORKER_MAX_AGE = 59,
    MAX_PLAUSIBLE_AGE = 130
};

void run_task2(void) {
    long age = 0;

    puts("\n=== Task 2: age group classification ===\n");

    if (!read_long("Enter age (years): ", &age)) {
        puts("Invalid input.");
        return;
    }

    if (age < 0 || age > MAX_PLAUSIBLE_AGE) {
        printf("Error: age must be between 0 and %d.\n", MAX_PLAUSIBLE_AGE);
        return;
    }

    printf("\nAge: %ld\n", age);

    if (age <= PRESCHOOLER_MAX_AGE) {
        puts("Group: preschooler.");
    } else if (age <= SCHOOLBOY_MAX_AGE) {
        puts("Group: schoolboy.");
    } else if (age <= WORKER_MAX_AGE) {
        puts("Group: worker.");
    } else {
        puts("Group: pensioner.");
    }
}
