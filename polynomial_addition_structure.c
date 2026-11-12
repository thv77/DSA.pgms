#include<stdio.h>
void main()
{
  struct poly
  {
    int exp[10];
    int coeff[10];
   }x[3];
     
      int n1,n2,m,i,j,k;
       
      printf("Enter the highest order of first polynomial: " );
      scanf("%d",&n1);
      printf("Enter the first polynomial: ");
      for(i=0;i<=n1;i++)
      {
       scanf("%d%d",&x[0].coeff[i],&x[0].exp[i]);
       }
       
           printf("Enter the highest order of second polynomial: " );
           scanf("%d",&n2);
           printf("Enter the second polynomial: ");
           for(j=0;j<=n2;j++)
           {
            scanf("%d%d",&x[1].coeff[j],&x[1].exp[j]);
           }
               
                   if(n1>n2)
                   {
                     m=n1;
                    }
                   else if(n1==n2)
                   {
                    m=n2;
                   }
                   else
                    {
                    m=n2;
                    }
                    
                          for(i=0,j=0,k=0;k<=m;k++)
                          {
                           if(x[0].exp[i]>x[1].exp[j])
                            {
                             x[2].exp[k]=x[0].exp[i];
                             x[2].coeff[k]=x[0].coeff[i];
                             i++;
                             }
                            else if(x[0].exp[i]<x[1].exp[j]) 
                            {
                              x[2].exp[k]=x[1].exp[j];
                              x[2].coeff[k]=x[1].coeff[j];
                              j++;
                             }
                              
                             else if(x[0].exp[i]==x[1].exp[j]) 
                            {
                              x[2].exp[k]=x[1].exp[j];
                              x[2].coeff[k]=x[1].coeff[j]+x[0].coeff[i];
                              i++;
                              j++;
                             }
                              else if(i>j)
                              {
                                x[2].exp[k]=x[0].exp[i];
                                x[2].coeff[k]=x[0].coeff[i];
                                i++
                               }
                               
                              else
                              {
                               x[2].exp[k]=x[1].exp[j];
                               x[2].coeff[k]=x[1].coeff[j];
                               j++;
                               }
                             }
                             
                                    
                                    printf("The sum: \n");
                                    for(k=0;k<=m;k++)
                                    {
                                      if(x[2].coeff[k]!=0)
                                      {
                                       if(x[2].exp[k]==0)
                                       {
                                        printf("%d",x[2].coeff[k]);
                                       }
                                        else
                                        {
                                         printf("%dx^%d",x[2].coeff[k],x[2].exp[k]);
                                         }
                                      }
                                         
                                         if(k<m)
                                         {
                                          printf("+");
                                          }
                                      }
}
                              
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             
                             

