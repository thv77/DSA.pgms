#include<stdio.h>
#define max 5
int main()
{
   int stack[max],choice,item,i;
   int top=-1;
   
       while(1)
       {
         printf("\n STACK \n");
         printf("\n 1.PUSH \n");
         printf("\n 2.POP \n");
         printf("\n 3.DISPLAY \n");
         printf("\n 4.EXIT \n");
         
         printf("\n Enter your choice: \n");
         scanf("%d",&choice);
         
                 if(choice==1)
                 { 
                  if(top=max-1)
                  {
                   printf("Stack overflow");
                  }
                  else
                  {
                   printf("Enter the element: ");
                   scanf("%d",&item);
                   top=top+1;
                   stack[top]=item;
                   printf("The element %d pushed into the stack",item);
                   }
                  }
                  
                  else if(choice==2)
                  {
                   if(top=-1)
                   {
                    printf("Stack Underflow");
                   }
                   else 
                   {
                    item=stack[top];
                    top=top-1;
                    printf("The element %d poped from the stack",item);
                   }
                  }
                  
                  else if(choice==3)
                  {
                   if(top==-1)
                   {
                    printf("Stack is empty");
                   }
                   else
                   {
                    printf("The stack elements are: ");
                     for(i=top;i>=0;i--)
                      {
                       printf("%d",stack[i]);
                       }
                    }
                    }
                    else if(choice==4)
                    break;
                    
                    else
                    {
                     printf("Invalid Choice");
                    }
                    return 0;
               }
            
  }                  
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                   
   
   
