#include<stdio.h>
#include<stdlib.h>

#define maxsize 3

int rear = -1;
int front = 0;
int queue[maxsize];

void enqueue();
void dequeue();
void display();

void main()
{
    int n = 0;

    while (n != 4)
    {
        printf("Enter your choice:\n");
        printf("1.choose 1 if you want to enter the elements.\n");
        printf("2.choose 2 if you want to delete the elements:\n");
        printf("3.choose 3 if you want to display the elements\n");
        printf("4.choose 4 to exit\n");

        scanf("%d", &n);

        switch (n)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Have a nice day");
                exit(0);
                break;

            default:
                printf("Wrong choice");
                break;
        }
    }
}

void enqueue()
{
    int item;

    printf("Enter the number to insert:");
    scanf("%d", &item);

    if (rear == maxsize - 1)
        printf("queue overflow\n");
    else
    {
        rear = rear + 1;
        queue[rear] = item;
    }
}

void dequeue()
{
    int data;

    if (rear == -1 && front == 0)
    {
        printf("%d%d", rear, front);
        printf("queue underflow\n");
    }
    else
    {
        data = queue[front];
        front = front + 1;
        printf("one element is successfully deleted\n");
    }
}

void display()
{
    int i;

    for (i = front; i <= rear; i++)
    {
        printf("%d\n", queue[i]);
    }
}
