#include "tasks.h"

#include <stdio.h>

typedef void (*task_fn)(void);

static const task_fn TASKS[] = {
#define X(num) run_task##num,
    TASK_LIST
#undef X
};
static const int TOTAL_TASKS = sizeof(TASKS) / sizeof(TASKS[0]);

void run_tasks(const int n) {
    if (n == -1) {
        for (int i = 0; i < TOTAL_TASKS; i++) {
            TASKS[i]();
        }
    } else if (n >= 1 && n <= TOTAL_TASKS) {
        TASKS[n - 1]();
    } else {
        printf(
            "Error: Task %d is out of range. Available tasks: 1-%d.\n",
            n,
            TOTAL_TASKS
        );
    }
}
