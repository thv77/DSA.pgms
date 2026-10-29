#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

static char stack[MAX_SIZE];
static int top = -1;

static int precedence(char operator)
{
    switch (operator) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

static void push(char value)
{
    if (top < MAX_SIZE - 1)
        stack[++top] = value;
}

static char pop(void)
{
    if (top < 0)
        return '\0';
    return stack[top--];
}

int main(void)
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    char ch;
    int i, j = 0;

    printf("Enter infix expression (no spaces): ");
    if (scanf("%99s", infix) != 1)
        return 1;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum((unsigned char) ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = pop();

            if (top < 0) {
                printf("Mismatched parentheses.\n");
                return 1;
            }

            pop();
        } else if (ch == '+' || ch == '-' || ch == '*' ||
                   ch == '/' || ch == '^') {
            while (top >= 0 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                    (precedence(stack[top]) == precedence(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }
            push(ch);
        } else {
            printf("Unsupported character: %c\n", ch);
            return 1;
        }
    }

    while (top >= 0) {
        if (stack[top] == '(') {
            printf("Mismatched parentheses.\n");
            return 1;
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
