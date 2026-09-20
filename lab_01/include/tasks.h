#ifndef TASKS_H
#define TASKS_H

#define TASK_LIST X(1) X(2) X(3) X(4)
#define X(num) void run_task##num(void);
TASK_LIST
#undef X

void run_tasks(int n);

#endif // TASKS_H
