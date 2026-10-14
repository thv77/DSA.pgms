/* Stack Operations Using an Array in C */
#include <stdio.h>

#define MAXSIZE 5

int top = -1;
int stack[MAXSIZE];

void push(void);
void pop(void);
void display(void);

int main(void)
{
    int choice;

    do {
        printf("\nStack Menu\n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Display the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Have a nice day!\n"); break;
            default: printf("Wrong choice.\n");
        }
    } while (choice != 4);

    return 0;
}

void push(void)
{
    int item;

    if (top == MAXSIZE - 1) {
        printf("Stack overflow.\n");
        return;
    }

    printf("Enter the number to insert: ");
    if (scanf("%d", &item) != 1) {
        printf("Invalid input.\n");
        return;
    }

    stack[++top] = item;
    printf("Element inserted successfully.\n");
}

void pop(void)
{
    if (top == -1) {
        printf("Stack underflow.\n");
        return;
    }

    printf("Deleted element: %d\n", stack[top--]);
}

void display(void)
{
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
