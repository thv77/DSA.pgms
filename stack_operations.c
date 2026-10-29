#include <stdio.h>

#define MAX_SIZE 5

static int stack[MAX_SIZE];
static int top = -1;

static void push(void)
{
    int value;

    if (top == MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        return;
    }

    printf("Enter value to push: ");
    if (scanf("%d", &value) != 1)
        return;

    stack[++top] = value;
    printf("%d pushed onto the stack.\n", value);
}

static void pop(void)
{
    if (top == -1) {
        printf("Stack underflow.\n");
        return;
    }

    printf("Popped: %d\n", stack[top--]);
}

static void display(void)
{
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main(void)
{
    int choice;

    do {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1)
            return 1;

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
