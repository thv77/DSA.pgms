#include<stdio.h>

void main()
{
    int n,i,key,flag=0,a[10];

    printf("enter the limit of the array:");
    scanf("%d",&n);

    printf("enter the %d elements:",n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("enter the key:");
    scanf("%d",&key);

    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("%d is found in %d\n",key,i);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("%d is not found",key);
    }
}