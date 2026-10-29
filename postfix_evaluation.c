#include <stdio.h>
#include <ctype.h>
#define MAX 100
int stack[MAX], top=-1;
int main(void) {
    char exp[MAX]; int i,a,b,r;
    printf("Enter postfix expression using single-digit operands: ");
    if(scanf("%99s",exp)!=1) return 1;
    for(i=0;exp[i]!='\0';i++) {
        if(isdigit((unsigned char)exp[i])) stack[++top]=exp[i]-'0';
        else {
            if(top<1) { printf("Invalid postfix expression\n"); return 1; }
            b=stack[top--]; a=stack[top--];
            switch(exp[i]) {
                case '+': r=a+b; break; case '-': r=a-b; break;
                case '*': r=a*b; break;
                case '/': if(b==0) { printf("Division by zero\n"); return 1; } r=a/b; break;
                default: printf("Unsupported operator\n"); return 1;
            }
            stack[++top]=r;
        }
    }
    if(top!=0) { printf("Invalid postfix expression\n"); return 1; }
    printf("Result = %d\n",stack[top]); return 0;
}