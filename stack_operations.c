#include<stdio.h>
#include<stdlib.h>

#define maxsize 5

int top = -1;
int stack[maxsize];

void push();
void pop();
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
                push();
                break;

            case 2:
                pop();
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

void push()
{
    int item;

    printf("Enter the number to insert:");
    scanf("%d", &item);

    if (top == maxsize - 1)
        printf("Stack overflow\n");
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

void pop()
{
    int data;

    if (top == -1)
        printf("stack underflow\n");
    else
    {
        data = stack[top];
        top = top - 1;
        printf("one element is successfully deleted\n");
    }
}

void display()
{
    int i;

    for (i = top; i > -1; i--)
    {
        printf("%d\n", stack[i]);
    }
}
