#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 100

// Function prototypes
void addTask(char tasks[][TASK_LENGTH], int *taskCount);
void viewTasks(char tasks[][TASK_LENGTH], int taskCount);
void deleteTask(char tasks[][TASK_LENGTH], int *taskCount);

int main() {
    char tasks[MAX_TASKS][TASK_LENGTH];
    int taskCount = 0;
    int choice;

    do {
        printf("\n--- To-Do List ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                deleteTask(tasks, &taskCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addTask(char tasks[][TASK_LENGTH], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter the task: ");
    getchar(); // To consume leftover newline from previous input
    fgets(tasks[*taskCount], TASK_LENGTH, stdin);
    tasks[*taskCount][strcspn(tasks[*taskCount], "\n")] = 0; // Remove newline character
    (*taskCount)++;
    printf("Task added successfully.\n");
}

void viewTasks(char tasks[][TASK_LENGTH], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }
    printf("\n--- Task List ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void deleteTask(char tasks[][TASK_LENGTH], int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }
    int taskIndex;
    printf("Enter the task number to delete: ");
    scanf("%d", &taskIndex);

    if (taskIndex < 1 || taskIndex > *taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    // Shift tasks
    for (int i = taskIndex - 1; i < *taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    (*taskCount)--;
    printf("Task deleted successfully.\n");
}
