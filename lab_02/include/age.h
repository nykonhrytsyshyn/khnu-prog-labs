#ifndef AGE_H
#define AGE_H

enum {
    PRESCHOOLER_MAX_AGE = 6,
    SCHOOLBOY_MAX_AGE = 17,
    WORKER_MAX_AGE = 59,
    MAX_PLAUSIBLE_AGE = 130
};

typedef enum {
    AGE_GROUP_INVALID = -1,
    AGE_GROUP_PRESCHOOLER,
    AGE_GROUP_SCHOOLBOY,
    AGE_GROUP_WORKER,
    AGE_GROUP_PENSIONER
} AgeGroup;

AgeGroup classify_age(long age);

const char *age_group_to_str(AgeGroup group);

#endif // AGE_H
