#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = 0, rear = -1;

void enqueue(void)
{
    int value;
    if (rear == MAX_SIZE - 1) {
        printf("Queue overflow.\n");
        return;
    }
    printf("Enter value: ");
    if (scanf("%d", &value) != 1)
        return;
    queue[++rear] = value;
    printf("%d inserted.\n", value);
}

void dequeue(void)
{
    if (front > rear) {
        printf("Queue underflow.\n");
        return;
    }
    printf("Deleted: %d\n", queue[front++]);
    if (front > rear) {
        front = 0;
        rear = -1;
    }
}

void display(void)
{
    int i;
    if (front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main(void)
{
    int choice;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1)
            return 1;
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
