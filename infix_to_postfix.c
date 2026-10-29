#include <stdio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX]; int top=-1;
void push(char c) { if(top<MAX-1) stack[++top]=c; }
char pop(void) { return top>=0 ? stack[top--] : '\0'; }
int priority(char c) { if(c=='^') return 3; if(c=='*'||c=='/') return 2; if(c=='+'||c=='-') return 1; return 0; }
int main(void) {
    char infix[MAX], postfix[MAX], ch; int i,j=0;
    printf("Enter infix expression (no spaces): ");
    if(scanf("%99s",infix)!=1) return 1;
    for(i=0;infix[i]!='\0';i++) {
        ch=infix[i];
        if(isalnum((unsigned char)ch)) postfix[j++]=ch;
        else if(ch=='(') push(ch);
        else if(ch==')') {
            while(top>=0 && stack[top]!='(') postfix[j++]=pop();
            if(top<0) { printf("Mismatched parentheses\n"); return 1; }
            pop();
        } else {
            while(top>=0 && stack[top]!='(' && (priority(stack[top])>priority(ch) || (priority(stack[top])==priority(ch) && ch!='^'))) postfix[j++]=pop();
            push(ch);
        }
    }
    while(top>=0) { if(stack[top]=='(') { printf("Mismatched parentheses\n"); return 1; } postfix[j++]=pop(); }
    postfix[j]='\0'; printf("Postfix expression: %s\n",postfix); return 0;
}