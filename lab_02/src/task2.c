#include "age.h"
#include "tasks.h"
#include "utils.h"

#include <stdio.h>

AgeGroup classify_age(const long age) {
    return age < 0 || age > MAX_PLAUSIBLE_AGE ? AGE_GROUP_INVALID
           : age <= PRESCHOOLER_MAX_AGE       ? AGE_GROUP_PRESCHOOLER
           : age <= SCHOOLBOY_MAX_AGE         ? AGE_GROUP_SCHOOLBOY
           : age <= WORKER_MAX_AGE            ? AGE_GROUP_WORKER
                                              : AGE_GROUP_PENSIONER;
}

const char *age_group_to_str(const AgeGroup group) {
    switch (group) {
        case AGE_GROUP_PRESCHOOLER: return "preschooler";
        case AGE_GROUP_SCHOOLBOY: return "schoolboy";
        case AGE_GROUP_WORKER: return "worker";
        case AGE_GROUP_PENSIONER: return "pensioner";
        default: return "unknown";
    }
}

void run_task2(void) {
    long age = 0;

    puts("\n=== Task 2: age group classification ===\n");

    if (!read_long("Enter age (years): ", &age)) {
        puts("Invalid input.");
        return;
    }

    const AgeGroup group = classify_age(age);

    if (group == AGE_GROUP_INVALID) {
        printf("Error: age must be between 0 and %d.\n", MAX_PLAUSIBLE_AGE);
        return;
    }

    printf("\nAge: %ld\n", age);
    printf("Group: %s.\n", age_group_to_str(group));
}
