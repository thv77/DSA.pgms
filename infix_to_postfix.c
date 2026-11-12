#include <stdio.h>
#include <ctype.h> /* isalnum = is alpha numeric*/
#define MAX 100

char stack[MAX];
int top = -1;

             void push(char ch) /* first function */
                {
                 stack[++top] = ch;
                }
                
                  char pop() /* second function */
                    {
                      return stack[top--];
                    }
                    
                      int priority(char ch) /* third function */
                        {
                         if (ch == '^')
                          return 3;
                         else if (ch == '*' || ch == '/')
                          return 2;
                         else if (ch == '+' || ch == '-')
                          return 1;
                         else
                          return 0;
                        }
                        
 int main()
 {
  char infix[MAX], postfix[MAX];
  int i, j = 0;
  char ch;
  
  printf("Enter the infix expression: ");
  scanf("%s", infix);
  
        for (i = 0; infix[i] != '\0'; i++)
           {
            ch = infix[i];
                /* If operand, add to postfix */
                      if (isalnum(ch))
                       {
                        postfix[j++] = ch;
                       }
                       
                   /* If '(', push into stack */
                      else if (ch == '(')
                       {
                        push(ch);
                       }
                       
                   /* If ')', pop until '(' */
                      else if (ch == ')')
                       {
                        while (stack[top] != '(')
                         {
                          postfix[j++] = pop();
                         }
                          pop(); // Remove '('
                       }
                  /* If operator */
                      else
                       {
                        while (top != -1 && priority(stack[top]) >= priority(ch))
                           {
                            postfix[j++] = pop();
                           }
                            push(ch);
                       }
             }

                                               /* Pop remaining operators */
                                                   while (top != -1)
                                                     {
                                                       postfix[j++] = pop();
                                                     }
                                                       postfix[j] = '\0';
                                                       printf("Postfix expression: %s\n", postfix);
                                                       return 0;
} 
