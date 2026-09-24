#ifndef LAB02_TASKS_H
#define LAB02_TASKS_H

#define TASK_LIST X(1) X(2) X(3) X(4)

#define X(num) void run_task##num(void);
TASK_LIST
#undef X

#define X(num) +1
enum { TASK_COUNT = 0 TASK_LIST };
#undef X

// Runs task `n`, which must be in the range 1..TASK_COUNT.
void run_task(int n);
void run_all_tasks(void);

#endif // LAB02_TASKS_H
