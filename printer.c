
#include <stdio.h>
#include <string.h>

#define SIZE 5

struct PrintJob {
    int jobID;
    char fileName[50];
};

struct PrintJob queue[SIZE];

int front = -1;
int rear = -1;
int nextID = 1;

int isFull() {
    return (rear + 1) % SIZE == front;
}

int isEmpty() {
    return front == -1;
}

void addJob() {
    if (isFull()) {
        printf("\nPrinter Queue is Full!\n");
        return;
    }

    char name[50];

    printf("Enter file name (without spaces): ");
    scanf("%49s", name);

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % SIZE;

    queue[rear].jobID = nextID++;
    strcpy(queue[rear].fileName, name);

    printf("Print job added successfully!\n");
    printf("Job ID: %d\n", queue[rear].jobID);
}

void processJob() {
    if (isEmpty()) {
        printf("\nNo pending print jobs!\n");
        return;
    }

    printf("\nProcessing Print Job...\n");
    printf("Job ID: %d\n", queue[front].jobID);
    printf("File Name: %s\n", queue[front].fileName);

    printf("Printing completed!\n");

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void displayJobs() {
    if (isEmpty()) {
        printf("\nNo pending jobs.\n");
        return;
    }

    printf("\n===== PENDING PRINT JOBS =====\n");

    int i = front;

    while (1) {
        printf("Job ID: %d | File: %s\n",
               queue[i].jobID,
               queue[i].fileName);

        if (i == rear) {
            break;
        }

        i = (i + 1) % SIZE;
    }
}

int main() {
    int choice;

    do {
        printf("\n===== PRINTER JOB SCHEDULER =====\n");
        printf("1. Add Print Job\n");
        printf("2. Process Print Job\n");
        printf("3. Display Pending Jobs\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addJob();
                break;

            case 2:
                processJob();
                break;

            case 3:
                displayJobs();
                break;

            case 4:
                printf("Exiting Printer Scheduler...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
