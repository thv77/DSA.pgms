#include<stdio.h>
void main()
{

 int a[100],i,n,elm,found=0;
 printf("enter the size of array: ");
 scanf("%d",&n);

 printf("enter the elements: ");

      for(i=0;i<n;i++)
      {
        scanf("%d",&a[i]);
      }
   
   printf("enter the element to search: ");
   scanf("%d",&elm);
   
                   for(i=0;i<n;i++)
                   {
                     if(a[i]==elm)
                     {
                       found=1;
                       break;
                       }
                    }
                    
                            if(found==1)
                             {
                               printf("the element %d found at position %d",elm, i);
                             }
                            else
                             {
                               printf("element not found");
                             }
}
