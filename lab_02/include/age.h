#ifndef AGE_H
#define AGE_H
#include <stddef.h>

typedef enum {
    AGE_GROUP_INVALID = -1,
    AGE_GROUP_PRESCHOOLER,
    AGE_GROUP_SCHOOLBOY,
    AGE_GROUP_WORKER,
    AGE_GROUP_PENSIONER
} AgeGroup;

typedef struct {
    long max_age;
    AgeGroup group;
    const char *name;
} AgeGroupRule;

enum { MIN_PLAUSIBLE_AGE = 0, MAX_PLAUSIBLE_AGE = 130 };

const AgeGroupRule AGE_RULES[] = {
    {.max_age = 6, .group = AGE_GROUP_PRESCHOOLER, .name = "preschooler"},
    {.max_age = 17, .group = AGE_GROUP_SCHOOLBOY, .name = "schoolboy"},
    {.max_age = 59, .group = AGE_GROUP_WORKER, .name = "worker"},
    {.max_age = 130, .group = AGE_GROUP_PENSIONER, .name = "pensioner"},
};

const size_t RULES_COUNT = sizeof(AGE_RULES) / sizeof(AGE_RULES[0]);

AgeGroup classify_age(long age);
const char *age_group_to_str(AgeGroup group);

#endif // AGE_H
