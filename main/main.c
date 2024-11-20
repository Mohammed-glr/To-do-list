#include<stdio.h>
#include<string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100


void addTasks(char tasks[][MAX_LENGTH], int *taskCount);
void viewTasks(char tasks[][MAX_LENGTH], int taskCount);
void removeTask(char tasks[][MAX_LENGTH], int *taskCount);

int main(){
    char tasks[MAX_TASKS][MAX_LENGTH];
    int taskCount = 0;
    int taskCount = 0;
    int choice;

    do {
        printf("\n--- To-Do List ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                addTasks(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                removeTask(tasks, &taskCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}



