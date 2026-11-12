#include<stdio.h>
void main()
{
  int n,i,j,k,a[10],b[10],c[10];
  printf("Enter the highest order of the polynomial: ");
  scanf("%d",&n);
        
        printf("\n Enter the first polynomial: ");
        for(i=0;i<=n;i++)
        {
         scanf("%d",&a[i]);
        }
        
             printf("\n Enter the second polynomial: ");
             for(j=0;j<=n;j++);
             {
              scanf("%d",&b[j]);
             }
                 
                   for(i=0,j=0,k=0;k<=n;k++,j++,i++)
                   {
                     c[k]=b[j]+a[i];
                   }
                   
                      printf("\n The resultant polynomial is ");
                      {
                        for(k=0;k<=n;k++)
                         {
                           if(c[k]!=0)
                            {
                              printf("%dx^%d",c[k],n-k);
                             }
                            if(k<n)
                            {
                             printf("+");
                            }
                         }
                      } 
                            
                         
   }                
             
