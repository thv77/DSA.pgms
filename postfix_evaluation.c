#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int main(void)
{
    char expression[MAX_SIZE];
    int stack[MAX_SIZE];
    int top = -1;
    int i, first, second, result;

    printf("Enter postfix expression using single-digit operands: ");
    if (scanf("%99s", expression) != 1)
        return 1;

    for (i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (isdigit((unsigned char) ch)) {
            if (top >= MAX_SIZE - 1) {
                printf("Expression is too long.\n");
                return 1;
            }
            stack[++top] = ch - '0';
        } else {
            if (top < 1) {
                printf("Invalid postfix expression.\n");
                return 1;
            }

            second = stack[top--];
            first = stack[top--];

            switch (ch) {
                case '+':
                    result = first + second;
                    break;
                case '-':
                    result = first - second;
                    break;
                case '*':
                    result = first * second;
                    break;
                case '/':
                    if (second == 0) {
                        printf("Division by zero is not allowed.\n");
                        return 1;
                    }
                    result = first / second;
                    break;
                default:
                    printf("Unsupported operator: %c\n", ch);
                    return 1;
            }

            stack[++top] = result;
        }
    }

    if (top != 0) {
        printf("Invalid postfix expression.\n");
        return 1;
    }

    printf("Result = %d\n", stack[top]);
    return 0;
}
