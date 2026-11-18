#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

int main() {

    printf("==============================\n");
    printf("         TASKFLOW OS          \n");
    printf("==============================\n");

    Task tasks[MAX_TASKS];
    int task_count;

    printf("\nHow many tasks do you want to add? ");

    if (scanf("%d", &task_count) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (task_count < 1 || task_count > MAX_TASKS) {
        printf("Please enter a number between 1 and %d.\n", MAX_TASKS);
        return 1;
    }

    for (int i = 0; i < task_count; i++) {

        printf("\n--- Task %d ---\n", i + 1);

        printf("Task ID: ");
        if (scanf("%d", &tasks[i].task_id) != 1) {
            printf("Invalid task ID!\n");
            return 1;
        }

        printf("Duration (seconds): ");
        if (scanf("%d", &tasks[i].duration) != 1 ||
            tasks[i].duration < 0) {
            printf("Invalid duration!\n");
            return 1;
        }

        printf("Memory (MB): ");
        if (scanf("%d", &tasks[i].memory) != 1 ||
            tasks[i].memory < 0) {
            printf("Invalid memory value!\n");
            return 1;
        }

        getchar();

        printf("Description: ");
        if (fgets(tasks[i].description,
                  sizeof(tasks[i].description), stdin) == NULL) {
            printf("Invalid description!\n");
            return 1;
        }

        tasks[i].description[
            strcspn(tasks[i].description, "\n")
        ] = '\0';

        tasks[i].status = WAITING;
    }

    printf("\n========== TASK QUEUE ==========\n");

    for (int i = 0; i < task_count; i++) {

        printf("\nTask ID: %d\n", tasks[i].task_id);
        printf("Description: %s\n", tasks[i].description);
        printf("Duration: %d seconds\n", tasks[i].duration);
        printf("Memory: %d MB\n", tasks[i].memory);
        printf("Status: WAITING\n");
    }

    printf("\nAll tasks received successfully!\n");

    return 0;
}