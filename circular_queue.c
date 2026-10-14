/* Circular Queue Operations Using an Array in C */
#include <stdio.h>

#define MAXSIZE 3

int front = -1;
int rear = -1;
int queue[MAXSIZE];

void enqueue(void);
void dequeue(void);
void display(void);

int main(void)
{
    int choice;

    do {
        printf("\nCircular Queue Menu\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Have a nice day!\n"); break;
            default: printf("Wrong choice.\n");
        }
    } while (choice != 4);

    return 0;
}

void enqueue(void)
{
    int item;

    if ((front == 0 && rear == MAXSIZE - 1) ||
        (front == rear + 1)) {
        printf("Queue overflow.\n");
        return;
    }

    printf("Enter the number to insert: ");
    if (scanf("%d", &item) != 1) {
        printf("Invalid input.\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAXSIZE;
    }

    queue[rear] = item;
    printf("Element inserted successfully.\n");
}

void dequeue(void)
{
    int data;

    if (front == -1) {
        printf("Queue underflow.\n");
        return;
    }

    data = queue[front];
    printf("Deleted element: %d\n", data);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAXSIZE;
    }
}

void display(void)
{
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular queue elements (front to rear):\n");
    i = front;

    while (1) {
        printf("%d\n", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAXSIZE;
    }
}
