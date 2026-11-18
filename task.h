#ifndef TASK_H
#define TASK_H

#define MAX_TASKS 20

#define WAITING 0
#define RUNNING 1
#define COMPLETED 2
#define FAILED 3

typedef struct {
    int task_id;
    char description[100];
    int duration;
    int memory;
    int status;
} Task;

#endif