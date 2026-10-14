/* Linear Queue Operations Using an Array in C */
#include <stdio.h>

#define MAXSIZE 3

int front = 0;
int rear = -1;
int queue[MAXSIZE];

void enqueue(void);
void dequeue(void);
void display(void);

int main(void)
{
    int choice;

    do {
        printf("\nLinear Queue Menu\n");
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

    if (rear == MAXSIZE - 1) {
        printf("Queue overflow.\n");
        return;
    }

    printf("Enter the number to insert: ");
    if (scanf("%d", &item) != 1) {
        printf("Invalid input.\n");
        return;
    }

    queue[++rear] = item;
    printf("Element inserted successfully.\n");
}

void dequeue(void)
{
    if (front > rear) {
        printf("Queue underflow.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front++]);
}

void display(void)
{
    int i;

    if (front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements (front to rear):\n");
    for (i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}
