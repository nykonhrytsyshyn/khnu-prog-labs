#include "age.h"
#include "tasks.h"
#include "utils.h"

#include <stdio.h>

AgeGroup classify_age(const long age) {
    if (age < MIN_PLAUSIBLE_AGE || age > MAX_PLAUSIBLE_AGE) {
        return AGE_GROUP_INVALID;
    }

    for (size_t i = 0; i < RULES_COUNT; ++i) {
        const AgeGroupRule rule = AGE_RULES[i];

        if (age <= rule.max_age) {
            return rule.group;
        }
    }

    return AGE_GROUP_INVALID;
}

const char *age_group_to_str(const AgeGroup group) {
    for (size_t i = 0; i < RULES_COUNT; ++i) {
        const AgeGroupRule rule = AGE_RULES[i];

        if (group == rule.group) {
            return rule.name;
        }
    }

    return "invalid";
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
        printf(
            "Error: age must be between %d and %d.\n",
            MIN_PLAUSIBLE_AGE,
            MAX_PLAUSIBLE_AGE
        );
        return;
    }

    printf("\nAge: %ld\n", age);
    printf("Group: %s.\n", age_group_to_str(group));
}
